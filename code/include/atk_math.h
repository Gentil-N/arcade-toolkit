#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#define MTH_DEF_CONST(type, t, name, val) static const type MTH_##name##_##t = val;

#define MTH_PI_f 3.141592653f
#define MTH_PI_d 3.141592653589793238
#define MTH_PI_HALF_f 1.570796327f
#define MTH_PI_HALF_d 1.570796326794896619
#define MTH_PI_2_f 6.283185307f
#define MTH_PI_2_d 6.283185307179586477

#define mth_to_radf(deg) (deg * MTH_PI_f / 180.0f)
#define mth_to_radd(deg) (deg * MTH_PI_d / 180.0)
#define mth_to_degf(rad) (rad * 180.0f / MTH_PI_f)
#define mth_to_degd(rad) (rad * 180.0 / MTH_PI_d)

       ATK_API float rsqrtssf(float val); //rsqrtss -> float

#define COMMA ,
#define MTH_DEC_VEC(type, t, n, vals)                                                 \
                                                                                      \
       typedef struct MthVec##n##t                                                    \
       {                                                                              \
              type vals;                                                              \
       } MthVec##n##t;                                                                \
                                                                                      \
       ATK_API MthVec##n##t *mthAddVec##n##t(MthVec##n##t *vec_a, const MthVec##n##t *vec_b); \
       ATK_API MthVec##n##t *mthMulVec##n##t(MthVec##n##t *vec, type factor);                 \
       ATK_API MthVec##n##t *mthNormVec##n##t(MthVec##n##t *vec);                             \
       ATK_API type mthDotVec##n##t(const MthVec##n##t *vec_a, const MthVec##n##t *vec_b);    \
       ATK_API type mthLenVec##n##t(MthVec##n##t *vec);                                       \
       ATK_API type mthLenSqVec##n##t(MthVec##n##t *vec);

#define MTH_DEC_FUNC_VEC2(type, t)                   \
       ATK_API MthVec2##t *mthOrthoVec2##t(MthVec2##t *vec); \
       ATK_API MthVec2##t *mthRotVe2##t(MthVec2##t *vec, type a);

#define MTH_DEC_FUNC_VEC3(type, t)                                        \
       ATK_API MthVec3##t *mthCrossVec3##t(MthVec3##t *vec_a, MthVec3##t *vec_b); \
       ATK_API MthVec3##t *mthRotXVec3##t(MthVec3##t *vec, type a);               \
       ATK_API MthVec3##t *mthRotYVec3##t(MthVec3##t *vec, type a);               \
       ATK_API MthVec3##t *mthRotZVec3##t(MthVec3##t *vec, type a);

#define MTH_DEC_FUNC_VEC4(type, t)                                        \
       ATK_API MthVec4##t *mthRotXVec4##t(MthVec4##t *vec, type a);               \
       ATK_API MthVec4##t *mthRotYVec4##t(MthVec4##t *vec, type a);               \
       ATK_API MthVec4##t *mthRotZVec4##t(MthVec4##t *vec, type a);

       MTH_DEC_VEC(float, f, 2, x COMMA y)
       MTH_DEC_VEC(double, d, 2, x COMMA y)
       MTH_DEC_VEC(int, i, 2, x COMMA y)

       MTH_DEC_FUNC_VEC2(float, f)
       MTH_DEC_FUNC_VEC2(double, d)
       MTH_DEC_FUNC_VEC2(int, i)

       MTH_DEC_VEC(float, f, 3, x COMMA y COMMA z)
       MTH_DEC_VEC(double, d, 3, x COMMA y COMMA z)
       MTH_DEC_VEC(int, i, 3, x COMMA y COMMA z)

       MTH_DEC_FUNC_VEC3(float, f)
       MTH_DEC_FUNC_VEC3(double, d)
       MTH_DEC_FUNC_VEC3(int, i)

       MTH_DEC_VEC(float, f, 4, x COMMA y COMMA z COMMA w)
       MTH_DEC_VEC(double, d, 4, x COMMA y COMMA z COMMA w)
       MTH_DEC_VEC(int, i, 4, x COMMA y COMMA z COMMA w)

       MTH_DEC_FUNC_VEC4(float, f)
       MTH_DEC_FUNC_VEC4(double, d)
       MTH_DEC_FUNC_VEC4(int, i)

