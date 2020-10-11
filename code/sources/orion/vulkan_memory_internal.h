#ifndef __VULKAN_MEMORY_EXTENSION_INTERNAL_H__
#define __VULKAN_MEMORY_EXTENSION_INTERNAL_H__

#include "vulkan_memory.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       static void *vkAllocationFunction(void *pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope)
       {
              return aligned_alloc(alignment, size);
       }

       static void *vkReallocationFunction(void *pUserData, void *pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope)
       {
              void *nptr = realloc(pOriginal, size);
              if ((uint64_t)nptr % alignment != 0)
              {
                     free(nptr);
                     nptr = aligned_alloc(size, alignment);
              }
              return nptr;
       }

       static void vkFreeFunction(void *pUserData, void *pMemory)
       {
              free(pMemory);
       }

       static const VkAllocationCallbacks defaultAllocCallbacks = {NULL, vkAllocationFunction, vkReallocationFunction, vkFreeFunction, NULL, NULL};

#define VKM_VK_CHECK_RETURN(func, result) \
       result = func;                     \
       if (result != VK_SUCCESS)          \
       {                                  \
              return result;              \
       }

       typedef struct _VkmDynamicArray *VkmDynamicArray;

       struct _VkmDynamicArray
       {
              void *pData;

              VkDeviceSize size;

              VkDeviceSize capacity;

              VkDeviceSize sizeOfElement;
       };

       void vkmNewDynamicArray(VkmDynamicArray *pArray, size_t size, size_t sizeOfElement, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDeleteDynamicArray(VkmDynamicArray array, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDynamicArrayPushBack(VkmDynamicArray array, void *pElement, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDynamicArrayPopBack(VkmDynamicArray array, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDynamicArrayInsert(VkmDynamicArray array, size_t index, void *pElement, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDynamicArrayRemove(VkmDynamicArray array, size_t index, const VkAllocationCallbacks *pAllocationCallbacks);

       void vkmDynamicArrayResizeCapacity(VkmDynamicArray array, size_t newCapacity, const VkAllocationCallbacks *pAllocationCallbacks);

#define VKM_DYN_ARR_GET(type, arr) ((type *)arr->pData)

       typedef struct _VkmPool *VkmPool;

       struct _VkmPool
       {
              VkDeviceMemory deviceMemory;

              uint32_t memoryTypeIndex;

              VkmDynamicArray allocations;

              VkDeviceSize numMapped;

              void *pMapped;
       };

       typedef struct VkmPoolCreateInfo
       {
              VkDeviceSize size;

              uint32_t memoryTypeIndex;

       } VkmPoolCreateInfo;

       VkResult vkmCreatePool(VkDevice device, VkmAllocator allocator, const VkmPoolCreateInfo *pCreateInfo, VkmPool *pMemPool);

       void vkmDestroyPool(VkDevice device, VkmAllocator allocator, VkmPool memPool);

       VkBool32 vkmAllocateMemoryFromPool(VkmAllocator allocator, VkmPool memPool, VkmAllocation allocation, VkDeviceSize alignment);

       void vkmFreeMemoryFromPool(VkmAllocator allocator, VkmAllocation allocation);

       struct _VkmAllocator
       {

              const VkAllocationCallbacks *allocationCallbacks;

              PFN_vkAllocateMemory pfn_allocateMemory;

              PFN_vkFreeMemory pfn_freeMemory;

              PFN_vkBindBufferMemory pfn_bindBufferMemory;

              PFN_vkBindImageMemory pfn_bindImageMemory;

              PFN_vkGetPhysicalDeviceMemoryProperties pfn_getPhysicalDeviceMemoryProperties;

              PFN_vkGetBufferMemoryRequirements pfn_getBufferMemoryRequirements;

              PFN_vkGetImageMemoryRequirements pfn_getImageMemoryRequirements;

              PFN_vkMapMemory pfn_mapMemory;

              PFN_vkUnmapMemory pfn_unmapMemory;

              VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;

              VkDeviceSize memoryPoolSize;

              VkmDynamicArray pools;
       };

       VkResult vkmAllocateMemoryFromAllocator(
           VkDevice device, VkmAllocator allocator, VkMemoryRequirements memoryRequirements, VkMemoryPropertyFlags memoryProperties, VkmAllocation allocation);

       VkResult vkmFindMemoryType(VkmAllocator allocator, uint32_t memoryTypeBits, uint32_t memoryProperties, uint32_t *memoryType);

       struct _VkmAllocation
       {
              VkDeviceSize offset;

              VkDeviceSize size;

              VkmPool pool;
       };

       VkResult vkmBindMemAllocation(VkDevice device, VkmAllocator allocator, const VkmAllocationCreateInfo *allocationCreateInfo, VkmAllocation allocation);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__VULKAN_MEMORY_EXTENSION_INTERNAL_H__