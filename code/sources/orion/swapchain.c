#include "orn_core.h"

VkSurfaceFormatKHR chooseSurfaceFormat(const OrnGpu *gpu)
{
       for (size_t i = 0; i < gpu->surface_formats.m_count; ++i)
       {
              VkSurfaceFormatKHR curr_surface_format = atk_get(VkSurfaceFormatKHR, gpu->surface_formats, i);
              if (curr_surface_format.format == VK_FORMAT_R8G8B8A8_UNORM && curr_surface_format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
              {
                     return curr_surface_format;
              }
       }
       return atk_get(VkSurfaceFormatKHR, gpu->surface_formats, 0);
}

#define SWAPCHAIN_IMAGE_COUNT 2

VkExtent2D chooseExtent(const OrnGpu *gpu, uint32_t width, uint32_t height)
{
       if (gpu->surface_capabilities.currentExtent.width != UINT32_MAX && gpu->surface_capabilities.currentExtent.height != UINT32_MAX)
       {
              return gpu->surface_capabilities.currentExtent;
       }
       VkExtent2D extent;
       extent.width = atk_max(gpu->surface_capabilities.minImageExtent.width, atk_min(width, gpu->surface_capabilities.maxImageExtent.width));
       extent.height = atk_max(gpu->surface_capabilities.minImageExtent.height, atk_min(height, gpu->surface_capabilities.maxImageExtent.height));
       return extent;
}

VkPresentModeKHR choosePresentMode(const OrnGpu *gpu)
{
       for (size_t i = 0; i < gpu->present_modes.m_count; ++i)
       {
              if (atk_get(VkPresentModeKHR, gpu->present_modes, i) == VK_PRESENT_MODE_MAILBOX_KHR)
              {
                     return atk_get(VkPresentModeKHR, gpu->present_modes, i);
              }
       }
       return VK_PRESENT_MODE_FIFO_KHR;
}

OrnSwapchain *ornCreateSwapchain(VkDevice device, const VklDeviceTable *dtbl, const OrnGpu *gpu, uint32_t width, uint32_t height, OrnSurface *surface)
{
       OrnSwapchain *swapchain = (OrnSwapchain*)atk_alloc(sizeof(struct OrnSwapchain));
       atk_assert(swapchain != NULL);

       atk_assert(gpu->surface_formats.m_count > 0);
       swapchain->surface_format = chooseSurfaceFormat(gpu);
       uint32_t image_count = atk_max(gpu->surface_capabilities.minImageCount, atk_min(gpu->surface_capabilities.maxImageCount, SWAPCHAIN_IMAGE_COUNT));

       swapchain->extent = chooseExtent(gpu, width, height);
       atk_assert(gpu->present_modes.m_count > 0);
       swapchain->present_mode = choosePresentMode(gpu);

       uint32_t queue_indices[2];
       VkSwapchainCreateInfoKHR swapchain_info = vkfSwapchainCreateInfoKHR(
           surface->handle, image_count, swapchain->surface_format.format, swapchain->surface_format.colorSpace, swapchain->extent, 1, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
           VK_SHARING_MODE_EXCLUSIVE, 1, queue_indices, gpu->surface_capabilities.currentTransform, VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR, swapchain->present_mode, VK_TRUE, VK_NULL_HANDLE);
       if (gpu->graphics_queue_index == gpu->present_queue_index)
       {
              queue_indices[0] = gpu->graphics_queue_index;
       }
       else
       {
              queue_indices[0] = gpu->graphics_queue_index;
              queue_indices[1] = gpu->present_queue_index;
              swapchain_info.queueFamilyIndexCount = 2;
       }
       orn_assert_vk(dtbl->vkCreateSwapchainKHR(device, &swapchain_info, VK_AC, &swapchain->handle));
       {
              uint32_t count = 0;
              orn_assert_vk(dtbl->vkGetSwapchainImagesKHR(device, swapchain->handle, &count, NULL));
              atkNewArray(&swapchain->images, count, sizeof(VkImage));
              orn_assert_vk(dtbl->vkGetSwapchainImagesKHR(device, swapchain->handle, &count, (VkImage *)swapchain->images.m_data));
       }
       atkNewArray(&swapchain->image_views, swapchain->images.m_count, sizeof(VkImageView));
       for (size_t i = 0; i < swapchain->image_views.m_count; ++i)
       {
              VkComponentMapping components = vkfComponentMapping(VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY);
              VkImageSubresourceRange subresource = vkfImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1);
              VkImageViewCreateInfo image_info = vkfImageViewCreateInfo(
                  atk_get(VkImage, swapchain->images, i), VK_IMAGE_VIEW_TYPE_2D, swapchain->surface_format.format, components, subresource);
              orn_assert_vk(dtbl->vkCreateImageView(device, &image_info, VK_AC, &atk_get(VkImageView, swapchain->image_views, i)));
       }

       atk_info("swapchain created");
       return swapchain;
}

void ornDestroySwapchain(VkDevice device, const VklDeviceTable *dtbl, OrnSwapchain *swapchain)
{
       for (size_t i = 0; i < swapchain->image_views.m_count; ++i)
       {
              dtbl->vkDestroyImageView(device, atk_get(VkImageView, swapchain->image_views, i), VK_AC);
       }
       atkDeleteArray(&swapchain->image_views);
       atkDeleteArray(&swapchain->images);
       dtbl->vkDestroySwapchainKHR(device, swapchain->handle, VK_AC);
       atk_free(swapchain);
       atk_info("swapchain destoyed");
}