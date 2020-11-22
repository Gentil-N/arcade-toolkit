#include "orn_core.h"

struct OrnMemoryPool
{
       VkDeviceMemory memory;
       uint32_t memory_type;
       AtkVector allocs;
       VkDeviceSize num_mapped;
       void *mapped;
};

OrnMemoryPool *ornCreateMemoryPool(VkDevice device, OrnMemoryAllocator *memory_allocator, VkDeviceSize size, uint32_t memory_type)
{
       OrnMemoryPool *memory_pool = (OrnMemoryPool *)atk_alloc(sizeof(struct OrnMemoryPool));
       atk_api_assert(memory_pool != NULL);

       VkMemoryAllocateInfo allocate_info = vkfMemoryAllocateInfo(size, memory_type);
       orn_assert_vk(memory_allocator->dtbl->vkAllocateMemory(device, &allocate_info, VK_AC, &memory_pool->memory));

       atkNewVector(&memory_pool->allocs, 0, sizeof(OrnMemoryAllocation *));
       memory_pool->memory_type = memory_type;
       memory_pool->num_mapped = 0;
       memory_pool->mapped = NULL;

       OrnMemoryAllocation *fake_alloc = (OrnMemoryAllocation *)atk_alloc(sizeof(struct OrnMemoryAllocation));
       atk_api_assert(fake_alloc != NULL);
       fake_alloc->memory_pool = memory_pool;
       fake_alloc->offset = size;
       fake_alloc->size = 0;

       atkVectorPushBack(&memory_pool->allocs, &fake_alloc);

       return memory_pool;
}

void ornDestroyMemoryPool(VkDevice device, OrnMemoryAllocator *memory_allocator, OrnMemoryPool *memory_pool)
{
       atk_free(atk_get(OrnMemoryAllocation *, memory_pool->allocs, memory_pool->allocs.m_count - 1));
       atkDeleteVector(&memory_pool->allocs);
       memory_allocator->dtbl->vkFreeMemory(device, memory_pool->memory, VK_AC);
       atk_free(memory_pool);
}

VkBool32 ornAllocateMemoryFromPool(OrnMemoryPool *memory_pool, OrnMemoryAllocation *memory_alloc, VkDeviceSize alignment)
{
       VkDeviceSize previous_max_offset = 0;
       VkDeviceSize shift;

       for (size_t i = 0; i < memory_pool->allocs.m_count; ++i)
       {
              OrnMemoryAllocation *curr_object = atk_get(OrnMemoryAllocation *, memory_pool->allocs, i);
              shift = previous_max_offset % alignment == 0 ? 0 : alignment - previous_max_offset % alignment;

              if (curr_object->offset - previous_max_offset >= memory_alloc->size + shift)
              {
                     memory_alloc->memory_pool = memory_pool;
                     memory_alloc->offset = previous_max_offset + shift;
                     atkVectorInsert(&memory_pool->allocs, i, &memory_alloc);
                     return VK_TRUE;
              }
              previous_max_offset = curr_object->offset + curr_object->size;
       }
       return VK_FALSE;
}

void ornFreeMemoryFromPool(OrnMemoryAllocation *memory_alloc)
{
       for (size_t i = 0; i < memory_alloc->memory_pool->allocs.m_count; ++i)
       {
              OrnMemoryAllocation *curr_object = atk_get(OrnMemoryAllocation *, memory_alloc->memory_pool->allocs, i);
              if (memory_alloc == curr_object)
              {
                     atkVectorRemove(&memory_alloc->memory_pool->allocs, i);
                     return;
              }
       }
       atk_api_dbg_warn("failed to free memory object from pool");
}

VkResult ornBindMemoryAllocation(VkDevice device, OrnMemoryAllocator *memory_allocator, const OrnMemoryAllocationSettings *settings, OrnMemoryAllocation *memory_alloc)
{
       if (settings->objectType == ORN_BUFFER_OBJECT_TYPE)
       {
              orn_assert_vk(memory_allocator->dtbl->vkBindBufferMemory(device, settings->buffer, memory_alloc->memory_pool->memory, memory_alloc->offset));
              return VK_SUCCESS;
       }
       else if (settings->objectType == ORN_IMAGE_OBJECT_TYPE)
       {
              orn_assert_vk(memory_allocator->dtbl->vkBindImageMemory(device, settings->image, memory_alloc->memory_pool->memory, memory_alloc->offset));
              return VK_SUCCESS;
       }
       else
       {
              return VK_ERROR_INITIALIZATION_FAILED;
       }

       return VK_SUCCESS;
}

OrnMemoryAllocator *ornCreateMemoryAllocator(const OrnMemoryAllocatorSettings *settings)
{
       OrnMemoryAllocator *memory_allocator = (OrnMemoryAllocator *)atk_alloc(sizeof(struct OrnMemoryAllocator));
       atk_api_assert(memory_allocator != NULL);

       memory_allocator->dtbl = settings->dtbl;
       memory_allocator->memory_pool_size = settings->memory_pool_size;
       atkNewVector(&memory_allocator->pools, 0, sizeof(OrnMemoryPool *));

       settings->itbl->vkGetPhysicalDeviceMemoryProperties(settings->physical_device, &memory_allocator->memory_properties);

       return memory_allocator;
}

