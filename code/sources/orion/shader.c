#include "orn_core.h"

OrnShader *ornCreateShader(OrnDevice *device, const OrnShaderSettings *settings)
{
       OrnShader *shader = (OrnShader *)atk_alloc(sizeof(struct OrnShader));
       atk_api_assert(shader != NULL);

       VkShaderModuleCreateInfo module_info = vkfShaderModuleCreateInfo(settings->size, settings->code);
       orn_assert_vk(device->tbl.vkCreateShaderModule(device->handle, &module_info, VK_AC, &shader->module));

       atk_api_dbg_info("shader created");
       return shader;
}

void ornDestroyShader(OrnDevice *device, OrnShader *shader)
{
       device->tbl.vkDestroyShaderModule(device->handle, shader->module, VK_AC);
       atk_free(shader);
       atk_api_dbg_info("shader desroyed");
}