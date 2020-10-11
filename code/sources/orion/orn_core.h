#ifndef __ORN_CORE_H__
#define __ORN_CORE_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#include "../../include/atk.h"
#include "../../include/atk_orion.h"

       /**
        * Common Headers
        */
#include <string.h>
#include <math.h>

#define ORN_MAX(a, b) (a > b ? a : b)
#define ORN_MIN(a, b) (a < b ? a : b)

#ifdef ATK_PLATFORM_LINUX
#define VK_USE_PLATFORM_XLIB_KHR
#endif //ATK_PLATFORM_LINUX
#include "vulkan_loader.h"
#include "vulkan_filler.h"
#include "vulkan_memory.h"
#define ORN_REQUIRED_VK_VERS_MAJ 1
#define ORN_REQUIRED_VK_VERS_MIN 2
#define ORN_MEMORY_POOL_SIZE 50000000 // 50Mb

#ifndef NDEBUG
#define orn_assert_vk(expr) atk_assert(expr == VK_SUCCESS)
#else
#define orn_assert_vk(expr) expr;
#endif //!NDEBUG
#define orn_check_ret(expr, type, desc, rtrn) if((expr)) {atk_error(type, desc); return rtrn;}

       bool ornCheckInstanceLayers(const char **required_layers, uint32_t layer_count);
       bool ornCheckInstanceExtentions(const char **required_extensions, uint32_t extensions_count);

       void *vulkanAllocationFunction(void *pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
       void *vulkanReallocationFunction(void *pUserData, void *pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
       void vulkanFreeFunction(void *pUserData, void *pMemory);

       static const VkAllocationCallbacks VK_ALLOC_FUNCS = {NULL, vulkanAllocationFunction, vulkanReallocationFunction, vulkanFreeFunction, NULL, NULL};
#define VK_AC &VK_ALLOC_FUNCS

       typedef struct OrnContext
       {
              VklMasterTable mtbl;
              VkInstance instance;
              VklInstanceTable itbl;
#ifdef ATK_DEBUG
              VkDebugUtilsMessengerEXT debug_msg;
#endif //ATK_DEBUG
              AtkArray gpus;
       } OrnContext;

       struct OrnSurface
       {
              VkSurfaceKHR handle;
       };

       struct OrnGpu
       {
              VkPhysicalDevice handle;
              VkPhysicalDeviceProperties properties;
              VkPhysicalDeviceFeatures features;
              AtkArray queue_families;
              uint32_t graphics_queue_index, present_queue_index;
              AtkArray present_modes;
              AtkArray surface_formats;
              VkSurfaceCapabilitiesKHR surface_capabilities;
              struct
              {
                     VkFormat format;
                     VkImageTiling tiling;
              } depth;
              struct
              {
                     VkFormat format;
                     VkFormatProperties properties;
              } texture;
       };

       void ornListGpus(AtkArray *gpus);
       void ornEraseGpus(AtkArray *gpus);
       bool ornCheckGpuExtensions(const OrnGpu *gpu, uint32_t extension_count, const char **required_extensions);

       typedef struct OrnSwapchain
       {
              VkSurfaceFormatKHR surface_format;
              VkPresentModeKHR present_mode;
              VkExtent2D extent;
              VkSwapchainKHR handle;
              AtkArray images, image_views;
       } OrnSwapchain;

       OrnSwapchain *ornCreateSwapchain(VkDevice device, const VklDeviceTable *dtbl, const OrnGpu *gpu, uint32_t width, uint32_t height, OrnSurface *surface);
       void ornDestroySwapchain(VkDevice device, const VklDeviceTable *dtbl, OrnSwapchain *swapchain);

       typedef struct OrnSyncObjects
       {
              AtkArray image_available_sems;
              AtkArray render_complete_sems;
              AtkArray fences;
       } OrnSyncObjects;

       OrnSyncObjects *ornCreateSyncObjects(const VklDeviceTable *dtbl, VkDevice device, uint32_t count);
       void ornDestroySyncObjects(const VklDeviceTable *dtbl, VkDevice device, OrnSyncObjects *sync_objects);

       struct OrnDevice
       {
              OrnGpu *gpu;
              VkDevice handle;
              VklDeviceTable tbl;
              VkQueue graphics_queue, present_queue;
              VkCommandPool command_pool;
              VkmAllocator allocator;
              OrnSwapchain *swapchain;
              AtkVector msgs;
              OrnSyncObjects *sync_objects;
              uint32_t curr_image_id;
              AtkVector commands;
              AtkArray command_buffers_per_frame;
       };

       typedef enum OrnDeviceMsgType
       {
              NOP = 0
       } OrnDeviceMsgType;

       typedef struct OrnDeviceMsg
       {
              OrnDeviceMsgType type;
              void *data;
       } OrnDeviceMsg;

       void ornPushDeviceMsg(OrnDevice *device, OrnDeviceMsgType type, void *data);
       void ornParseDeviceMsgs(OrnDevice *device, bool force_wait);

       typedef struct OrnImage
       {
              VkImage handle;
              VkmAllocation allocation;
       } OrnImage;

       OrnImage *ornCreateImage(
           VkDevice device, const VklDeviceTable *dtbl, VkmAllocator allocator, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
           uint32_t mip_level_count, VkSampleCountFlagBits sample_count);
       void ornDestroyImage(VkDevice device, const VklDeviceTable *dtbl, VkmAllocator allocator, OrnImage *image);

       struct OrnRenderer
       {
              VkRenderPass render_pass;
              AtkArray framebuffers;
              VkExtent2D frame_extent;
              struct
              {
                     OrnImage *image;
                     VkImageView image_view;
              } depth, msaa;
       };

       struct OrnShader
       {
              VkShaderModule module;
       };

       struct OrnPipeline
       {
              AtkArray descriptor_set_layouts;
              VkDescriptorPool descriptor_pool;
              VkPipelineLayout layout;
              VkPipeline handle;
       };

       VkFormat ornGetFormatEquivalent(OrnVertexInputType input_type);
       VkDeviceSize ornGetSizeofFormat(VkFormat format);

       struct OrnBuffer
       {
              VkBuffer handle;
              VkmAllocation allocation;
       };

       struct OrnTexture
       {
              OrnImage *image;
              VkImageView image_view;
              VkSampler sampler;
              VkImageLayout layout;
              uint32_t width, height;
              uint32_t mip_level_count;
       };

       struct OrnMemoryOperation
       {
              VkCommandBuffer command_buffer;
              VkFence fence;
       };

       struct OrnUniform
       {
              VkDescriptorSet descriptor_set;
       };

       struct OrnCommand
       {
              VklDeviceTable *dtbl;
              AtkArray command_buffers;
       };

       /**
        * Globals
        */
#ifdef ORN_DEFINE_GLOBAL
#define ORN_GLOBAL
#else
#define ORN_GLOBAL extern
#endif //ORN_DEFINE_GLOBAL
       ORN_GLOBAL OrnContext CONTEXT;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__ORN_CORE_H__