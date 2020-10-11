#include "orn_core.h"

#include <stdio.h>
#include <stdarg.h>

/**
 * Context
 */
bool ornCheckInstanceLayers(const char **required_layers, uint32_t layer_count)
{
       uint32_t count = 0;
       orn_assert_vk(CONTEXT.mtbl.vkEnumerateInstanceLayerProperties(&count, NULL));
       AtkArray properties;
       atkNewArray(&properties, count, sizeof(VkLayerProperties));
       orn_assert_vk(CONTEXT.mtbl.vkEnumerateInstanceLayerProperties(&count, (VkLayerProperties *)properties.m_data));

       for (uint32_t i = 0; i < layer_count; ++i)
       {
              const char *required_layer = required_layers[i];
              bool found = false;
              for (size_t j = 0; j < count; ++j)
              {
                     if (strcmp(atk_get(VkLayerProperties, properties, j).layerName, required_layer) == 0)
                     {
                            found = true;
                            break;
                     }
              }
              if (!found)
              {
                     atkDeleteArray(&properties);
                     return false;
              }
       }
       atkDeleteArray(&properties);
       return true;
}

bool ornCheckInstanceExtentions(const char **required_extensions, uint32_t extensions_count)
{
       uint32_t count = 0;
       orn_assert_vk(CONTEXT.mtbl.vkEnumerateInstanceExtensionProperties(NULL, &count, NULL));
       AtkArray properties;
       atkNewArray(&properties, count, sizeof(VkExtensionProperties));
       orn_assert_vk(CONTEXT.mtbl.vkEnumerateInstanceExtensionProperties(NULL, &count, (VkExtensionProperties *)properties.m_data));

       for (uint32_t i = 0; i < extensions_count; ++i)
       {
              const char *required_extension = required_extensions[i];
              bool found = false;
              for (size_t j = 0; j < count; ++j)
              {
                     if (strcmp(atk_get(VkExtensionProperties, properties, j).extensionName, required_extension) == 0)
                     {
                            found = true;
                            break;
                     }
              }
              if (!found)
              {
                     atkDeleteArray(&properties);
                     return false;
              }
       }
       atkDeleteArray(&properties);
       return true;
}

void *vulkanAllocationFunction(void *pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope)
{
       return atk_alloc_aligned(alignment, size);
}

void *vulkanReallocationFunction(void *pUserData, void *pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope)
{
       return atk_realloc_aligned(pOriginal, alignment, size);
}

void vulkanFreeFunction(void *pUserData, void *pMemory)
{
       atk_free(pMemory);
}

#ifdef ATK_DEBUG
VKAPI_ATTR VkBool32 VKAPI_CALL vulkanDebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData)
{
       if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
       {
              atk_error(ATK_MSG_LIB_REPORT, pCallbackData->pMessage);
       }
       return VK_FALSE;
}
#endif //ATK_DEBUG

#ifdef ATK_DEBUG
static const uint32_t LAYER_COUNT = 1;
static const char *LAYERS[1] = {"VK_LAYER_KHRONOS_validation"};
static const uint32_t INST_EXTENSION_COUNT = 3;
#ifdef ATK_PLATFORM_LINUX
static const char *INST_EXTENSIONS[3] = {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME};
#endif //ATK_PLATFORM_LINUX
#else
static uint32_t LAYER_COUNT = 0;
static const char **LAYERS = NULL;
static uint32_t INST_EXTENSION_COUNT = 2;
#ifdef ATK_PLATFORM_LINUX
static const char *INST_EXTENSIONS[2] = {VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_XLIB_SURFACE_EXTENSION_NAME};
#endif //ATK_PLATFORM_LINUX
#endif //ATK_DEBUG

