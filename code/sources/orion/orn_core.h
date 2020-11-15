#ifndef __ORN_CORE_H__
#define __ORN_CORE_H__

#include "../../include/atk.h"
#include "../../include/atk_orion.h"

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       /**
        * Common Headers
        */
#include <string.h>
#include <math.h>

#ifdef ATK_PLATFORM_LINUX
#define VK_USE_PLATFORM_XLIB_KHR
#endif //ATK_PLATFORM_LINUX
#include "vulkan_loader.h"
#include "vulkan_filler.h"
#define ORN_REQUIRED_VK_VERS_MAJ 1
#define ORN_REQUIRED_VK_VERS_MIN 2
#define ORN_MEMORY_POOL_SIZE 50000000 // 50Mb

#ifndef NDEBUG
#define orn_assert_vk(expr) atk_assert(expr == VK_SUCCESS)
#else
#define orn_assert_vk(expr) expr;
#endif //!NDEBUG
#define orn_check_ret(expr, type, desc, rtrn) \
       if ((expr))                            \
       {                                      \
              atk_error(type, desc);          \
              return rtrn;                    \
       }
#define orn_check_vk_ret(expr, type, desc, rtrn) \
       if ((expr) != VK_SUCCESS)                 \
       {                                         \
              atk_error(type, desc);             \
              return rtrn;                       \
       }
