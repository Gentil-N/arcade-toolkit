#include "orn_core.h"

OrnMemoryOperation *ornCreateMemoryOperation(OrnDevice *device)
{
       OrnMemoryOperation *operation = (OrnMemoryOperation *)atk_alloc(sizeof(struct OrnMemoryOperation));
       atk_assert(operation != NULL);

       VkCommandBufferAllocateInfo alloc_info = vkfCommandBufferAllocateInfo(device->command_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1);
       orn_assert_vk(device->tbl.vkAllocateCommandBuffers(device->handle, &alloc_info, &operation->command_buffer));

       VkFenceCreateInfo fence_info = vkfFenceCreateInfo();
       orn_assert_vk(device->tbl.vkCreateFence(device->handle, &fence_info, VK_AC, &operation->fence));

       atk_info("memory operation created");
       return operation;
}

void ornBeginMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation)
{
       VkCommandBufferBeginInfo begin_info = vkfCommandBufferBeginInfo(NULL);
       orn_assert_vk(device->tbl.vkBeginCommandBuffer(memory_operation->command_buffer, &begin_info));
}

void ornCopyBufferToBuffer(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnBuffer *src_buffer, OrnBuffer *dst_buffer, size_t src_offset, size_t dst_offset, size_t size)
{
       VkBufferCopy copy = vkfBufferCopy(src_offset, dst_offset, size);
       device->tbl.vkCmdCopyBuffer(memory_operation->command_buffer, src_buffer->handle, dst_buffer->handle, 1, &copy);
}

void ornPrepareTexture(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnTexture *texture)
{
       VkAccessFlags src_access_mask, dst_access_mask = VK_ACCESS_TRANSFER_WRITE_BIT;
       VkPipelineStageFlags src_stage, dst_stage = VK_PIPELINE_STAGE_TRANSFER_BIT;
       switch (texture->layout)
       {
       case VK_IMAGE_LAYOUT_UNDEFINED:
       {
              src_access_mask = 0;
              src_stage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
       }
       break;
       case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
       {
              src_access_mask = VK_ACCESS_SHADER_READ_BIT;
              src_stage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
       }
       break;
       default:
       {
              atk_error(ATK_MSG_INVALID_ARGUMENT, "texture layout is not valid");
       }
       break;
       }
       VkImageMemoryBarrier barrier = vkfImageMemoryBarrier(
           src_access_mask, dst_access_mask, texture->layout, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED, texture->image->handle,
           vkfImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, texture->mip_level_count, 0, 1));

       device->tbl.vkCmdPipelineBarrier(memory_operation->command_buffer, src_stage, dst_stage, 0, 0, NULL, 0, NULL, 1, &barrier);
       texture->layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
}

void ornCopyBufferToTexture(
    OrnDevice *device, OrnMemoryOperation *memory_operation, OrnBuffer *buffer, size_t buffer_offset, OrnTexture *texture, uint32_t width, uint32_t height, uint32_t width_offset,
    uint32_t height_offset)
{
       VkBufferImageCopy region = vkfBufferImageCopy(
           buffer_offset, 0, 0, vkfImageSubresourceLayers(VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1), (VkOffset3D){(int32_t)width_offset, (int32_t)height_offset, 0},
           (VkExtent3D){width, height, 1});
       device->tbl.vkCmdCopyBufferToImage(memory_operation->command_buffer, buffer->handle, texture->image->handle, texture->layout, 1, &region);
}

void ornEndTexture(OrnDevice *device, OrnMemoryOperation *memory_operation, OrnTexture *texture)
{
       VkImageMemoryBarrier barrier = vkfImageMemoryBarrier(
           VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT, texture->layout, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_QUEUE_FAMILY_IGNORED,
           VK_QUEUE_FAMILY_IGNORED, texture->image->handle, vkfImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1));

       uint32_t mip_width = texture->width, mip_height = texture->height;

       for (uint32_t i = 1; i < texture->mip_level_count; ++i)
       {
              barrier.oldLayout = texture->layout;
              barrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
              barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
              barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
              barrier.subresourceRange.baseMipLevel = i - 1;
              device->tbl.vkCmdPipelineBarrier(memory_operation->command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 0, NULL, 1, &barrier);

              VkImageBlit blit = vkfImageBlit(vkfImageSubresourceLayers(VK_IMAGE_ASPECT_COLOR_BIT, i - 1, 0, 1), vkfImageSubresourceLayers(VK_IMAGE_ASPECT_COLOR_BIT, i, 0, 1));
              blit.srcOffsets[0] = vkfOffset3D(0, 0, 0);
              blit.srcOffsets[1] = vkfOffset3D(mip_width, mip_height, 1);
              blit.dstOffsets[0] = vkfOffset3D(0, 0, 0);
              blit.dstOffsets[1] = vkfOffset3D(mip_width > 1 ? mip_width / 2 : 1, mip_height > 1 ? mip_height / 2 : 1, 1);
              device->tbl.vkCmdBlitImage(
                  memory_operation->command_buffer, texture->image->handle, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, texture->image->handle,
                  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blit, VK_FILTER_LINEAR);

              barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
              barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
              barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
              barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
              device->tbl.vkCmdPipelineBarrier(memory_operation->command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, NULL, 0, NULL, 1, &barrier);

              mip_width = (mip_width > 1 ? mip_width / 2 : mip_width);
              mip_height = (mip_height > 1 ? mip_height / 2 : mip_height);
       }

       barrier.subresourceRange.baseMipLevel = texture->mip_level_count - 1;
       barrier.oldLayout = texture->layout;
       barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
       barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
       barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
       device->tbl.vkCmdPipelineBarrier(memory_operation->command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, NULL, 0, NULL, 1, &barrier);
       texture->layout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
}

void ornSendMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation)
{
       orn_assert_vk(device->tbl.vkEndCommandBuffer(memory_operation->command_buffer));

       VkSubmitInfo submit_info = vkfSubmitInfo(0, NULL, NULL, 1, &memory_operation->command_buffer, 0, NULL);
       device->tbl.vkQueueSubmit(device->graphics_queue, 1, &submit_info, memory_operation->fence);
}

void ornWaitMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation)
{
       orn_assert_vk(device->tbl.vkWaitForFences(device->handle, 1, &memory_operation->fence, VK_TRUE, UINT64_MAX));
       orn_assert_vk(device->tbl.vkResetFences(device->handle, 1, &memory_operation->fence));
       atk_info("memory operation waited");
}

void ornDestroyMemoryOperation(OrnDevice *device, OrnMemoryOperation *memory_operation)
{
       device->tbl.vkDestroyFence(device->handle, memory_operation->fence, VK_AC);
       device->tbl.vkFreeCommandBuffers(device->handle, device->command_pool, 1, &memory_operation->command_buffer);
       atk_free(memory_operation);
       atk_info("memory operation destroyed");
}