#define MTH_DEC_MAT(type, t, n)                                                       \
                                                                                      \
       typedef struct MthMat##n##t                                                    \
       {                                                                              \
              type m[n][n];                                                           \
       } MthMat##n##t;                                                                \
                                                                                      \
       ATK_API MthMat##n##t *mthIdentityMat##n##t(MthMat##n##t *mat);                         \
       ATK_API MthMat##n##t *mthAddMat##n##t(MthMat##n##t *mat_a, const MthMat##n##t *mat_b); \
       ATK_API MthMat##n##t *mthMulfMat##n##t(MthMat##n##t *mat, type factor);                \
       ATK_API MthMat##n##t *mthMulMat##n##t(MthMat##n##t *mat_a, const MthMat##n##t *mat_b); \
       ATK_API MthVec##n##t *mthMulMatVec##n##t(const MthMat##n##t *mat, MthVec##n##t *vec);  \
       ATK_API MthMat##n##t *mthTransposeMat##n##t(MthMat##n##t *mat);                        \
       ATK_API MthMat##n##t *mthScaleMat##n##t(MthMat##n##t *mat, const MthVec##n##t *vec);

#define MTH_DEC_FUNC_MAT2(type, t)                            \
       ATK_API MthMat2##t *mthRotFstMat2##t(MthMat2##t *mat, type a); \
       ATK_API MthMat2##t *mthRotSecMat2##t(MthMat2##t *mat, type a);

#define MTH_DEC_FUNC_MAT3(type, t)                             \
       ATK_API MthMat3##t *mthRotXFstMat3##t(MthMat3##t *mat, type a); \
       ATK_API MthMat3##t *mthRotXSecMat3##t(MthMat3##t *mat, type a); \
       ATK_API MthMat3##t *mthRotYFstMat3##t(MthMat3##t *mat, type a); \
       ATK_API MthMat3##t *mthRotYSecMat3##t(MthMat3##t *mat, type a); \
       ATK_API MthMat3##t *mthRotZFstMat3##t(MthMat3##t *mat, type a); \
       ATK_API MthMat3##t *mthRotZSecMat3##t(MthMat3##t *mat, type a);

#define MTH_DEC_FUNC_MAT4(type, t)                                                     \
       ATK_API MthMat4##t *mthScaleMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec);\
       ATK_API MthMat4##t *mthTranslateFstMat4##t(MthMat4##t *mat, const MthVec4##t *vec);     \
       ATK_API MthMat4##t *mthTranslateSecMat4##t(MthMat4##t *mat, const MthVec4##t *vec);     \
       ATK_API MthMat4##t *mthTranslateFstMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec); \
       ATK_API MthMat4##t *mthTranslateSecMat4Vec3##t(MthMat4##t *mat, const MthVec3##t *vec); \
       ATK_API MthMat4##t *mthRotXFstMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthRotXSecMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthRotYFstMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthRotYSecMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthRotZFstMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthRotZSecMat4##t(MthMat4##t *mat, type a);                         \
       ATK_API MthMat4##t *mthPerspectiveMat4##t(MthMat4##t *mat, type width, type height, type fov, type znear, type zfar);

       MTH_DEC_MAT(float, f, 2)
       MTH_DEC_MAT(double, d, 2)
       MTH_DEC_MAT(int, i, 2)

       MTH_DEC_FUNC_MAT2(float, f)
       MTH_DEC_FUNC_MAT2(double, d)
       MTH_DEC_FUNC_MAT2(int, i)

       MTH_DEC_MAT(float, f, 3)
       MTH_DEC_MAT(double, d, 3)
       MTH_DEC_MAT(int, i, 3)

       MTH_DEC_FUNC_MAT3(float, f)
       MTH_DEC_FUNC_MAT3(double, d)
       MTH_DEC_FUNC_MAT3(int, i)

       MTH_DEC_MAT(float, f, 4)
       MTH_DEC_MAT(double, d, 4)
       MTH_DEC_MAT(int, i, 4)

       MTH_DEC_FUNC_MAT4(float, f)
       MTH_DEC_FUNC_MAT4(double, d)
       MTH_DEC_FUNC_MAT4(int, i)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__MATH_H__