#define orn_check_vk_proc_ret(expr, desc, end, rtrn) \
       if ((expr) != VK_SUCCESS)                     \
       {                                             \
              atk_error(ATK_MSG_PROC_FAILED, desc);  \
              end return rtrn;                       \
       }

       void *vulkanAllocationFunction(void *pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
       void *vulkanReallocationFunction(void *pUserData, void *pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
       void vulkanFreeFunction(void *pUserData, void *pMemory);

       /**
        * DECLARATIONS
        */

       typedef struct OrnContext OrnContext;

       void ornListGpus(AtkArray *gpus);
       void ornEraseGpus(AtkArray *gpus);
       bool ornCheckGpuExtensions(const OrnGpu *gpu, uint32_t extension_count, const char **required_extensions);

       typedef struct OrnMemoryPool OrnMemoryPool;

       typedef struct OrnMemoryAllocation OrnMemoryAllocation;

       typedef struct OrnMemoryAllocator OrnMemoryAllocator;

       typedef struct OrnMemoryAllocatorSettings OrnMemoryAllocatorSettings;

       OrnMemoryAllocator *ornCreateMemoryAllocator(const OrnMemoryAllocatorSettings *settings);
       void ornDestroyMemoryAllocator(VkDevice device, OrnMemoryAllocator *memory_allocator);

       typedef enum OrnMemoryObjectType OrnMemoryObjectType;

       typedef struct OrnMemoryAllocationSettings OrnMemoryAllocationSettings;

       OrnMemoryAllocation *ornAllocateMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, const OrnMemoryAllocationSettings *settings);
       void ornFreeMemory(OrnMemoryAllocation *memory_alloc);
       void *ornMapMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, OrnMemoryAllocation *memory_alloc);
       void ornUnmapMemory(VkDevice device, OrnMemoryAllocator *memory_allocator, OrnMemoryAllocation *memory_alloc);

       typedef struct OrnSwapchain OrnSwapchain;

       OrnSwapchain *ornCreateSwapchain(VkDevice device, const VklDeviceTable *dtbl, const OrnGpu *gpu, uint32_t width, uint32_t height, OrnSurface *surface);
       void ornDestroySwapchain(VkDevice device, const VklDeviceTable *dtbl, OrnSwapchain *swapchain);

       typedef struct OrnSyncObjects OrnSyncObjects;

       OrnSyncObjects *ornCreateSyncObjects(const VklDeviceTable *dtbl, VkDevice device, uint32_t count);
       void ornDestroySyncObjects(const VklDeviceTable *dtbl, VkDevice device, OrnSyncObjects *sync_objects);

       typedef enum OrnDeviceMsgType OrnDeviceMsgType;

       typedef struct OrnDeviceMsg OrnDeviceMsg;

       void ornPushDeviceMsg(OrnDevice *device, OrnDeviceMsgType type, void *data);
       void ornParseDeviceMsgs(OrnDevice *device, bool force_wait);

       typedef struct OrnImage OrnImage;

       OrnImage *ornCreateImage(
           VkDevice device, const VklDeviceTable *dtbl, OrnMemoryAllocator *memory_allocator, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling,
           VkImageUsageFlags usage, uint32_t mip_level_count, VkSampleCountFlagBits sample_count);
       void ornDestroyImage(VkDevice device, const VklDeviceTable *dtbl, OrnImage *image);

       VkFormat ornGetFormatEquivalent(OrnVertexInputType input_type);
       VkDeviceSize ornGetSizeofFormat(VkFormat format);

       /**
        * DEFINITIONS
        */

       struct OrnContext
       {
              VklMasterTable mtbl;
              VkInstance instance;
              VklInstanceTable itbl;
#ifdef ATK_DEBUG
              VkDebugUtilsMessengerEXT debug_msg;
#endif //ATK_DEBUG
              AtkArray gpus;
       };

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
                     VkImageTiling tiling;
                     VkImageUsageFlags usage;
                     VkFormatProperties properties;
                     VkImageFormatProperties image_properties;
              } texture;
       };

       struct OrnMemoryAllocation
       {
              VkDeviceSize offset;
              VkDeviceSize size;
              OrnMemoryPool *memory_pool;
       };

       struct OrnMemoryAllocator
       {
              const VklDeviceTable *dtbl;
              VkDeviceSize memory_pool_size;
              AtkVector pools;
              VkPhysicalDeviceMemoryProperties memory_properties;
       };

       struct OrnMemoryAllocatorSettings
       {
              VkPhysicalDevice physical_device;
              const VklInstanceTable *itbl;
              const VklDeviceTable *dtbl;
              VkDeviceSize memory_pool_size;
       };

       enum OrnMemoryObjectType
       {
              ORN_BUFFER_OBJECT_TYPE = 0x1,
              ORN_IMAGE_OBJECT_TYPE = 0x2
       };

       struct OrnMemoryAllocationSettings
       {
              OrnMemoryObjectType objectType;
              union
              {
                     VkBuffer buffer;
                     VkImage image;
              };
              VkMemoryPropertyFlags memoryProperties;
       };

       struct OrnSwapchain
       {
              VkSurfaceFormatKHR surface_format;
              VkPresentModeKHR present_mode;
              VkExtent2D extent;
              VkSwapchainKHR handle;
              AtkArray images, image_views;
       };

       struct OrnSyncObjects
       {
              AtkArray image_available_sems;
              AtkArray render_complete_sems;
              AtkArray fences;
       };

       struct OrnDevice
       {
              OrnGpu *gpu;
              VkDevice handle;
              VklDeviceTable tbl;
              VkQueue graphics_queue, present_queue;
              VkCommandPool command_pool;
              //VkmAllocator allocator;
              OrnMemoryAllocator *memory_allocator;
              OrnSwapchain *swapchain;
              AtkVector msgs;
              OrnSyncObjects *sync_objects;
              uint32_t curr_image_id;
              AtkVector commands;
              AtkArray command_buffers_per_frame;
       };

       enum OrnDeviceMsgType
       {
              NOP = 0
       };

       struct OrnDeviceMsg
       {
              OrnDeviceMsgType type;
              void *data;
       };

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

       struct OrnBuffer
       {
              VkBuffer handle;
              OrnMemoryAllocation *alloc;
       };

       struct OrnImage
       {
              VkImage handle;
              OrnMemoryAllocation *alloc;
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
              uint32_t set;
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
       ATK_GLOBAL_DEF(OrnContext CONTEXT, );
       ATK_GLOBAL_DEF(const VkAllocationCallbacks VK_ALLOC_FUNCS,
                      = {NULL ATK_COMMA vulkanAllocationFunction ATK_COMMA vulkanReallocationFunction ATK_COMMA vulkanFreeFunction ATK_COMMA NULL ATK_COMMA NULL});

#define VK_AC &VK_ALLOC_FUNCS

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__ORN_CORE_H__