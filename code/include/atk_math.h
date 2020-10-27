#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

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

template <typename type>
struct MthVec2
{
       type x, y;

       MthVec2() : x(0), y(0)
       {
       }
       MthVec2(type _x, type _y) : x(_x), y(_y)
       {
       }
       MthVec2(const MthVec2 &vec) : x(vec.x), y(vec.y)
       {
       }
       MthVec2<type> &operator=(const MthVec2 &vec) = default;
       MthVec2<type> &operator+=(const MthVec2 &vec)
       {
              x += vec.x;
              y += vec.y;
              return *this;
       }
       MthVec2<type> operator+(const MthVec2 &vec) const
       {
              return MthVec2<type>(x + vec.x, y + vec.y);
       }
       MthVec2<type> &operator-=(const MthVec2 &vec)
       {
              x -= vec.x;
              y -= vec.y;
              return *this;
       }
       MthVec2<type> operator-(const MthVec2 &vec) const
       {
              return MthVec2<type>(x - vec.x, y - vec.y);
       }
       MthVec2<type> operator-() const
       {
              return MthVec2<type>(-x, -y);
       }
       MthVec2<type> &operator*=(type factor)
       {
              x *= factor;
              y *= factor;
              return *this;
       }
       MthVec2<type> operator*(type factor) const
       {
              return MthVec2<type>(x * factor, y * factor);
       }
       MthVec2<type> &operator/=(type factor)
       {
              atk_assert(factor != (type)0);
              x /= factor;
              y /= factor;
              return *this;
       }
       MthVec2<type> operator/(type factor) const
       {
              atk_assert(factor != (type)0);
              return MthVec2<type>(x / factor, y / factor);
       }
       type dot(type _x, type _y) const
       {
              return x * _x + y * _y;
       }
       type dot(const MthVec2<type> &vec) const
       {
              return dot(vec.x, vec.y);
       }
       type len() const
       {
              return (type)1.0 / (type)rsqrtssf(x * x + y * y);
       }
       type lenSq() const
       {
              return x * x + y * y;
       }
       MthVec2<type> &norm()
       {
              type lenght = len();
              atk_assert(lenght != 0);
              x /= lenght;
              y /= lenght;
              return *this;
       }
       MthVec2<type> &ortho()
       {
              type buf = x;
              x = -y;
              y = buf;
              return *this;
       }
       MthVec2<type> &rot(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type nx = x * c + y * -s;
              type ny = x * s + y * c;
              x = nx;
              y = ny;
              return *this;
       }
};

template <typename type>
struct MthVec3
{
       type x, y, z;

       MthVec3() : x(0), y(0), z(0)
       {
       }
       MthVec3(type _x, type _y, type _z) : x(_x), y(_y), z(_z)
       {
       }
       MthVec3(const MthVec3 &vec) : x(vec.x), y(vec.y), z(vec.z)
       {
       }
       MthVec3<type> &operator=(const MthVec3 &vec) = default;
       MthVec3<type> &operator+=(const MthVec3 &vec)
       {
              x += vec.x;
              y += vec.y;
              z += vec.z;
              return *this;
       }
       MthVec3<type> operator+(const MthVec3 &vec) const
       {
              return MthVec3<type>(x + vec.x, y + vec.y, z + vec.z);
       }
       MthVec3<type> &operator-=(const MthVec3 &vec)
       {
              x -= vec.x;
              y -= vec.y;
              z -= vec.z;
              return *this;
       }
       MthVec3<type> operator-(const MthVec3 &vec) const
       {
              return MthVec3<type>(x - vec.x, y - vec.y, z - vec.z);
       }
       MthVec3<type> operator-() const
       {
              return MthVec3<type>(-x, -y, -z);
       }
       MthVec3<type> &operator*=(type factor)
       {
              x *= factor;
              y *= factor;
              z *= factor;
              return *this;
       }
       MthVec3<type> operator*(type factor) const
       {
              return MthVec3<type>(x * factor, y * factor, z * factor);
       }
       MthVec3<type> &operator*=(const MthVec3<type> &vec)
       {
              type nx = y * vec.z - z * vec.y;
              type ny = z * vec.x - x * vec.z;
              type nz = x * vec.y - y * vec.x;
              x = nx;
              y = ny;
              z = nz;
              return *this;
       }
       MthVec3<type> operator*(const MthVec3<type> &vec) const
       {
              return MthVec3<type>(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
       }
       MthVec3<type> &operator/=(type factor)
       {
              atk_assert(factor != (type)0);
              x /= factor;
              y /= factor;
              z /= factor;
              return *this;
       }
       MthVec3<type> operator/(type factor) const
       {
              atk_assert(factor != (type)0);
              return MthVec3<type>(x / factor, y / factor, z / factor);
       }
       type dot(type _x, type _y, type _z) const
       {
              return x * _x + y * _y + z * _z;
       }
       type dot(const MthVec2<type> &vec) const
       {
              return dot(vec.x, vec.y, vec.z);
       }
       type len() const
       {
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z);
       }
       type lenSq() const
       {
              return x * x + y * y + z * z;
       }
       MthVec3<type> &norm()
       {
              type lenght = len();
              atk_assert(lenght != 0);
              x /= lenght;
              y /= lenght;
              z /= lenght;
              return *this;
       }
       MthVec3<type> &rotX(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type ny = y * c + z * -s;
              type nz = y * s + z * c;
              y = ny;
              z = nz;
              return *this;
       }
       MthVec3<type> &rotY(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type nx = x * c + z * s;
              type nz = x * -s + z * c;
              x = nx;
              z = nz;
              return *this;
       }
       MthVec3<type> &rotZ(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type nx = x * c + y * -s;
              type ny = x * s + y * c;
              x = nx;
              y = ny;
              return *this;
       }
};

template <typename type>
struct MthVec4
{
       type x, y, z, w;

