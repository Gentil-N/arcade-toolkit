#include "orn_core.h"

OrnUniform *ornCreateUniform(OrnDevice *device, const OrnUniformSettings *settings)
{
       OrnUniform *uniform = (OrnUniform *)atk_alloc(sizeof(struct OrnUniform));
       atk_assert(uniform != NULL);

       VkDescriptorSetAllocateInfo descriptor_alloc_info = vkfDescriptorSetAllocateInfo(
           settings->pipeline->descriptor_pool, 1, &atk_get(VkDescriptorSetLayout, settings->pipeline->descriptor_set_layouts, settings->set));
       orn_assert_vk(device->tbl.vkAllocateDescriptorSets(device->handle, &descriptor_alloc_info, &uniform->descriptor_set));

       atk_info("uniform created");
       return uniform;
}

void ornDestroyUniform(OrnDevice *device, OrnPipeline *pipeline, OrnUniform *uniform)
{
       device->tbl.vkFreeDescriptorSets(device->handle, pipeline->descriptor_pool, 1, &uniform->descriptor_set);
       atk_free(uniform);
       atk_info("descriptor sets released");
}

void ornLinkBufferToUniform(OrnDevice *device, OrnUniform *uniform, OrnBuffer *buffer, size_t offset, size_t size, uint32_t binding)
{
       VkDescriptorBufferInfo buffer_info = vkfDescriptorBufferInfo(buffer->handle, offset, size);
       VkWriteDescriptorSet write_desc_set = vkfWriteDescriptorSet(
           uniform->descriptor_set, binding, 0, 1, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, NULL, &buffer_info, NULL);
       device->tbl.vkUpdateDescriptorSets(device->handle, 1, &write_desc_set, 0, NULL);
       atk_info("buffer linked to descriptor");
}

void ornLinkTextureToUniform(OrnDevice *device, OrnUniform *uniform, OrnTexture *texture, uint32_t binding)
{
       VkDescriptorImageInfo image_info = vkfDescriptorImageInfo(texture->sampler, texture->image_view, texture->layout);
       VkWriteDescriptorSet write_desc_set = vkfWriteDescriptorSet(
           uniform->descriptor_set, binding, 0, 1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &image_info, NULL, NULL);
       device->tbl.vkUpdateDescriptorSets(device->handle, 1, &write_desc_set, 0, NULL);
       atk_info("texture linked to descriptor");
}