#include "orn_core.h"

void ornListGpus(AtkArray *gpus)
{
       uint32_t count = 0;
       orn_assert_vk(CONTEXT.itbl.vkEnumeratePhysicalDevices(CONTEXT.instance, &count, NULL));
       AtkArray physical_devices;
       atkNewArray(&physical_devices, count, sizeof(VkPhysicalDevice));
       orn_assert_vk(CONTEXT.itbl.vkEnumeratePhysicalDevices(CONTEXT.instance, &count, (VkPhysicalDevice *)physical_devices.m_data));

       atkNewArray(gpus, physical_devices.m_count, sizeof(OrnGpu *));
       
       for (size_t i = 0; i < count; ++i)
       {
              VkPhysicalDevice curr_physical_device = atk_get(VkPhysicalDevice, physical_devices, i);
              atk_get(OrnGpu *, *gpus, i) = (OrnGpu *)atk_alloc(sizeof(struct OrnGpu));
              OrnGpu *curr_gpu = atk_get(OrnGpu *, *gpus, i);
              curr_gpu->handle = curr_physical_device;
              curr_gpu->surface_formats.m_data = NULL; //to check alloc
              CONTEXT.itbl.vkGetPhysicalDeviceFeatures(curr_gpu->handle, &curr_gpu->features);
              curr_gpu->texture.format = VK_FORMAT_R8G8B8A8_UNORM;
              CONTEXT.itbl.vkGetPhysicalDeviceFormatProperties(curr_gpu->handle, curr_gpu->texture.format, &curr_gpu->texture.properties);
              CONTEXT.itbl.vkGetPhysicalDeviceProperties(curr_physical_device, &curr_gpu->properties);
              {
                     uint32_t count = 0;
                     CONTEXT.itbl.vkGetPhysicalDeviceQueueFamilyProperties(curr_physical_device, &count, NULL);
                     atkNewArray(&curr_gpu->queue_families, count, sizeof(VkQueueFamilyProperties));
                     CONTEXT.itbl.vkGetPhysicalDeviceQueueFamilyProperties(curr_physical_device, &count, (VkQueueFamilyProperties *)curr_gpu->queue_families.m_data);
              }
       }
       atkDeleteArray(&physical_devices);
}

void ornEraseGpus(AtkArray *gpus)
{
       for (size_t i = 0; i < gpus->m_count; ++i)
       {
              OrnGpu *curr_gpu = atk_get(OrnGpu *, *gpus, i);
              if (curr_gpu->surface_formats.m_data != NULL)
              {
                     atkDeleteArray(&curr_gpu->present_modes);
                     atkDeleteArray(&curr_gpu->surface_formats);
              }
              atkDeleteArray(&curr_gpu->queue_families);
              atk_free(atk_get(OrnGpu *, *gpus, i));
       }
       atkDeleteArray(gpus);
}

OrnGpu *const *ornGetGpus(uint32_t *count)
{
       *count = CONTEXT.gpus.m_count;
       return (OrnGpu *const *)CONTEXT.gpus.m_data;
}

const char *ornGetGpuName(const OrnGpu *gpu)
{
       return gpu->properties.deviceName;
}

bool ornCheckGpuExtensions(const OrnGpu *gpu, uint32_t extension_count, const char **required_extensions)
{
       AtkArray extensions;
       {
              uint32_t count = 0;
              orn_assert_vk(CONTEXT.itbl.vkEnumerateDeviceExtensionProperties(gpu->handle, NULL, &count, NULL));
              atkNewArray(&extensions, count, sizeof(VkExtensionProperties));
              orn_assert_vk(CONTEXT.itbl.vkEnumerateDeviceExtensionProperties(gpu->handle, NULL, &count, (VkExtensionProperties *)extensions.m_data));
       }

       for (uint32_t i = 0; i < extension_count; ++i)
       {
              const char *required_extension = required_extensions[i];
              bool found = false;
              for (size_t j = 0; j < extensions.m_count; ++j)
              {
                     if (strcmp(atk_get(VkExtensionProperties, extensions, j).extensionName, required_extension) == 0)
                     {
                            found = true;
                            break;
                     }
              }
              if (!found)
              {
                     atkDeleteArray(&extensions);
                     return false;
              }
       }
       atkDeleteArray(&extensions);
       return true;
}

