#include "orn_core.h"

OrnRenderer *ornCreateRenderer(OrnDevice *device, const OrnRendererSettings *settings)
{
    OrnRenderer *renderer = (OrnRenderer *)atk_alloc(sizeof(struct OrnRenderer));
    atk_assert(renderer != NULL);

    renderer->frame_extent = device->swapchain->extent;
    VkResult result;
    VkAttachmentDescription attachment_descriptions[3];
    VkAttachmentReference depth_attachment_ref, color_resolve_attachment_ref;
    uint32_t attachment_count = 1;

    if (settings->enable_depth_test)
    {
        renderer->depth.image = ornCreateImage(
            device->handle, &device->tbl, device->memory_allocator, renderer->frame_extent.width, renderer->frame_extent.height, device->gpu->depth.format,
            device->gpu->depth.tiling, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, 1, (VkSampleCountFlagBits)settings->sample_count);
        VkImageViewCreateInfo image_view_info = vkfImageViewCreateInfo(
            renderer->depth.image->handle, VK_IMAGE_VIEW_TYPE_2D, device->gpu->depth.format, (VkComponentMapping){}, vkfImageSubresourceRange(VK_IMAGE_ASPECT_DEPTH_BIT, 0, 1, 0, 1));
        orn_assert_vk(device->tbl.vkCreateImageView(device->handle, &image_view_info, VK_AC, &renderer->depth.image_view));
        attachment_descriptions[attachment_count] = vkfAttachmentDescription(
            device->gpu->depth.format, (VkSampleCountFlagBits)settings->sample_count, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_ATTACHMENT_LOAD_OP_DONT_CARE,
            VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        depth_attachment_ref = vkfAttachmentReference(attachment_count, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        ++attachment_count;
    }
    else
    {
        renderer->depth.image = NULL;
    }

    bool msaa_enabled = (uint32_t)settings->sample_count > 0x1;
    if (msaa_enabled)
    {
        renderer->msaa.image = ornCreateImage(
            device->handle, &device->tbl, device->memory_allocator, renderer->frame_extent.width, renderer->frame_extent.height, device->swapchain->surface_format.format,
            VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, 1, (VkSampleCountFlagBits)settings->sample_count);
        VkImageViewCreateInfo image_view_info = vkfImageViewCreateInfo(
            renderer->msaa.image->handle, VK_IMAGE_VIEW_TYPE_2D, device->swapchain->surface_format.format, (VkComponentMapping){},
            vkfImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1));
        orn_assert_vk(device->tbl.vkCreateImageView(device->handle, &image_view_info, VK_AC, &renderer->msaa.image_view));
        attachment_descriptions[attachment_count] = vkfAttachmentDescription(
            device->swapchain->surface_format.format, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE,
            VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
        color_resolve_attachment_ref = vkfAttachmentReference(attachment_count, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
        ++attachment_count;
    }
    else
    {
        renderer->msaa.image = NULL;
    }

    attachment_descriptions[0] = vkfAttachmentDescription(
        device->swapchain->surface_format.format, (VkSampleCountFlagBits)settings->sample_count, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, msaa_enabled ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL : VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
    VkAttachmentReference color_attachment_ref = vkfAttachmentReference(0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
    VkSubpassDescription subpass_desc = vkfSubpassDescription(
        VK_PIPELINE_BIND_POINT_GRAPHICS, 0, NULL, 1, &color_attachment_ref,
        (msaa_enabled ? &color_resolve_attachment_ref : NULL),
        (settings->enable_depth_test ? &depth_attachment_ref : NULL), 0, NULL);
    VkSubpassDependency subpass_dependency = vkfSubpassDependency(
        VK_SUBPASS_EXTERNAL, 0, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        0, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, 0);
    VkRenderPassCreateInfo render_pass_info = vkfRenderPassCreateInfo(
        attachment_count, attachment_descriptions, 1, &subpass_desc, 1, &subpass_dependency);

    orn_assert_vk(device->tbl.vkCreateRenderPass(device->handle, &render_pass_info, VK_AC, &renderer->render_pass));

    atkNewArray(&renderer->framebuffers, device->swapchain->image_views.m_count, sizeof(VkFramebuffer));
    for (size_t i = 0; i < renderer->framebuffers.m_count; ++i)
    {
        VkImageView attachments[3] = {atk_get(VkImageView, device->swapchain->image_views, i), renderer->depth.image_view, VK_NULL_HANDLE};
        if (msaa_enabled)
        {
            attachments[0] = renderer->msaa.image_view;
            attachments[settings->enable_depth_test ? 2 : 1] = atk_get(VkImageView, device->swapchain->image_views, i);
        }
        VkFramebufferCreateInfo framebuffer_info = vkfFramebufferCreateInfo(
            renderer->render_pass, attachment_count, attachments, renderer->frame_extent.width, renderer->frame_extent.height, 1);
        orn_assert_vk(device->tbl.vkCreateFramebuffer(device->handle, &framebuffer_info, VK_AC, &atk_get(VkFramebuffer, renderer->framebuffers, i)));
    }

    atk_info("renderer created");
    return renderer;
}

void ornDestroyRenderer(OrnDevice *device, OrnRenderer *renderer)
{
    for (size_t i = 0; i < renderer->framebuffers.m_count; ++i)
    {
        device->tbl.vkDestroyFramebuffer(device->handle, atk_get(VkFramebuffer, renderer->framebuffers, i), VK_AC);
    }
    atkDeleteArray(&renderer->framebuffers);
    device->tbl.vkDestroyRenderPass(device->handle, renderer->render_pass, VK_AC);
    if (renderer->depth.image != NULL)
    {
        device->tbl.vkDestroyImageView(device->handle, renderer->depth.image_view, VK_AC);
        ornDestroyImage(device->handle, &device->tbl, renderer->depth.image);
    }
    if (renderer->msaa.image != NULL)
    {
        device->tbl.vkDestroyImageView(device->handle, renderer->msaa.image_view, VK_AC);
        ornDestroyImage(device->handle, &device->tbl, renderer->msaa.image);
    }
    atk_free(renderer);
    atk_info("renderer destroyed");
}