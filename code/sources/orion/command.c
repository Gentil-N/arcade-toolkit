#include "orn_core.h"

OrnCommand *ornCreateCommand(OrnDevice *device)
{
       OrnCommand *command = (OrnCommand *)atk_alloc(sizeof(struct OrnCommand));
       atk_assert(command != NULL);

       command->dtbl = &device->tbl;
       atkNewArray(&command->command_buffers, device->swapchain->images.m_count, sizeof(VkCommandBuffer));

       VkCommandBufferAllocateInfo alloc_info = vkfCommandBufferAllocateInfo(device->command_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, command->command_buffers.m_count);
       orn_assert_vk(command->dtbl->vkAllocateCommandBuffers(device->handle, &alloc_info, (VkCommandBuffer *)command->command_buffers.m_data));

       atk_info("command created");
       return command;
}

void ornDestroyCommand(OrnDevice *device, OrnCommand *command)
{
       device->tbl.vkFreeCommandBuffers(device->handle, device->command_pool, (uint32_t)command->command_buffers.m_count, (VkCommandBuffer *)command->command_buffers.m_data);
       atkDeleteArray(&command->command_buffers);
       atk_free(command);
       atk_info("command destroyed");
}

void ornCmdBegin(OrnCommand *command)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              VkCommandBufferBeginInfo command_buffer_begin_info = vkfCommandBufferBeginInfo(NULL);
              orn_assert_vk(command->dtbl->vkBeginCommandBuffer(atk_get(VkCommandBuffer, command->command_buffers, i), &command_buffer_begin_info));
       }
}

void ornCmdBeginRender(OrnCommand *command, OrnRenderer *renderer, OrnPipeline *pipeline, float clear_r, float clear_g, float clear_b)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              VkCommandBuffer curr_cmd_buf = atk_get(VkCommandBuffer, command->command_buffers, i);
              VkClearValue clear_values[2];
              VkClearColorValue color_value = {clear_r, clear_g, clear_b, 1.0f};
              VkClearDepthStencilValue depth_value = {1.0f, 0};
              clear_values[0].color = color_value;
              clear_values[1].depthStencil = depth_value;
              VkRect2D render_area = vkfRect2D(vkfOffset2D(0, 0), renderer->frame_extent);
              VkRenderPassBeginInfo render_pass_begin_info = vkfRenderPassBeginInfo(
                  renderer->render_pass, atk_get(VkFramebuffer, renderer->framebuffers, i), render_area, renderer->depth.image == NULL ? 1 : 2, clear_values);
              command->dtbl->vkCmdBeginRenderPass(curr_cmd_buf, &render_pass_begin_info, VK_SUBPASS_CONTENTS_INLINE);
              command->dtbl->vkCmdBindPipeline(curr_cmd_buf, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->handle);
       }
}

void ornCmdBindUniform(OrnCommand *command, OrnPipeline *pipeline, OrnUniform *uniform)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              VkCommandBuffer curr_cmd_buf = atk_get(VkCommandBuffer, command->command_buffers, i);
              command->dtbl->vkCmdBindDescriptorSets(curr_cmd_buf, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->layout, uniform->set, 1, &uniform->descriptor_set, 0, NULL);
       }
}

void ornCmdBindVertex(OrnCommand *command, OrnBuffer *buffer, uint32_t binding, size_t offset)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              command->dtbl->vkCmdBindVertexBuffers(atk_get(VkCommandBuffer, command->command_buffers, i), binding, 1, &buffer->handle, &offset);
       }
}

void ornCmdBindIndex(OrnCommand *command, OrnBuffer *buffer, size_t offset)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              command->dtbl->vkCmdBindIndexBuffer(atk_get(VkCommandBuffer, command->command_buffers, i), buffer->handle, offset, VK_INDEX_TYPE_UINT32);
       }
}

void ornCmdDraw(OrnCommand *command, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              command->dtbl->vkCmdDraw(atk_get(VkCommandBuffer, command->command_buffers, i), vertex_count, instance_count, first_vertex, first_instance);
       }
}

void ornCmdDrawIndexed(OrnCommand *command, uint32_t index_count, uint32_t instance_count, uint32_t first_index, uint32_t first_instance)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              command->dtbl->vkCmdDrawIndexed(atk_get(VkCommandBuffer, command->command_buffers, i), index_count, instance_count, first_index, 0, first_instance);
       }
}

void ornCmdEndRender(OrnCommand *command)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              command->dtbl->vkCmdEndRenderPass(atk_get(VkCommandBuffer, command->command_buffers, i));
       }
}

void ornCmdEnd(OrnCommand *command)
{
       for (size_t i = 0; i < command->command_buffers.m_count; ++i)
       {
              orn_assert_vk(command->dtbl->vkEndCommandBuffer(atk_get(VkCommandBuffer, command->command_buffers, i)));
       }
}

void ornBindCommand(OrnDevice *device, OrnCommand *command)
{
       atkVectorPushBack(&device->commands, &command);
       for (size_t i = 0; i < device->command_buffers_per_frame.m_count; ++i)
       {
              atkVectorPushBack(&atk_get(AtkVector, device->command_buffers_per_frame, i), &atk_get(VkCommandBuffer, command->command_buffers, i));
       }
}

void ornUnbindCommand(OrnDevice *device, OrnCommand *command)
{
       for (size_t i = 0; i < device->commands.m_count; ++i)
       {
              if (atk_get(OrnCommand *, device->commands, i) == command)
              {
                     atkVectorRemove(&device->commands, i);
                     for (size_t j = 0; j < device->command_buffers_per_frame.m_count; ++j)
                     {
                            atkVectorRemove(&atk_get(AtkVector, device->command_buffers_per_frame, j), i);
                     }
                     return;
              }
       }
       atk_warn(ATK_MSG_INVALID_ARGUMENT, "failed to unbind command");
}