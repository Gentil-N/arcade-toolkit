#include "../../include/atk_asset.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/postprocess.h>

bool astModelCreate(AstModel *model, const struct aiMesh *mesh, uint32_t load_options)
{
       size_t vertex_size = 3;
       bool has_colors = false, has_normals = false, has_textcoords = false;
       if ((load_options & AST_LOAD_OPT_NORMALS) == AST_LOAD_OPT_NORMALS)
       {
              if (mesh->mNormals == NULL)
              {
                     atk_error(ATK_MSG_FEATURE_NOT_PRESENT, "normals are not available");
                     return false;
              }
              has_normals = true;
              vertex_size += 3;
       }
       if ((load_options & AST_LOAD_OPT_COLORS) == AST_LOAD_OPT_COLORS)
       {
              if (mesh->mColors[0] == NULL)
              {
                     atk_error(ATK_MSG_FEATURE_NOT_PRESENT, "color channel is not available");
                     return false;
              }
              has_colors = true;
              vertex_size += 4;
       }
       if ((load_options & AST_LOAD_OPT_TEXTCOORDS) == AST_LOAD_OPT_TEXTCOORDS)
       {
              if (mesh->mTextureCoords[0] == NULL)
              {
                     atk_error(ATK_MSG_FEATURE_NOT_PRESENT, "textcoords are not available");
                     return false;
              }
              has_textcoords = true;
              vertex_size += 2;
       }
       if (mesh->mNumFaces == 0)
       {
              return false;
       }
       atkNewArray(&model->m_vertices, vertex_size * mesh->mNumVertices, sizeof(float)); // !!!be sure that all components are floats!!!
       atkNewArray(&model->m_indices, mesh->mNumFaces * 3, sizeof(uint32_t));
       for (size_t i = 0; i < mesh->mNumVertices; ++i)
       {
              atk_get(float, model->m_vertices, i *vertex_size) = mesh->mVertices[i].x;
              atk_get(float, model->m_vertices, i *vertex_size + 1) = mesh->mVertices[i].y;
              atk_get(float, model->m_vertices, i *vertex_size + 2) = mesh->mVertices[i].z;
              size_t vertex_pos = 3;
              if (has_normals)
              {
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mNormals[i].x;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mNormals[i].y;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mNormals[i].z;
                     ++vertex_pos;
              }
              if (has_colors)
              {
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mColors[0][i].r;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mColors[0][i].g;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mColors[0][i].b;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mColors[0][i].a;
                     ++vertex_pos;
              }
              if(has_textcoords)
              {
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mTextureCoords[0][i].x;
                     ++vertex_pos;
                     atk_get(float, model->m_vertices, i * vertex_size + vertex_pos) = mesh->mTextureCoords[0][i].y;
                     ++vertex_pos;
              }
       }
       for(size_t i = 0; i < mesh->mNumFaces; ++i)
       {
              atk_get(uint32_t, model->m_indices, i * 3) = mesh->mFaces[i].mIndices[0];
              atk_get(uint32_t, model->m_indices, i * 3 + 1) = mesh->mFaces[i].mIndices[1];
              atk_get(uint32_t, model->m_indices, i * 3 + 2) = mesh->mFaces[i].mIndices[2];
       }
       return true;
}

bool astModelCreateFromFile(AstModel *model, const char *file_name, uint32_t load_options)
{
       const struct aiScene *scene = aiImportFile(file_name, aiProcess_FlipUVs | aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);
       if (scene == NULL || scene->mNumMeshes == 0)
       {
              atk_vwarn(ATK_MSG_RESOURCE_MISSING, "%s%s", "failed to load scene from ", file_name);
              return false;
       }
       return astModelCreate(model, scene->mMeshes[0], load_options);
}

bool astModelCreateFromMemory(AstModel *model, const void *data, size_t size, uint32_t load_options)
{
       const struct aiScene *scene = aiImportFileFromMemory(data, size, aiProcess_FlipUVs | aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices, "");
       if (scene == NULL || scene->mNumMeshes == 0)
       {
              atk_vwarn(ATK_MSG_RESOURCE_MISSING, "%s%s", "failed to load scene from memory");
              return false;
       }
       return astModelCreate(model, scene->mMeshes[0], load_options);
}

void astModelCreateFromOther(AstModel *model, const AstModel *other)
{
       atkNewArrayFromOther(&model->m_vertices, &other->m_vertices);
       atkNewArrayFromOther(&model->m_indices, &other->m_indices);
}

void astModelDestroy(AstModel *model)
{
       atkDeleteArray(&model->m_indices);
       atkDeleteArray(&model->m_vertices);
}