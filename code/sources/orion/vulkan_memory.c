#include "vulkan_memory_internal.h"
#ifndef NDEBUG
#include <assert.h>
#include <stdio.h>
#else
#define assert(expression) ((void)0)
#endif

#define ALLOC(pCallbacks, size) pCallbacks->pfnAllocation(pCallbacks->pUserData, size, 1, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT)
#define REALLOC(pCallbacks, ptr, size) pCallbacks->pfnReallocation(pCallbacks->pUserData, ptr, size, 1, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT)
#define FREE(pCallbacks, ptr) pCallbacks->pfnFree(pCallbacks->pUserData, ptr)

void vkmNewDynamicArray(VkmDynamicArray *pArray, size_t size, size_t sizeOfElement, const VkAllocationCallbacks *pAllocationCallbacks)
{
       (*pArray) = (VkmDynamicArray)ALLOC(pAllocationCallbacks, sizeof(struct _VkmDynamicArray));
       assert((*pArray) != 0);
       (*pArray)->size = size;
       if (size != 0)
              (*pArray)->capacity = size * 2;
       else
              (*pArray)->capacity = 10;
       (*pArray)->sizeOfElement = sizeOfElement;
       (*pArray)->pData = (void *)ALLOC(pAllocationCallbacks, sizeOfElement * (*pArray)->capacity);
       assert((*pArray)->pData != 0);
}

void vkmDeleteDynamicArray(VkmDynamicArray array, const VkAllocationCallbacks *pAllocationCallbacks)
{
       FREE(pAllocationCallbacks, array->pData);
       FREE(pAllocationCallbacks, array);
}

void vkmDynamicArrayPushBack(VkmDynamicArray array, void *pElement, const VkAllocationCallbacks *pAllocationCallbacks)
{
       if (array->size == array->capacity)
              vkmDynamicArrayResizeCapacity(array, array->size * 2, pAllocationCallbacks);

       memcpy(((char *)array->pData) + array->size * array->sizeOfElement, pElement, array->sizeOfElement);
       array->size++;
}

void vkmDynamicArrayPopBack(VkmDynamicArray array, const VkAllocationCallbacks *pAllocationCallbacks)
{
       array->size--;
       if (array->capacity > array->size * 2 && array->size != 0)
              vkmDynamicArrayResizeCapacity(array, array->size * 2, pAllocationCallbacks);
}

void vkmDynamicArrayInsert(VkmDynamicArray array, size_t index, void *pElement, const VkAllocationCallbacks *pAllocationCallbacks)
{
       if (array->size == array->capacity)
              vkmDynamicArrayResizeCapacity(array, array->size * 2, pAllocationCallbacks);

       char *ptr = ((char *)array->pData) + index * array->sizeOfElement;
       memmove(ptr + array->sizeOfElement, ptr, array->sizeOfElement * (array->size - index));
       memcpy(ptr, pElement, array->sizeOfElement);
       array->size++;
}

void vkmDynamicArrayRemove(VkmDynamicArray array, size_t index, const VkAllocationCallbacks *pAllocationCallbacks)
{
       char *ptr = ((char *)array->pData) + index * array->sizeOfElement;
       memmove(ptr, ptr + array->sizeOfElement, array->sizeOfElement * (array->size - index));
       array->size--;

       if (array->capacity > array->size * 2 && array->size != 0)
              vkmDynamicArrayResizeCapacity(array, array->size * 2, pAllocationCallbacks);
}

void vkmDynamicArrayResizeCapacity(VkmDynamicArray array, size_t newCapacity, const VkAllocationCallbacks *pAllocationCallbacks)
{
       array->capacity = newCapacity;
       array->pData = REALLOC(pAllocationCallbacks, array->pData, array->capacity * array->sizeOfElement);
       assert(array->pData != 0);
}

