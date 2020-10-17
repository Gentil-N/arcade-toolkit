#include "../../include/atk_math.h"

#include <math.h>

#define MTH_DEF_VEC2(type, t)                                                       \
                                                                                    \
       MthVec2##t *mthAddVec2##t(MthVec2##t *vec_a, const MthVec2##t *vec_b)        \
       {                                                                            \
              vec_a->x += vec_b->x;                                                 \
              vec_a->y += vec_b->y;                                                 \
              return vec_a;                                                         \
       }                                                                            \
                                                                                    \
       MthVec2##t *mthMulVec2##t(MthVec2##t *vec, type factor)                      \
       {                                                                            \
              vec->x *= factor;                                                     \
              vec->y *= factor;                                                     \
              return vec;                                                           \
       }                                                                            \
       MthVec2##t *mthNormVec2##t(MthVec2##t *vec)                                  \
       {                                                                            \
              type lenght = mthLenVec2##t(vec);                                     \
              vec->x /= lenght;                                                     \
              vec->y /= lenght;                                                     \
              return vec;                                                           \
       }                                                                            \
       type mthDotVec2##t(const MthVec2##t *vec_a, const MthVec2##t *vec_b)         \
       {                                                                            \
              return vec_a->x * vec_b->x + vec_a->y * vec_b->y;                     \
       }                                                                            \
       type mthLenVec2##t(MthVec2##t *vec)                                          \
       {                                                                            \
              return (type)1.0 / (type)rsqrtssf(vec->x * vec->x + vec->y * vec->y); \
       }                                                                            \
       type mthLenSqVec2##t(MthVec2##t *vec)                                        \
       {                                                                            \
              return vec->x * vec->x + vec->y * vec->y;                             \
       }                                                                            \
       MthVec2##t *mthOrthoVec2##t(MthVec2##t *vec)                                 \
       {                                                                            \
              type buf = vec->x;                                                    \
              vec->x = -vec->y;                                                     \
              vec->y = buf;                                                         \
              return vec;                                                           \
       }                                                                            \
       MthVec2##t *mthRotVe2##t(MthVec2##t *vec, type a)                            \
       {                                                                            \
              type c = (type)cosf(a);                                               \
              type s = (type)sinf(a);                                               \
              type nx = vec->x * c + vec->y * -s;                                   \
              type ny = vec->x * s + vec->y * c;                                    \
              vec->x = nx;                                                          \
              vec->y = ny;                                                          \
              return vec;                                                           \
       }

#define MTH_DEF_VEC3(type, t)                                                                         \
                                                                                                      \
       MthVec3##t *mthAddVec3##t(MthVec3##t *vec_a, const MthVec3##t *vec_b)                          \
       {                                                                                              \
              vec_a->x += vec_b->x;                                                                   \
              vec_a->y += vec_b->y;                                                                   \
              vec_a->z += vec_b->z;                                                                   \
              return vec_a;                                                                           \
       }                                                                                              \
                                                                                                      \
       MthVec3##t *mthMulVec3##t(MthVec3##t *vec, type factor)                                        \
       {                                                                                              \
              vec->x *= factor;                                                                       \
              vec->y *= factor;                                                                       \
              vec->z *= factor;                                                                       \
              return vec;                                                                             \
       }                                                                                              \
       MthVec3##t *mthNormVec3##t(MthVec3##t *vec)                                                    \
       {                                                                                              \
              type lenght = mthLenVec3##t(vec);                                                       \
              vec->x /= lenght;                                                                       \
              vec->y /= lenght;                                                                       \
              vec->z /= lenght;                                                                       \
              return vec;                                                                             \
       }                                                                                              \
       type mthDotVec3##t(const MthVec3##t *vec_a, const MthVec3##t *vec_b)                           \
       {                                                                                              \
              return vec_a->x * vec_b->x + vec_a->y * vec_b->y + vec_a->z * vec_b->z;                 \
       }                                                                                              \
       type mthLenVec3##t(MthVec3##t *vec)                                                            \
       {                                                                                              \
              return (type)1.0 / (type)rsqrtssf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z); \
       }                                                                                              \
       type mthLenSqVec3##t(MthVec3##t *vec)                                                          \
       {                                                                                              \
              return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;                             \
       }                                                                                              \
       MthVec3##t *mthCrossVec3##t(MthVec3##t *vec_a, MthVec3##t *vec_b)                              \
       {                                                                                              \
              type nx = vec_a->y * vec_b->z - vec_a->z * vec_b->y;                                    \
              type ny = vec_a->z * vec_b->x - vec_a->x * vec_b->z;                                    \
              type nz = vec_a->x * vec_b->y - vec_a->y * vec_b->x;                                    \
              vec_a->x = nx;                                                                          \
              vec_a->y = ny;                                                                          \
              vec_a->z = nz;                                                                          \
              return vec_a;                                                                           \
       }                                                                                              \
       MthVec3##t *mthRotXVec3##t(MthVec3##t *vec, type a)                                            \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type ny = vec->y * c + vec->z * -s;                                                     \
              type nz = vec->y * s + vec->z * c;                                                      \
              vec->y = ny;                                                                            \
              vec->z = nz;                                                                            \
              return vec;                                                                             \
       }                                                                                              \
       MthVec3##t *mthRotYVec3##t(MthVec3##t *vec, type a)                                            \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type nx = vec->x * c + vec->z * s;                                                      \
              type nz = vec->x * -s + vec->z * c;                                                     \
              vec->x = nx;                                                                            \
              vec->z = nz;                                                                            \
              return vec;                                                                             \
       }                                                                                              \
       MthVec3##t *mthRotZVec3##t(MthVec3##t *vec, type a)                                            \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type nx = vec->x * c + vec->y * -s;                                                     \
              type ny = vec->x * s + vec->y * c;                                                      \
              vec->x = nx;                                                                            \
              vec->y = ny;                                                                            \
              return vec;                                                                             \
       }

