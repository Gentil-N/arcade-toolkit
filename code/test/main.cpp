#include <iostream>
#include <vector>
#include "../include/atk.h"
#include "../include/atk_orion.h"
#include "../include/atk_asset.h"
#include "../include/atk_desktop.h"
/*haha*/

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

#ifdef TRIANGLE_DEMO
#define WINDOW_TITLE "Triangle demo"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
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
                     OrnGpu *gpu;
                     {
                            uint32_t gpus_count = 0;
                            OrnGpu *const *gpus = ornGetGpus(&gpus_count);
                            std::vector<OrnGpu *> suitable_gpus;
                            for (size_t i = 0; i < gpus_count; i++)
                            {
                                   std::cout << ornGetGpuName(gpus[i]) << std::endl;
                                   if (ornGpuCheckMinimalGraphicsSupport(gpus[i], surface))
                                   {
                                          suitable_gpus.push_back(gpus[i]);
                                   }
                            }
                            if (suitable_gpus.empty())
                            {
                                   atk_error(ATK_MSG_FEATURE_NOT_PRESENT, "no gpu available");
                            }
                            gpu = suitable_gpus[0];
                            for (OrnGpu *element_gpu : suitable_gpus)
                            {
                                   if (ornGpuIsDedicated(element_gpu))
                                   {
                                          gpu = element_gpu;
                                   }
                            }
                     }
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