VkResult vkmCreatePool(VkDevice device, VkmAllocator allocator, const VkmPoolCreateInfo *pCreateInfo, VkmPool *pMemPool)
{
       (*pMemPool) = (VkmPool)ALLOC(allocator->allocationCallbacks, sizeof(struct _VkmPool));
       assert((*pMemPool) != 0);

       VkResult vkResult;

       VkMemoryAllocateInfo allocateInfo;
       allocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
       allocateInfo.pNext = NULL;
       allocateInfo.allocationSize = pCreateInfo->size;
       allocateInfo.memoryTypeIndex = pCreateInfo->memoryTypeIndex;

       VKM_VK_CHECK_RETURN(allocator->pfn_allocateMemory(device, &allocateInfo, allocator->allocationCallbacks, &(*pMemPool)->deviceMemory), vkResult);

       vkmNewDynamicArray(&(*pMemPool)->allocations, 0, sizeof(VkmAllocation), allocator->allocationCallbacks);

       (*pMemPool)->memoryTypeIndex = pCreateInfo->memoryTypeIndex;
       (*pMemPool)->numMapped = 0;
       (*pMemPool)->pMapped = NULL;

       VkmAllocation fakeAllocation = (VkmAllocation)ALLOC(allocator->allocationCallbacks, sizeof(struct _VkmAllocation));
       assert(fakeAllocation != 0);
       fakeAllocation->pool = (*pMemPool);
       fakeAllocation->offset = pCreateInfo->size;
       fakeAllocation->size = 0;
       vkmDynamicArrayPushBack((*pMemPool)->allocations, &fakeAllocation, allocator->allocationCallbacks);

       return VK_SUCCESS;
}

void vkmDestroyPool(VkDevice device, VkmAllocator allocator, VkmPool memPool)
{
       FREE(allocator->allocationCallbacks, VKM_DYN_ARR_GET(VkmAllocation, memPool->allocations)[memPool->allocations->size - 1]);
       vkmDeleteDynamicArray(memPool->allocations, allocator->allocationCallbacks);
       allocator->pfn_freeMemory(device, memPool->deviceMemory, allocator->allocationCallbacks);
       FREE(allocator->allocationCallbacks, memPool);
}

VkBool32 vkmAllocateMemoryFromPool(VkmAllocator allocator, VkmPool memPool, VkmAllocation allocation, VkDeviceSize alignment)
{
       VkDeviceSize previousMaxOffset = 0;
       VkDeviceSize shift;

       for (VkDeviceSize i = 0; i < memPool->allocations->size; ++i)
       {
              VkmAllocation currAlloc = VKM_DYN_ARR_GET(VkmAllocation, memPool->allocations)[i];
              shift = previousMaxOffset % alignment == 0 ? 0 : alignment - previousMaxOffset % alignment;

              if (currAlloc->offset - previousMaxOffset >= allocation->size + shift)
              {
                     allocation->pool = memPool;
                     allocation->offset = previousMaxOffset + shift;
                     vkmDynamicArrayInsert(memPool->allocations, i, &allocation, allocator->allocationCallbacks);
                     return VK_TRUE;
              }
              previousMaxOffset = currAlloc->offset + currAlloc->size;
       }
       return VK_FALSE;
}

void vkmFreeMemoryFromPool(VkmAllocator allocator, VkmAllocation allocation)
{
       for (VkDeviceSize i = 0; i < allocation->pool->allocations->size; ++i)
       {
              VkmAllocation currAlloc = VKM_DYN_ARR_GET(VkmAllocation, allocation->pool->allocations)[i];
              if (allocation == currAlloc)
                     vkmDynamicArrayRemove(allocation->pool->allocations, i, allocator->allocationCallbacks);
       }
}

