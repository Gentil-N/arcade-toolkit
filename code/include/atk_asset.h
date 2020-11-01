#ifndef __ASSET_H__
#define __ASSET_H__

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       typedef struct AstModel AstModel;

       typedef enum AstModelLoadOption
       {
              AST_MDL_LOAD_OPT_NORMALS = 0x1,
              AST_MDL_LOAD_OPT_COLORS = 0x2,
              AST_MDL_LOAD_OPT_ALPHA_COLOR_CHANNEL = 0x4,
              AST_MDL_LOAD_OPT_TEXTCOORDS = 0x8
       } AstModelLoadOption;

       ATK_API bool astModelCreateFromFile(AstModel *model, const char *file_name, uint32_t load_options);
       ATK_API bool astModelCreateFromMemory(AstModel *model, const void *data, size_t size, uint32_t load_options);
       ATK_API void astModelCreateFromOther(AstModel *model, const AstModel *other);
       ATK_API void astModelDestroy(AstModel *model);

       typedef struct AstImage AstImage;

       typedef enum AstImageLoadOption
       {
              AST_IMG_LOAD_OPTS_GREY = 0x1,
              AST_IMG_LOAD_OPTS_GREY_ALPHA = 0x2,
              AST_IMG_LOAD_OPTS_RGB = 0x3,
              AST_IMG_LOAD_OPTS_RGB_ALPHA = 0x4
       } AstImageLoadOption;

       ATK_API bool astImageLoadFromFile(AstImage *image, const char *file_name, AstImageLoadOption load_option);
       ATK_API bool astImageLoadFromMemory(AstImage *image, const void *data, int size, AstImageLoadOption load_option);
       ATK_API void astImageCreateFromOther(AstImage *image, const AstImage *other);
       ATK_API void astImageFree(AstImage *image);

#ifdef __cplusplus
}
#endif //__cplusplus

struct AstModel
{
       AtkArray m_vertices;
       AtkArray m_indices;
#ifdef __cplusplus
       AstModel() //"createFrom..." must be called
       {
       }
       AstModel(const char *file_name, uint32_t load_options)
       {
              astModelCreateFromFile(this, file_name, load_options);
       }
       AstModel(const void *data, size_t size, uint32_t load_options)
       {
              astModelCreateFromMemory(this, data, size, load_options);
       }
       AstModel(const AstModel &model)
       {
              astModelCreateFromOther(this, &model);
       }
       AstModel(AstModel &&model)
       {
              m_vertices = model.m_vertices;
              m_indices = model.m_indices;
              model.m_vertices.m_data = nullptr;
              model.m_indices.m_data = nullptr;
       }
       ~AstModel()
       {
              if (m_vertices.m_data != nullptr)
              {
                     astModelDestroy(this);
              }
       }
       AstModel &operator=(const AstModel &model)
       {
              atk_free(m_indices.m_data);
              atk_free(m_vertices.m_data);
              astModelCreateFromOther(this, &model);
              return *this;
       }
       AstModel &operator=(AstModel &&model)
       {
              m_vertices = model.m_vertices;
              m_indices = model.m_indices;
              model.m_vertices.m_data = nullptr;
              model.m_indices.m_data = nullptr;
              return *this;
       }
       bool createFromFile(const char *file_name, uint32_t load_options)
       {
              atk_free(m_indices.m_data);
              atk_free(m_vertices.m_data);
              return astModelCreateFromFile(this, file_name, load_options);
       }
       bool createFromMemory(const void *data, size_t size, uint32_t load_options)
       {
              atk_free(m_indices.m_data);
              atk_free(m_vertices.m_data);
              return astModelCreateFromMemory(this, data, size, load_options);
       }
       inline const void *vertices() const noexcept
       {
              return m_vertices.m_data;
       }
       inline const uint32_t *indices() const noexcept
       {
              return (uint32_t *)m_indices.m_data;
       }
       inline size_t vertexCount() const noexcept
       {
              return m_vertices.m_count;
       }
       inline size_t indexCount() const noexcept
       {
              return m_indices.m_count;
       }
#endif //__cplusplus
};

struct AstImage
{
       void *m_data ATK_HIDE_CPP(= nullptr);
       int m_width ATK_HIDE_CPP(= 0), m_height ATK_HIDE_CPP(= 0), m_channel_count ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       AstImage() //"loadFrom..." must be called
       {
       }
       AstImage(const char *file_name, AstImageLoadOption load_option)
       {
              astImageLoadFromFile(this, file_name, load_option);
       }
       AstImage(const void *data, int size, AstImageLoadOption load_option)
       {
              astImageLoadFromMemory(this, data, size, load_option);
       }
       AstImage(const AstImage &image)
       {
              astImageCreateFromOther(this, &image);
       }
       AstImage(AstImage &&image)
       {
              m_data = image.m_data;
              m_width = image.m_width;
              m_height = image.m_height;
              m_channel_count = image.m_channel_count;
              image.m_data = nullptr;
       }
       ~AstImage()
       {
              if(m_data != nullptr)
              {
                     astImageFree(this);
              }
       }
       AstImage &operator=(const AstImage &image)
       {
              astImageFree(this);
              astImageCreateFromOther(this, &image);
              return *this;
       }
       AstImage &operator=(AstImage &&image)
       {
              m_data = image.m_data;
              m_width = image.m_width;
              m_height = image.m_height;
              m_channel_count = image.m_channel_count;
              image.m_data = nullptr;
              return *this;
       }
       bool loadFromFile(const char *file_name, AstImageLoadOption load_option)
       {
              astImageFree(this);
              return astImageLoadFromFile(this, file_name, load_option);
       }
       bool loadFromMemory(const void *data, size_t size, AstImageLoadOption load_option)
       {
              astImageFree(this);
              return astImageLoadFromMemory(this, data, size, load_option);
       }
       inline const void *data() const noexcept
       {
              return m_data;
       }
       inline int width() const noexcept
       {
              return m_width;
       }
       inline int height() const noexcept
       {
              return m_height;
       }
       inline int channelCount() const noexcept
       {
              return m_channel_count;
       }
#endif //__cplusplus
};

#endif //__ASSET_H__