void ornDestroyMemoryAllocator(VkDevice device, OrnMemoryAllocator *memory_allocator)
{
       for (size_t i = 0; i < memory_allocator->pools.m_count; ++i)
       {
              ornDestroyMemoryPool(device, memory_allocator, atk_get(OrnMemoryPool *, memory_allocator->pools, i));
       }
       atkDeleteVector(&memory_allocator->pools);
       atk_free(memory_allocator);
}

VkResult ornFindMemoryType(OrnMemoryAllocator *memory_allocator, uint32_t memory_type_bits, uint32_t memory_properties, uint32_t *memory_type)
{
       for (uint32_t i = 0; i < memory_allocator->memory_properties.memoryTypeCount; ++i)

              if (
                  (memory_type_bits & (1 << i)) &&
                  (memory_allocator->memory_properties.memoryTypes[i].propertyFlags & memory_properties) == memory_properties)
              {
                     (*memory_type) = i;
                     return VK_SUCCESS;
              }

       return VK_ERROR_INITIALIZATION_FAILED;
}

VkResult ornAllocateMemoryFromAllocator(
    VkDevice device, OrnMemoryAllocator *memory_allocator, VkMemoryRequirements memory_requirements, VkMemoryPropertyFlags memory_properties, OrnMemoryAllocation *memory_alloc)
{
       uint32_t memory_type = -1;
       orn_assert_vk(ornFindMemoryType(memory_allocator, memory_requirements.memoryTypeBits, memory_properties, &memory_type));
       memory_alloc->size = memory_requirements.size;

       if (memory_requirements.size > memory_allocator->memory_pool_size)
       { //pour les tailles trop grandes
              OrnMemoryPool *memory_pool = ornCreateMemoryPool(device, memory_allocator, memory_requirements.size, memory_type);
              atk_api_assert(memory_pool != NULL);
              //l'alignement n'est pas nécessaire vu que le pool est unique à l'allocation
              VkBool32 alloc_success = ornAllocateMemoryFromPool(memory_pool, memory_alloc, 1);
              atk_api_assert(alloc_success == VK_TRUE);
              atkVectorPushBack(&memory_allocator->pools, &memory_pool);
              return VK_SUCCESS;
       }

       for (size_t i = 0; i < memory_allocator->pools.m_count; ++i)
       { //traitement de chaque pool
              OrnMemoryPool *pool = atk_get(OrnMemoryPool *, memory_allocator->pools, i);
              if (pool->memory_type != memory_type)
              {
                     continue;
              }
              if (ornAllocateMemoryFromPool(pool, memory_alloc, memory_requirements.alignment) == VK_FALSE)
              {
                     continue;
              }
              return VK_SUCCESS;
       }

       OrnMemoryPool *pool = ornCreateMemoryPool(device, memory_allocator, memory_allocator->memory_pool_size, memory_type);
       atk_api_assert(pool != NULL);
       //l'alignement est "1" puisque l'allocation présente est forcément la première
       VkBool32 alloc_success = ornAllocateMemoryFromPool(pool, memory_alloc, 1);
       atk_api_assert(alloc_success == VK_TRUE);
       atkVectorPushBack(&memory_allocator->pools, &pool);
       return VK_SUCCESS;
}

OrnMemoryAllocation *ornAllocateMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, const OrnMemoryAllocationSettings *settings)
{
       OrnMemoryAllocation *memory_alloc = (OrnMemoryAllocation *)atk_alloc(sizeof(struct OrnMemoryAllocation));
       atk_api_assert(memory_alloc != NULL);

       VkMemoryRequirements memory_requirements;
       if (settings->objectType == ORN_BUFFER_OBJECT_TYPE)
       {
              memory_allocator->dtbl->vkGetBufferMemoryRequirements(device, settings->buffer, &memory_requirements);
       }
       else if (settings->objectType == ORN_IMAGE_OBJECT_TYPE)
       {
              memory_allocator->dtbl->vkGetImageMemoryRequirements(device, settings->image, &memory_requirements);
       }
       else
       {
              return NULL;
       }
       orn_assert_vk(ornAllocateMemoryFromAllocator(device, memory_allocator, memory_requirements, settings->memoryProperties, memory_alloc));
       orn_assert_vk(ornBindMemoryAllocation(device, memory_allocator, settings, memory_alloc));

       return memory_alloc;
}

void ornFreeMemory(OrnMemoryAllocation *memory_alloc)
{
       ornFreeMemoryFromPool(memory_alloc);
       atk_free(memory_alloc);
}

void *ornMapMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, OrnMemoryAllocation *memory_alloc)
{
       if (memory_alloc->memory_pool->num_mapped == 0)
       {
              orn_assert_vk(memory_allocator->dtbl->vkMapMemory(
                  device, memory_alloc->memory_pool->memory, 0,
                  atk_get(OrnMemoryAllocation *, memory_alloc->memory_pool->allocs, memory_alloc->memory_pool->allocs.m_count - 1)->offset,
                  0, &memory_alloc->memory_pool->mapped));
       }
       ++memory_alloc->memory_pool->num_mapped;
       return ((char *)memory_alloc->memory_pool->mapped) + memory_alloc->offset;
}

void ornUnmapMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, OrnMemoryAllocation *memory_alloc)
{
       --memory_alloc->memory_pool->num_mapped;
       if (memory_alloc->memory_pool->num_mapped == 0)
       {
              memory_allocator->dtbl->vkUnmapMemory(device, memory_alloc->memory_pool->memory);
       }
}