       MthVec4() : x(0), y(0), z(0), w(0)
       {
       }
       MthVec4(type _x, type _y, type _z, type _w) : x(_x), y(_y), z(_z), w(_w)
       {
       }
       MthVec4(const MthVec4 &vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w)
       {
       }
       MthVec4<type> &operator=(const MthVec4 &vec) = default;
       MthVec4<type> &operator+=(const MthVec4 &vec)
       {
              x += vec.x;
              y += vec.y;
              z += vec.z;
              w += vec.w;
              return *this;
       }
       MthVec4<type> operator+(const MthVec4 &vec) const
       {
              return MthVec4<type>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
       }
       MthVec4<type> &operator-=(const MthVec4 &vec)
       {
              x -= vec.x;
              y -= vec.y;
              z -= vec.z;
              w -= vec.w;
              return *this;
       }
       MthVec4<type> operator-(const MthVec4 &vec) const
       {
              return MthVec4<type>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
       }
       MthVec4<type> operator-() const
       {
              return MthVec4<type>(-x, -y, -z, -w);
       }
       MthVec4<type> &operator*=(type factor)
       {
              x *= factor;
              y *= factor;
              z *= factor;
              w *= factor;
              return *this;
       }
       MthVec4<type> operator*(type factor) const
       {
              return MthVec4<type>(x * factor, y * factor, z * factor, w * factor);
       }
       MthVec4<type> &operator/=(type factor)
       {
              atk_assert(factor != (type)0);
              x /= factor;
              y /= factor;
              z /= factor;
              w /= factor;
              return *this;
       }
       MthVec4<type> operator/(type factor) const
       {
              atk_assert(factor != (type)0);
              return MthVec4<type>(x / factor, y / factor, z / factor, w / factor);
       }
       MthVec4<type> &crossDim3(type _x, type _y, type _z)
       {
              type nx = y * _z - z * _y;
              type ny = z * _x - x * _z;
              type nz = x * _y - y * _x;
              x = nx;
              y = ny;
              z = nz;
              return *this;
       }
       MthVec4<type> &crossDim3(const MthVec4<type> &vec)
       {
              return crossDim3(vec.x, vec.y, vec.z);
       }
       type dot(type _x, type _y, type _z, type _w) const
       {
              return x * _x + y * _y + z * _z, w * _w;
       }
       type dot(const MthVec2<type> &vec) const
       {
              return dot(vec.x, vec.y, vec.z, vec.w);
       }
       type len() const
       {
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z + w * w);
       }
       type lenSq() const
       {
              return x * x + y * y + z * z + w * w;
       }
       type lenDim3() const
       {
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z);
       }
       type lenSqDim3() const
       {
              return x * x + y * y + z * z;
       }
       MthVec4<type> &norm()
       {
              type lenght = len();
              atk_assert(lenght != 0);
              x /= lenght;
              y /= lenght;
              z /= lenght;
              w /= lenght;
              return *this;
       }
       MthVec4<type> &normDim3()
       {
              type lenght = lenDim3();
              atk_assert(lenght != 0);
              x /= lenght;
              y /= lenght;
              z /= lenght;
              return *this;
       }
       MthVec4<type> &rotXDim3(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type ny = y * c + z * -s;
              type nz = y * s + z * c;
              y = ny;
              z = nz;
              return *this;
       }
       MthVec4<type> &rotYDim3(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type nx = x * c + z * s;
              type nz = x * -s + z * c;
              x = nx;
              z = nz;
              return *this;
       }
       MthVec4<type> &rotZDim3(float a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type nx = x * c + y * -s;
              type ny = x * s + y * c;
              x = nx;
              y = ny;
              return *this;
       }
};

template <typename type>
struct MthMat2
{
       type m[2][2];

       MthMat2() : m{0, 0, 0, 0}
       {
       }
       MthMat2(type m00, type m01, type m10, type m11) : m{m00, m01, m10, m11}
       {
       }
       MthMat2(const MthMat2<type> &mat) : m{mat.m[0][0], mat.m[0][1], mat.m[1][0], mat.m[1][1]}
       {
       }
       MthMat2<type> &operator=(const MthMat2<type> &mat) = default;
       MthMat2<type> &operator+=(const MthMat2<type> &mat)
       {
              m[0][0] += mat.m[0][0];
              m[0][1] += mat.m[0][1];
              m[1][0] += mat.m[1][0];
              m[1][1] += mat.m[1][1];
              return *this;
       }
       MthMat2<type> operator+(const MthMat2<type> &mat) const
       {
              return MthMat2<type>(m[0][0] + mat.m[0][0], m[0][1] + mat.m[0][1], m[1][0] + mat.m[1][0], m[1][1] + mat.m[1][1]);
       }
       MthMat2<type> &operator-=(const MthMat2<type> &mat)
       {
              m[0][0] -= mat.m[0][0];
              m[0][1] -= mat.m[0][1];
              m[1][0] -= mat.m[1][0];
              m[1][1] -= mat.m[1][1];
              return *this;
       }
       MthMat2<type> operator-(const MthMat2<type> &mat)
       {
              return MthMat2<type>(m[0][0] - mat.m[0][0], m[0][1] - mat.m[0][1], m[1][0] - mat.m[1][0], m[1][1] - mat.m[1][1]);
       }
       MthMat2<type> operator-() const
       {
              return MthMat2<type>(-m[0][0], -m[0][1], -m[1][0], -m[1][1]);
       }
       MthMat2<type> &operator*=(const MthMat2<type> &mat)
       {
              type m00 = m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1];
              type m01 = m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1];
              type m10 = m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1];
              type m11 = m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1];
              m[0][0] = m00;
              m[0][1] = m01;
              m[1][0] = m10;
              m[1][1] = m11;
              return *this;
       }
       MthMat2<type> operator*(const MthMat2<type> &mat)
       {
              return MthMat2<type>(m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1], m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1],
                                   m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1], m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1]);
       }
       MthVec2<type> operator*(const MthVec2<type> &vec) const
       {
              return MthVec2<type>(m[0][0] * vec.x + m[1][0] * vec.y,
                                   m[0][1] * vec.x + m[1][1] * vec.y);
       }
       MthMat2<type> &operator*=(type factor)
       {
              m[0][0] *= factor;
              m[0][1] *= factor;
              m[1][0] *= factor;
              m[1][1] *= factor;
              return *this;
       }
       MthMat2<type> operator*(type factor) const
       {
              return MthMat2<type>(m[0][0] * factor, m[0][1] * factor, m[1][0] * factor, m[1][1] * factor);
       }
       MthMat2<type> &identity()
       {
              m[0][0] = 1;
              m[0][1] = 0;
              m[1][0] = 0;
              m[1][1] = 1;
              return *this;
       }
       MthMat2<type> &transpose()
       {
              type buf10 = m[1][0];
              m[1][0] = m[0][1];
              m[0][1] = buf10;
              return *this;
       }
       MthMat2<type> &scale(type x, type y)
       {
              m[0][0] * x;
              m[0][1] * x;
              m[1][0] * y;
              m[1][1] * y;
              return *this;
       }
       MthMat2<type> &scale(const MthVec2<type> &vec)
       {
              return scale(vec.x, vec.y);
       }
       MthMat2<type> &rotFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[1][0] * s;
              type m01 = m[0][1] * c + m[1][1] * s;
              type m10 = m[0][0] * -s + m[1][0] * c;
              type m11 = m[0][1] * -s + m[1][1] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[1][0] = m10;
              m[1][1] = m11;
              return *this;
       }
       MthMat2<type> &rotSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[0][1] * -s;
              type m01 = m[0][0] * s + m[0][1] * c;
              type m10 = m[1][0] * c + m[1][1] * -s;
              type m11 = m[1][0] * s + m[1][1] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[1][0] = m10;
              m[1][1] = m11;
              return *this;
       }
};

