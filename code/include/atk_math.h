#ifndef __MATH_H__
#define __MATH_H__

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#include <math.h>

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

#ifdef __cplusplus
}
#endif //__cplusplus

#ifdef __cplusplus

#define MTH_VEC2(type, t)                                             \
       struct MthVec2##t : public AtkPack2##t                         \
       {                                                              \
              MthVec2##t();                                           \
              MthVec2##t(type _x, type _y);                           \
              MthVec2##t(const MthVec2##t &vec);                      \
              MthVec2##t(const AtkPack2##t &pack);\
              bool operator==(const MthVec2##t &vec) const;           \
              bool operator!=(const MthVec2##t &vec) const;           \
              MthVec2##t &operator=(const MthVec2##t &vec) = default; \
              MthVec2##t &operator=(const AtkPack2##t &pack);\
              MthVec2##t &operator+=(const MthVec2##t &vec);          \
              MthVec2##t operator+(const MthVec2##t &vec) const;      \
              MthVec2##t &operator-=(const MthVec2##t &vec);          \
              MthVec2##t operator-(const MthVec2##t &vec) const;      \
              MthVec2##t operator-() const;                           \
              MthVec2##t &operator*=(type factor);                    \
              MthVec2##t operator*(type factor) const;                \
              MthVec2##t &operator/=(type factor);                    \
              MthVec2##t operator/(type factor) const;                \
              type dot(type _x, type _y) const;                       \
              type dot(const MthVec2##t &vec) const;                  \
              type len() const;                                       \
              type lenSq() const;                                     \
              MthVec2##t &norm();                                     \
              MthVec2##t &ortho();                                    \
              MthVec2##t &rot(type a);                                \
       };

#define MTH_VEC3(type, t)                                             \
       struct MthVec3##t : public AtkPack3##t                         \
       {                                                              \
              MthVec3##t();                                           \
              MthVec3##t(type _x, type _y, type _z);                  \
              MthVec3##t(const MthVec3##t &vec);                      \
              MthVec3##t(const AtkPack3##t &pack);\
              bool operator==(const MthVec3##t &vec) const;           \
              bool operator!=(const MthVec3##t &vec) const;           \
              MthVec3##t &operator=(const MthVec3##t &vec) = default; \
              MthVec3##t &operator=(const AtkPack3##t &pack);\
              MthVec3##t &operator+=(const MthVec3##t &vec);          \
              MthVec3##t operator+(const MthVec3##t &vec) const;      \
              MthVec3##t &operator-=(const MthVec3##t &vec);          \
              MthVec3##t operator-(const MthVec3##t &vec) const;      \
              MthVec3##t operator-() const;                           \
              MthVec3##t &operator*=(type factor);                    \
              MthVec3##t operator*(type factor) const;                \
              MthVec3##t &operator*=(const MthVec3##t &vec);          \
              MthVec3##t operator*(const MthVec3##t &vec) const;      \
              MthVec3##t &operator/=(type factor);                    \
              MthVec3##t operator/(type factor) const;                \
              type dot(type _x, type _y, type _z) const;              \
              type dot(const MthVec3##t &vec) const;                  \
              type len() const;                                       \
              type lenSq() const;                                     \
              MthVec3##t &norm();                                     \
              MthVec3##t &rotX(float a);                              \
              MthVec3##t &rotY(float a);                              \
              MthVec3##t &rotZ(float a);                              \
       };

#define MTH_VEC4(type, t)                                             \
       struct MthVec4##t : public AtkPack4##t                         \
       {                                                              \
              MthVec4##t();                                           \
              MthVec4##t(type _x, type _y, type _z, type _w);         \
              MthVec4##t(const MthVec4##t &vec);                      \
              MthVec4##t(const AtkPack4##t &pack);\
              bool operator==(const MthVec4##t &vec) const;           \
              bool operator!=(const MthVec4##t &vec) const;           \
              MthVec4##t &operator=(const MthVec4##t &vec) = default; \
              MthVec4##t &operator=(const AtkPack4##t &pack);\
              MthVec4##t &operator+=(const MthVec4##t &vec);          \
              MthVec4##t operator+(const MthVec4##t &vec) const;      \
              MthVec4##t &operator-=(const MthVec4##t &vec);          \
              MthVec4##t operator-(const MthVec4##t &vec) const;      \
              MthVec4##t operator-() const;                           \
              MthVec4##t &operator*=(type factor);                    \
              MthVec4##t operator*(type factor) const;                \
              MthVec4##t &operator/=(type factor);                    \
              MthVec4##t operator/(type factor) const;                \
              MthVec4##t &crossDim3(type _x, type _y, type _z);       \
              MthVec4##t &crossDim3(const MthVec4##t &vec);           \
              type dot(type _x, type _y, type _z, type _w) const;     \
              type dot(const MthVec4##t &vec) const;                  \
              type len() const;                                       \
              type lenSq() const;                                     \
              type lenDim3() const;                                   \
              type lenSqDim3() const;                                 \
              MthVec4##t &norm();                                     \
              MthVec4##t &normDim3();                                 \
              MthVec4##t &rotXDim3(float a);                          \
              MthVec4##t &rotYDim3(float a);                          \
              MthVec4##t &rotZDim3(float a);                          \
       };

#define MTH_MAT2(type, t)                                             \
       struct MthMat2##t : public AtkPack2x2##t                       \
       {                                                              \
              MthMat2##t();                                           \
              MthMat2##t(type m00, type m01, type m10, type m11);     \
              MthMat2##t(const MthMat2##t &mat);                      \
              MthMat2##t(const AtkPack2x2##t &pack);\
              bool operator==(const MthMat2##t &mat) const;           \
              bool operator!=(const MthMat2##t &mat) const;           \
              MthMat2##t &operator=(const MthMat2##t &mat) = default; \
              MthMat2##t &operator=(const AtkPack2x2##t &pack);\
              MthMat2##t &operator+=(const MthMat2##t &mat);          \
              MthMat2##t operator+(const MthMat2##t &mat) const;      \
              MthMat2##t &operator-=(const MthMat2##t &mat);          \
              MthMat2##t operator-(const MthMat2##t &mat);            \
              MthMat2##t operator-() const;                           \
              MthMat2##t &operator*=(const MthMat2##t &mat);          \
              MthMat2##t operator*(const MthMat2##t &mat);            \
              MthVec2##t operator*(const MthVec2##t &vec) const;      \
              MthMat2##t &operator*=(type factor);                    \
              MthMat2##t operator*(type factor) const;                \
              MthMat2##t &identity();                                 \
              MthMat2##t &transpose();                                \
              MthMat2##t &scale(type x, type y);                      \
              MthMat2##t &scale(const MthVec2##t &vec);               \
              MthMat2##t &rotFst(type a);                             \
              MthMat2##t &rotSec(type a);                             \
       };

#define MTH_MAT3(type, t)                                                                                           \
       struct MthMat3##t : public AtkPack3x3##t                                                                     \
       {                                                                                                            \
              MthMat3##t();                                                                                         \
              MthMat3##t(type m00, type m01, type m02, type m10, type m11, type m12, type m20, type m21, type m22); \
              MthMat3##t(const MthMat3##t &mat);                                                                    \
              MthMat3##t(const AtkPack3x3##t &pack);\
              bool operator==(const MthMat2##t &mat) const;                                                         \
              bool operator!=(const MthMat2##t &mat) const;                                                         \
              MthMat3##t &operator=(const MthMat3##t &mat) = default;                                               \
              MthMat3##t &operator=(const AtkPack3x3##t &pack);\
              MthMat3##t &operator+=(const MthMat3##t &mat);                                                        \
              MthMat3##t operator+(const MthMat3##t &mat) const;                                                    \
              MthMat3##t &operator-=(const MthMat3##t &mat);                                                        \
              MthMat3##t operator-(const MthMat3##t &mat);                                                          \
              MthMat3##t operator-() const;                                                                         \
              MthMat3##t &operator*=(const MthMat3##t &mat);                                                        \
              MthMat3##t operator*(const MthMat3##t &mat);                                                          \
              MthVec3##t operator*(const MthVec3##t &vec) const;                                                    \
              MthMat3##t &operator*=(type factor);                                                                  \
              MthMat3##t operator*(type factor) const;                                                              \
              MthMat3##t &identity();                                                                               \
              MthMat3##t &transpose();                                                                              \
              MthMat3##t &scale(type x, type y, type z);                                                            \
              MthMat3##t &scale(const MthVec3##t &vec);                                                             \
              MthMat3##t &rotXFst(type a);                                                                          \
              MthMat3##t &rotXSec(type a);                                                                          \
              MthMat3##t &rotYFst(type a);                                                                          \
              MthMat3##t &rotYSec(type a);                                                                          \
              MthMat3##t &rotZFst(type a);                                                                          \
              MthMat3##t &rotZSec(type a);                                                                          \
       };

#define MTH_MAT4(type, t)                                                                        \
       struct MthMat4##t : public AtkPack4x4##t                                                  \
       {                                                                                         \
              MthMat4##t();                                                                      \
              MthMat4##t(type m00, type m01, type m02, type m03,                                 \
                         type m10, type m11, type m12, type m13,                                 \
                         type m20, type m21, type m22, type m23,                                 \
                         type m30, type m31, type m32, type m33);                                \
              MthMat4##t(const AtkPack4x4##t &pack);\
              MthMat4##t(const MthMat4##t &mat);                                                 \
              bool operator==(const MthMat2##t &mat) const;                                      \
              bool operator!=(const MthMat2##t &mat) const;                                      \
              MthMat4##t &operator=(const MthMat4##t &mat) = default;                            \
              MthMat4##t &operator=(const AtkPack4x4##t &pack);\
              MthMat4##t &operator+=(const MthMat4##t &mat);                                     \
              MthMat4##t operator+(const MthMat4##t &mat) const;                                 \
              MthMat4##t &operator-=(const MthMat4##t &mat);                                     \
              MthMat4##t operator-(const MthMat4##t &mat);                                       \
              MthMat4##t operator-() const;                                                      \
              MthMat4##t &operator*=(const MthMat4##t &mat);                                     \
              MthMat4##t operator*(const MthMat4##t &mat);                                       \
              MthVec4##t operator*(const MthVec4##t &vec) const;                                 \
              MthMat4##t &operator*=(type factor);                                               \
              MthMat4##t operator*(type factor) const;                                           \
              MthMat4##t &identity();                                                            \
              MthMat4##t &transpose();                                                           \
              MthMat4##t &scale(type x, type y, type z, type w);                                 \
              MthMat4##t &scale(const MthVec4##t &vec);                                          \
              MthMat4##t &scaleDim3(type x, type y, type z);                                     \
              MthMat4##t &scaleDim3(const MthVec3##t &vec);                                      \
              MthMat4##t &rotXFst(type a);                                                       \
              MthMat4##t &rotXSec(type a);                                                       \
              MthMat4##t &rotYFst(type a);                                                       \
              MthMat4##t &rotYSec(type a);                                                       \
              MthMat4##t &rotZFst(type a);                                                       \
              MthMat4##t &rotZSec(type a);                                                       \
              MthMat4##t &translateFst(type x, type y, type z, type w);                          \
              MthMat4##t &translateFst(const MthVec4##t &vec);                                   \
              MthMat4##t &translateSec(type x, type y, type z, type w);                          \
              MthMat4##t &translateSec(const MthVec4##t &vec);                                   \
              MthMat4##t &translateFstDim3(type x, type y, type z);                              \
              MthMat4##t &translateFstDim3(const MthVec3##t &vec);                               \
              MthMat4##t &translateSecDim3(type x, type y, type z);                              \
              MthMat4##t &translateSecDim3(const MthVec3##t &vec);                               \
              MthMat4##t &perspective(type width, type height, type fov, type znear, type zfar); \
       };

MTH_VEC2(float, f);
MTH_VEC2(double, d)
MTH_VEC2(int, i)

MTH_VEC3(float, f)
MTH_VEC3(double, d)
MTH_VEC3(int, i)

MTH_VEC4(float, f)
MTH_VEC4(double, d)
MTH_VEC4(int, i)

MTH_MAT2(float, f)
MTH_MAT2(double, d)
MTH_MAT2(int, i)

MTH_MAT3(float, f)
MTH_MAT3(double, d)
MTH_MAT3(int, i)

MTH_MAT4(float, f)
MTH_MAT4(double, d)
MTH_MAT4(int, i)

#ifdef ATK_MTH_NO_CONFUSION
typedef MthVec2f vec2f;
typedef MthVec2d vec2d;
typedef MthVec2i vec2i;

typedef MthVec3f vec3f;
typedef MthVec3d vec3d;
typedef MthVec3i vec3i;

typedef MthVec4f vec4f;
typedef MthVec4d vec4d;
typedef MthVec4i vec4i;

typedef MthMat2f mat2f;
typedef MthMat2d mat2d;
typedef MthMat2i mat2i;

typedef MthMat3f mat3f;
typedef MthMat3d mat3d;
typedef MthMat3i mat3i;

typedef MthMat4f mat4f;
typedef MthMat4d mat4d;
typedef MthMat4i mat4i;
#endif //ATK_MTH_NO_CONFUSION

#endif //__cplusplus

#endif //__MATH_H__