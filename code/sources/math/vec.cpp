#include "../../include/atk_math.h"

#define MTH_DEF_VEC2(type, t)                                        \
       MthVec2##t::MthVec2##t()                                      \
       {                                                             \
              x = 0;                                                 \
              y = 0;                                                 \
       }                                                             \
       MthVec2##t::MthVec2##t(type _x, type _y)                      \
       {                                                             \
              x = _x;                                                \
              y = _y;                                                \
       }                                                             \
       MthVec2##t::MthVec2##t(const MthVec2##t &vec)                 \
       {                                                             \
              x = vec.x;                                             \
              y = vec.y;                                             \
       }                                                             \
       MthVec2##t::MthVec2##t(const AtkPack2##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
       }\
       bool MthVec2##t::operator==(const MthVec2##t &vec) const      \
       {                                                             \
              return x == vec.x && y == vec.y;                       \
       }                                                             \
       bool MthVec2##t::operator!=(const MthVec2##t &vec) const      \
       {                                                             \
              return x != vec.x || y != vec.y;                       \
       }                                                             \
       MthVec2##t &MthVec2##t::operator=(const AtkPack2##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
              return *this;\
       }\
       MthVec2##t &MthVec2##t::operator+=(const MthVec2##t &vec)     \
       {                                                             \
              x += vec.x;                                            \
              y += vec.y;                                            \
              return *this;                                          \
       }                                                             \
       MthVec2##t MthVec2##t::operator+(const MthVec2##t &vec) const \
       {                                                             \
              return MthVec2##t(x + vec.x, y + vec.y);               \
       }                                                             \
       MthVec2##t &MthVec2##t::operator-=(const MthVec2##t &vec)     \
       {                                                             \
              x -= vec.x;                                            \
              y -= vec.y;                                            \
              return *this;                                          \
       }                                                             \
       MthVec2##t MthVec2##t::operator-(const MthVec2##t &vec) const \
       {                                                             \
              return MthVec2##t(x - vec.x, y - vec.y);               \
       }                                                             \
       MthVec2##t MthVec2##t::operator-() const                      \
       {                                                             \
              return MthVec2##t(-x, -y);                             \
       }                                                             \
       MthVec2##t &MthVec2##t::operator*=(type factor)               \
       {                                                             \
              x *= factor;                                           \
              y *= factor;                                           \
              return *this;                                          \
       }                                                             \
       MthVec2##t MthVec2##t::operator*(type factor) const           \
       {                                                             \
              return MthVec2##t(x * factor, y * factor);             \
       }                                                             \
       MthVec2##t &MthVec2##t::operator/=(type factor)               \
       {                                                             \
              atk_assert(factor != (type)0);                         \
              x /= factor;                                           \
              y /= factor;                                           \
              return *this;                                          \
       }                                                             \
       MthVec2##t MthVec2##t::operator/(type factor) const           \
       {                                                             \
              atk_assert(factor != (type)0);                         \
              return MthVec2##t(x / factor, y / factor);             \
       }                                                             \
       type MthVec2##t::dot(type _x, type _y) const                  \
       {                                                             \
              return x * _x + y * _y;                                \
       }                                                             \
       type MthVec2##t::dot(const MthVec2##t &vec) const             \
       {                                                             \
              return dot(vec.x, vec.y);                              \
       }                                                             \
       type MthVec2##t::len() const                                  \
       {                                                             \
              return (type)1.0 / (type)rsqrtssf(x * x + y * y);      \
       }                                                             \
       type MthVec2##t::lenSq() const                                \
       {                                                             \
              return x * x + y * y;                                  \
       }                                                             \
       MthVec2##t &MthVec2##t::norm()                                \
       {                                                             \
              type lenght = len();                                   \
              atk_assert(lenght != 0);                               \
              x /= lenght;                                           \
              y /= lenght;                                           \
              return *this;                                          \
       }                                                             \
       MthVec2##t &MthVec2##t::ortho()                               \
       {                                                             \
              type buf = x;                                          \
              x = -y;                                                \
              y = buf;                                               \
              return *this;                                          \
       }                                                             \
       MthVec2##t &MthVec2##t::rot(type a)                           \
       {                                                             \
              type c = (type)cosf(a);                                \
              type s = (type)sinf(a);                                \
              type nx = x * c + y * -s;                              \
              type ny = x * s + y * c;                               \
              x = nx;                                                \
              y = ny;                                                \
              return *this;                                          \
       }
