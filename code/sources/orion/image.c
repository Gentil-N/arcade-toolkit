#include "orn_core.h"

OrnImage *ornCreateImage(
       VkDevice device, const VklDeviceTable *dtbl, OrnMemoryAllocator *memory_allocator, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
       uint32_t mip_level_count, VkSampleCountFlagBits sample_count)
{
       OrnImage *image = (OrnImage*)atk_alloc(sizeof(struct OrnImage));
       atk_assert(image != NULL);

       VkImageCreateInfo image_info = vkfImageCreateInfo(
              VK_IMAGE_TYPE_2D, format, (VkExtent3D){width, height, 1}, mip_level_count, 1, sample_count, tiling, usage, VK_SHARING_MODE_EXCLUSIVE, 
              0, NULL, VK_IMAGE_LAYOUT_UNDEFINED);
       orn_assert_vk(dtbl->vkCreateImage(device, &image_info, VK_AC, &image->handle));

       OrnMemoryAllocationSettings settings;
       settings.image = image->handle;
       settings.memoryProperties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
       settings.objectType = ORN_IMAGE_OBJECT_TYPE;
       image->alloc = ornAllocateMemory(device, memory_allocator, &settings);

       atk_info("image created");
       return image;
}

void ornDestroyImage(VkDevice device, const VklDeviceTable *dtbl, OrnImage *image)
{
       ornFreeMemory(image->alloc);
       dtbl->vkDestroyImage(device, image->handle, VK_AC);
       atk_free(image);
       atk_info("image destroyed");
}