#define MTH_DEF_VEC4(type, t)                                                                                           \
                                                                                                                        \
       MthVec4##t *mthAddVec4##t(MthVec4##t *vec_a, const MthVec4##t *vec_b)                                            \
       {                                                                                                                \
              vec_a->x += vec_b->x;                                                                                     \
              vec_a->y += vec_b->y;                                                                                     \
              vec_a->z += vec_b->z;                                                                                     \
              vec_a->w += vec_b->w;                                                                                     \
              return vec_a;                                                                                             \
       }                                                                                                                \
                                                                                                                        \
       MthVec4##t *mthMulVec4##t(MthVec4##t *vec, type factor)                                                          \
       {                                                                                                                \
              vec->x *= factor;                                                                                         \
              vec->y *= factor;                                                                                         \
              vec->z *= factor;                                                                                         \
              vec->w *= factor;                                                                                         \
              return vec;                                                                                               \
       }                                                                                                                \
       MthVec4##t *mthNormVec4##t(MthVec4##t *vec)                                                                      \
       {                                                                                                                \
              type lenght = mthLenVec4##t(vec);                                                                         \
              vec->x /= lenght;                                                                                         \
              vec->y /= lenght;                                                                                         \
              vec->z /= lenght;                                                                                         \
              vec->w /= lenght;                                                                                         \
              return vec;                                                                                               \
       }                                                                                                                \
       type mthDotVec4##t(const MthVec4##t *vec_a, const MthVec4##t *vec_b)                                             \
       {                                                                                                                \
              return vec_a->x * vec_b->x + vec_a->y * vec_b->y + vec_a->z * vec_b->z + vec_a->w * vec_b->w;             \
       }                                                                                                                \
       type mthLenVec4##t(MthVec4##t *vec)                                                                              \
       {                                                                                                                \
              return (type)1.0 / (type)rsqrtssf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z + vec->w * vec->w); \
       }                                                                                                                \
       type mthLenSqVec4##t(MthVec4##t *vec)                                                                            \
       {                                                                                                                \
              return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z + vec->w * vec->w;                             \
       }                                                                                                                \
       MthVec4##t *mthRotXVec4##t(MthVec4##t *vec, type a)                                                              \
       {                                                                                                                \
              type c = (type)cosf(a);                                                                                   \
              type s = (type)sinf(a);                                                                                   \
              type ny = vec->y * c + vec->z * -s;                                                                       \
              type nz = vec->y * s + vec->z * c;                                                                        \
              vec->y = ny;                                                                                              \
              vec->z = nz;                                                                                              \
              return vec;                                                                                               \
       }                                                                                                                \
       MthVec4##t *mthRotYVec4##t(MthVec4##t *vec, type a)                                                              \
       {                                                                                                                \
              type c = (type)cosf(a);                                                                                   \
              type s = (type)sinf(a);                                                                                   \
              type nx = vec->x * c + vec->z * s;                                                                        \
              type nz = vec->x * -s + vec->z * c;                                                                       \
              vec->x = nx;                                                                                              \
              vec->z = nz;                                                                                              \
              return vec;                                                                                               \
       }                                                                                                                \
       MthVec4##t *mthRotZVec4##t(MthVec4##t *vec, type a)                                                              \
       {                                                                                                                \
              type c = (type)cosf(a);                                                                                   \
              type s = (type)sinf(a);                                                                                   \
              type nx = vec->x * c + vec->y * -s;                                                                       \
              type ny = vec->x * s + vec->y * c;                                                                        \
              vec->x = nx;                                                                                              \
              vec->y = ny;                                                                                              \
              return vec;                                                                                               \
       }

MTH_DEF_VEC2(float, f)
MTH_DEF_VEC2(double, d)
MTH_DEF_VEC2(int, i)

MTH_DEF_VEC3(float, f)
MTH_DEF_VEC3(double, d)
MTH_DEF_VEC3(int, i)

MTH_DEF_VEC4(float, f)
MTH_DEF_VEC4(double, d)
MTH_DEF_VEC4(int, i)