template <typename type>
struct MthMat3
{
       type m[3][3];

       MthMat3() : m{0, 0, 0, 0, 0, 0, 0, 0, 0}
       {
       }
       MthMat3(type m00, type m01, type m02, type m10, type m11, type m12, type m20, type m21, type m22) : m{m00, m01, m02, m10, m11, m12, m20, m21, m22}
       {
       }
       MthMat3(const MthMat3<type> &mat) : m{mat.m[0][0], mat.m[0][1], mat.m[0][2], mat.m[1][0], mat.m[1][1], mat.m[1][2], mat.m[2][0], mat.m[2][1], mat.m[2][2]}
       {
       }
       MthMat3<type> &operator=(const MthMat3<type> &mat) = default;
       MthMat3<type> &operator+=(const MthMat3<type> &mat)
       {
              m[0][0] += mat.m[0][0];
              m[0][1] += mat.m[0][1];
              m[0][2] += mat.m[0][2];
              m[1][0] += mat.m[1][0];
              m[1][1] += mat.m[1][1];
              m[1][2] += mat.m[1][2];
              m[2][0] += mat.m[2][0];
              m[2][1] += mat.m[2][1];
              m[2][2] += mat.m[2][2];
              return *this;
       }
       MthMat3<type> operator+(const MthMat3<type> &mat) const
       {
              return MthMat3<type>(m[0][0] + mat.m[0][0], m[0][1] + mat.m[0][1], m[0][2] + mat.m[0][2],
                                   m[1][0] + mat.m[1][0], m[1][1] + mat.m[1][1], m[1][2] + mat.m[1][2],
                                   m[2][0] + mat.m[2][0], m[2][1] + mat.m[2][1], m[2][2] + mat.m[2][2]);
       }
       MthMat3<type> &operator-=(const MthMat3<type> &mat)
       {
              m[0][0] -= mat.m[0][0];
              m[0][1] -= mat.m[0][1];
              m[0][2] -= mat.m[0][2];
              m[1][0] -= mat.m[1][0];
              m[1][1] -= mat.m[1][1];
              m[1][2] -= mat.m[1][2];
              m[2][0] -= mat.m[2][0];
              m[2][1] -= mat.m[2][1];
              m[2][2] -= mat.m[2][2];
              return *this;
       }
       MthMat3<type> operator-(const MthMat3<type> &mat)
       {
              return MthMat3<type>(m[0][0] - mat.m[0][0], m[0][1] - mat.m[0][1], m[0][2] - mat.m[0][2],
                                   m[1][0] - mat.m[1][0], m[1][1] - mat.m[1][1], m[1][2] - mat.m[1][2],
                                   m[2][0] - mat.m[2][0], m[2][1] - mat.m[2][1], m[2][2] - mat.m[2][2]);
       }
       MthMat3<type> operator-() const
       {
              return MthMat3<type>(-m[0][0], -m[0][1], -m[0][2],
                                   -m[1][0], -m[1][1], -m[1][2],
                                   -m[2][0], -m[2][1], -m[2][2]);
       }
       MthMat3<type> &operator*=(const MthMat3<type> &mat)
       {
              type m00 = m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1] + m[2][0] * mat.m[0][2];
              type m01 = m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1] + m[2][1] * mat.m[0][2];
              type m02 = m[0][2] * mat.m[0][0] + m[1][2] * mat.m[0][1] + m[2][2] * mat.m[0][2];
              type m10 = m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1] + m[2][0] * mat.m[1][2];
              type m11 = m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1] + m[2][1] * mat.m[1][2];
              type m12 = m[0][2] * mat.m[1][0] + m[1][2] * mat.m[1][1] + m[2][2] * mat.m[1][2];
              type m20 = m[0][0] * mat.m[2][0] + m[1][0] * mat.m[2][1] + m[2][0] * mat.m[2][2];
              type m21 = m[0][1] * mat.m[2][0] + m[1][1] * mat.m[2][1] + m[2][1] * mat.m[2][2];
              type m22 = m[0][2] * mat.m[2][0] + m[1][2] * mat.m[2][1] + m[2][2] * mat.m[2][2];
              m[0][0] = m00;
              m[0][1] = m01;
              m[0][2] = m02;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              return *this;
       }
       MthMat3<type> operator*(const MthMat3<type> &mat)
       {
              return MthMat3<type>(m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1] + m[2][0] * mat.m[0][2],
                                   m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1] + m[2][1] * mat.m[0][2],
                                   m[0][2] * mat.m[0][0] + m[1][2] * mat.m[0][1] + m[2][2] * mat.m[0][2],
                                   m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1] + m[2][0] * mat.m[1][2],
                                   m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1] + m[2][1] * mat.m[1][2],
                                   m[0][2] * mat.m[1][0] + m[1][2] * mat.m[1][1] + m[2][2] * mat.m[1][2],
                                   m[0][0] * mat.m[2][0] + m[1][0] * mat.m[2][1] + m[2][0] * mat.m[2][2],
                                   m[0][1] * mat.m[2][0] + m[1][1] * mat.m[2][1] + m[2][1] * mat.m[2][2],
                                   m[0][2] * mat.m[2][0] + m[1][2] * mat.m[2][1] + m[2][2] * mat.m[2][2]);
       }
       MthVec3<type> operator*(const MthVec3<type> &vec) const
       {
              return MthVec3<type>(m[0][0] * vec.x + m[1][0] * vec.y + m[2][0] * vec.z,
                                   m[0][1] * vec.x + m[1][1] * vec.y + m[2][1] * vec.z,
                                   m[0][2] * vec.x + m[1][2] * vec.y + m[2][2] * vec.z);
       }
       MthMat3<type> &operator*=(type factor)
       {
              m[0][0] *= factor;
              m[0][1] *= factor;
              m[0][2] *= factor;
              m[1][0] *= factor;
              m[1][1] *= factor;
              m[1][2] *= factor;
              m[2][0] *= factor;
              m[2][1] *= factor;
              m[2][2] *= factor;
              return *this;
       }
       MthMat3<type> operator*(type factor) const
       {
              return MthMat3<type>(m[0][0] * factor,
                                   m[0][1] * factor,
                                   m[0][2] * factor,
                                   m[1][0] * factor,
                                   m[1][1] * factor,
                                   m[1][2] * factor,
                                   m[2][0] * factor,
                                   m[2][1] * factor,
                                   m[2][2] * factor);
       }
       MthMat3<type> &identity()
       {
              m[0][0] = 1;
              m[0][1] = 0;
              m[0][2] = 0;
              m[1][0] = 0;
              m[1][1] = 1;
              m[1][2] = 0;
              m[2][0] = 0;
              m[2][1] = 0;
              m[2][2] = 1;
              return *this;
       }
       MthMat3<type> &transpose()
       {
              type buf10 = m[1][0];
              m[1][0] = m[0][1];
              m[0][1] = buf10;
              type buf20 = m[2][0];
              m[2][0] = m[0][2];
              m[0][2] = buf20;
              type buf21 = m[2][1];
              m[2][1] = m[1][2];
              m[1][2] = buf21;
              return *this;
       }
       MthMat3<type> &scale(type x, type y, type z)
       {
              m[0][0] *= x;
              m[0][1] *= x;
              m[0][2] *= x;
              m[1][0] *= y;
              m[1][1] *= y;
              m[1][2] *= y;
              m[2][0] *= z;
              m[2][1] *= z;
              m[2][2] *= z;
              return *this;
       }
       MthMat3<type> &scale(const MthVec3<type> &vec)
       {
              return scale(vec.x, vec.y, vec.z);
       }
       MthMat3<type> &rotXFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m10 = m[1][0] * c + m[2][0] * s;
              type m11 = m[1][1] * c + m[2][1] * s;
              type m12 = m[1][2] * c + m[2][2] * s;
              type m20 = m[1][0] * -s + m[2][0] * c;
              type m21 = m[1][1] * -s + m[2][1] * c;
              type m22 = m[1][2] * -s + m[2][2] * c;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              return *this;
       }
       MthMat3<type> &rotXSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m01 = m[0][1] * c + m[0][2] * -s;
              type m02 = m[0][1] * s + m[0][2] * c;
              type m11 = m[1][1] * c + m[1][2] * -s;
              type m12 = m[1][1] * s + m[1][2] * c;
              type m21 = m[2][1] * c + m[2][2] * -s;
              type m22 = m[2][1] * s + m[2][2] * c;
              m[0][1] = m01;
              m[0][2] = m02;
              m[1][1] = m11;
              m[1][2] = m12;
              m[2][1] = m21;
              m[2][2] = m22;
              return *this;
       }
       MthMat3<type> &rotYFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[2][0] * -s;
              type m01 = m[0][1] * c + m[2][1] * -s;
              type m02 = m[0][2] * c + m[2][2] * -s;
              type m20 = m[0][0] * s + m[2][0] * c;
              type m21 = m[0][1] * s + m[2][1] * c;
              type m22 = m[0][2] * s + m[2][2] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[0][2] = m02;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              return *this;
       }
       MthMat3<type> &rotYSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[0][2] * s;
              type m02 = m[0][0] * -s + m[0][2] * c;
              type m10 = m[1][0] * c + m[1][2] * s;
              type m12 = m[1][0] * -s + m[1][2] * c;
              type m20 = m[2][0] * c + m[2][2] * s;
              type m22 = m[2][0] * -s + m[2][2] * c;
              m[0][0] = m00;
              m[0][2] = m02;
              m[1][0] = m10;
              m[1][2] = m12;
              m[2][0] = m20;
              m[2][2] = m22;
              return *this;
       }
       MthMat3<type> &rotZFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[1][0] * s;
              type m01 = m[0][1] * c + m[1][1] * s;
              type m02 = m[0][2] * c + m[1][2] * s;
              type m10 = m[0][0] * -s + m[1][0] * c;
              type m11 = m[0][1] * -s + m[1][1] * c;
              type m12 = m[0][2] * -s + m[1][2] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[0][2] = m02;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              return *this;
       }
       MthMat3<type> &rotZSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[0][1] * -s;
              type m01 = m[0][0] * s + m[0][1] * c;
              type m10 = m[1][0] * c + m[1][1] * -s;
              type m11 = m[1][0] * s + m[1][1] * c;
              type m20 = m[2][0] * c + m[2][1] * -s;
              type m21 = m[2][0] * s + m[2][1] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[1][0] = m10;
              m[1][1] = m11;
              m[2][0] = m20;
              m[2][1] = m21;
              return *this;
       }
};