void vkmCreateAllocator(const VkmAllocatorCreateInfo *pCreateInfo, VkmAllocator *pAllocator)
{
       const VkAllocationCallbacks* callbacks = pCreateInfo->allocationCallbacks == NULL
                                                   ? &defaultAllocCallbacks
                                                   : pCreateInfo->allocationCallbacks;
       (*pAllocator) = (VkmAllocator)callbacks->pfnAllocation(NULL, sizeof(struct _VkmAllocator), 1, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
       assert((*pAllocator) != 0);
       (*pAllocator)->allocationCallbacks = callbacks;
       
       (*pAllocator)->pfn_allocateMemory = pCreateInfo->pfn_allocateMemory;
       (*pAllocator)->pfn_freeMemory = pCreateInfo->pfn_freeMemory;
       (*pAllocator)->pfn_bindBufferMemory = pCreateInfo->pfn_bindBufferMemory;
       (*pAllocator)->pfn_bindImageMemory = pCreateInfo->pfn_bindImageMemory;
       (*pAllocator)->pfn_getBufferMemoryRequirements = pCreateInfo->pfn_getBufferMemoryRequirements;
       (*pAllocator)->pfn_getImageMemoryRequirements = pCreateInfo->pfn_getImageMemoryRequirements;
       (*pAllocator)->pfn_getPhysicalDeviceMemoryProperties = pCreateInfo->pfn_getPhysicalDeviceMemoryProperties;
       (*pAllocator)->pfn_mapMemory = pCreateInfo->pfn_mapMemory;
       (*pAllocator)->pfn_unmapMemory = pCreateInfo->pfn_unmapMemory;
       vkmNewDynamicArray(&(*pAllocator)->pools, 0, sizeof(VkmPool), (*pAllocator)->allocationCallbacks);
       (*pAllocator)->memoryPoolSize = pCreateInfo->memoryPoolSize;
       (*pAllocator)->pfn_getPhysicalDeviceMemoryProperties(pCreateInfo->physicalDevice, &(*pAllocator)->physicalDeviceMemoryProperties);
}

void vkmDestroyAllocator(VkDevice device, VkmAllocator allocator)
{
       for (size_t i = 0; i < allocator->pools->size; ++i)
              vkmDestroyPool(device, allocator, VKM_DYN_ARR_GET(VkmPool, allocator->pools)[i]);
       vkmDeleteDynamicArray(allocator->pools, allocator->allocationCallbacks);
       PFN_vkFreeFunction localFree = allocator->allocationCallbacks->pfnFree;
       localFree(NULL, allocator);
}

void vkmOptimizeMemory(VkmAllocator allocator)
{
}

VkResult vkmAllocateMemoryFromAllocator(
    VkDevice device, VkmAllocator allocator, VkMemoryRequirements memoryRequirements, VkMemoryPropertyFlags memoryProperties, VkmAllocation allocation)
{
       VkResult vkResult;

       uint32_t memoryTypeIndex = -1;
       VKM_VK_CHECK_RETURN(vkmFindMemoryType(allocator, memoryRequirements.memoryTypeBits, memoryProperties, &memoryTypeIndex), vkResult);

       allocation->size = memoryRequirements.size;

       if (memoryRequirements.size > allocator->memoryPoolSize)
       { //pour les tailles trop grandes

              VkmPoolCreateInfo poolInfo;
              poolInfo.memoryTypeIndex = memoryTypeIndex;
              poolInfo.size = memoryRequirements.size;
              VkmPool pool;
              VKM_VK_CHECK_RETURN(vkmCreatePool(device, allocator, &poolInfo, &pool), vkResult);
              //l'alignement n'est pas nécessaire vu que le pool est unique à l'allocation
              VkBool32 allocSuccess = vkmAllocateMemoryFromPool(allocator, pool, allocation, 1);
              assert(allocSuccess == VK_TRUE);
              vkmDynamicArrayPushBack(allocator->pools, &pool, allocator->allocationCallbacks);
              return VK_SUCCESS;
       }

       for (VkDeviceSize i = 0; i < allocator->pools->size; ++i)
       { //traitement de chaque pool
              VkmPool pool = VKM_DYN_ARR_GET(VkmPool, allocator->pools)[i];
              if (pool->memoryTypeIndex != memoryTypeIndex)
                     continue;
              if (vkmAllocateMemoryFromPool(allocator, pool, allocation, memoryRequirements.alignment) == VK_FALSE)
                     continue;
              return VK_SUCCESS;
       }

       VkmPoolCreateInfo poolInfo;
       poolInfo.memoryTypeIndex = memoryTypeIndex;
       poolInfo.size = allocator->memoryPoolSize;
       VkmPool pool;
       VKM_VK_CHECK_RETURN(vkmCreatePool(device, allocator, &poolInfo, &pool), vkResult);
       //l'alignement est "1" puisque l'allocation présente est forcément la première
       VkBool32 allocSuccess = vkmAllocateMemoryFromPool(allocator, pool, allocation, 1);
       assert(allocSuccess == VK_TRUE);
       vkmDynamicArrayPushBack(allocator->pools, &pool, allocator->allocationCallbacks);
       return VK_SUCCESS;
}

VkResult vkmFindMemoryType(VkmAllocator allocator, uint32_t memoryTypeBits, uint32_t memoryProperties, uint32_t *memoryType)
{
       for (uint32_t i = 0; i < allocator->physicalDeviceMemoryProperties.memoryTypeCount; ++i)

              if (
                  (memoryTypeBits & (1 << i)) &&
                  (allocator->physicalDeviceMemoryProperties.memoryTypes[i].propertyFlags & memoryProperties) == memoryProperties)
              {

                     (*memoryType) = i;
                     return VK_SUCCESS;
              }

       return VK_ERROR_INITIALIZATION_FAILED;
}

#ifndef NDEBUG
void vkmPrintMemAllocator(VkmAllocator allocator)
{
       printf("%s%p", "Vulkan Memory Extension : Allocator Details : ", allocator);
       printf("\n");

       printf("%s%lu", "Pool Size : ", allocator->memoryPoolSize);
       printf("\n");
       printf("%s%lu", "Num pool : ", allocator->pools->size);
       printf("\n\n");

       for (size_t i = 0; i < allocator->pools->size; ++i)
       {

              VkmPool pool = VKM_DYN_ARR_GET(VkmPool, allocator->pools)[i];
              printf("%s%lu%s%u%s%p", "Pool n.", i, ", type : ", pool->memoryTypeIndex, ", ", pool);
              printf("\n");

              for (size_t j = 0; j < pool->allocations->size; ++j)
              {
                     VkmAllocation allocation = VKM_DYN_ARR_GET(VkmAllocation, pool->allocations)[j];
                     printf("%s%lu%s%p", "\t> Allocation n.", j, " : ", allocation);
                     printf("\n");
                     printf("%s%lu", "\t-offset : ", allocation->offset);
                     printf("\n");
                     printf("%s%lu", "\t-size : ", allocation->size);
                     printf("\n");
                     printf("%s%p", "\t-Pool : ", allocation->pool);
                     printf("\n");
              }
       }
}
#endif

VkResult vkmAllocateMemory(VkDevice device, VkmAllocator allocator, const VkmAllocationCreateInfo *pCreateInfo, VkmAllocation *pAllocation)
{
       (*pAllocation) = (VkmAllocation)ALLOC(allocator->allocationCallbacks, sizeof(struct _VkmAllocation));
       assert((*pAllocation) != 0);

       VkMemoryRequirements memoryRequirements;
       if (pCreateInfo->objectType == VKM_BUFFER_OBJECT_TYPE)
              allocator->pfn_getBufferMemoryRequirements(device, pCreateInfo->buffer, &memoryRequirements);
       else if (pCreateInfo->objectType == VKM_IMAGE_OBJECT_TYPE)
              allocator->pfn_getImageMemoryRequirements(device, pCreateInfo->image, &memoryRequirements);
       else
              return VK_ERROR_INITIALIZATION_FAILED;

       VkResult vkResult;
       VKM_VK_CHECK_RETURN(
           vkmAllocateMemoryFromAllocator(
               device, allocator, memoryRequirements, pCreateInfo->memoryProperties, (*pAllocation)),
           vkResult);
       VKM_VK_CHECK_RETURN(vkmBindMemAllocation(device, allocator, pCreateInfo, (*pAllocation)), vkResult);
       return VK_SUCCESS;
}

void vkmFreeMemory(VkmAllocator allocator, VkmAllocation allocation)
{
       vkmFreeMemoryFromPool(allocator, allocation);
       FREE(allocator->allocationCallbacks, allocation);
}

VkResult vkmMapMemory(VkDevice device, VkmAllocator allocator, VkmAllocation allocation, void **ppData)
{
       VkResult vkResult;
       if (allocation->pool->numMapped == 0)
       {
              VKM_VK_CHECK_RETURN(
                  allocator->pfn_mapMemory(
                      device, allocation->pool->deviceMemory, 0,
                      VKM_DYN_ARR_GET(VkmAllocation, allocation->pool->allocations)[allocation->pool->allocations->size - 1]->offset,
                      0, &allocation->pool->pMapped),
                  vkResult);
       }
       (*ppData) = ((char *)allocation->pool->pMapped) + allocation->offset;
       ++allocation->pool->numMapped;
       return VK_SUCCESS;
}

void vkmUnmapMemory(VkDevice device, VkmAllocator allocator, VkmAllocation allocation)
{
       --allocation->pool->numMapped;
       if (allocation->pool->numMapped == 0)
              allocator->pfn_unmapMemory(device, allocation->pool->deviceMemory);
}

VkResult vkmBindMemAllocation(VkDevice device, VkmAllocator allocator, const VkmAllocationCreateInfo *allocationCreateInfo, VkmAllocation allocation)
{
       VkResult vkResult;

       if (allocationCreateInfo->objectType == VKM_BUFFER_OBJECT_TYPE)
       {
              VKM_VK_CHECK_RETURN(
                  allocator->pfn_bindBufferMemory(
                      device, allocationCreateInfo->buffer, allocation->pool->deviceMemory, allocation->offset),
                  vkResult);
              return VK_SUCCESS;
       }
       else if (allocationCreateInfo->objectType == VKM_IMAGE_OBJECT_TYPE)
       {
              VKM_VK_CHECK_RETURN(
                  allocator->pfn_bindImageMemory(
                      device, allocationCreateInfo->image, allocation->pool->deviceMemory, allocation->offset),
                  vkResult);
              return VK_SUCCESS;
       }
       else
              return VK_ERROR_INITIALIZATION_FAILED;

       return VK_SUCCESS;
}