#define MTH_DEF_VEC3(type, t)                                                                         \
       MthVec3##t::MthVec3##t()                                                                       \
       {                                                                                              \
              x = 0;                                                                                  \
              y = 0;                                                                                  \
              z = 0;                                                                                  \
       }                                                                                              \
       MthVec3##t::MthVec3##t(type _x, type _y, type _z)                                              \
       {                                                                                              \
              x = _x;                                                                                 \
              y = _y;                                                                                 \
              z = _z;                                                                                 \
       }                                                                                              \
       MthVec3##t::MthVec3##t(const MthVec3##t &vec)                                                  \
       {                                                                                              \
              x = vec.x;                                                                              \
              y = vec.y;                                                                              \
              z = vec.z;                                                                              \
       }                                                                                              \
       MthVec3##t::MthVec3##t(const AtkPack3##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
              z = pack.z;\
       }\
       bool MthVec3##t::operator==(const MthVec3##t &vec) const                                       \
       {                                                                                              \
              return x == vec.x && y == vec.y && z == vec.z;                                          \
       }                                                                                              \
       bool MthVec3##t::operator!=(const MthVec3##t &vec) const                                       \
       {                                                                                              \
              return x != vec.x || y != vec.y || z != vec.z;                                          \
       }                                                                                              \
       MthVec3##t &MthVec3##t::operator=(const AtkPack3##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
              z = pack.z;\
              return *this;\
       }\
       MthVec3##t &MthVec3##t::operator+=(const MthVec3##t &vec)                                      \
       {                                                                                              \
              x += vec.x;                                                                             \
              y += vec.y;                                                                             \
              z += vec.z;                                                                             \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator+(const MthVec3##t &vec) const                                  \
       {                                                                                              \
              return MthVec3##t(x + vec.x, y + vec.y, z + vec.z);                                     \
       }                                                                                              \
       MthVec3##t &MthVec3##t::operator-=(const MthVec3##t &vec)                                      \
       {                                                                                              \
              x -= vec.x;                                                                             \
              y -= vec.y;                                                                             \
              z -= vec.z;                                                                             \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator-(const MthVec3##t &vec) const                                  \
       {                                                                                              \
              return MthVec3##t(x - vec.x, y - vec.y, z - vec.z);                                     \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator-() const                                                       \
       {                                                                                              \
              return MthVec3##t(-x, -y, -z);                                                          \
       }                                                                                              \
       MthVec3##t &MthVec3##t::operator*=(type factor)                                                \
       {                                                                                              \
              x *= factor;                                                                            \
              y *= factor;                                                                            \
              z *= factor;                                                                            \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator*(type factor) const                                            \
       {                                                                                              \
              return MthVec3##t(x * factor, y * factor, z * factor);                                  \
       }                                                                                              \
       MthVec3##t &MthVec3##t::operator*=(const MthVec3##t &vec)                                      \
       {                                                                                              \
              type nx = y * vec.z - z * vec.y;                                                        \
              type ny = z * vec.x - x * vec.z;                                                        \
              type nz = x * vec.y - y * vec.x;                                                        \
              x = nx;                                                                                 \
              y = ny;                                                                                 \
              z = nz;                                                                                 \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator*(const MthVec3##t &vec) const                                  \
       {                                                                                              \
              return MthVec3##t(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x); \
       }                                                                                              \
       MthVec3##t &MthVec3##t::operator/=(type factor)                                                \
       {                                                                                              \
              atk_assert(factor != (type)0);                                                          \
              x /= factor;                                                                            \
              y /= factor;                                                                            \
              z /= factor;                                                                            \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t MthVec3##t::operator/(type factor) const                                            \
       {                                                                                              \
              atk_assert(factor != (type)0);                                                          \
              return MthVec3##t(x / factor, y / factor, z / factor);                                  \
       }                                                                                              \
       type MthVec3##t::dot(type _x, type _y, type _z) const                                          \
       {                                                                                              \
              return x * _x + y * _y + z * _z;                                                        \
       }                                                                                              \
       type MthVec3##t::dot(const MthVec3##t &vec) const                                              \
       {                                                                                              \
              return dot(vec.x, vec.y, vec.z);                                                        \
       }                                                                                              \
       type MthVec3##t::len() const                                                                   \
       {                                                                                              \
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z);                               \
       }                                                                                              \
       type MthVec3##t::lenSq() const                                                                 \
       {                                                                                              \
              return x * x + y * y + z * z;                                                           \
       }                                                                                              \
       MthVec3##t &MthVec3##t::norm()                                                                 \
       {                                                                                              \
              type lenght = len();                                                                    \
              atk_assert(lenght != 0);                                                                \
              x /= lenght;                                                                            \
              y /= lenght;                                                                            \
              z /= lenght;                                                                            \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t &MthVec3##t::rotX(float a)                                                          \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type ny = y * c + z * -s;                                                               \
              type nz = y * s + z * c;                                                                \
              y = ny;                                                                                 \
              z = nz;                                                                                 \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t &MthVec3##t::rotY(float a)                                                          \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type nx = x * c + z * s;                                                                \
              type nz = x * -s + z * c;                                                               \
              x = nx;                                                                                 \
              z = nz;                                                                                 \
              return *this;                                                                           \
       }                                                                                              \
       MthVec3##t &MthVec3##t::rotZ(float a)                                                          \
       {                                                                                              \
              type c = (type)cosf(a);                                                                 \
              type s = (type)sinf(a);                                                                 \
              type nx = x * c + y * -s;                                                               \
              type ny = x * s + y * c;                                                                \
              x = nx;                                                                                 \
              y = ny;                                                                                 \
              return *this;                                                                           \
       }

#define MTH_DEF_VEC4(type, t)                                                    \
       MthVec4##t::MthVec4##t()                                                  \
       {                                                                         \
              x = 0;                                                             \
              y = 0;                                                             \
              z = 0;                                                             \
              w = 0;                                                             \
       }                                                                         \
       MthVec4##t::MthVec4##t(type _x, type _y, type _z, type _w)                \
       {                                                                         \
              x = _x;                                                            \
              y = _y;                                                            \
              z = _z;                                                            \
              w = _w;                                                            \
       }                                                                         \
       MthVec4##t::MthVec4##t(const MthVec4##t &vec)                             \
       {                                                                         \
              x = vec.x;                                                         \
              y = vec.y;                                                         \
              z = vec.z;                                                         \
              w = vec.w;                                                         \
       }                                                                         \
       MthVec4##t::MthVec4##t(const AtkPack4##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
              z = pack.z;\
              w = pack.w;\
       }\
       MthVec4##t &MthVec4##t::operator=(const AtkPack4##t &pack)\
       {\
              x = pack.x;\
              y = pack.y;\
              z = pack.z;\
              w = pack.w;\
              return *this;\
       }\
       bool MthVec4##t::operator==(const MthVec4##t &vec) const                  \
       {                                                                         \
              return x == vec.x && y == vec.y && z == vec.z && w == vec.w;       \
       }                                                                         \
       bool MthVec4##t::operator!=(const MthVec4##t &vec) const                  \
       {                                                                         \
              return x != vec.x || y != vec.y || z != vec.z || w != vec.w;       \
       }                                                                         \
       MthVec4##t &MthVec4##t::operator+=(const MthVec4##t &vec)                 \
       {                                                                         \
              x += vec.x;                                                        \
              y += vec.y;                                                        \
              z += vec.z;                                                        \
              w += vec.w;                                                        \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t MthVec4##t::operator+(const MthVec4##t &vec) const             \
       {                                                                         \
              return MthVec4##t(x + vec.x, y + vec.y, z + vec.z, w + vec.w);     \
       }                                                                         \
       MthVec4##t &MthVec4##t::operator-=(const MthVec4##t &vec)                 \
       {                                                                         \
              x -= vec.x;                                                        \
              y -= vec.y;                                                        \
              z -= vec.z;                                                        \
              w -= vec.w;                                                        \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t MthVec4##t::operator-(const MthVec4##t &vec) const             \
       {                                                                         \
              return MthVec4##t(x - vec.x, y - vec.y, z - vec.z, w - vec.w);     \
       }                                                                         \
       MthVec4##t MthVec4##t::operator-() const                                  \
       {                                                                         \
              return MthVec4##t(-x, -y, -z, -w);                                 \
       }                                                                         \
       MthVec4##t &MthVec4##t::operator*=(type factor)                           \
       {                                                                         \
              x *= factor;                                                       \
              y *= factor;                                                       \
              z *= factor;                                                       \
              w *= factor;                                                       \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t MthVec4##t::operator*(type factor) const                       \
       {                                                                         \
              return MthVec4##t(x * factor, y * factor, z * factor, w * factor); \
       }                                                                         \
       MthVec4##t &MthVec4##t::operator/=(type factor)                           \
       {                                                                         \
              atk_assert(factor != (type)0);                                     \
              x /= factor;                                                       \
              y /= factor;                                                       \
              z /= factor;                                                       \
              w /= factor;                                                       \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t MthVec4##t::operator/(type factor) const                       \
       {                                                                         \
              atk_assert(factor != (type)0);                                     \
              return MthVec4##t(x / factor, y / factor, z / factor, w / factor); \
       }                                                                         \
       MthVec4##t &MthVec4##t::crossDim3(type _x, type _y, type _z)              \
       {                                                                         \
              type nx = y * _z - z * _y;                                         \
              type ny = z * _x - x * _z;                                         \
              type nz = x * _y - y * _x;                                         \
              x = nx;                                                            \
              y = ny;                                                            \
              z = nz;                                                            \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::crossDim3(const MthVec4##t &vec)                  \
       {                                                                         \
              return crossDim3(vec.x, vec.y, vec.z);                             \
       }                                                                         \
       type MthVec4##t::dot(type _x, type _y, type _z, type _w) const            \
       {                                                                         \
              return x * _x + y * _y + z * _z, w * _w;                           \
       }                                                                         \
       type MthVec4##t::dot(const MthVec4##t &vec) const                         \
       {                                                                         \
              return dot(vec.x, vec.y, vec.z, vec.w);                            \
       }                                                                         \
       type MthVec4##t::len() const                                              \
       {                                                                         \
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z + w * w);  \
       }                                                                         \
       type MthVec4##t::lenSq() const                                            \
       {                                                                         \
              return x * x + y * y + z * z + w * w;                              \
       }                                                                         \
       type MthVec4##t::lenDim3() const                                          \
       {                                                                         \
              return (type)1.0 / (type)rsqrtssf(x * x + y * y + z * z);          \
       }                                                                         \
       type MthVec4##t::lenSqDim3() const                                        \
       {                                                                         \
              return x * x + y * y + z * z;                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::norm()                                            \
       {                                                                         \
              type lenght = len();                                               \
              atk_assert(lenght != 0);                                           \
              x /= lenght;                                                       \
              y /= lenght;                                                       \
              z /= lenght;                                                       \
              w /= lenght;                                                       \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::normDim3()                                        \
       {                                                                         \
              type lenght = lenDim3();                                           \
              atk_assert(lenght != 0);                                           \
              x /= lenght;                                                       \
              y /= lenght;                                                       \
              z /= lenght;                                                       \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::rotXDim3(float a)                                 \
       {                                                                         \
              type c = (type)cosf(a);                                            \
              type s = (type)sinf(a);                                            \
              type ny = y * c + z * -s;                                          \
              type nz = y * s + z * c;                                           \
              y = ny;                                                            \
              z = nz;                                                            \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::rotYDim3(float a)                                 \
       {                                                                         \
              type c = (type)cosf(a);                                            \
              type s = (type)sinf(a);                                            \
              type nx = x * c + z * s;                                           \
              type nz = x * -s + z * c;                                          \
              x = nx;                                                            \
              z = nz;                                                            \
              return *this;                                                      \
       }                                                                         \
       MthVec4##t &MthVec4##t::rotZDim3(float a)                                 \
       {                                                                         \
              type c = (type)cosf(a);                                            \
              type s = (type)sinf(a);                                            \
              type nx = x * c + y * -s;                                          \
              type ny = x * s + y * c;                                           \
              x = nx;                                                            \
              y = ny;                                                            \
              return *this;                                                      \
       }

MTH_DEF_VEC2(float, f);
MTH_DEF_VEC2(double, d)
MTH_DEF_VEC2(int, i)

MTH_DEF_VEC3(float, f)
MTH_DEF_VEC3(double, d)
MTH_DEF_VEC3(int, i)

MTH_DEF_VEC4(float, f)
MTH_DEF_VEC4(double, d)
MTH_DEF_VEC4(int, i)