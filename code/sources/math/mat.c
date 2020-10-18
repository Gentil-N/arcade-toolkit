#include "../../include/atk_math.h"

#include <math.h>

#define MTH_DEF_MAT2(type, t)                                                               \
                                                                                            \
       MthMat2##t *mthIdentityMat##n##t(MthMat2##t *mat)                                    \
       {                                                                                    \
              mat->m[0][0] = (type)1;                                                       \
              mat->m[1][0] = (type)0;                                                       \
              mat->m[0][1] = (type)0;                                                       \
              mat->m[1][1] = (type)1;                                                       \
                                                                                            \
              return mat;                                                                   \
       }                                                                                    \
       MthMat2##t *mthAddMat2##t(MthMat2##t *mat_a, const MthMat2##t *mat_b)                \
       {                                                                                    \
              mat_a->m[0][0] += mat_b->m[0][0];                                             \
              mat_a->m[1][0] += mat_b->m[1][0];                                             \
              mat_a->m[0][1] += mat_b->m[0][1];                                             \
              mat_a->m[1][1] += mat_b->m[1][1];                                             \
              return mat_a;                                                                 \
       }                                                                                    \
       MthMat2##t *mthMulfMat2##t(MthMat2##t *mat, type factor)                             \
       {                                                                                    \
              mat->m[0][0] *= factor;                                                       \
              mat->m[0][1] *= factor;                                                       \
              mat->m[1][0] *= factor;                                                       \
              mat->m[1][1] *= factor;                                                       \
              return mat;                                                                   \
       }                                                                                    \
       MthMat2##t *mthMulMat2##t(MthMat2##t *mat_a, const MthMat2##t *mat_b)                \
       {                                                                                    \
              type m00 = mat_a->m[0][0] * mat_b->m[0][0] + mat_a->m[1][0] * mat_b->m[0][1]; \
              type m01 = mat_a->m[0][1] * mat_b->m[0][0] + mat_a->m[1][1] * mat_b->m[0][1]; \
              type m10 = mat_a->m[0][0] * mat_b->m[1][0] + mat_a->m[1][0] * mat_b->m[1][1]; \
              type m11 = mat_a->m[0][1] * mat_b->m[1][0] + mat_a->m[1][1] * mat_b->m[1][1]; \
              mat_a->m[0][0] = m00;                                                         \
              mat_a->m[0][1] = m01;                                                         \
              mat_a->m[1][0] = m10;                                                         \
              mat_a->m[1][1] = m11;                                                         \
              return mat_a;                                                                 \
       }                                                                                    \
       MthVec2##t *mthMulMatVec2##t(const MthMat2##t *mat, MthVec2##t *vec)                 \
       {                                                                                    \
              type nx = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y;                      \
              type ny = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y;                      \
              vec->x = nx;                                                                  \
              vec->y = ny;                                                                  \
              return vec;                                                                   \
       }                                                                                    \
       MthMat2##t *mthTransposeMat2##t(MthMat2##t *mat)                                     \
       {                                                                                    \
              type buf10 = mat->m[1][0];                                                    \
              mat->m[1][0] = mat->m[0][1];                                                  \
              mat->m[0][1] = buf10;                                                         \
              return mat;                                                                   \
       }                                                                                    \
       MthMat2##t *mthScaleMat2##t(MthMat2##t *mat, const MthVec2##t *vec)                  \
       {                                                                                    \
              mat->m[0][0] *= vec->x;                                                       \
              mat->m[0][1] *= vec->x;                                                       \
              mat->m[1][0] *= vec->y;                                                       \
              mat->m[1][1] *= vec->y;                                                       \
              return mat;                                                                   \
       }                                                                                    \
       MthMat2##t *mthRotFstMat2##t(MthMat2##t *mat, type a)                                \
       {                                                                                    \
              type c = (type)cosf(a);                                                       \
              type s = (type)sinf(a);                                                       \
              type m00 = mat->m[0][0] * c + mat->m[1][0] * s;                               \
              type m01 = mat->m[0][1] * c + mat->m[1][1] * s;                               \
              type m10 = mat->m[0][0] * -s + mat->m[1][0] * c;                              \
              type m11 = mat->m[0][1] * -s + mat->m[1][1] * c;                              \
              mat->m[0][0] = m00;                                                           \
              mat->m[0][1] = m01;                                                           \
              mat->m[1][0] = m10;                                                           \
              mat->m[1][1] = m11;                                                           \
              return mat;                                                                   \
       }                                                                                    \
       MthMat2##t *mthRotSecMat2##t(MthMat2##t *mat, type a)                                \
       {                                                                                    \
              type c = (type)cosf(a);                                                       \
              type s = (type)sinf(a);                                                       \
              type m00 = mat->m[0][0] * c + mat->m[0][1] * -s;                              \
              type m01 = mat->m[0][0] * s + mat->m[0][1] * c;                               \
              type m10 = mat->m[1][0] * c + mat->m[1][1] * -s;                              \
              type m11 = mat->m[1][0] * s + mat->m[1][1] * c;                               \
              mat->m[0][0] = m00;                                                           \
              mat->m[0][1] = m01;                                                           \
              mat->m[1][0] = m10;                                                           \
              mat->m[1][1] = m11;                                                           \
              return mat;                                                                   \
       }

