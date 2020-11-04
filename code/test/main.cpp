#include <iostream>
#include <vector>
#include "../include/atk.h"
#include "../include/atk_orion.h"
#include "../include/atk_asset.h"
#include "../include/atk_desktop.h"
#define ATK_MTH_NO_CONFUSION
#include "../include/atk_math.h"

void myMessageCallback(AtkMsgType code, const char *description, const char *file, size_t line)
{
       if ((code & ATK_MSG_INFO) == ATK_MSG_INFO)
       {
              printf("%s%s%s", "Atk Info : ", description, "\n");
              return;
       }
       else if ((code & ATK_MSG_WARNING) == ATK_MSG_WARNING)
       {
              printf("%s%i%s%s%s%s%s%lu%s", "\e[33mAtk Warning : ", (int)(code ^ ATK_MSG_WARNING), " - ", description, " in ", file, " at ", line, "\e[0m\n");
              return;
       }
       else if ((code & ATK_MSG_ERROR) == ATK_MSG_ERROR)
       {
              printf("%s%i%s%s%s%s%s%lu%s", "\e[31mAtk Error : ", (int)(code ^ ATK_MSG_ERROR), " - ", description, " in ", file, " at ", line, "\e[0m\n");
              exit(1);
              return;
       }
}

OrnGpu *chooseGpu(const OrnSurface *surface)
{
       uint32_t gpus_count = 0;
       OrnGpu *const *gpus = ornGetGpus(&gpus_count);
       std::vector<OrnGpu *> suitable_gpus;
       for (size_t i = 0; i < gpus_count; i++)
       {
              std::cout << ornGetGpuName(gpus[i]) << std::endl;
              if (ornGpuCheckMinimalGraphicsSupport(gpus[i], surface) && ornGpuCheckDepthTestSupport(gpus[i]))
              {
                     suitable_gpus.push_back(gpus[i]);
              }
       }
       if (suitable_gpus.empty())
       {
              atk_error(ATK_MSG_FEATURE_NOT_PRESENT, "no gpu available");
       }
       OrnGpu *result = suitable_gpus[0];
       for (OrnGpu *element_gpu : suitable_gpus)
       {
              if (ornGpuIsDedicated(element_gpu))
              {
                     result = element_gpu;
              }
       }
       return result;
}

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

#ifdef TRIANGLE_DEMO
#define WINDOW_TITLE "Triangle demo"
int main()
{
       atk_init(myMessageCallback, NULL, NULL, NULL, NULL);
       {
              OrnContextSettings context_settings;
              context_settings.application_name = "test";
              context_settings.version_major = 0;
              context_settings.version_minor = 1;
              context_settings.version_patch = 0;
              bool init = ornInitContext(&context_settings);
              if (!init)
              {
                     atk_error(ATK_MSG_INIT_FAILED, "failed to init orion");
              }
              init = dskInit();
              if (!init)
              {
                     atk_error(ATK_MSG_INIT_FAILED, "failed to init desktop");
              }
              {
                     DskWindow window({WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false});

                     OrnSurfaceSettings surface_settings = {dskGetX11Display(), window.getX11Window()};
                     OrnSurface *surface = ornCreateSurface(&surface_settings);
                     OrnGpu *gpu = chooseGpu(surface);
                     std::cout << "Gpu = " << ornGetGpuName(gpu) << std::endl;
                     OrnDeviceSettings device_settings = {gpu, surface, WINDOW_WIDTH, WINDOW_HEIGHT, false};
                     OrnDevice *device = ornCreateDevice(&device_settings);
                     OrnRendererSettings renderer_settings = {false, ORN_SAMPLE_COUNT_1};
                     OrnRenderer *renderer = ornCreateRenderer(device, &renderer_settings);
                     AtkFile vertex_file("triangle_vert.spv", "r");
                     AtkFile fragment_file("triangle_frag.spv", "r");
                     void *vertex_buffer = new char[vertex_file.size()];
                     void *fragment_buffer = new char[fragment_file.size()];
                     vertex_file.read(vertex_buffer, vertex_file.size());
                     fragment_file.read(fragment_buffer, fragment_file.size());
                     OrnShaderSettings vertex_shader_settings = {vertex_file.size(), (const uint32_t *)vertex_buffer};
                     OrnShaderSettings fragment_shader_settings = {fragment_file.size(), (const uint32_t *)fragment_buffer};
                     OrnShader *vertex_shader = ornCreateShader(device, &vertex_shader_settings);
                     OrnShader *fragment_shader = ornCreateShader(device, &fragment_shader_settings);
                     OrnPipelineSettings pipeline_settings = {
                         vertex_shader, fragment_shader, nullptr, 0, ORN_CULL_MODE_NONE, ORN_POLYGON_MODE_FILL, nullptr, 0, renderer, false, ORN_SAMPLE_COUNT_1};
                     OrnPipeline *pipeline = ornCreatePipeline(device, &pipeline_settings);
                     ornDestroyShader(device, fragment_shader);
                     ornDestroyShader(device, vertex_shader);
                     OrnCommand *command = ornCreateCommand(device);
                     ornCmdBegin(command);
                     ornCmdBeginRender(command, renderer, pipeline, 0.0f, 0.0f, 0.0f, false);
                     ornCmdDraw(command, 3, 1, 0, 0);
                     ornCmdEndRender(command);
                     ornCmdEnd(command);
                     ornBindCommand(device, command);

                     window.show();
                     while (!window.shouldClose())
                     {
                            ornRenderNextFrame(device);
                            dskRefresh();
                     }

                     ornUpdateDevice(device, true);
                     ornDestroyCommand(device, command);
                     ornDestroyPipeline(device, pipeline);
                     ornDestroyRenderer(device, renderer);
                     ornDestroyDevice(device);
                     ornDestroySurface(surface);
              }
              dskEnd();

              ornEndContext();
       }
       atk_end();
       return 0;
}
#endif //TRIANGLE_DEMO