const uint32_t GPU_EXTENSION_COUNT = 1;
const char *GPU_EXTENSIONS[1] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

bool ornGpuCheckMinimalGraphicsSupport(OrnGpu *gpu, const OrnSurface *surface)
{
       gpu->graphics_queue_index = UINT32_MAX;
       gpu->present_queue_index = UINT32_MAX;

       if (!ornCheckGpuExtensions(gpu, GPU_EXTENSION_COUNT, GPU_EXTENSIONS))
       {
              return false;
       }

       bool suitable_device = false;
       for (uint32_t j = 0; j < gpu->queue_families.m_count; ++j)
       {
              VkQueueFamilyProperties queue_props = atk_get(VkQueueFamilyProperties, gpu->queue_families, j);
              if (gpu->graphics_queue_index == UINT32_MAX && queue_props.queueCount > 0 && (queue_props.queueFlags & VK_QUEUE_GRAPHICS_BIT) == VK_QUEUE_GRAPHICS_BIT)
              {
                     gpu->graphics_queue_index = j;
              }
              VkBool32 pres_supported = VK_FALSE;
              orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfaceSupportKHR(gpu->handle, j, surface->handle, &pres_supported));
              if (gpu->present_queue_index == UINT32_MAX && pres_supported && queue_props.queueCount > 0)
              {
                     gpu->present_queue_index = j;
              }
              if (gpu->graphics_queue_index != UINT32_MAX && gpu->present_queue_index != UINT32_MAX)
              {
                     suitable_device = true;
                     break;
              }
       }

       orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfaceCapabilitiesKHR(gpu->handle, surface->handle, &gpu->surface_capabilities));
       {
              uint32_t count = 0;
              orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfaceFormatsKHR(gpu->handle, surface->handle, &count, NULL));
              atkNewArray(&gpu->surface_formats, count, sizeof(VkSurfaceFormatKHR));
              orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfaceFormatsKHR(gpu->handle, surface->handle, &count, (VkSurfaceFormatKHR *)gpu->surface_formats.m_data));
       }
       {
              uint32_t count = 0;
              orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfacePresentModesKHR(gpu->handle, surface->handle, &count, NULL));
              atkNewArray(&gpu->present_modes, count, sizeof(VkPresentModeKHR));
              orn_assert_vk(CONTEXT.itbl.vkGetPhysicalDeviceSurfacePresentModesKHR(gpu->handle, surface->handle, &count, (VkPresentModeKHR *)gpu->present_modes.m_data));
       }

       return suitable_device && gpu->surface_formats.m_count > 0 && gpu->present_modes.m_count > 0;
}

const VkFormat DEPTH_FORMAT = VK_FORMAT_D32_SFLOAT;
const VkFormatFeatureFlags DEPTH_FEATURES = VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT;

bool ornGpuCheckDepthTestSupport(OrnGpu *gpu)
{
       VkFormatProperties properties;
       CONTEXT.itbl.vkGetPhysicalDeviceFormatProperties(gpu->handle, DEPTH_FORMAT, &properties);
       if ((properties.optimalTilingFeatures & DEPTH_FEATURES) == DEPTH_FEATURES)
       {
              gpu->depth.format = DEPTH_FORMAT;
              gpu->depth.tiling = VK_IMAGE_TILING_OPTIMAL;
              return true;
       }
       else if ((properties.linearTilingFeatures & DEPTH_FEATURES) == DEPTH_FEATURES)
       {
              gpu->depth.format = DEPTH_FORMAT;
              gpu->depth.tiling = VK_IMAGE_TILING_OPTIMAL;
              return true;
       }
       return false;
}

bool ornGpuIsDedicated(const OrnGpu *gpu)
{
       return gpu->properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
}

bool ornGpuSupportAnisotropy(const OrnGpu *gpu)
{
       return (bool)gpu->features.samplerAnisotropy;
}

bool ornGpuSupportMipmapGeneration(const OrnGpu *gpu)
{
       return (gpu->texture.properties.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT) == VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT;
}

uint32_t ornGpuGetSampleCount(const OrnGpu *gpu)
{
       return (uint32_t)(gpu->properties.limits.framebufferColorSampleCounts & gpu->properties.limits.framebufferDepthSampleCounts);
}

float ornGpuGetMaxAnisotropy(const OrnGpu *gpu)
{
       return gpu->properties.limits.maxSamplerAnisotropy;
}