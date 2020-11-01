#include "../../include/atk_asset.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../external/stb_image.h"

bool astImageLoadFromFile(AstImage *image, const char *file_name, AstImageLoadOption load_option)
{
       int image_channels = 0;
       image->m_data = stbi_load(file_name, &image->m_width, &image->m_height, &image_channels, (int)load_option);
       image->m_channel_count = (int)load_option;
       if(image->m_data == NULL)
       {
              atk_error(ATK_MSG_PROC_FAILED, "failed to load image from file");
              return false;
       }
       return true;
}

bool astImageLoadFromMemory(AstImage *image, const void *data, int size, AstImageLoadOption load_option)
{
       int image_channels = 0;
       image->m_data = stbi_load_from_memory((const stbi_uc*)data, (int)size, &image->m_width, &image->m_height, &image_channels, (int)load_option);
       image->m_channel_count = (int)load_option;
       if(image->m_data == NULL)
       {
              atk_error(ATK_MSG_PROC_FAILED, "failed to load image from memory");
              return false;
       }
       return true;
}

void astImageCreateFromOther(AstImage *image, const AstImage *other)
{
       size_t size = other->m_width * other->m_height * other->m_channel_count;
       image->m_data = stbi__malloc(size);
       memcpy(image->m_data, other->m_data, size);
       image->m_width = other->m_width;
       image->m_height = other->m_height;
       image->m_channel_count = other->m_channel_count;
}

void astImageFree(AstImage *image)
{
       stbi_image_free(image->m_data);
       image->m_data = NULL;
       image->m_width = 0;
       image->m_height = 0;
       image->m_channel_count = 0;
}