#ifdef CUBE_DEMO
#define WINDOW_TITLE "Cube demo"
#define ROTATION mth_to_radf(0.5f)

/*const std::vector<float> VERTICES = {
    -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f,
    0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f};
const size_t VERTICES_SIZE = VERTICES.size() * sizeof(float);
const std::vector<uint32_t> INDICES = {0, 1, 2, 2, 3, 0};
const size_t INDICES_SIZE = INDICES.size() * sizeof(uint32_t);*/
struct Camera
{
       mat4f projection;
       mat4f view;
} camera;
const size_t UNIFORM_SIZE = sizeof(float) * 16 * 2;

int main()
{
       atk_init(myMessageCallback, NULL, NULL, NULL, NULL);
       {
              OrnContextSettings context_settings;
              context_settings.application_name = "test";
              context_settings.version_major = 0;
              context_settings.version_minor = 1;
              context_settings.version_patch = 0;
              bool init = ornInitContext(&context_settings);
              if (!init)
              {
                     atk_error(ATK_MSG_INIT_FAILED, "failed to init orion");
              }
              init = dskInit();
              if (!init)
              {
                     atk_error(ATK_MSG_INIT_FAILED, "failed to init desktop");
              }
              {
                     DskWindow window({WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false});
                     DskMouse mouse({&window});

                     OrnSurfaceSettings surface_settings = {dskGetX11Display(), window.getX11Window()};
                     OrnSurface *surface = ornCreateSurface(&surface_settings);
                     OrnGpu *gpu = chooseGpu(surface);
                     std::cout << "Gpu = " << ornGetGpuName(gpu) << std::endl;
                     OrnDeviceSettings device_settings = {gpu, surface, WINDOW_WIDTH, WINDOW_HEIGHT, false};
                     OrnDevice *device = ornCreateDevice(&device_settings);
                     OrnRendererSettings renderer_settings = {true, ORN_SAMPLE_COUNT_1};
                     OrnRenderer *renderer = ornCreateRenderer(device, &renderer_settings);
                     AtkFile vertex_file("../../code/test/shaders/cube_vert.spv", "r");
                     AtkFile fragment_file("../../code/test/shaders/cube_frag.spv", "r");
                     void *vertex_buffer = new char[vertex_file.size()];
                     void *fragment_buffer = new char[fragment_file.size()];
                     vertex_file.read(vertex_buffer, vertex_file.size());
                     fragment_file.read(fragment_buffer, fragment_file.size());
                     OrnShaderSettings vertex_shader_settings = {vertex_file.size(), (const uint32_t *)vertex_buffer};
                     OrnShaderSettings fragment_shader_settings = {fragment_file.size(), (const uint32_t *)fragment_buffer};
                     OrnShader *vertex_shader = ornCreateShader(device, &vertex_shader_settings);
                     OrnShader *fragment_shader = ornCreateShader(device, &fragment_shader_settings);
                     OrnVertexInputType input_types[] = {ORN_VERTEX_INPUT_TYPE_VEC_3, ORN_VERTEX_INPUT_TYPE_VEC_4};
                     OrnVertexBindingInput vertex_inputs = {0, ORN_VERTEX_INPUT_RATE_VERTEX, input_types, 2};
                     OrnUniformBinding uniform_binding = {ORN_UNIFORM_TYPE_BUFFER, ORN_VERTEX_SHADER};
                     OrnUniformSet uniform_set = {&uniform_binding, 1, 1};
                     OrnPipelineSettings pipeline_settings = {
                         vertex_shader, fragment_shader, &vertex_inputs, 1, ORN_CULL_MODE_NONE, ORN_POLYGON_MODE_FILL, &uniform_set, 1, renderer, ORN_SAMPLE_COUNT_1};
                     OrnPipeline *pipeline = ornCreatePipeline(device, &pipeline_settings);
                     ornDestroyShader(device, fragment_shader);
                     ornDestroyShader(device, vertex_shader);

                     AstModel model("../../code/test/models/colored-cube.ply", AST_MDL_LOAD_OPT_COLORS | AST_MDL_LOAD_OPT_ALPHA_COLOR_CHANNEL);
                     OrnBufferSettings buffer_settings = {model.vertexCount() * sizeof(float) + model.indexCount() * sizeof(uint32_t),
                                                          ORN_BUFFER_USAGE_VERTEX | ORN_BUFFER_USAGE_INDEX, ORN_BUFFER_HOST_MEMORY};
                     OrnBuffer *buffer = ornCreateBuffer(device, &buffer_settings);
                     void *mapped = ornMapBuffer(device, buffer);
                     memcpy(mapped, model.vertices(), model.vertexCount() * sizeof(float));
                     memcpy((char *)mapped + model.vertexCount() * sizeof(float), model.indices(), model.indexCount() * sizeof(uint32_t));
                     ornUnmapBuffer(device, buffer);

                     camera.projection.perspective(WINDOW_WIDTH, WINDOW_HEIGHT, mth_to_radf(90.0f), 0.1f, 100.0f);
                     camera.view.identity().rotYFst(mth_to_radf(45.0f)).rotXSec(mth_to_radf(45.0f)).translateSecDim3(0.0f, 0.0f, 10.0f);
                     
                     buffer_settings.size = UNIFORM_SIZE;
                     buffer_settings.usage = ORN_BUFFER_USAGE_UNIFORM;
                     OrnBuffer *uniform_buffer = ornCreateBuffer(device, &buffer_settings);
                     mapped = ornMapBuffer(device, uniform_buffer);
                     memcpy(mapped, camera.projection.m, sizeof(float) * 16);
                     memcpy((char *)mapped + sizeof(float) * 16, camera.view.m, sizeof(float) * 16);
                     ornUnmapBuffer(device, uniform_buffer);
                     OrnUniformSettings uniform_settings = {pipeline, 0};
                     OrnUniform *uniform = ornCreateUniform(device, &uniform_settings);
                     ornLinkBufferToUniform(device, uniform, uniform_buffer, 0, UNIFORM_SIZE, 0);

                     OrnCommand *command = ornCreateCommand(device);
                     ornCmdBegin(command);
                     ornCmdBeginRender(command, renderer, pipeline, 0.0f, 0.0f, 0.0f);
                     ornCmdBindVertex(command, buffer, 0, 0);
                     ornCmdBindIndex(command, buffer, model.vertexCount() * sizeof(float));
                     ornCmdBindUniform(command, pipeline, uniform, 0);
                     ornCmdDrawIndexed(command, (uint32_t)model.indexCount(), 1, 0, 0);
                     ornCmdEndRender(command);
                     ornCmdEnd(command);
                     ornBindCommand(device, command);

                     window.show();
                     while (!window.shouldClose())
                     {
                            camera.view.rotYFst(ROTATION);
                            mapped = ornMapBuffer(device, uniform_buffer);
                            memcpy((char *)mapped + sizeof(float) * 16, camera.view.m, sizeof(float) * 16);
                            ornUnmapBuffer(device, uniform_buffer);
                            ornRenderNextFrame(device);
                            dskRefresh();
                            if(mouse.isButtonPressed(DSK_MOUSE_BUTTON_RIGHT))
                            {
                                   vec2d vec = mouse.getCursorPos();
                                   std::cout << vec.x << " " << vec.y << std::endl;
                            }
                     }

                     ornUpdateDevice(device, true);
                     ornDestroyCommand(device, command);
                     ornDestroyUniform(device, pipeline, uniform);
                     ornDestroyBuffer(device, uniform_buffer);
                     ornDestroyBuffer(device, buffer);
                     ornDestroyPipeline(device, pipeline);
                     ornDestroyRenderer(device, renderer);
                     ornDestroyDevice(device);
                     ornDestroySurface(surface);
              }
              dskEnd();

              ornEndContext();
       }
       atk_end();
       return 0;
}
#endif //CUBE_DEMO