#include "orn_core.h"

OrnPipeline *ornCreatePipeline(OrnDevice *device, const OrnPipelineSettings *settings)
{
       OrnPipeline *pipeline = (OrnPipeline *)atk_alloc(sizeof(struct OrnPipeline));
       atk_assert(pipeline != NULL);

       VkResult result;
       pipeline->descriptor_set_layouts.m_data = NULL;
       if (settings->uniform_set_count > 0)
       {
              VkDescriptorPoolSize descriptor_uniform_pool_size[2];
              descriptor_uniform_pool_size[0] = vkfDescriptorPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 0);
              descriptor_uniform_pool_size[1] = vkfDescriptorPoolSize(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 0);
              VkDescriptorPoolCreateInfo descriptor_pool_info = vkfDescriptorPoolCreateInfo(0, 0, NULL);
              descriptor_pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;

              atkNewArray(&pipeline->descriptor_set_layouts, settings->uniform_set_count, sizeof(VkDescriptorSetLayout));
              for (size_t i = 0; i < settings->uniform_set_count; ++i)
              {
                     OrnUniformSet curr_uniform_set = settings->uniform_sets[i];
                     AtkArray layout_bindings;
                     atkNewArray(&layout_bindings, curr_uniform_set.binding_count, sizeof(VkDescriptorSetLayoutBinding));
                     uint32_t uniform_buffer_count = 0, uniform_image_count = 0;
                     for (size_t j = 0; j < curr_uniform_set.binding_count; ++j)
                     {
                            VkDescriptorSetLayoutBinding *curr_layout_binding = &atk_get(VkDescriptorSetLayoutBinding, layout_bindings, j);
                            curr_layout_binding->binding = j;
                            curr_layout_binding->descriptorCount = 1;
                            curr_layout_binding->descriptorType = (VkDescriptorType)curr_uniform_set.bindings[j].type;
                            curr_layout_binding->pImmutableSamplers = NULL;
                            curr_layout_binding->stageFlags = (VkShaderStageFlags)curr_uniform_set.bindings[j].shader_access;
                            switch (curr_layout_binding->descriptorType)
                            {
                            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                                   ++uniform_buffer_count;
                                   break;
                            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                                   ++uniform_image_count;
                                   break;
                            default:
                                   atk_error(ATK_MSG_INVALID_ARGUMENT, "descriptor type is invalid");
                                   break;
                            }
                     }
                     descriptor_pool_info.maxSets += curr_uniform_set.alloc_count;
                     descriptor_uniform_pool_size[0].descriptorCount += curr_uniform_set.alloc_count * uniform_buffer_count;
                     descriptor_uniform_pool_size[1].descriptorCount += curr_uniform_set.alloc_count * uniform_image_count;
                     VkDescriptorSetLayoutCreateInfo set_layout_info = vkfDescriptorSetLayoutCreateInfo(curr_uniform_set.binding_count, (VkDescriptorSetLayoutBinding *)layout_bindings.m_data);
                     orn_assert_vk(device->tbl.vkCreateDescriptorSetLayout(device->handle, &set_layout_info, VK_AC, &atk_get(VkDescriptorSetLayout, pipeline->descriptor_set_layouts, i)));
                     atkDeleteArray(&layout_bindings);
              }

              AtkVector desc_pool_sizes;
              atkNewVector(&desc_pool_sizes, 0, sizeof(VkDescriptorPoolSize));
              for (size_t i = 0; i < 2; ++i) // !!! modify for type desc count !!!
              {
                     if (descriptor_uniform_pool_size[i].descriptorCount > 0)
                     {
                            atkVectorPushBack(&desc_pool_sizes, &descriptor_uniform_pool_size[i]);
                     }
              }
              descriptor_pool_info.poolSizeCount = (uint32_t)desc_pool_sizes.m_count;
              descriptor_pool_info.pPoolSizes = (VkDescriptorPoolSize *)desc_pool_sizes.m_data;
              orn_assert_vk(device->tbl.vkCreateDescriptorPool(device->handle, &descriptor_pool_info, VK_AC, &pipeline->descriptor_pool));
              atkDeleteVector(&desc_pool_sizes);

              VkPipelineLayoutCreateInfo pipeline_layout_info = vkfPipelineLayoutCreateInfo(
                  (uint32_t)settings->uniform_set_count, (VkDescriptorSetLayout *)pipeline->descriptor_set_layouts.m_data, 0, NULL);
              orn_assert_vk(device->tbl.vkCreatePipelineLayout(device->handle, &pipeline_layout_info, VK_AC, &pipeline->layout));
       }
       else
       {
              VkPipelineLayoutCreateInfo pipeline_layout_info = vkfPipelineLayoutCreateInfo(0, NULL, 0, NULL);
              orn_assert_vk(device->tbl.vkCreatePipelineLayout(device->handle, &pipeline_layout_info, VK_AC, &pipeline->layout));
       }

       VkPipelineShaderStageCreateInfo shader_stages[2];
       shader_stages[0] = vkfPipelineShaderStageCreateInfo(VK_SHADER_STAGE_VERTEX_BIT, settings->vertex_shader->module, "main", NULL);
       shader_stages[1] = vkfPipelineShaderStageCreateInfo(VK_SHADER_STAGE_FRAGMENT_BIT, settings->fragment_shader->module, "main", NULL);

       VkPipelineVertexInputStateCreateInfo vertex_input_state = vkfPipelineVertexInputStateCreateInfo(0, NULL, 0, NULL);
       AtkArray binding_descriptions;
       AtkVector attribute_descriptions;
       if (settings->binding_input_count > 0)
       {
              atkNewArray(&binding_descriptions, settings->binding_input_count, sizeof(VkVertexInputBindingDescription));
              atkNewVector(&attribute_descriptions, 0, sizeof(VkVertexInputAttributeDescription));
              size_t total_previous_locations = 0;
              for (size_t i = 0; i < settings->binding_input_count; ++i)
              {
                     VkVertexInputBindingDescription *binding_desc = &atk_get(VkVertexInputBindingDescription, binding_descriptions, i);
                     OrnVertexBindingInput *binding_input = &((OrnVertexBindingInput *)settings->binding_inputs)[i];
                     binding_desc->binding = binding_input->binding;
                     binding_desc->inputRate = (VkVertexInputRate)binding_input->input_rate;
                     VkDeviceSize stride = 0;
                     for (size_t j = 0; j < binding_input->input_count; ++j)
                     {
                            VkVertexInputAttributeDescription attribute = vkfVertexInputAttributeDescription( total_previous_locations + j, binding_input->binding, ornGetFormatEquivalent(binding_input->inputs[j]), stride);
                            stride += ornGetSizeofFormat(attribute.format);
                            atkVectorPushBack(&attribute_descriptions, &attribute);
                     }
                     total_previous_locations += binding_input->input_count;
                     binding_desc->stride = stride;
              }
              vertex_input_state.vertexBindingDescriptionCount = settings->binding_input_count;
              vertex_input_state.pVertexBindingDescriptions = (VkVertexInputBindingDescription *)binding_descriptions.m_data;
              vertex_input_state.vertexAttributeDescriptionCount = (uint32_t)attribute_descriptions.m_count;
              vertex_input_state.pVertexAttributeDescriptions = (VkVertexInputAttributeDescription *)attribute_descriptions.m_data;
       }

       VkPipelineInputAssemblyStateCreateInfo input_assembly_state = vkfPipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, VK_FALSE);
       VkViewport viewport = vkfViewport(0, 0, settings->renderer->frame_extent.width, settings->renderer->frame_extent.height, 0.0f, 1.0f);
       VkOffset2D offset = vkfOffset2D(0, 0);
       VkRect2D scissor = vkfRect2D(offset, settings->renderer->frame_extent);
       VkPipelineViewportStateCreateInfo viewport_state = vkfPipelineViewportStateCreateInfo(1, &viewport, 1, &scissor);
       VkPipelineRasterizationStateCreateInfo rasterization_state = vkfPipelineRasterizationStateCreateInfo(
           VK_FALSE, VK_FALSE, (VkPolygonMode)settings->polygon_mode, (VkCullModeFlags)settings->cull_mode, VK_FRONT_FACE_CLOCKWISE, VK_FALSE, 0.0f, 0.0f, 0.0f, 1.0f);
       VkPipelineMultisampleStateCreateInfo multisample_state = vkfPipelineMultisampleStateCreateInfo(
           (VkSampleCountFlagBits)settings->sample_count, VK_FALSE, 0.0f, NULL, VK_FALSE, VK_FALSE);
       VkStencilOpState front = {}, back = {};
       VkPipelineDepthStencilStateCreateInfo depth_state =
           settings->renderer->depth.image == NULL
               ? vkfPipelineDepthStencilStateCreateInfo(VK_FALSE, VK_FALSE, VK_COMPARE_OP_LESS, VK_FALSE, VK_FALSE, front, back, 0.0f, 0.0f)
               : vkfPipelineDepthStencilStateCreateInfo(VK_TRUE, VK_TRUE, VK_COMPARE_OP_LESS, VK_FALSE, VK_FALSE, front, back, 0.0f, 1.0f);
       VkPipelineColorBlendAttachmentState color_blend_attachment_state = vkfPipelineColorBlendAttachmentState(
           VK_FALSE, VK_BLEND_FACTOR_ONE, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_BLEND_FACTOR_ONE, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD,
           VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT);
       VkPipelineColorBlendStateCreateInfo color_blend_state = vkfPipelineColorBlendStateCreateInfo(VK_FALSE, VK_LOGIC_OP_COPY, 1, &color_blend_attachment_state);
       color_blend_state.blendConstants[0] = 0.0f;
       color_blend_state.blendConstants[1] = 0.0f;
       color_blend_state.blendConstants[2] = 0.0f;
       color_blend_state.blendConstants[3] = 0.0f;
       VkGraphicsPipelineCreateInfo graphics_pipeline_info = vkfGraphicsPipelineCreateInfo(
           2, shader_stages, &vertex_input_state, &input_assembly_state, NULL, &viewport_state, &rasterization_state,
           &multisample_state, &depth_state, &color_blend_state, NULL, pipeline->layout, settings->renderer->render_pass, 0, VK_NULL_HANDLE, -1);
       orn_assert_vk(device->tbl.vkCreateGraphicsPipelines(device->handle, VK_NULL_HANDLE, 1, &graphics_pipeline_info, VK_AC, &pipeline->handle));

       if (settings->binding_input_count > 0)
       {
              atkDeleteVector(&attribute_descriptions);
              atkDeleteArray(&binding_descriptions);
       }

       atk_info("pipeline created");
       return pipeline;
}

void ornDestroyPipeline(OrnDevice *device, OrnPipeline *pipeline)
{
       device->tbl.vkDestroyPipeline(device->handle, pipeline->handle, VK_AC);
       device->tbl.vkDestroyPipelineLayout(device->handle, pipeline->layout, VK_AC);
       if (pipeline->descriptor_set_layouts.m_data != NULL)
       {
              device->tbl.vkDestroyDescriptorPool(device->handle, pipeline->descriptor_pool, VK_AC);
              for (size_t i = 0; i < pipeline->descriptor_set_layouts.m_count; ++i)
              {
                     device->tbl.vkDestroyDescriptorSetLayout(device->handle, atk_get(VkDescriptorSetLayout, pipeline->descriptor_set_layouts, i), VK_AC);
              }
              atkDeleteArray(&pipeline->descriptor_set_layouts);
       }
       atk_free(pipeline);
       atk_info("pipeline destroyed");
}