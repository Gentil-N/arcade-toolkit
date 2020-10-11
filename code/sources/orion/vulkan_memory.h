#ifndef __VULKAN_MEMORY_EXTENSION_H__
#define __VULKAN_MEMORY_EXTENSION_H__

#ifndef VULKAN_H_
#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
#endif //VULKAN_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       typedef struct _VkmAllocator *VkmAllocator;

       typedef struct VkmAllocatorCreateInfo
       {
              const VkAllocationCallbacks* allocationCallbacks;//if not null, must be alive during the life of this allocator

              PFN_vkAllocateMemory pfn_allocateMemory;//should not be null

              PFN_vkFreeMemory pfn_freeMemory;//should not be null

              PFN_vkBindBufferMemory pfn_bindBufferMemory;//should not be null

              PFN_vkBindImageMemory pfn_bindImageMemory;//should not be null

              PFN_vkGetPhysicalDeviceMemoryProperties pfn_getPhysicalDeviceMemoryProperties;//should not be null

              PFN_vkGetBufferMemoryRequirements pfn_getBufferMemoryRequirements;//should not be null

              PFN_vkGetImageMemoryRequirements pfn_getImageMemoryRequirements;//should not be null

              PFN_vkMapMemory pfn_mapMemory;//should not be null

              PFN_vkUnmapMemory pfn_unmapMemory;//should not be null

              VkPhysicalDevice physicalDevice;

              VkDeviceSize memoryPoolSize;
       } VkmAllocatorCreateInfo;

       void vkmCreateAllocator(const VkmAllocatorCreateInfo *pCreateInfo, VkmAllocator *allocator);

       void vkmDestroyAllocator(VkDevice device, VkmAllocator allocator);

       void vkmOptimizeMemory(VkmAllocator memAllocator);

#ifndef NDEBUG
       void vkmPrintMemAllocator(VkmAllocator memAllocator);
#endif

       typedef enum VkmObjectTypeFlagBits
       {
              VKM_BUFFER_OBJECT_TYPE = 0x0000001,

              VKM_IMAGE_OBJECT_TYPE = 0x0000002,
       } VkmObjectTypeFlagBits;

       typedef VkFlags VkmObjectTypeFlags;

       typedef struct _VkmAllocation *VkmAllocation;

       typedef struct VkmAllocationCreateInfo
       {
              VkmObjectTypeFlags objectType;

              union {

                     VkBuffer buffer;

                     VkImage image;
              };

              VkMemoryPropertyFlags memoryProperties;
       } VkmAllocationCreateInfo;

       VkResult vkmAllocateMemory(
           VkDevice device, VkmAllocator allocator, const VkmAllocationCreateInfo *pCreateInfo, VkmAllocation *pAllocation);

       void vkmFreeMemory(VkmAllocator allocator, VkmAllocation allocation);

       VkResult vkmMapMemory(VkDevice device, VkmAllocator allocator, VkmAllocation allocation, void **ppData);

       void vkmUnmapMemory(VkDevice device, VkmAllocator allocator, VkmAllocation allocation);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__VULKAN_MEMORY_EXTENSION_H__