#define MTH_DEF_MAT3(type, t)                                                                                                 \
                                                                                                                              \
       MthMat3##t *mthIdentityMat3##t(MthMat3##t *mat)                                                                        \
       {                                                                                                                      \
              mat->m[0][0] = (type)1;                                                                                         \
              mat->m[1][0] = (type)0;                                                                                         \
              mat->m[2][0] = (type)0;                                                                                         \
              mat->m[0][1] = (type)0;                                                                                         \
              mat->m[1][1] = (type)1;                                                                                         \
              mat->m[2][1] = (type)0;                                                                                         \
              mat->m[2][0] = (type)0;                                                                                         \
              mat->m[2][1] = (type)0;                                                                                         \
              mat->m[2][2] = (type)1;                                                                                         \
                                                                                                                              \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthAddMat3##t(MthMat3##t *mat_a, const MthMat3##t *mat_b)                                                  \
       {                                                                                                                      \
              mat_a->m[0][0] += mat_b->m[0][0];                                                                               \
              mat_a->m[0][1] += mat_b->m[0][1];                                                                               \
              mat_a->m[0][2] += mat_b->m[0][2];                                                                               \
              mat_a->m[1][0] += mat_b->m[1][0];                                                                               \
              mat_a->m[1][1] += mat_b->m[1][1];                                                                               \
              mat_a->m[1][2] += mat_b->m[1][2];                                                                               \
              mat_a->m[2][0] += mat_b->m[2][0];                                                                               \
              mat_a->m[2][1] += mat_b->m[2][1];                                                                               \
              mat_a->m[2][2] += mat_b->m[2][2];                                                                               \
              return mat_a;                                                                                                   \
       }                                                                                                                      \
       MthMat3##t *mthMulfMat3##t(MthMat3##t *mat, type factor)                                                               \
       {                                                                                                                      \
              mat->m[0][0] *= factor;                                                                                         \
              mat->m[0][1] *= factor;                                                                                         \
              mat->m[0][2] *= factor;                                                                                         \
              mat->m[1][0] *= factor;                                                                                         \
              mat->m[1][1] *= factor;                                                                                         \
              mat->m[1][2] *= factor;                                                                                         \
              mat->m[2][0] *= factor;                                                                                         \
              mat->m[2][1] *= factor;                                                                                         \
              mat->m[2][2] *= factor;                                                                                         \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthMulMat3##t(MthMat3##t *mat_a, const MthMat3##t *mat_b)                                                  \
       {                                                                                                                      \
              type m00 = mat_a->m[0][0] * mat_b->m[0][0] + mat_a->m[1][0] * mat_b->m[0][1] + mat_a->m[2][0] * mat_b->m[0][2]; \
              type m01 = mat_a->m[0][1] * mat_b->m[0][0] + mat_a->m[1][1] * mat_b->m[0][1] + mat_a->m[2][1] * mat_b->m[0][2]; \
              type m02 = mat_a->m[0][2] * mat_b->m[0][0] + mat_a->m[1][2] * mat_b->m[0][1] + mat_a->m[2][2] * mat_b->m[0][2]; \
              type m10 = mat_a->m[0][0] * mat_b->m[1][0] + mat_a->m[1][0] * mat_b->m[1][1] + mat_a->m[2][0] * mat_b->m[1][2]; \
              type m11 = mat_a->m[0][1] * mat_b->m[1][0] + mat_a->m[1][1] * mat_b->m[1][1] + mat_a->m[2][1] * mat_b->m[1][2]; \
              type m12 = mat_a->m[0][2] * mat_b->m[1][0] + mat_a->m[1][2] * mat_b->m[1][1] + mat_a->m[2][2] * mat_b->m[1][2]; \
              type m20 = mat_a->m[0][0] * mat_b->m[2][0] + mat_a->m[1][0] * mat_b->m[2][1] + mat_a->m[2][0] * mat_b->m[2][2]; \
              type m21 = mat_a->m[0][1] * mat_b->m[2][0] + mat_a->m[1][1] * mat_b->m[2][1] + mat_a->m[2][1] * mat_b->m[2][2]; \
              type m22 = mat_a->m[0][2] * mat_b->m[2][0] + mat_a->m[1][2] * mat_b->m[2][1] + mat_a->m[2][2] * mat_b->m[2][2]; \
              mat_a->m[0][0] = m00;                                                                                           \
              mat_a->m[0][1] = m01;                                                                                           \
              mat_a->m[0][2] = m02;                                                                                           \
              mat_a->m[1][0] = m10;                                                                                           \
              mat_a->m[1][1] = m11;                                                                                           \
              mat_a->m[1][2] = m12;                                                                                           \
              mat_a->m[2][0] = m20;                                                                                           \
              mat_a->m[2][1] = m21;                                                                                           \
              mat_a->m[2][2] = m22;                                                                                           \
              return mat_a;                                                                                                   \
       }                                                                                                                      \
       MthVec3##t *mthMulMatVec3##t(const MthMat3##t *mat, MthVec3##t *vec)                                                   \
       {                                                                                                                      \
              type nx = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y + mat->m[2][0] * vec->z;                                \
              type ny = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y + mat->m[2][1] * vec->z;                                \
              type nz = mat->m[0][2] * vec->x + mat->m[1][2] * vec->y + mat->m[2][2] * vec->z;                                \
              vec->x = nx;                                                                                                    \
              vec->y = ny;                                                                                                    \
              vec->z = nz;                                                                                                    \
              return vec;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthTransposeMat3##t(MthMat3##t *mat)                                                                       \
       {                                                                                                                      \
              type buf10 = mat->m[1][0];                                                                                      \
              type buf20 = mat->m[2][0];                                                                                      \
              type buf21 = mat->m[2][1];                                                                                      \
              mat->m[1][0] = mat->m[0][1];                                                                                    \
              mat->m[2][0] = mat->m[0][2];                                                                                    \
              mat->m[2][1] = mat->m[1][2];                                                                                    \
              mat->m[0][1] = buf10;                                                                                           \
              mat->m[0][2] = buf20;                                                                                           \
              mat->m[1][2] = buf21;                                                                                           \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthScaleMat3##t(MthMat3##t *mat, const MthVec3##t *vec)                                                    \
       {                                                                                                                      \
              mat->m[0][0] *= vec->x;                                                                                         \
              mat->m[0][1] *= vec->x;                                                                                         \
              mat->m[0][2] *= vec->x;                                                                                         \
              mat->m[1][0] *= vec->y;                                                                                         \
              mat->m[1][1] *= vec->y;                                                                                         \
              mat->m[1][2] *= vec->y;                                                                                         \
              mat->m[2][0] *= vec->z;                                                                                         \
              mat->m[2][1] *= vec->z;                                                                                         \
              mat->m[2][2] *= vec->z;                                                                                         \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotXFstMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m10 = mat->m[1][0] * c + mat->m[2][0] * s;                                                                 \
              type m11 = mat->m[1][1] * c + mat->m[2][1] * s;                                                                 \
              type m12 = mat->m[1][2] * c + mat->m[2][2] * s;                                                                 \
              type m20 = mat->m[1][0] * -s + mat->m[2][0] * c;                                                                \
              type m21 = mat->m[1][1] * -s + mat->m[2][1] * c;                                                                \
              type m22 = mat->m[1][2] * -s + mat->m[2][2] * c;                                                                \
              mat->m[1][0] = m10;                                                                                             \
              mat->m[1][1] = m11;                                                                                             \
              mat->m[1][2] = m12;                                                                                             \
              mat->m[2][0] = m20;                                                                                             \
              mat->m[2][1] = m21;                                                                                             \
              mat->m[2][2] = m22;                                                                                             \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotXSecMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m01 = mat->m[0][1] * c + mat->m[0][2] * -s;                                                                \
              type m02 = mat->m[0][1] * s + mat->m[0][2] * c;                                                                 \
              type m11 = mat->m[1][1] * c + mat->m[1][2] * -s;                                                                \
              type m12 = mat->m[1][1] * s + mat->m[1][2] * c;                                                                 \
              type m21 = mat->m[2][1] * c + mat->m[2][2] * -s;                                                                \
              type m22 = mat->m[2][1] * s + mat->m[2][2] * c;                                                                 \
              mat->m[0][1] = m01;                                                                                             \
              mat->m[0][2] = m02;                                                                                             \
              mat->m[1][1] = m11;                                                                                             \
              mat->m[1][2] = m12;                                                                                             \
              mat->m[2][1] = m21;                                                                                             \
              mat->m[2][2] = m22;                                                                                             \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotYFstMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m00 = mat->m[0][0] * c + mat->m[2][0] * -s;                                                                \
              type m01 = mat->m[0][1] * c + mat->m[2][1] * -s;                                                                \
              type m02 = mat->m[0][2] * c + mat->m[2][2] * -s;                                                                \
              type m20 = mat->m[0][0] * s + mat->m[2][0] * c;                                                                 \
              type m21 = mat->m[0][1] * s + mat->m[2][1] * c;                                                                 \
              type m22 = mat->m[0][2] * s + mat->m[2][2] * c;                                                                 \
              mat->m[0][0] = m00;                                                                                             \
              mat->m[0][1] = m01;                                                                                             \
              mat->m[0][2] = m02;                                                                                             \
              mat->m[2][0] = m20;                                                                                             \
              mat->m[2][1] = m21;                                                                                             \
              mat->m[2][2] = m22;                                                                                             \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotYSecMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m00 = mat->m[0][0] * c + mat->m[0][2] * s;                                                                 \
              type m02 = mat->m[0][0] * -s + mat->m[0][2] * c;                                                                \
              type m10 = mat->m[1][0] * c + mat->m[1][2] * s;                                                                 \
              type m12 = mat->m[1][0] * -s + mat->m[1][2] * c;                                                                \
              type m20 = mat->m[2][0] * c + mat->m[2][2] * s;                                                                 \
              type m22 = mat->m[2][0] * -s + mat->m[2][2] * c;                                                                \
              mat->m[0][0] = m00;                                                                                             \
              mat->m[0][2] = m02;                                                                                             \
              mat->m[1][0] = m10;                                                                                             \
              mat->m[1][2] = m12;                                                                                             \
              mat->m[2][0] = m20;                                                                                             \
              mat->m[2][2] = m22;                                                                                             \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotZFstMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m00 = mat->m[0][0] * c + mat->m[1][0] * s;                                                                 \
              type m01 = mat->m[0][1] * c + mat->m[1][1] * s;                                                                 \
              type m02 = mat->m[0][2] * c + mat->m[1][2] * s;                                                                 \
              type m10 = mat->m[0][0] * -s + mat->m[1][0] * c;                                                                \
              type m11 = mat->m[0][1] * -s + mat->m[1][1] * c;                                                                \
              type m12 = mat->m[0][2] * -s + mat->m[1][2] * c;                                                                \
              mat->m[0][0] = m00;                                                                                             \
              mat->m[0][1] = m01;                                                                                             \
              mat->m[0][2] = m02;                                                                                             \
              mat->m[1][0] = m10;                                                                                             \
              mat->m[1][1] = m11;                                                                                             \
              mat->m[1][2] = m12;                                                                                             \
              return mat;                                                                                                     \
       }                                                                                                                      \
       MthMat3##t *mthRotZSecMat3##t(MthMat3##t *mat, type a)                                                                 \
       {                                                                                                                      \
              type c = (type)cosf(a);                                                                                         \
              type s = (type)sinf(a);                                                                                         \
              type m00 = mat->m[0][0] * c + mat->m[0][1] * -s;                                                                \
              type m01 = mat->m[0][0] * s + mat->m[0][1] * c;                                                                 \
              type m10 = mat->m[1][0] * c + mat->m[1][1] * -s;                                                                \
              type m11 = mat->m[1][0] * s + mat->m[1][1] * c;                                                                 \
              type m20 = mat->m[2][0] * c + mat->m[2][1] * -s;                                                                \
              type m21 = mat->m[2][0] * s + mat->m[2][1] * c;                                                                 \
              mat->m[0][0] = m00;                                                                                             \
              mat->m[0][1] = m01;                                                                                             \
              mat->m[1][0] = m10;                                                                                             \
              mat->m[1][1] = m11;                                                                                             \
              mat->m[2][0] = m20;                                                                                             \
              mat->m[2][1] = m21;                                                                                             \
              return mat;                                                                                                     \
       }

#define MTH_DEF_MAT4(type, t)                                                                                                                                   \
                                                                                                                                                                \
       MthMat4##t *mthIdentityMat4##t(MthMat4##t *mat)                                                                                                          \
       {                                                                                                                                                        \
              mat->m[0][0] = (type)1;                                                                                                                           \
              mat->m[1][0] = (type)0;                                                                                                                           \
              mat->m[2][0] = (type)0;                                                                                                                           \
              mat->m[3][0] = (type)0;                                                                                                                           \
              mat->m[0][1] = (type)0;                                                                                                                           \
              mat->m[1][1] = (type)1;                                                                                                                           \
              mat->m[2][1] = (type)0;                                                                                                                           \
              mat->m[3][1] = (type)0;                                                                                                                           \
              mat->m[2][0] = (type)0;                                                                                                                           \
              mat->m[2][1] = (type)0;                                                                                                                           \
              mat->m[2][2] = (type)1;                                                                                                                           \
              mat->m[3][2] = (type)0;                                                                                                                           \
              mat->m[2][1] = (type)0;                                                                                                                           \
              mat->m[3][0] = (type)0;                                                                                                                           \
              mat->m[3][1] = (type)0;                                                                                                                           \
              mat->m[3][2] = (type)0;                                                                                                                           \
              mat->m[3][3] = (type)1;                                                                                                                           \
                                                                                                                                                                \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthAddMat4##t(MthMat4##t *mat_a, const MthMat4##t *mat_b)                                                                                    \
       {                                                                                                                                                        \
              mat_a->m[0][0] += mat_b->m[0][0];                                                                                                                 \
              mat_a->m[0][1] += mat_b->m[0][1];                                                                                                                 \
              mat_a->m[0][2] += mat_b->m[0][2];                                                                                                                 \
              mat_a->m[0][3] += mat_b->m[0][3];                                                                                                                 \
              mat_a->m[1][0] += mat_b->m[1][0];                                                                                                                 \
              mat_a->m[1][1] += mat_b->m[1][1];                                                                                                                 \
              mat_a->m[1][2] += mat_b->m[1][2];                                                                                                                 \
              mat_a->m[1][3] += mat_b->m[1][3];                                                                                                                 \
              mat_a->m[2][0] += mat_b->m[2][0];                                                                                                                 \
              mat_a->m[2][1] += mat_b->m[2][1];                                                                                                                 \
              mat_a->m[2][2] += mat_b->m[2][2];                                                                                                                 \
              mat_a->m[2][3] += mat_b->m[2][3];                                                                                                                 \
              mat_a->m[3][0] += mat_b->m[3][0];                                                                                                                 \
              mat_a->m[3][1] += mat_b->m[3][1];                                                                                                                 \
              mat_a->m[3][2] += mat_b->m[3][2];                                                                                                                 \
              mat_a->m[3][3] += mat_b->m[3][3];                                                                                                                 \
              return mat_a;                                                                                                                                     \
       }                                                                                                                                                        \
       MthMat4##t *mthMulfMat4##t(MthMat4##t *mat, type factor)                                                                                                 \
       {                                                                                                                                                        \
              mat->m[0][0] *= factor;                                                                                                                           \
              mat->m[0][1] *= factor;                                                                                                                           \
              mat->m[0][2] *= factor;                                                                                                                           \
              mat->m[0][3] *= factor;                                                                                                                           \
              mat->m[1][0] *= factor;                                                                                                                           \
              mat->m[1][1] *= factor;                                                                                                                           \
              mat->m[1][2] *= factor;                                                                                                                           \
              mat->m[1][3] *= factor;                                                                                                                           \
              mat->m[2][0] *= factor;                                                                                                                           \
              mat->m[2][1] *= factor;                                                                                                                           \
              mat->m[2][2] *= factor;                                                                                                                           \
              mat->m[2][3] *= factor;                                                                                                                           \
              mat->m[3][0] *= factor;                                                                                                                           \
              mat->m[3][1] *= factor;                                                                                                                           \
              mat->m[3][2] *= factor;                                                                                                                           \
              mat->m[3][3] *= factor;                                                                                                                           \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthMulMat4##t(MthMat4##t *mat_a, const MthMat4##t *mat_b)                                                                                    \
       {                                                                                                                                                        \
              type m00 = mat_a->m[0][0] * mat_b->m[0][0] + mat_a->m[1][0] * mat_b->m[0][1] + mat_a->m[2][0] * mat_b->m[0][2] + mat_a->m[3][0] * mat_b->m[0][3]; \
              type m01 = mat_a->m[0][1] * mat_b->m[0][0] + mat_a->m[1][1] * mat_b->m[0][1] + mat_a->m[2][1] * mat_b->m[0][2] + mat_a->m[3][1] * mat_b->m[0][3]; \
              type m02 = mat_a->m[0][2] * mat_b->m[0][0] + mat_a->m[1][2] * mat_b->m[0][1] + mat_a->m[2][2] * mat_b->m[0][2] + mat_a->m[3][2] * mat_b->m[0][3]; \
              type m03 = mat_a->m[0][3] * mat_b->m[0][0] + mat_a->m[1][3] * mat_b->m[0][1] + mat_a->m[2][3] * mat_b->m[0][2] + mat_a->m[3][3] * mat_b->m[0][3]; \
              type m10 = mat_a->m[0][0] * mat_b->m[1][0] + mat_a->m[1][0] * mat_b->m[1][1] + mat_a->m[2][0] * mat_b->m[1][2] + mat_a->m[3][0] * mat_b->m[1][3]; \
              type m11 = mat_a->m[0][1] * mat_b->m[1][0] + mat_a->m[1][1] * mat_b->m[1][1] + mat_a->m[2][1] * mat_b->m[1][2] + mat_a->m[3][1] * mat_b->m[1][3]; \
              type m12 = mat_a->m[0][2] * mat_b->m[1][0] + mat_a->m[1][2] * mat_b->m[1][1] + mat_a->m[2][2] * mat_b->m[1][2] + mat_a->m[3][2] * mat_b->m[1][3]; \
              type m13 = mat_a->m[0][3] * mat_b->m[1][0] + mat_a->m[1][3] * mat_b->m[1][1] + mat_a->m[2][3] * mat_b->m[1][2] + mat_a->m[3][3] * mat_b->m[1][3]; \
              type m20 = mat_a->m[0][0] * mat_b->m[2][0] + mat_a->m[1][0] * mat_b->m[2][1] + mat_a->m[2][0] * mat_b->m[2][2] + mat_a->m[3][0] * mat_b->m[2][3]; \
              type m21 = mat_a->m[0][1] * mat_b->m[2][0] + mat_a->m[1][1] * mat_b->m[2][1] + mat_a->m[2][1] * mat_b->m[2][2] + mat_a->m[3][1] * mat_b->m[2][3]; \
              type m22 = mat_a->m[0][2] * mat_b->m[2][0] + mat_a->m[1][2] * mat_b->m[2][1] + mat_a->m[2][2] * mat_b->m[2][2] + mat_a->m[3][2] * mat_b->m[2][3]; \
              type m23 = mat_a->m[0][3] * mat_b->m[2][0] + mat_a->m[1][3] * mat_b->m[2][1] + mat_a->m[2][3] * mat_b->m[2][2] + mat_a->m[3][3] * mat_b->m[2][3]; \
              type m30 = mat_a->m[0][0] * mat_b->m[3][0] + mat_a->m[1][0] * mat_b->m[3][1] + mat_a->m[2][0] * mat_b->m[3][2] + mat_a->m[3][0] * mat_b->m[3][3]; \
              type m31 = mat_a->m[0][1] * mat_b->m[3][0] + mat_a->m[1][1] * mat_b->m[3][1] + mat_a->m[2][1] * mat_b->m[3][2] + mat_a->m[3][1] * mat_b->m[3][3]; \
              type m32 = mat_a->m[0][2] * mat_b->m[3][0] + mat_a->m[1][2] * mat_b->m[3][1] + mat_a->m[2][2] * mat_b->m[3][2] + mat_a->m[3][2] * mat_b->m[3][3]; \
              type m33 = mat_a->m[0][3] * mat_b->m[3][0] + mat_a->m[1][3] * mat_b->m[3][1] + mat_a->m[2][3] * mat_b->m[3][2] + mat_a->m[3][3] * mat_b->m[3][3]; \
              mat_a->m[0][0] = m00;                                                                                                                             \
              mat_a->m[0][0] = m01;                                                                                                                             \
              mat_a->m[0][0] = m02;                                                                                                                             \
              mat_a->m[0][0] = m03;                                                                                                                             \
              mat_a->m[1][0] = m10;                                                                                                                             \
              mat_a->m[1][1] = m11;                                                                                                                             \
              mat_a->m[1][2] = m12;                                                                                                                             \
              mat_a->m[1][3] = m13;                                                                                                                             \
              mat_a->m[2][0] = m20;                                                                                                                             \
              mat_a->m[2][1] = m21;                                                                                                                             \
              mat_a->m[2][2] = m22;                                                                                                                             \
              mat_a->m[2][3] = m23;                                                                                                                             \
              mat_a->m[3][0] = m30;                                                                                                                             \
              mat_a->m[3][1] = m31;                                                                                                                             \
              mat_a->m[3][2] = m32;                                                                                                                             \
              mat_a->m[3][3] = m33;                                                                                                                             \
              return mat_a;                                                                                                                                     \
       }                                                                                                                                                        \
       MthVec4##t *mthMulMatVec4##t(const MthMat4##t *mat, MthVec4##t *vec)                                                                                     \
       {                                                                                                                                                        \
              type nx = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y + mat->m[2][0] * vec->z + mat->m[3][0] * vec->w;                                          \
              type ny = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y + mat->m[2][1] * vec->z + mat->m[3][1] * vec->w;                                          \
              type nz = mat->m[0][2] * vec->x + mat->m[1][2] * vec->y + mat->m[2][2] * vec->z + mat->m[3][2] * vec->w;                                          \
              type nw = mat->m[0][3] * vec->x + mat->m[1][3] * vec->y + mat->m[2][3] * vec->z + mat->m[3][3] * vec->w;                                          \
              vec->x = nx;                                                                                                                                      \
              vec->y = ny;                                                                                                                                      \
              vec->z = nz;                                                                                                                                      \
              vec->w = nw;                                                                                                                                      \
              return vec;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthTransposeMat4##t(MthMat4##t *mat)                                                                                                         \
       {                                                                                                                                                        \
              type buf10 = mat->m[1][0];                                                                                                                        \
              type buf20 = mat->m[2][0];                                                                                                                        \
              type buf30 = mat->m[3][0];                                                                                                                        \
              type buf21 = mat->m[2][1];                                                                                                                        \
              type buf31 = mat->m[3][1];                                                                                                                        \
              type buf32 = mat->m[3][2];                                                                                                                        \
              mat->m[1][0] = mat->m[0][1];                                                                                                                      \
              mat->m[2][0] = mat->m[0][2];                                                                                                                      \
              mat->m[3][0] = mat->m[0][3];                                                                                                                      \
              mat->m[2][1] = mat->m[1][2];                                                                                                                      \
              mat->m[3][1] = mat->m[1][3];                                                                                                                      \
              mat->m[3][2] = mat->m[2][3];                                                                                                                      \
              mat->m[1][1] = buf10;                                                                                                                             \
              mat->m[0][2] = buf20;                                                                                                                             \
              mat->m[0][3] = buf30;                                                                                                                             \
              mat->m[1][2] = buf21;                                                                                                                             \
              mat->m[1][3] = buf31;                                                                                                                             \
              mat->m[2][3] = buf32;                                                                                                                             \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthScaleMat4##t(MthMat4##t *mat, const MthVec4##t *vec)                                                                                      \
       {                                                                                                                                                        \
              mat->m[0][0] *= vec->x;                                                                                                                           \
              mat->m[0][1] *= vec->x;                                                                                                                           \
              mat->m[0][2] *= vec->x;                                                                                                                           \
              mat->m[0][3] *= vec->x;                                                                                                                           \
              mat->m[1][0] *= vec->y;                                                                                                                           \
              mat->m[1][1] *= vec->y;                                                                                                                           \
              mat->m[1][2] *= vec->y;                                                                                                                           \
              mat->m[1][3] *= vec->y;                                                                                                                           \
              mat->m[2][0] *= vec->z;                                                                                                                           \
              mat->m[2][1] *= vec->z;                                                                                                                           \
              mat->m[2][2] *= vec->z;                                                                                                                           \
              mat->m[2][3] *= vec->z;                                                                                                                           \
              mat->m[3][0] *= vec->w;                                                                                                                           \
              mat->m[3][1] *= vec->w;                                                                                                                           \
              mat->m[3][2] *= vec->w;                                                                                                                           \
              mat->m[3][3] *= vec->w;                                                                                                                           \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthScaleMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec)                                                                                  \
       {                                                                                                                                                        \
              mat->m[0][0] *= vec->x;                                                                                                                           \
              mat->m[0][1] *= vec->x;                                                                                                                           \
              mat->m[0][2] *= vec->x;                                                                                                                           \
              mat->m[0][3] *= vec->x;                                                                                                                           \
              mat->m[1][0] *= vec->y;                                                                                                                           \
              mat->m[1][1] *= vec->y;                                                                                                                           \
              mat->m[1][2] *= vec->y;                                                                                                                           \
              mat->m[1][3] *= vec->y;                                                                                                                           \
              mat->m[2][0] *= vec->z;                                                                                                                           \
              mat->m[2][1] *= vec->z;                                                                                                                           \
              mat->m[2][2] *= vec->z;                                                                                                                           \
              mat->m[2][3] *= vec->z;                                                                                                                           \
       }                                                                                                                                                        \
       MthMat4##t *mthTranslateFstMat4##t(MthMat4##t *mat, const MthVec4##t *vec)                                                                               \
       {                                                                                                                                                        \
              mat->m[3][0] = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y + mat->m[2][0] * vec->z + mat->m[3][0] * vec->w;                                     \
              mat->m[3][1] = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y + mat->m[2][1] * vec->z + mat->m[3][1] * vec->w;                                     \
              mat->m[3][2] = mat->m[0][2] * vec->x + mat->m[1][2] * vec->y + mat->m[2][2] * vec->z + mat->m[3][2] * vec->w;                                     \
              mat->m[3][3] = mat->m[0][3] * vec->x + mat->m[1][3] * vec->y + mat->m[2][3] * vec->z + mat->m[3][3] * vec->w;                                     \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthTranslateSecMat4##t(MthMat4##t *mat, const MthVec4##t *vec)                                                                               \
       {                                                                                                                                                        \
              mat->m[0][0] = mat->m[0][0] + vec->x * mat->m[0][3];                                                                                              \
              mat->m[0][1] = mat->m[0][1] + vec->y * mat->m[0][3];                                                                                              \
              mat->m[0][2] = mat->m[0][2] + vec->z * mat->m[0][3];                                                                                              \
              mat->m[0][3] = vec->w * mat->m[0][3];                                                                                                             \
              mat->m[1][0] = mat->m[1][0] + vec->x * mat->m[1][3];                                                                                              \
              mat->m[1][1] = mat->m[1][1] + vec->y * mat->m[1][3];                                                                                              \
              mat->m[1][2] = mat->m[1][2] + vec->z * mat->m[1][3];                                                                                              \
              mat->m[1][3] = vec->w * mat->m[1][3];                                                                                                             \
              mat->m[2][0] = mat->m[2][0] + vec->x * mat->m[2][3];                                                                                              \
              mat->m[2][1] = mat->m[2][1] + vec->y * mat->m[2][3];                                                                                              \
              mat->m[2][2] = mat->m[2][2] + vec->z * mat->m[2][3];                                                                                              \
              mat->m[2][3] = vec->w * mat->m[2][3];                                                                                                             \
              mat->m[3][0] = mat->m[3][0] + vec->x * mat->m[3][3];                                                                                              \
              mat->m[3][1] = mat->m[3][1] + vec->y * mat->m[3][3];                                                                                              \
              mat->m[3][2] = mat->m[3][2] + vec->z * mat->m[3][3];                                                                                              \
              mat->m[3][3] = vec->w * mat->m[3][3];                                                                                                             \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthTranslateFstMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec)                                                                           \
       {                                                                                                                                                        \
              mat->m[3][0] = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y + mat->m[2][0] * vec->z + mat->m[3][0];                                              \
              mat->m[3][1] = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y + mat->m[2][1] * vec->z + mat->m[3][1];                                              \
              mat->m[3][2] = mat->m[0][2] * vec->x + mat->m[1][2] * vec->y + mat->m[2][2] * vec->z + mat->m[3][2];                                              \
              mat->m[3][3] = mat->m[0][3] * vec->x + mat->m[1][3] * vec->y + mat->m[2][3] * vec->z + mat->m[3][3];                                              \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthTranslateSecMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec)                                                                           \
       {                                                                                                                                                        \
              mat->m[0][0] = mat->m[0][0] + vec->x * mat->m[0][3];                                                                                              \
              mat->m[0][1] = mat->m[0][1] + vec->y * mat->m[0][3];                                                                                              \
              mat->m[0][2] = mat->m[0][2] + vec->z * mat->m[0][3];                                                                                              \
              mat->m[1][0] = mat->m[1][0] + vec->x * mat->m[1][3];                                                                                              \
              mat->m[1][1] = mat->m[1][1] + vec->y * mat->m[1][3];                                                                                              \
              mat->m[1][2] = mat->m[1][2] + vec->z * mat->m[1][3];                                                                                              \
              mat->m[2][0] = mat->m[2][0] + vec->x * mat->m[2][3];                                                                                              \
              mat->m[2][1] = mat->m[2][1] + vec->y * mat->m[2][3];                                                                                              \
              mat->m[2][2] = mat->m[2][2] + vec->z * mat->m[2][3];                                                                                              \
              mat->m[3][0] = mat->m[3][0] + vec->x * mat->m[3][3];                                                                                              \
              mat->m[3][1] = mat->m[3][1] + vec->y * mat->m[3][3];                                                                                              \
              mat->m[3][2] = mat->m[3][2] + vec->z * mat->m[3][3];                                                                                              \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotXFstMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m10 = mat->m[1][0] * c + mat->m[2][0] * s;                                                                                                   \
              type m11 = mat->m[1][1] * c + mat->m[2][1] * s;                                                                                                   \
              type m12 = mat->m[1][2] * c + mat->m[2][2] * s;                                                                                                   \
              type m13 = mat->m[1][3] * c + mat->m[2][3] * s;                                                                                                   \
              type m20 = mat->m[1][0] * -s + mat->m[2][0] * c;                                                                                                  \
              type m21 = mat->m[1][1] * -s + mat->m[2][1] * c;                                                                                                  \
              type m22 = mat->m[1][2] * -s + mat->m[2][2] * c;                                                                                                  \
              type m23 = mat->m[1][3] * -s + mat->m[2][3] * c;                                                                                                  \
              mat->m[1][0] = m10;                                                                                                                               \
              mat->m[1][1] = m11;                                                                                                                               \
              mat->m[1][2] = m12;                                                                                                                               \
              mat->m[1][3] = m13;                                                                                                                               \
              mat->m[2][0] = m20;                                                                                                                               \
              mat->m[2][1] = m21;                                                                                                                               \
              mat->m[2][2] = m22;                                                                                                                               \
              mat->m[2][3] = m23;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotXSecMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m01 = mat->m[0][1] * c + mat->m[0][2] * -s;                                                                                                  \
              type m02 = mat->m[0][1] * s + mat->m[0][2] * c;                                                                                                   \
              type m11 = mat->m[1][1] * c + mat->m[1][2] * -s;                                                                                                  \
              type m12 = mat->m[1][1] * s + mat->m[1][2] * c;                                                                                                   \
              type m21 = mat->m[2][1] * c + mat->m[2][2] * -s;                                                                                                  \
              type m22 = mat->m[2][1] * s + mat->m[2][2] * c;                                                                                                   \
              type m31 = mat->m[3][1] * c + mat->m[3][2] * -s;                                                                                                  \
              type m32 = mat->m[3][1] * s + mat->m[3][2] * c;                                                                                                   \
              mat->m[0][1] = m01;                                                                                                                               \
              mat->m[0][2] = m02;                                                                                                                               \
              mat->m[1][1] = m11;                                                                                                                               \
              mat->m[1][2] = m12;                                                                                                                               \
              mat->m[2][1] = m21;                                                                                                                               \
              mat->m[2][2] = m22;                                                                                                                               \
              mat->m[3][1] = m31;                                                                                                                               \
              mat->m[3][2] = m32;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotYFstMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m00 = mat->m[0][0] * c + mat->m[2][0] * -s;                                                                                                  \
              type m01 = mat->m[0][1] * c + mat->m[2][1] * -s;                                                                                                  \
              type m02 = mat->m[0][2] * c + mat->m[2][2] * -s;                                                                                                  \
              type m03 = mat->m[0][3] * c + mat->m[2][3] * -s;                                                                                                  \
              type m20 = mat->m[0][0] * s + mat->m[2][0] * c;                                                                                                   \
              type m21 = mat->m[0][1] * s + mat->m[2][1] * c;                                                                                                   \
              type m22 = mat->m[0][2] * s + mat->m[2][2] * c;                                                                                                   \
              type m23 = mat->m[0][3] * s + mat->m[2][3] * c;                                                                                                   \
              mat->m[0][0] = m00;                                                                                                                               \
              mat->m[0][1] = m01;                                                                                                                               \
              mat->m[0][2] = m02;                                                                                                                               \
              mat->m[0][3] = m03;                                                                                                                               \
              mat->m[2][0] = m20;                                                                                                                               \
              mat->m[2][1] = m21;                                                                                                                               \
              mat->m[2][2] = m22;                                                                                                                               \
              mat->m[2][3] = m23;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotYSecMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m00 = mat->m[0][0] * c + mat->m[0][2] * s;                                                                                                   \
              type m02 = mat->m[0][0] * -s + mat->m[0][2] * c;                                                                                                  \
              type m10 = mat->m[1][0] * c + mat->m[1][2] * s;                                                                                                   \
              type m12 = mat->m[1][0] * -s + mat->m[1][2] * c;                                                                                                  \
              type m20 = mat->m[2][0] * c + mat->m[2][2] * s;                                                                                                   \
              type m22 = mat->m[2][0] * -s + mat->m[2][2] * c;                                                                                                  \
              type m30 = mat->m[3][0] * c + mat->m[3][2] * s;                                                                                                   \
              type m32 = mat->m[3][0] * -s + mat->m[3][2] * c;                                                                                                  \
              mat->m[0][0] = m00;                                                                                                                               \
              mat->m[0][2] = m02;                                                                                                                               \
              mat->m[1][0] = m10;                                                                                                                               \
              mat->m[1][2] = m12;                                                                                                                               \
              mat->m[2][0] = m20;                                                                                                                               \
              mat->m[2][2] = m22;                                                                                                                               \
              mat->m[3][0] = m30;                                                                                                                               \
              mat->m[3][2] = m32;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotZFstMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m00 = mat->m[0][0] * c + mat->m[1][0] * s;                                                                                                   \
              type m01 = mat->m[0][1] * c + mat->m[1][1] * s;                                                                                                   \
              type m02 = mat->m[0][2] * c + mat->m[1][2] * s;                                                                                                   \
              type m03 = mat->m[0][3] * c + mat->m[1][3] * s;                                                                                                   \
              type m10 = mat->m[0][0] * -s + mat->m[1][0] * c;                                                                                                  \
              type m11 = mat->m[0][1] * -s + mat->m[1][1] * c;                                                                                                  \
              type m12 = mat->m[0][2] * -s + mat->m[1][2] * c;                                                                                                  \
              type m13 = mat->m[0][3] * -s + mat->m[1][3] * c;                                                                                                  \
              mat->m[0][0] = m00;                                                                                                                               \
              mat->m[0][1] = m01;                                                                                                                               \
              mat->m[0][2] = m02;                                                                                                                               \
              mat->m[0][3] = m03;                                                                                                                               \
              mat->m[1][0] = m10;                                                                                                                               \
              mat->m[1][1] = m11;                                                                                                                               \
              mat->m[1][2] = m12;                                                                                                                               \
              mat->m[1][3] = m13;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthRotZSecMat4##t(MthMat4##t *mat, type a)                                                                                                   \
       {                                                                                                                                                        \
              type c = (type)cosf(a);                                                                                                                           \
              type s = (type)sinf(a);                                                                                                                           \
              type m00 = mat->m[0][0] * c + mat->m[0][1] * -s;                                                                                                  \
              type m01 = mat->m[0][0] * s + mat->m[0][1] * c;                                                                                                   \
              type m10 = mat->m[1][0] * c + mat->m[1][1] * -s;                                                                                                  \
              type m11 = mat->m[1][0] * s + mat->m[1][1] * c;                                                                                                   \
              type m20 = mat->m[2][0] * c + mat->m[2][1] * -s;                                                                                                  \
              type m21 = mat->m[2][0] * s + mat->m[2][1] * c;                                                                                                   \
              type m30 = mat->m[3][0] * c + mat->m[3][1] * -s;                                                                                                  \
              type m31 = mat->m[3][0] * s + mat->m[3][1] * c;                                                                                                   \
              mat->m[0][0] = m00;                                                                                                                               \
              mat->m[0][1] = m01;                                                                                                                               \
              mat->m[1][0] = m10;                                                                                                                               \
              mat->m[1][1] = m11;                                                                                                                               \
              mat->m[2][0] = m20;                                                                                                                               \
              mat->m[2][1] = m21;                                                                                                                               \
              mat->m[3][0] = m30;                                                                                                                               \
              mat->m[3][1] = m31;                                                                                                                               \
              return mat;                                                                                                                                       \
       }                                                                                                                                                        \
       MthMat4##t *mthPerspectiveMat4##t(MthMat4##t *mat, type width, type height, type fov, type znear, type zfar)                                             \
       {                                                                                                                                                        \
              type aspect = width / height;                                                                                                                     \
              type tan_half_fov = (type)tanf(fov / 2.0f);                                                                                                       \
              type range = znear - zfar;                                                                                                                        \
              mat->m[0][0] = (type)1 / (aspect * tan_half_fov);                                                                                                 \
              mat->m[0][1] = (type)0;                                                                                                                           \
              mat->m[0][2] = (type)0;                                                                                                                           \
              mat->m[0][3] = (type)0;                                                                                                                           \
              mat->m[1][0] = (type)0;                                                                                                                           \
              mat->m[1][1] = (type)1 / tan_half_fov;                                                                                                            \
              mat->m[1][2] = (type)0;                                                                                                                           \
              mat->m[1][3] = (type)0;                                                                                                                           \
              mat->m[2][0] = (type)0;                                                                                                                           \
              mat->m[2][1] = (type)0;                                                                                                                           \
              mat->m[2][2] = (-znear - zfar) / range;                                                                                                           \
              mat->m[2][3] = (type)1;                                                                                                                           \
              mat->m[3][0] = (type)0;                                                                                                                           \
              mat->m[3][1] = (type)0;                                                                                                                           \
              mat->m[3][2] = ((type)2 * zfar * znear) / range;                                                                                                  \
              mat->m[3][3] = (type)0;                                                                                                                           \
              return mat;                                                                                                                                       \
       }

MTH_DEF_MAT2(float, f)
MTH_DEF_MAT2(double, d)
MTH_DEF_MAT2(int, i)

MTH_DEF_MAT3(float, f)
MTH_DEF_MAT3(double, d)
MTH_DEF_MAT3(int, i)

MTH_DEF_MAT4(float, f)
MTH_DEF_MAT4(double, d)
MTH_DEF_MAT4(int, i)