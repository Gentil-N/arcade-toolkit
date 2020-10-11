#include "orn_core.h"

OrnTexture *ornCreateTexture(OrnDevice *device, const OrnTextureSettings *settings)
{
    OrnTexture *texture = (OrnTexture *)atk_alloc(sizeof(struct OrnTexture));
    atk_assert(texture != NULL);

    texture->width = settings->width;
    texture->height = settings->height;
    texture->mip_level_count = settings->enable_mipmaps ? (uint32_t)floorf(log2f((float)ORN_MAX(settings->width, settings->height))) + 1 : 1;
    texture->image = ornCreateImage(
        device->handle, &device->tbl, device->allocator, settings->width, settings->height, device->gpu->texture.format, VK_IMAGE_TILING_OPTIMAL,
        VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, texture->mip_level_count, VK_SAMPLE_COUNT_1_BIT);
    texture->layout = VK_IMAGE_LAYOUT_UNDEFINED;
    VkImageViewCreateInfo image_info = vkfImageViewCreateInfo(
        texture->image->handle, VK_IMAGE_VIEW_TYPE_2D, device->gpu->texture.format, (VkComponentMapping){},
        vkfImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, texture->mip_level_count, 0, 1));
    orn_assert_vk(device->tbl.vkCreateImageView(device->handle, &image_info, VK_AC, &texture->image_view));
    VkSamplerCreateInfo sampler_info = vkfSamplerCreateInfo(
        VK_FILTER_LINEAR, VK_FILTER_LINEAR, VK_SAMPLER_MIPMAP_MODE_LINEAR, VK_SAMPLER_ADDRESS_MODE_REPEAT, VK_SAMPLER_ADDRESS_MODE_REPEAT, VK_SAMPLER_ADDRESS_MODE_REPEAT,
        0.0f, settings->max_anisotropy > 1.0f ? VK_TRUE : VK_FALSE, settings->max_anisotropy, VK_FALSE, VK_COMPARE_OP_ALWAYS, 0.0f, (float)texture->mip_level_count,
        VK_BORDER_COLOR_INT_OPAQUE_BLACK, VK_FALSE);
    orn_assert_vk(device->tbl.vkCreateSampler(device->handle, &sampler_info, VK_AC, &texture->sampler));

    atk_info("texture created");
    return texture;
}

void ornDestroyTexture(OrnDevice *device, OrnTexture *texture)
{
    device->tbl.vkDestroySampler(device->handle, texture->sampler, VK_AC);
    device->tbl.vkDestroyImageView(device->handle, texture->image_view, VK_AC);
    ornDestroyImage(device->handle, &device->tbl, device->allocator, texture->image);
    atk_free(texture);
    atk_info("texture destroyed");
}