#include "orn_core.h"

OrnImage *ornCreateImage(
       VkDevice device, const VklDeviceTable *dtbl, VkmAllocator allocator, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
       uint32_t mip_level_count, VkSampleCountFlagBits sample_count)
{
       OrnImage *image = (OrnImage*)atk_alloc(sizeof(struct OrnImage));
       atk_assert(image != NULL);

       VkImageCreateInfo image_info = vkfImageCreateInfo(
              VK_IMAGE_TYPE_2D, format, (VkExtent3D){width, height, 1}, mip_level_count, 1, sample_count, tiling, usage, VK_SHARING_MODE_EXCLUSIVE, 
              0, NULL, VK_IMAGE_LAYOUT_UNDEFINED);
       orn_assert_vk(dtbl->vkCreateImage(device, &image_info, VK_AC, &image->handle));

       VkmAllocationCreateInfo alloc_info;
       alloc_info.image = image->handle;
       alloc_info.memoryProperties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
       alloc_info.objectType = VKM_IMAGE_OBJECT_TYPE;
       orn_assert_vk(vkmAllocateMemory(device, allocator, &alloc_info, &image->allocation));

       atk_info("image created");
       return image;
}

void ornDestroyImage(VkDevice device, const VklDeviceTable *dtbl, VkmAllocator allocator, OrnImage *image)
{
       vkmFreeMemory(allocator, image->allocation);
       dtbl->vkDestroyImage(device, image->handle, VK_AC);
       atk_free(image);
       atk_info("image destroyed");
}