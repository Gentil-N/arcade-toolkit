#ifndef __ATK_H__
#define __ATK_H__

#ifdef __cplusplus
/**
 * Cpp Standard headers
 */
#include <utility>

extern "C"
{
#endif //__cplusplus

       /**
        *  Utils
        */
#define ATK_COMMA ,

       /**
        * Compilation States
        */
#ifndef NDEBUG
#define ATK_DEBUG
#endif //!NDEBUG
#ifdef __cplusplus
#define ATK_HIDE_CPP(expr) expr
#else
#define ATK_HIDE_CPP(expr)
#ifdef ATK_DEFINE_GLOBAL
#define ATK_GLOBAL
#define ATK_GLOBAL_DEF(var, def) var def
#else
#define ATK_GLOBAL extern
#define ATK_GLOBAL_DEF(var, def) extern var
#endif //ATK_DEFINE_GLOBAL
#endif //__cplusplus

       /**
        * PLateforms
        */
#if defined(__linux__) && !defined(__ANDROID__)
#define ATK_PLATFORM_LINUX
#else
#error "other platforms not supported yet"
#endif //LINUX

#if defined(ATK_PLATFORM_LINUX) && (defined(ATK_IMPORT_LIB) || defined(ATK_EXPORT_LIB))
#define ATK_API extern
#else
#define ATK_API
#endif //ATK_PLATFORM_LINUX && ATK_BUILD_SHARED_LIB

       /**
        * Standard headers
        */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

       /**
        * Memory
        */
       typedef void *(*fct_atkAllocCallback)(size_t size);
       typedef void *(*fct_atkAllocAlignedCallback)(size_t alignment, size_t size);
       typedef void *(*fct_atkReallocCallback)(void *ptr, size_t size);
       typedef void (*fct_atkFreeCallback)(void *ptr);
       ATK_API void *atkAlloc(size_t size);
       ATK_API void *atkAllocAligned(size_t alignment, size_t size);
       ATK_API void *atkRealloc(void *ptr, size_t size);
       ATK_API void *atkReallocAligned(void *ptr, size_t alignment, size_t size);
       ATK_API void atkFree(void *ptr);

       /**
        * Mutex
        */
       typedef struct AtkMutex AtkMutex;

       ATK_API AtkMutex *atkCreateMutex();
       ATK_API void atkLockMutex(AtkMutex *mutex);
       ATK_API void atkUnlockMutex(AtkMutex *mutex);
       ATK_API void atkDestroyMutex(AtkMutex *mutex);

       /**
        * Callback Info/Warning/Error
        */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

       typedef enum AtkMsgType
       {
              ATK_MSG_VOID = 0,
              ATK_MSG_INFO = 1,
              ATK_MSG_WARNING = 2,
              ATK_MSG_ERROR = 4,
              ATK_MSG_UNKNOW = 0b1000,
              ATK_MSG_OUT_OF_MEMORY = 0b10000,
              ATK_MSG_FEATURE_NOT_PRESENT = 0b11000,
              ATK_MSG_INIT_FAILED = 0b100000,
              ATK_MSG_PROC_FAILED = 0b101000,
              ATK_MSG_LIB_REPORT = 0b111000,
              ATK_MSG_RESOURCE_MISSING = 0b1000000,
              ATK_MSG_INVALID_ARGUMENT = 0b1001000
       } AtkMsgType;

       typedef void (*fct_atkMessageCallback)(AtkMsgType code, const char *description, const char *file, size_t line);

#ifdef ATK_DEBUG

       ATK_API void atkPushMessage(AtkMsgType code, const char *description, const char *file, size_t line);
       ATK_API void atkConcatAndPushMsg(AtkMsgType code, const char *file, size_t line, const char *format, ...);
       
#define atk_vinfo(format, ...) atkConcatAndPushMsg(ATK_MSG_INFO, __FILENAME__, __LINE__, format, __VA_ARGS__)
#define atk_info(description) atkPushMessage(ATK_MSG_INFO, description, __FILENAME__, __LINE__)
#define atk_vwarn(type, format, ...) atkConcatAndPushMsg((AtkMsgType)(ATK_MSG_WARNING | type), __FILENAME__, __LINE__, format, __VA_ARGS__)
#define atk_warn(type, description) atkPushMessage((AtkMsgType)(ATK_MSG_WARNING | type), description, __FILENAME__, __LINE__)
#define atk_verror(type, format, ...) atkConcatAndPushMsg((AtkMsgType)(ATK_MSG_ERROR | type), __FILENAME__, __LINE__, format, __VA_ARGS__)
#define atk_error(type, description) atkPushMessage((AtkMsgType)(ATK_MSG_ERROR | type), description, __FILENAME__, __LINE__)
#define atk_assert(expr) ((expr) ? (void)(0) : atk_error(ATK_MSG_PROC_FAILED, "assertion failed"))
#define atk_dassert(expr, type, description) ((expr) ? (void)(0) : atk_error(type, description))
#else
#define atk_vinfo(format, ...)
#define atk_info(description)
#define atk_vwarn(type, format, ...)
#define atk_warn(type, description)
#define atk_verror(type, format, ...)
#define atk_error(type, description)
#define atk_assert(expr)
#define atk_dassert(expr, type, description)
#endif //ATK_DEBUG

       /**
        * Pack
        */
#define ATK_PACK(type, t, n, vars) \
       typedef struct AtkPack##n##t \
       { \
              type vars;\
       } AtkPack##n##t

       ATK_PACK(int, i, 2, x ATK_COMMA y);
       ATK_PACK(float, f, 2, x ATK_COMMA y);
       ATK_PACK(double, d, 2, x ATK_COMMA y);

       ATK_PACK(int, i, 3, x ATK_COMMA y ATK_COMMA z);
       ATK_PACK(float, f, 3, x ATK_COMMA y ATK_COMMA z);
       ATK_PACK(double, d, 3, x ATK_COMMA y ATK_COMMA z);

       ATK_PACK(int, i, 4, x ATK_COMMA y ATK_COMMA z ATK_COMMA w);
       ATK_PACK(float, f, 4, x ATK_COMMA y ATK_COMMA z ATK_COMMA w);
       ATK_PACK(double, d, 4, x ATK_COMMA y ATK_COMMA z ATK_COMMA w);

#define ATK_PACKX(type, t, n) \
       typedef struct AtkPack##n##x##n##t \
       { \
              type m[n][n];\
       } AtkPack##n##x##n##t

       ATK_PACKX(int, i, 2);
       ATK_PACKX(float, f, 2);
       ATK_PACKX(double, d, 2);

       ATK_PACKX(int, i, 3);
       ATK_PACKX(float, f, 3);
       ATK_PACKX(double, d, 3);

       ATK_PACKX(int, i, 4);
       ATK_PACKX(float, f, 4);
       ATK_PACKX(double, d, 4);

       /**
        * Vector
        */
#define atk_get(type, arr, index) ((type *)(arr).m_data)[index]

       typedef struct AtkVector AtkVector;

       ATK_API void atkNewVector(AtkVector *vector, size_t count, size_t size_of_element);
       ATK_API void atkNewVectorFromOther(AtkVector *vector, const AtkVector *other);
       ATK_API void atkDeleteVector(AtkVector *vector);
       ATK_API void atkVectorRecreate(AtkVector *vector, size_t count, size_t size_of_element);
       ATK_API void atkVectorPushBack(AtkVector *vector, const void *element);
       ATK_API void atkVectorPopBack(AtkVector *vector);
       ATK_API void atkVectorInsert(AtkVector *vector, size_t index, const void *element);
       ATK_API void atkVectorRemove(AtkVector *vector, size_t index);
       ATK_API void atkVectorResizeCapacity(AtkVector *vector, size_t new_capacity);
       ATK_API void atkVectorClear(AtkVector *vector);

       /**
        * Array
        */
       typedef struct AtkArray AtkArray;

       ATK_API void atkNewArray(AtkArray *array, size_t count, size_t size_of_element);
       ATK_API void atkNewArrayFromOther(AtkArray *array, const AtkArray *other);
       ATK_API void atkDeleteArray(AtkArray *array);
       ATK_API void atkArrayRecreate(AtkArray *array, size_t count, size_t size_of_element);

       /**
        * String
        */
       typedef struct AtkString AtkString;

       ATK_API void atkNewString(AtkString *string);
       ATK_API void atkNewStringFromChars(AtkString *string, const char *str);
       ATK_API void atkNewStringFromOther(AtkString *string, const AtkString *other);
       ATK_API void atkDeleteString(AtkString *string);
       ATK_API AtkString *atkStringAppend(AtkString *string, const char *str);
       ATK_API AtkString *atkStringRemove(AtkString *string, size_t position, size_t count);
       ATK_API AtkString *atkStringInsert(AtkString *string, size_t position, const char *str);
       ATK_API void atkStringResizeCapacity(AtkString *string, size_t new_capacity);

       /**
        * File
        */
       typedef struct AtkFile AtkFile;

       ATK_API bool atkFileCreate(AtkFile *file, const char *file_name, const char *access_mode); //file handle should not be NULL
       ATK_API bool atkFileClose(AtkFile *file);                                                  //file handle should be NULL
       ATK_API bool atkFileRead(AtkFile *file, void *buffer, size_t size);
       ATK_API bool atkFileWrite(AtkFile *file, void *buffer, size_t size);
       ATK_API bool atkFileSetCursor(AtkFile *file, size_t position);

       /**
        * Debug
        */
#ifdef ATK_DEBUG
       ATK_API void *atkAllocDebug(size_t size, size_t line, const char *file_name);
       ATK_API void *atkAllocAlignedDebug(size_t alignment, size_t size, size_t line, const char *file_name);
       ATK_API void *atkReallocDebug(void *ptr, size_t size);
       ATK_API void *atkReallocAlignedDebug(void *ptr, size_t alignment, size_t size);
       ATK_API void atkFreeDebug(void *ptr);
#endif //ATK_DEBUG

       /**
        * Init/End
        */
       ATK_API void atkInit(
           fct_atkMessageCallback msg_cb, fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback alloc_align_cb, fct_atkReallocCallback realloc_cb,
           fct_atkFreeCallback free_cb);
       ATK_API void atkEnd();
#define atk_init atkInit
#define atk_end atkEnd

#ifdef ATK_DEBUG
#define atk_alloc(size) atkAllocDebug(size, __LINE__, __FILENAME__)
#define atk_alloc_aligned(alignment, size) atkAllocAlignedDebug(alignment, size, __LINE__, __FILENAME__)
#define atk_realloc(ptr, size) atkReallocDebug(ptr, size)
#define atk_realloc_aligned(ptr, alignment, size) atkReallocAlignedDebug(ptr, alignment, size)
#define atk_free(ptr) atkFreeDebug(ptr)
#else
#define atk_alloc(size) atkAlloc(size)
#define atk_alloc_aligned(alignment, size) atkAllocAligned(alignment, size)
#define atk_realloc(ptr, size) atkRealloc(ptr, size)
#define atk_realloc_aligned(ptr, alignment, size) atkReallocAligned(ptr, alignment, size)
#define atk_free(ptr) atkFree(ptr)
#endif //ATK_DEBUG

#ifdef __cplusplus
}
#endif //__cplusplus

