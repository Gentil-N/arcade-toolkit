#ifndef __ORION_H__
#define __ORION_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#define ORN_LIB_NAME "Orion"

       /**
        * PLateforms
        */
#ifdef ATK_PLATFORM_LINUX
#include <X11/Xlib.h>
#endif //LINUX

       /**
        * Versions
        */
#define ORN_VERSION_MAJOR 0
#define ORN_VERSION_MINOR 1
#define ORN_VERSION_PATCH 0

       /**
        * Code
        */
       typedef struct OrnContextSettings
       {
              uint32_t version_major, version_minor, version_patch;
              const char *application_name;
       } OrnContextSettings;

       ATK_API bool ornInitContext(const OrnContextSettings *settings); //no thread-safe but must be called once
       ATK_API void ornEndContext();                                    //the same

       typedef struct OrnSurface OrnSurface;

       typedef struct OrnSurfaceSettings
       {
#ifdef ATK_PLATFORM_LINUX
              Display *display;
              Window window;
#endif //ATK_PLATFORM_LINUX
       } OrnSurfaceSettings;

       ATK_API OrnSurface *ornCreateSurface(const OrnSurfaceSettings *settings);
       ATK_API void ornDestroySurface(OrnSurface *surface);

       typedef enum OrnSampleCount
       {
              ORN_SAMPLE_COUNT_1 = 0x00000001,
              ORN_SAMPLE_COUNT_2 = 0x00000002,
              ORN_SAMPLE_COUNT_4 = 0x00000004,
              ORN_SAMPLE_COUNT_8 = 0x00000008,
              ORN_SAMPLE_COUNT_16 = 0x00000010,
              ORN_SAMPLE_COUNT_32 = 0x00000020,
              ORN_SAMPLE_COUNT_64 = 0x00000040
       } OrnSampleCount;

       typedef struct OrnGpu OrnGpu;

       ATK_API OrnGpu *const *ornGetGpus(uint32_t *count);
       ATK_API const char *ornGetGpuName(const OrnGpu *gpu);
       ATK_API bool ornGpuCheckMinimalGraphicsSupport(OrnGpu *gpu, const OrnSurface *surface);//must be called before the device creation
       ATK_API bool ornGpuCheckDepthTestSupport(OrnGpu *gpu);//must be called if "depth testing" is used
       ATK_API bool ornGpuIsDedicated(const OrnGpu *gpu);
       ATK_API bool ornGpuSupportAnisotropy(const OrnGpu *gpu);
       ATK_API bool ornGpuSupportMipmapGeneration(const OrnGpu *gpu);
       ATK_API uint32_t ornGpuGetSampleCount(const OrnGpu *gpu);
       ATK_API float ornGpuGetMaxAnisotropy(const OrnGpu *gpu);

       typedef struct OrnDeviceSettings
       {
              OrnGpu *gpu;
              OrnSurface *surface;
              uint32_t width, height;
              bool enable_anisotropy;
       } OrnDeviceSettings;

       typedef struct OrnDevice OrnDevice;

       ATK_API OrnDevice *ornCreateDevice(const OrnDeviceSettings *settings);
       ATK_API void ornDestroyDevice(OrnDevice *device);
       ATK_API void ornUpdateDevice(OrnDevice *device, bool force_wait);
       ATK_API void ornRenderNextFrame(OrnDevice *device);

       typedef struct OrnRendererSettings
       {
              bool enable_depth_test;
              OrnSampleCount sample_count; //set "1" to disable
       } OrnRendererSettings;

       typedef struct OrnRenderer OrnRenderer;

       ATK_API OrnRenderer *ornCreateRenderer(OrnDevice *device, const OrnRendererSettings *settings);
       ATK_API void ornDestroyRenderer(OrnDevice *device, OrnRenderer *renderer);

       typedef struct OrnShaderSettings
       {
              size_t size;
              const uint32_t* code;
       } OrnShaderSettings;

       typedef struct OrnShader OrnShader;

       ATK_API OrnShader *ornCreateShader(OrnDevice *device, const OrnShaderSettings *settings);
       ATK_API void ornDestroyShader(OrnDevice *device, OrnShader *shader);

       typedef enum OrnShaderType
       {
              ORN_VERTEX_SHADER = 0x00000001,
              ORN_FRAGMENT_SHADER = 0x00000010
       } OrnShaderType;

       typedef enum OrnVertexInputType
       {
              ORN_VERTEX_INPUT_TYPE_FLOAT = 1,
              ORN_VERTEX_INPUT_TYPE_VEC_2 = 2,
              ORN_VERTEX_INPUT_TYPE_VEC_3 = 3,
              ORN_VERTEX_INPUT_TYPE_VEC_4 = 4,
              ORN_VERTEX_INPUT_TYPE_INT = 5,
              ORN_VERTEX_INPUT_TYPE_IVEC_2 = 6,
              ORN_VERTEX_INPUT_TYPE_IVEC_3 = 7,
              ORN_VERTEX_INPUT_TYPE_IVEC_4 = 8
       } OrnVertexInputType;

       typedef enum OrnCullMode
       {
              ORN_CULL_MODE_NONE = 0,
              ORN_CULL_MODE_FRONT = 1,
              ORN_CULL_MODE_BACK = 2,
              ORN_CULL_MODE_FRONT_AND_BACK = 3
       } OrnCullMode;

       typedef enum OrnPolygonMode
       {
              ORN_POLYGON_MODE_FILL = 0,
              ORN_POLYGON_MODE_LINE = 1,
              ORN_POLYGON_MODE_POINT = 2
       } OrnPolygonMode;

       typedef enum OrnVertexInputRate
       {
              ORN_VERTEX_INPUT_RATE_VERTEX = 0,
              ORN_VERTEX_INPUT_RATE_INSTANCE = 1
       } OrnVertexInputRate;

       typedef struct OrnVertexBindingInput
       {
              uint32_t binding;
              OrnVertexInputRate input_rate;
              OrnVertexInputType *inputs;
              uint32_t input_count;
       } OrnVertexBindingInput;

       typedef enum OrnUniformType
       {
              ORN_UNIFORM_TYPE_COMBINED_IMAGE_SAMPLER = 1,
              ORN_UNIFORM_TYPE_BUFFER = 6
       } OrnUniformType;

       typedef struct OrnUniformBinding //binding id attributed in order
       {
              OrnUniformType type;
              OrnShaderType shader_access;
       } OrnUniformBinding;

       typedef struct OrnUniformSet //set id attributed in order
       {
              OrnUniformBinding *bindings;
              uint32_t binding_count;
              uint32_t alloc_count;
       } OrnUniformSet;

       typedef struct OrnPipelineSettings
       {
              OrnShader *vertex_shader, *fragment_shader;
              OrnVertexBindingInput *binding_inputs;
              uint32_t binding_input_count;
              OrnCullMode cull_mode;
              OrnPolygonMode polygon_mode;
              OrnUniformSet *uniform_sets;
              uint32_t uniform_set_count;
              OrnRenderer *renderer;
              OrnSampleCount sample_count;
       } OrnPipelineSettings;

       typedef struct OrnPipeline OrnPipeline;

       ATK_API OrnPipeline *ornCreatePipeline(OrnDevice *device, const OrnPipelineSettings *settings);
       ATK_API void ornDestroyPipeline(OrnDevice *device, OrnPipeline *pipeline);

       typedef enum OrnBufferUsage
       {
              ORN_BUFFER_USAGE_TRANSFER_SRC = 0x00000001,
              ORN_BUFFER_USAGE_TRANSFER_DST = 0x00000002,
              ORN_BUFFER_USAGE_UNIFORM = 0x00000010,
              ORN_BUFFER_USAGE_INDEX = 0x00000040,
              ORN_BUFFER_USAGE_VERTEX = 0x00000080
       } OrnBufferUsage;

       typedef enum OrnBufferMemoryType
       {
              ORN_BUFFER_DEVICE_MEMORY = 0x00000001,
              ORN_BUFFER_HOST_MEMORY = 0x00000006,
       } OrnBufferMemoryType;

       typedef struct OrnBuffer OrnBuffer;

       typedef struct OrnBufferSettings
       {
              size_t size;
              uint32_t usage;
              uint32_t memory;
       } OrnBufferSettings;

       ATK_API OrnBuffer *ornCreateBuffer(OrnDevice *device, const OrnBufferSettings *buffer_settings);
       ATK_API void ornDestroyBuffer(OrnDevice *device, OrnBuffer *buffer);
       ATK_API void *ornMapBuffer(OrnDevice *device, OrnBuffer *buffer);
       ATK_API void ornUnmapBuffer(OrnDevice *device, OrnBuffer *buffer);

       typedef struct OrnTexture OrnTexture;

       typedef struct OrnTextureSettings
       {
              uint32_t width, height;
              float max_anisotropy;//set 1.0f to disable anisotropy
              bool enable_mipmaps;
       } OrnTextureSettings;

       ATK_API OrnTexture *ornCreateTexture(OrnDevice *device, const OrnTextureSettings *settings);
       ATK_API void ornDestroyTexture(OrnDevice *device, OrnTexture *texture);

       typedef struct OrnMemoryOperation OrnMemoryOperation;

       ATK_API OrnMemoryOperation *ornCreateMemoryOperation(OrnDevice *device);
       ATK_API void ornDestroyMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation);
       ATK_API void ornBeginMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation);
       ATK_API void ornCopyBufferToBuffer(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnBuffer *src_buffer, OrnBuffer *dst_buffer, size_t src_offset, 
              size_t dst_offset, size_t size);
       ATK_API void ornPrepareTexture(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnTexture *texture);
       ATK_API void ornCopyBufferToTexture(
              OrnDevice *device, OrnMemoryOperation *memory_operation, OrnBuffer *buffer, size_t buffer_offset, OrnTexture *texture, uint32_t width, uint32_t height, uint32_t width_offset, 
              uint32_t height_offset);
       ATK_API void ornEndTexture(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnTexture *texture);
       ATK_API void ornSendMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation);
       ATK_API void ornWaitMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation);

       typedef struct OrnUniform OrnUniform;

       typedef struct OrnUniformSettings
       {
              OrnPipeline *pipeline;
              uint32_t set;
       } OrnUniformSettings;

       ATK_API OrnUniform *ornCreateUniform(OrnDevice *device, const OrnUniformSettings *settings);
       ATK_API void ornDestroyUniform(OrnDevice *device, OrnPipeline *pipeline, OrnUniform *uniform);
       ATK_API void ornLinkBufferToUniform(OrnDevice *device, OrnUniform *uniform, OrnBuffer *buffer, size_t offset, size_t size, uint32_t binding);
       ATK_API void ornLinkTextureToUniform(OrnDevice *device, OrnUniform *uniform, OrnTexture *texture, uint32_t binding);

       typedef struct OrnCommand OrnCommand;

       ATK_API OrnCommand *ornCreateCommand(OrnDevice *device);
       ATK_API void ornDestroyCommand(OrnDevice *device, OrnCommand *command);
       ATK_API void ornCmdBegin(OrnCommand *command);
       ATK_API void ornCmdBeginRender(OrnCommand *command, OrnRenderer *renderer, OrnPipeline *pipeline, float clear_r, float clear_g, float clear_b);
       ATK_API void ornCmdBindUniform(OrnCommand *command, OrnPipeline *pipeline, OrnUniform *uniform, uint32_t set);
       ATK_API void ornCmdBindVertex(OrnCommand *command, OrnBuffer *buffer, uint32_t binding, size_t offset);
       ATK_API void ornCmdBindIndex(OrnCommand *command, OrnBuffer *buffer, size_t offset);
       ATK_API void ornCmdDraw(OrnCommand *command, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance);
       ATK_API void ornCmdDrawIndexed(OrnCommand *command, uint32_t index_count, uint32_t instance_count, uint32_t first_index, uint32_t first_instance);
       ATK_API void ornCmdEndRender(OrnCommand *command);
       ATK_API void ornCmdEnd(OrnCommand *command);
       ATK_API void ornBindCommand(OrnDevice *device, OrnCommand *command);
       ATK_API void ornUnbindCommand(OrnDevice *device, OrnCommand *command);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__ORION_H__