bool ornInitContext(const OrnContextSettings *settings)
{
       VkResult result = vklInitVulkan(&CONTEXT.mtbl);
       orn_check_ret(result != VK_SUCCESS, ATK_MSG_INIT_FAILED, "failed to load vulkan", false);

       uint32_t api_version;
       orn_assert_vk(CONTEXT.mtbl.vkEnumerateInstanceVersion(&api_version));
       uint32_t vk_major = (api_version >> 22);
       uint32_t vk_minor = api_version >> 12 ^ (vk_major << 10);
       orn_check_ret(!(vk_major >= ORN_REQUIRED_VK_VERS_MAJ && vk_minor >= ORN_REQUIRED_VK_VERS_MIN), ATK_MSG_FEATURE_NOT_PRESENT, "vulkan version is too old", false);

       VkApplicationInfo app_info = vkfApplicationInfo(
           settings->application_name, VK_MAKE_VERSION(settings->version_major, settings->version_minor, settings->version_patch), ORN_LIB_NAME,
           VK_MAKE_VERSION(ORN_VERSION_MAJOR, ORN_VERSION_MINOR, ORN_VERSION_PATCH), api_version);
       orn_check_ret(ornCheckInstanceLayers(LAYERS, LAYER_COUNT) == false, ATK_MSG_FEATURE_NOT_PRESENT, "required layers are not present", false);
       orn_check_ret(ornCheckInstanceExtentions(INST_EXTENSIONS, INST_EXTENSION_COUNT) == false, ATK_MSG_FEATURE_NOT_PRESENT, "required extensions are not present", false)
       VkInstanceCreateInfo instance_info = vkfInstanceCreateInfo(&app_info, LAYER_COUNT, LAYERS, INST_EXTENSION_COUNT, INST_EXTENSIONS);
       orn_assert_vk(CONTEXT.mtbl.vkCreateInstance(&instance_info, VK_AC, &CONTEXT.instance));
       orn_check_ret(result != VK_SUCCESS, ATK_MSG_INIT_FAILED, "failed to init vulkan", false);

       vklLoadInstanceTable(CONTEXT.instance, &CONTEXT.mtbl, &CONTEXT.itbl);
#ifdef ATK_DEBUG
       orn_check_ret(CONTEXT.itbl.vkCreateDebugUtilsMessengerEXT == NULL, ATK_MSG_INIT_FAILED, "fonction <vkCreateDebugUtilsMessengerEXT> is not present", false);
       orn_check_ret(CONTEXT.itbl.vkCreateDebugUtilsMessengerEXT == NULL, ATK_MSG_FEATURE_NOT_PRESENT, "fonction <vkCreateDebugUtilsMessengerEXT> is not present", false);
       orn_check_ret(CONTEXT.itbl.vkDestroyDebugUtilsMessengerEXT == NULL, ATK_MSG_FEATURE_NOT_PRESENT, "fonction <vkDestroyDebugUtilsMessengerEXT> is not present", false);
       VkDebugUtilsMessengerCreateInfoEXT debug_info = vkfDebugUtilsMessengerCreateInfoEXT(
           VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
           VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT, vulkanDebugCallback, NULL);
       instance_info.pNext = &debug_info;
       orn_assert_vk(CONTEXT.itbl.vkCreateDebugUtilsMessengerEXT(CONTEXT.instance, &debug_info, VK_AC, &CONTEXT.debug_msg));
#endif //ATK_DEBUG

       ornListGpus(&CONTEXT.gpus);

       atk_info("context initialized");
       return true;
}

void ornEndContext()
{
       ornEraseGpus(&CONTEXT.gpus);
#ifdef ATK_DEBUG
       CONTEXT.itbl.vkDestroyDebugUtilsMessengerEXT(CONTEXT.instance, CONTEXT.debug_msg, VK_AC);
#endif //ATK_DEBUG
       CONTEXT.itbl.vkDestroyInstance(CONTEXT.instance, VK_AC);

       atk_info("context ended");
}

VkFormat ornGetFormatEquivalent(OrnVertexInputType input_type)
{
       switch (input_type)
       {
       case ORN_VERTEX_INPUT_TYPE_FLOAT:
              return VK_FORMAT_R32_SFLOAT;
       case ORN_VERTEX_INPUT_TYPE_INT:
              return VK_FORMAT_R32_SINT;
       case ORN_VERTEX_INPUT_TYPE_IVEC_2:
              return VK_FORMAT_R32G32_SINT;
       case ORN_VERTEX_INPUT_TYPE_IVEC_3:
              return VK_FORMAT_R32G32B32_SINT;
       case ORN_VERTEX_INPUT_TYPE_IVEC_4:
              return VK_FORMAT_R32G32B32A32_SINT;
       case ORN_VERTEX_INPUT_TYPE_VEC_2:
              return VK_FORMAT_R32G32_SFLOAT;
       case ORN_VERTEX_INPUT_TYPE_VEC_3:
              return VK_FORMAT_R32G32B32_SFLOAT;
       case ORN_VERTEX_INPUT_TYPE_VEC_4:
              return VK_FORMAT_R32G32B32A32_SFLOAT;
       default:
              atk_error(ATK_MSG_INVALID_ARGUMENT, "vertex input type is not valid");
              return VK_FORMAT_R32_SFLOAT;
       }
}

VkDeviceSize ornGetSizeofFormat(VkFormat format)
{
       switch (format)
       {
       case VK_FORMAT_R32_SFLOAT:
              return 4;
       case VK_FORMAT_R32_SINT:
              return 4;
       case VK_FORMAT_R32G32_SINT:
              return 8;
       case VK_FORMAT_R32G32B32_SINT:
              return 12;
       case VK_FORMAT_R32G32B32A32_SINT:
              return 16;
       case VK_FORMAT_R32G32_SFLOAT:
              return 8;
       case VK_FORMAT_R32G32B32_SFLOAT:
              return 12;
       case VK_FORMAT_R32G32B32A32_SFLOAT:
              return 16;
       default:
              atk_error(ATK_MSG_INVALID_ARGUMENT, "format is not valid");
              return 4;
       }
}