struct AtkVector
{
       void *m_data ATK_HIDE_CPP(= nullptr);
       size_t m_count ATK_HIDE_CPP(= 0);
       size_t m_capacity ATK_HIDE_CPP(= 0);
       size_t m_size_of_element ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       AtkVector() : m_data(nullptr), m_count(0), m_capacity(0), m_size_of_element(0) //"recreate" must be called
       {
       }
       AtkVector(size_t size, size_t size_of_element)
       {
              atkNewVector(this, size, size_of_element);
       }
       AtkVector(const AtkVector &vector)
       {
              atkNewVectorFromOther(this, &vector);
       }
       AtkVector(AtkVector &&vector)
       {
              m_data = vector.m_data;
              m_count = vector.m_count;
              m_capacity = vector.m_capacity;
              m_size_of_element = vector.m_size_of_element;
              vector.m_data = nullptr;
       }
       ~AtkVector()
       {
              atkDeleteVector(this);
       }
       AtkVector &operator=(const AtkVector &vector)
       {
              atk_free(m_data);
              atkNewVectorFromOther(this, &vector);
              return *this;
       }
       AtkVector &operator=(AtkVector &&vector)
       {
              atk_free(m_data);
              m_data = vector.m_data;
              m_count = vector.m_count;
              m_capacity = vector.m_capacity;
              m_size_of_element = vector.m_size_of_element;
              vector.m_data = nullptr;
              return *this;
       }
       void recreate(size_t count, size_t size_of_element)
       {
              atkVectorRecreate(this, count, size_of_element);
       }
       template <typename T>
       T &get(size_t index)
       {
              atk_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       template <typename T>
       const T &get(size_t index) const
       {
              atk_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       template <typename T>
       void pushBack(const T &element)
       {
              atkVectorPushBack(this, &element);
       }
       void pushBack(const void *element)
       {
              atkVectorPushBack(this, element);
       }
       void popBack()
       {
              atkVectorPopBack(this);
       }
       template <typename T>
       void insert(size_t index, const T &element)
       {
              atk_assert(index < m_count);
              atkVectorInsert(this, index, &element);
       }
       void insert(size_t index, const void *element)
       {
              atk_assert(index < m_count);
              atkVectorInsert(this, index, element);
       }
       void remove(size_t index)
       {
              atk_assert(index < m_count);
              atkVectorRemove(this, index);
       }
       void resizeCapacity(size_t new_capacity)
       {
              atkVectorResizeCapacity(this, new_capacity);
       }
       void clear()
       {
              atkVectorClear(this);
       }
       inline bool isEmpty() const noexcept
       {
              return m_count == 0;
       }
       inline size_t count() const noexcept
       {
              return m_count;
       }
       inline size_t capacity() const noexcept
       {
              return m_capacity;
       }
       inline size_t sizeOfElement() const noexcept
       {
              return m_size_of_element;
       }
       template <typename T = void>
       inline T *data()
       {
              return (T *)m_data;
       }
       template <typename T = void>
       inline const T *data() const
       {
              return (const T *)m_data;
       }
#endif //__cplusplus
};

struct AtkArray
{
       void *m_data ATK_HIDE_CPP(= nullptr);
       size_t m_count ATK_HIDE_CPP(= 0);
       size_t m_size_of_element ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       AtkArray() : m_data(nullptr), m_count(0), m_size_of_element(0) //"recreate" must be called
       {
       }
       AtkArray(size_t count, size_t size_of_element)
       {
              atkNewArray(this, count, size_of_element);
       }
       AtkArray(const AtkArray &array)
       {
              atkNewArrayFromOther(this, &array);
       }
       AtkArray(AtkArray &&array)
       {
              m_data = array.m_data;
              m_count = array.m_count;
              m_size_of_element = array.m_size_of_element;
              array.m_data = nullptr;
       }
       ~AtkArray()
       {
              atkDeleteArray(this);
       }
       AtkArray &operator=(const AtkArray &array)
       {
              atk_free(m_data);
              atkNewArrayFromOther(this, &array);
              return *this;
       }
       AtkArray &operator=(AtkArray &&array)
       {
              atk_free(m_data);
              m_data = array.m_data;
              m_count = array.m_count;
              m_size_of_element = array.m_size_of_element;
              array.m_data = nullptr;
              return *this;
       }
       void recreate(size_t count, size_t size_of_element)
       {
              atkArrayRecreate(this, count, size_of_element);
       }
       template <typename T>
       T &get(size_t index)
       {
              atk_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       template <typename T>
       const T &get(size_t index) const
       {
              atk_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       inline bool isEmpty() const noexcept
       {
              return m_count == 0;
       }
       inline size_t count() const noexcept
       {
              return m_count;
       }
       template <typename T = void>
       inline T *data()
       {
              return (T *)m_data;
       }
       template <typename T = void>
       inline const T *data() const
       {
              return (const T *)m_data;
       }
#endif //__cplusplus
};

struct AtkString
{
       char *m_data ATK_HIDE_CPP(= nullptr);
       size_t m_size ATK_HIDE_CPP(= 0);
       size_t m_capacity ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       AtkString()
       {
              atkNewString(this);
       }
       AtkString(const char *str)
       {
              atkNewStringFromChars(this, str);
       }
       AtkString(const AtkString &string)
       {
              atkNewStringFromOther(this, &string);
       }
       AtkString(AtkString &&string)
       {
              m_data = string.m_data;
              m_size = string.m_size;
              m_capacity = string.m_capacity;
              string.m_data = nullptr;
       }
       ~AtkString()
       {
              atkDeleteString(this);
       }
       AtkString &operator=(const AtkString &string)
       {
              atk_free(m_data);
              atkNewStringFromOther(this, &string);
              return *this;
       }
       AtkString &operator=(AtkString &&string)
       {
              atk_free(m_data);
              m_data = string.m_data;
              m_size = string.m_size;
              m_capacity = string.m_capacity;
              string.m_data = nullptr;
              return *this;
       }
       AtkString &append(const char *str)
       {
              return *atkStringAppend(this, str);
       }
       AtkString &remove(size_t position, size_t count)
       {
              return *atkStringRemove(this, position, count);
       }
       AtkString &insert(size_t position, const char *str)
       {
              return *atkStringInsert(this, position, str);
       }
       void resizeCapacity(size_t new_capacity)
       {
              atkStringResizeCapacity(this, new_capacity);
       }
       inline bool isEmpty() const noexcept
       {
              return m_size == 0;
       }
       inline size_t size() const noexcept
       {
              return m_size;
       }
       template <typename T = char>
       inline T *data()
       {
              return (T *)m_data;
       }
       template <typename T = char>
       inline const T *data() const
       {
              return (const T *)m_data;
       }
#endif //__cplusplus
};

struct AtkFile
{
       void *m_handle ATK_HIDE_CPP(= nullptr);
       size_t m_size ATK_HIDE_CPP(= 0);
#ifdef __cplusplus
       AtkFile()
       {
       }
       AtkFile(const char *name, const char *access_mode)
       {
              atkFileCreate(this, name, access_mode);
       }
       AtkFile(const AtkFile &file) = delete; //to avoid close errors
       AtkFile(AtkFile &&file)
       {
              m_handle = file.m_handle;
              m_size = file.m_size;
              file.m_handle = nullptr;
       }
       ~AtkFile()
       {
              if (m_handle != nullptr)
              {
                     atkFileClose(this);
              }
       }
       AtkFile &operator=(const AtkFile &file) = delete;
       AtkFile &operator=(AtkFile &&file)
       {
              if (m_handle != nullptr)
              {
                     atkFileClose(this);
              }
              m_handle = file.m_handle;
              m_size = file.m_size;
              file.m_handle = nullptr;
              return *this;
       }
       bool create(const char *name, const char *&access_mode)
       {
              return atkFileCreate(this, name, access_mode);
       }
       bool close()
       {
              return atkFileClose(this);
       }
       bool read(void *buffer, size_t size)
       {
              return atkFileRead(this, buffer, size);
       }
       bool write(void *buffer, size_t size)
       {
              return atkFileWrite(this, buffer, size);
       }
       bool setCursor(size_t position)
       {
              return atkFileSetCursor(this, position);
       }
       inline size_t size() const noexcept
       {
              return m_size;
       }
       inline void *handle() const noexcept
       {
              return m_handle;
       }
#endif //__cplusplus
};

#endif //__ATK_H__