template <typename type>
struct MthMat4
{
       type m[4][4];

       MthMat4() : m{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
       {
       }
       MthMat4(type m00, type m01, type m02, type m03,
               type m10, type m11, type m12, type m13,
               type m20, type m21, type m22, type m23,
               type m30, type m31, type m32, type m33) : m{m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33}
       {
       }
       MthMat4(const MthMat4<type> &mat) : m{mat.m[0][0], mat.m[0][1], mat.m[0][2], mat.m[0][3], mat.m[1][0], mat.m[1][1], mat.m[1][2], mat.m[1][3], mat.m[2][0], mat.m[2][1], mat.m[2][2], mat.m[2][3],
                                             mat.m[2][0], mat.m[2][1], mat.m[2][2], mat.m[3][3]}
       {
       }
       MthMat4<type> &operator=(const MthMat4<type> &mat) = default;
       MthMat4<type> &operator+=(const MthMat4<type> &mat)
       {
              m[0][0] += mat.m[0][0];
              m[0][1] += mat.m[0][1];
              m[0][2] += mat.m[0][2];
              m[0][3] += mat.m[0][3];
              m[1][0] += mat.m[1][0];
              m[1][1] += mat.m[1][1];
              m[1][2] += mat.m[1][2];
              m[1][3] += mat.m[1][3];
              m[2][0] += mat.m[2][0];
              m[2][1] += mat.m[2][1];
              m[2][2] += mat.m[2][2];
              m[2][3] += mat.m[2][3];
              m[3][0] += mat.m[3][0];
              m[3][1] += mat.m[3][1];
              m[3][2] += mat.m[3][2];
              m[3][3] += mat.m[3][3];
              return *this;
       }
       MthMat4<type> operator+(const MthMat4<type> &mat) const
       {
              return MthMat4<type>(m[0][0] + mat.m[0][0],
                                   m[0][1] + mat.m[0][1],
                                   m[0][2] + mat.m[0][2],
                                   m[0][3] + mat.m[0][3],
                                   m[1][0] + mat.m[1][0],
                                   m[1][1] + mat.m[1][1],
                                   m[1][2] + mat.m[1][2],
                                   m[1][3] + mat.m[1][3],
                                   m[2][0] + mat.m[2][0],
                                   m[2][1] + mat.m[2][1],
                                   m[2][2] + mat.m[2][2],
                                   m[2][3] + mat.m[2][3],
                                   m[3][0] + mat.m[3][0],
                                   m[3][1] + mat.m[3][1],
                                   m[3][2] + mat.m[3][2],
                                   m[3][3] + mat.m[3][3]);
       }
       MthMat4<type> &operator-=(const MthMat4<type> &mat)
       {
              m[0][0] += mat.m[0][0];
              m[0][1] += mat.m[0][1];
              m[0][2] += mat.m[0][2];
              m[0][3] += mat.m[0][3];
              m[1][0] += mat.m[1][0];
              m[1][1] += mat.m[1][1];
              m[1][2] += mat.m[1][2];
              m[1][3] += mat.m[1][3];
              m[2][0] += mat.m[2][0];
              m[2][1] += mat.m[2][1];
              m[2][2] += mat.m[2][2];
              m[2][3] += mat.m[2][3];
              m[3][0] += mat.m[3][0];
              m[3][1] += mat.m[3][1];
              m[3][2] += mat.m[3][2];
              m[3][3] += mat.m[3][3];
              return *this;
       }
       MthMat4<type> operator-(const MthMat4<type> &mat)
       {
              return MthMat4<type>(m[0][0] - mat.m[0][0],
                                   m[0][1] - mat.m[0][1],
                                   m[0][2] - mat.m[0][2],
                                   m[0][3] - mat.m[0][3],
                                   m[1][0] - mat.m[1][0],
                                   m[1][1] - mat.m[1][1],
                                   m[1][2] - mat.m[1][2],
                                   m[1][3] - mat.m[1][3],
                                   m[2][0] - mat.m[2][0],
                                   m[2][1] - mat.m[2][1],
                                   m[2][2] - mat.m[2][2],
                                   m[2][3] - mat.m[2][3],
                                   m[3][0] - mat.m[3][0],
                                   m[3][1] - mat.m[3][1],
                                   m[3][2] - mat.m[3][2],
                                   m[3][3] - mat.m[3][3]);
       }
       MthMat4<type> operator-() const
       {
              return MthMat4<type>(-m[0][0], -m[0][1], -m[0][2], -m[0][3],
                                   -m[1][0], -m[1][1], -m[1][2], -m[1][3],
                                   -m[2][0], -m[2][1], -m[2][2], -m[2][3],
                                   -m[3][0], -m[3][1], -m[3][2], -m[3][3]);
       }
       MthMat4<type> &operator*=(const MthMat4<type> &mat)
       {
              type m00 = m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1] + m[2][0] * mat.m[0][2] + m[3][0] * mat.m[0][3];
              type m01 = m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1] + m[2][1] * mat.m[0][2] + m[3][1] * mat.m[0][3];
              type m02 = m[0][2] * mat.m[0][0] + m[1][2] * mat.m[0][1] + m[2][2] * mat.m[0][2] + m[3][2] * mat.m[0][3];
              type m03 = m[0][3] * mat.m[0][0] + m[1][3] * mat.m[0][1] + m[2][3] * mat.m[0][2] + m[3][3] * mat.m[0][3];
              type m10 = m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1] + m[2][0] * mat.m[1][2] + m[3][0] * mat.m[1][3];
              type m11 = m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1] + m[2][1] * mat.m[1][2] + m[3][1] * mat.m[1][3];
              type m12 = m[0][2] * mat.m[1][0] + m[1][2] * mat.m[1][1] + m[2][2] * mat.m[1][2] + m[3][2] * mat.m[1][3];
              type m13 = m[0][3] * mat.m[1][0] + m[1][3] * mat.m[1][1] + m[2][3] * mat.m[1][2] + m[3][3] * mat.m[1][3];
              type m20 = m[0][0] * mat.m[2][0] + m[1][0] * mat.m[2][1] + m[2][0] * mat.m[2][2] + m[3][0] * mat.m[2][3];
              type m21 = m[0][1] * mat.m[2][0] + m[1][1] * mat.m[2][1] + m[2][1] * mat.m[2][2] + m[3][1] * mat.m[2][3];
              type m22 = m[0][2] * mat.m[2][0] + m[1][2] * mat.m[2][1] + m[2][2] * mat.m[2][2] + m[3][2] * mat.m[2][3];
              type m23 = m[0][3] * mat.m[2][0] + m[1][3] * mat.m[2][1] + m[2][3] * mat.m[2][2] + m[3][3] * mat.m[2][3];
              type m30 = m[0][0] * mat.m[3][0] + m[1][0] * mat.m[3][1] + m[2][0] * mat.m[3][2] + m[3][0] * mat.m[3][3];
              type m31 = m[0][1] * mat.m[3][0] + m[1][1] * mat.m[3][1] + m[2][1] * mat.m[3][2] + m[3][1] * mat.m[3][3];
              type m32 = m[0][2] * mat.m[3][0] + m[1][2] * mat.m[3][1] + m[2][2] * mat.m[3][2] + m[3][2] * mat.m[3][3];
              type m33 = m[0][3] * mat.m[3][0] + m[1][3] * mat.m[3][1] + m[2][3] * mat.m[3][2] + m[3][3] * mat.m[3][3];
              m[0][0] = m00;
              m[0][0] = m01;
              m[0][0] = m02;
              m[0][0] = m03;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              m[1][3] = m13;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              m[2][3] = m23;
              m[3][0] = m30;
              m[3][1] = m31;
              m[3][2] = m32;
              m[3][3] = m33;
              return *this;
       }
       MthMat4<type> operator*(const MthMat4<type> &mat)
       {
              return MthMat4<type>(m[0][0] * mat.m[0][0] + m[1][0] * mat.m[0][1] + m[2][0] * mat.m[0][2] + m[3][0] * mat.m[0][3],
                                   m[0][1] * mat.m[0][0] + m[1][1] * mat.m[0][1] + m[2][1] * mat.m[0][2] + m[3][1] * mat.m[0][3],
                                   m[0][2] * mat.m[0][0] + m[1][2] * mat.m[0][1] + m[2][2] * mat.m[0][2] + m[3][2] * mat.m[0][3],
                                   m[0][3] * mat.m[0][0] + m[1][3] * mat.m[0][1] + m[2][3] * mat.m[0][2] + m[3][3] * mat.m[0][3],
                                   m[0][0] * mat.m[1][0] + m[1][0] * mat.m[1][1] + m[2][0] * mat.m[1][2] + m[3][0] * mat.m[1][3],
                                   m[0][1] * mat.m[1][0] + m[1][1] * mat.m[1][1] + m[2][1] * mat.m[1][2] + m[3][1] * mat.m[1][3],
                                   m[0][2] * mat.m[1][0] + m[1][2] * mat.m[1][1] + m[2][2] * mat.m[1][2] + m[3][2] * mat.m[1][3],
                                   m[0][3] * mat.m[1][0] + m[1][3] * mat.m[1][1] + m[2][3] * mat.m[1][2] + m[3][3] * mat.m[1][3],
                                   m[0][0] * mat.m[2][0] + m[1][0] * mat.m[2][1] + m[2][0] * mat.m[2][2] + m[3][0] * mat.m[2][3],
                                   m[0][1] * mat.m[2][0] + m[1][1] * mat.m[2][1] + m[2][1] * mat.m[2][2] + m[3][1] * mat.m[2][3],
                                   m[0][2] * mat.m[2][0] + m[1][2] * mat.m[2][1] + m[2][2] * mat.m[2][2] + m[3][2] * mat.m[2][3],
                                   m[0][3] * mat.m[2][0] + m[1][3] * mat.m[2][1] + m[2][3] * mat.m[2][2] + m[3][3] * mat.m[2][3],
                                   m[0][0] * mat.m[3][0] + m[1][0] * mat.m[3][1] + m[2][0] * mat.m[3][2] + m[3][0] * mat.m[3][3],
                                   m[0][1] * mat.m[3][0] + m[1][1] * mat.m[3][1] + m[2][1] * mat.m[3][2] + m[3][1] * mat.m[3][3],
                                   m[0][2] * mat.m[3][0] + m[1][2] * mat.m[3][1] + m[2][2] * mat.m[3][2] + m[3][2] * mat.m[3][3],
                                   m[0][3] * mat.m[3][0] + m[1][3] * mat.m[3][1] + m[2][3] * mat.m[3][2] + m[3][3] * mat.m[3][3]);
       }
       MthVec4<type> operator*(const MthVec3<type> &vec) const
       {
              return MthVec4<type>(m[0][0] * vec.x + m[1][0] * vec.y + m[2][0] * vec.z + m[3][0] * vec.w,
                                   m[0][1] * vec.x + m[1][1] * vec.y + m[2][1] * vec.z + m[3][1] * vec.w,
                                   m[0][2] * vec.x + m[1][2] * vec.y + m[2][2] * vec.z + m[3][2] * vec.w,
                                   m[0][3] * vec.x + m[1][3] * vec.y + m[2][3] * vec.z + m[3][3] * vec.w);
       }
       MthMat4<type> &operator*=(type factor)
       {
              m[0][0] *= factor;
              m[0][1] *= factor;
              m[0][2] *= factor;
              m[0][3] *= factor;
              m[1][0] *= factor;
              m[1][1] *= factor;
              m[1][2] *= factor;
              m[1][3] *= factor;
              m[2][0] *= factor;
              m[2][1] *= factor;
              m[2][2] *= factor;
              m[2][3] *= factor;
              m[3][0] *= factor;
              m[3][1] *= factor;
              m[3][2] *= factor;
              m[3][3] *= factor;
              return *this;
       }
       MthMat4<type> operator*(type factor) const
       {
              return MthMat4<type>(m[0][0] * factor,
                                   m[0][1] * factor,
                                   m[0][2] * factor,
                                   m[0][3] * factor,
                                   m[1][0] * factor,
                                   m[1][1] * factor,
                                   m[1][2] * factor,
                                   m[1][3] * factor,
                                   m[2][0] * factor,
                                   m[2][1] * factor,
                                   m[2][2] * factor,
                                   m[2][3] * factor,
                                   m[3][0] * factor,
                                   m[3][1] * factor,
                                   m[3][2] * factor,
                                   m[3][3] * factor);
       }
       MthMat4<type> &identity()
       {
              m[0][0] = 1;
              m[0][1] = 0;
              m[0][2] = 0;
              m[0][3] = 0;
              m[1][0] = 0;
              m[1][1] = 1;
              m[1][2] = 0;
              m[1][3] = 0;
              m[2][0] = 0;
              m[2][1] = 0;
              m[2][2] = 1;
              m[2][3] = 0;
              m[3][0] = 0;
              m[3][1] = 0;
              m[3][2] = 0;
              m[3][3] = 1;
              return *this;
       }
       MthMat4<type> &transpose()
       {
              type buf10 = m[1][0];
              m[1][0] = m[0][1];
              m[1][1] = buf10;
              type buf20 = m[2][0];
              m[2][0] = m[0][2];
              m[0][2] = buf20;
              type buf30 = m[3][0];
              m[3][0] = m[0][3];
              m[0][3] = buf30;
              type buf21 = m[2][1];
              m[2][1] = m[1][2];
              m[1][2] = buf21;
              type buf31 = m[3][1];
              m[3][1] = m[1][3];
              m[1][3] = buf31;
              type buf32 = m[3][2];
              m[3][2] = m[2][3];
              m[2][3] = buf32;
              return *this;
       }
       MthMat4<type> &scale(type x, type y, type z, type w)
       {
              m[0][0] *= x;
              m[0][1] *= x;
              m[0][2] *= x;
              m[0][3] *= x;
              m[1][0] *= y;
              m[1][1] *= y;
              m[1][2] *= y;
              m[1][3] *= y;
              m[2][0] *= z;
              m[2][1] *= z;
              m[2][2] *= z;
              m[2][3] *= z;
              m[3][0] *= w;
              m[3][1] *= w;
              m[3][2] *= w;
              m[3][3] *= w;
              return *this;
       }
       MthMat4<type> &scale(const MthVec4<type> &vec)
       {
              return scale(vec.x, vec.y, vec.z, vec.w);
       }
       MthMat4<type> &scaleDim3(type x, type y, type z)
       {
              m[0][0] *= x;
              m[0][1] *= x;
              m[0][2] *= x;
              m[0][3] *= x;
              m[1][0] *= y;
              m[1][1] *= y;
              m[1][2] *= y;
              m[1][3] *= y;
              m[2][0] *= z;
              m[2][1] *= z;
              m[2][2] *= z;
              m[2][3] *= z;
              return *this;
       }
       MthMat4<type> &scaleDim3(const MthVec3<type> &vec)
       {
              return scaleDim3(vec.x, vec.y, vec.z);
       }
       MthMat4<type> &rotXFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m10 = m[1][0] * c + m[2][0] * s;
              type m11 = m[1][1] * c + m[2][1] * s;
              type m12 = m[1][2] * c + m[2][2] * s;
              type m13 = m[1][3] * c + m[2][3] * s;
              type m20 = m[1][0] * -s + m[2][0] * c;
              type m21 = m[1][1] * -s + m[2][1] * c;
              type m22 = m[1][2] * -s + m[2][2] * c;
              type m23 = m[1][3] * -s + m[2][3] * c;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              m[1][3] = m13;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              m[2][3] = m23;
              return *this;
       }
       MthMat4<type> &rotXSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m01 = m[0][1] * c + m[0][2] * -s;
              type m02 = m[0][1] * s + m[0][2] * c;
              type m11 = m[1][1] * c + m[1][2] * -s;
              type m12 = m[1][1] * s + m[1][2] * c;
              type m21 = m[2][1] * c + m[2][2] * -s;
              type m22 = m[2][1] * s + m[2][2] * c;
              type m31 = m[3][1] * c + m[3][2] * -s;
              type m32 = m[3][1] * s + m[3][2] * c;
              m[0][1] = m01;
              m[0][2] = m02;
              m[1][1] = m11;
              m[1][2] = m12;
              m[2][1] = m21;
              m[2][2] = m22;
              m[3][1] = m31;
              m[3][2] = m32;
              return *this;
       }
       MthMat4<type> &rotYFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[2][0] * -s;
              type m01 = m[0][1] * c + m[2][1] * -s;
              type m02 = m[0][2] * c + m[2][2] * -s;
              type m03 = m[0][3] * c + m[2][3] * -s;
              type m20 = m[0][0] * s + m[2][0] * c;
              type m21 = m[0][1] * s + m[2][1] * c;
              type m22 = m[0][2] * s + m[2][2] * c;
              type m23 = m[0][3] * s + m[2][3] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[0][2] = m02;
              m[0][3] = m03;
              m[2][0] = m20;
              m[2][1] = m21;
              m[2][2] = m22;
              m[2][3] = m23;
              return *this;
       }
       MthMat4<type> &rotYSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[0][2] * s;
              type m02 = m[0][0] * -s + m[0][2] * c;
              type m10 = m[1][0] * c + m[1][2] * s;
              type m12 = m[1][0] * -s + m[1][2] * c;
              type m20 = m[2][0] * c + m[2][2] * s;
              type m22 = m[2][0] * -s + m[2][2] * c;
              type m30 = m[3][0] * c + m[3][2] * s;
              type m32 = m[3][0] * -s + m[3][2] * c;
              m[0][0] = m00;
              m[0][2] = m02;
              m[1][0] = m10;
              m[1][2] = m12;
              m[2][0] = m20;
              m[2][2] = m22;
              m[3][0] = m30;
              m[3][2] = m32;
              return *this;
       }
       MthMat4<type> &rotZFst(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[1][0] * s;
              type m01 = m[0][1] * c + m[1][1] * s;
              type m02 = m[0][2] * c + m[1][2] * s;
              type m03 = m[0][3] * c + m[1][3] * s;
              type m10 = m[0][0] * -s + m[1][0] * c;
              type m11 = m[0][1] * -s + m[1][1] * c;
              type m12 = m[0][2] * -s + m[1][2] * c;
              type m13 = m[0][3] * -s + m[1][3] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[0][2] = m02;
              m[0][3] = m03;
              m[1][0] = m10;
              m[1][1] = m11;
              m[1][2] = m12;
              m[1][3] = m13;
              return *this;
       }
       MthMat4<type> &rotZSec(type a)
       {
              type c = (type)cosf(a);
              type s = (type)sinf(a);
              type m00 = m[0][0] * c + m[0][1] * -s;
              type m01 = m[0][0] * s + m[0][1] * c;
              type m10 = m[1][0] * c + m[1][1] * -s;
              type m11 = m[1][0] * s + m[1][1] * c;
              type m20 = m[2][0] * c + m[2][1] * -s;
              type m21 = m[2][0] * s + m[2][1] * c;
              type m30 = m[3][0] * c + m[3][1] * -s;
              type m31 = m[3][0] * s + m[3][1] * c;
              m[0][0] = m00;
              m[0][1] = m01;
              m[1][0] = m10;
              m[1][1] = m11;
              m[2][0] = m20;
              m[2][1] = m21;
              m[3][0] = m30;
              m[3][1] = m31;
              return *this;
       }
       MthMat4<type> &translateFst(type x, type y, type z, type w)
       {
              m[3][0] = m[0][0] * x + m[1][0] * y + m[2][0] * z + m[3][0] * w;
              m[3][1] = m[0][1] * x + m[1][1] * y + m[2][1] * z + m[3][1] * w;
              m[3][2] = m[0][2] * x + m[1][2] * y + m[2][2] * z + m[3][2] * w;
              m[3][3] = m[0][3] * x + m[1][3] * y + m[2][3] * z + m[3][3] * w;
              return *this;
       }
       MthMat4<type> &translateFst(const MthVec4<type> &vec)
       {
              return translateFst(vec.x, vec.y, vec.z, vec.w);
       }
       MthMat4<type> &translateSec(type x, type y, type z, type w)
       {
              m[0][0] = m[0][0] + x * m[0][3];
              m[0][1] = m[0][1] + y * m[0][3];
              m[0][2] = m[0][2] + z * m[0][3];
              m[0][3] = w * m[0][3];
              m[1][0] = m[1][0] + x * m[1][3];
              m[1][1] = m[1][1] + y * m[1][3];
              m[1][2] = m[1][2] + z * m[1][3];
              m[1][3] = w * m[1][3];
              m[2][0] = m[2][0] + x * m[2][3];
              m[2][1] = m[2][1] + y * m[2][3];
              m[2][2] = m[2][2] + z * m[2][3];
              m[2][3] = w * m[2][3];
              m[3][0] = m[3][0] + x * m[3][3];
              m[3][1] = m[3][1] + y * m[3][3];
              m[3][2] = m[3][2] + z * m[3][3];
              m[3][3] = w * m[3][3];
              return *this;
       }
       MthMat4<type> &translateSec(const MthVec4<type> &vec)
       {
              return translateSec(vec.x, vec.y, vec.z, vec.w);
       }
       MthMat4<type> &translateFstDim3(type x, type y, type z)
       {
              m[3][0] = m[0][0] * x + m[1][0] * y + m[2][0] * z + m[3][0];
              m[3][1] = m[0][1] * x + m[1][1] * y + m[2][1] * z + m[3][1];
              m[3][2] = m[0][2] * x + m[1][2] * y + m[2][2] * z + m[3][2];
              m[3][3] = m[0][3] * x + m[1][3] * y + m[2][3] * z + m[3][3];
              return *this;
       }
       MthMat4<type> &translateFstDim3(const MthVec3<type> &vec)
       {
              return translateFstDim3(vec.x, vec.y, vec.z);
       }
       MthMat4<type> &translateSecDim3(type x, type y, type z)
       {
              m[0][0] = m[0][0] + x * m[0][3];
              m[0][1] = m[0][1] + y * m[0][3];
              m[0][2] = m[0][2] + z * m[0][3];
              m[1][0] = m[1][0] + x * m[1][3];
              m[1][1] = m[1][1] + y * m[1][3];
              m[1][2] = m[1][2] + z * m[1][3];
              m[2][0] = m[2][0] + x * m[2][3];
              m[2][1] = m[2][1] + y * m[2][3];
              m[2][2] = m[2][2] + z * m[2][3];
              m[3][0] = m[3][0] + x * m[3][3];
              m[3][1] = m[3][1] + y * m[3][3];
              m[3][2] = m[3][2] + z * m[3][3];
              return *this;
       }
       MthMat4<type> &translateSecDim3(const MthVec4<type> &vec)
       {
              return translateSecDim3(vec.x, vec.y, vec.z);
       }
       MthMat4<type> &perspective(type width, type height, type fov, type znear, type zfar)
       {
              type aspect = width / height;
              type tan_half_fov = (type)tanf(fov / 2.0f);
              type range = znear - zfar;
              m[0][0] = 1 / (aspect * tan_half_fov);
              m[0][1] = 0;
              m[0][2] = 0;
              m[0][3] = 0;
              m[1][0] = 0;
              m[1][1] = 1 / tan_half_fov;
              m[1][2] = 0;
              m[1][3] = 0;
              m[2][0] = 0;
              m[2][1] = 0;
              m[2][2] = (-znear - zfar) / range;
              m[2][3] = 1;
              m[3][0] = 0;
              m[3][1] = 0;
              m[3][2] = ((type)2 * zfar * znear) / range;
              m[3][3] = 0;
              return *this;
       }
};

typedef MthVec2<float> MthVec2f;
typedef MthVec2<double> MthVec2d;
typedef MthVec2<int> MthVec2i;

typedef MthVec3<float> MthVec3f;
typedef MthVec3<double> MthVec3d;
typedef MthVec3<int> MthVec3i;

typedef MthVec4<float> MthVec4f;
typedef MthVec4<double> MthVec4d;
typedef MthVec4<int> MthVec4i;

typedef MthMat2<float> MthMat2f;
typedef MthMat2<double> MthMat2d;
typedef MthMat2<int> MthMat2i;

typedef MthMat3<float> MthMat3f;
typedef MthMat3<double> MthMat3d;
typedef MthMat3<int> MthMat3i;

typedef MthMat4<float> MthMat4f;
typedef MthMat4<double> MthMat4d;
typedef MthMat4<int> MthMat4i;

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