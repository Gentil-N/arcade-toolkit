#ifndef __ASSET_H__
#define __ASSET_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

       typedef struct AstModel AstModel;

       typedef enum AstLoadOption
       {
              AST_LOAD_OPT_NORMALS = 0x1,
              AST_LOAD_OPT_COLORS = 0x2,
              AST_LOAD_OPT_TEXTCOORDS = 0x4
       } AstLoadOption;

       ATK_API bool astModelCreateFromFile(AstModel *model, const char *file_name, uint32_t load_options);
       ATK_API bool astModelCreateFromMemory(AstModel *model, const void *data, size_t size, uint32_t load_options);
       ATK_API void astModelCreateFromOther(AstModel *model, const AstModel *other);
       ATK_API void astModelDestroy(AstModel *model);

#ifdef __cplusplus
}
#endif //__cplusplus

struct AstModel
{
       AtkArray m_vertices;
       AtkArray m_indices;
#ifdef __cplusplus
       AstModel()//"loadFrom..." must be called
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
              astModelDestroy(this);
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
       bool loadFromFile(const char *file_name, uint32_t load_options)
       {
              atk_free(m_indices.m_data);
              atk_free(m_vertices.m_data);
              return astModelCreateFromFile(this, file_name, load_options);
       }
       bool loadFromMemory(const void *data, size_t size, uint32_t load_options)
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

#endif //__ASSET_H__