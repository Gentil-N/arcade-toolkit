#ifndef __ATK_CORE_H__
#define __ATK_CORE_H__

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
#define atk_max(a, b) (a > b ? a : b)
#define atk_min(a, b) (a > b ? b : a)

       /**
        * Compilation States
        */
#ifndef NDEBUG
#define ATK_DEBUG
#endif //!NDEBUG
#ifdef ATK_DEFINE_GLOBAL
#define ATK_GLOBAL
#define ATK_GLOBAL_DEF(var, def) var def
#else
#define ATK_GLOBAL extern
#define ATK_GLOBAL_DEF(var, def) extern var
#endif //ATK_DEFINE_GLOBAL

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
       ATK_API void atkSetMemoryFunctions(
              fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback aligned_alloc_cb, fct_atkReallocCallback realloc_cb, fct_atkFreeCallback free_cb);
#ifdef ATK_DEBUG
       ATK_API void *atkAllocDbg(size_t size, size_t line, const char *file_name);
       ATK_API void *atkAllocAlignedDbg(size_t alignment, size_t size, size_t line, const char *file_name);
       ATK_API void *atkReallocDbg(void *ptr, size_t size, size_t line, const char *file);
       ATK_API void *atkReallocAlignedDbg(void *ptr, size_t alignment, size_t size, size_t line, const char *file);
       ATK_API void atkFreeDbg(void *ptr);
       ATK_API void atkCheckMemoryLeak();
#define atk_alloc(size) atkAllocDbg(size, __LINE__, __FILENAME__)
#define atk_alloc_aligned(alignment, size) atkAllocAlignedDbg(alignment, size, __LINE__, __FILENAME__)
#define atk_realloc(ptr, size) atkReallocDbg(ptr, size, __LINE__, __FILENAME__)
#define atk_realloc_aligned(ptr, alignment, size) atkReallocAlignedDbg(ptr, alignment, size, __LINE__, __FILENAME__)
#define atk_free(ptr) atkFreeDbg(ptr)
#else
#define atk_alloc(size) atkAlloc(size)
#define atk_alloc_aligned(alignment, size) atkAllocAligned(alignment, size)
#define atk_realloc(ptr, size) atkRealloc(ptr, size)
#define atk_realloc_aligned(ptr, alignment, size) atkReallocAligned(ptr, alignment, size)
#define atk_free(ptr) atkFree(ptr)
#endif //ATK_DEBUG

       /**
        * Mutex
        */
       typedef struct AtkMutex AtkMutex;

       ATK_API AtkMutex *atkCreateMutex();
       ATK_API void atkLockMutex(AtkMutex *mutex);
       ATK_API void atkUnlockMutex(AtkMutex *mutex);
       ATK_API void atkDestroyMutex(AtkMutex *mutex);

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

       /**
        * Logger
        */
       typedef enum AtkLogLevel
       {
              ATK_LOG_LVL_DEBUG = 0x1,
              ATK_LOG_LVL_INFO = 0x2,
              ATK_LOG_LVL_WARN = 0x4,
              ATK_LOG_LVL_ERROR = 0x8,
              ATK_LOG_LVL_FATAL = 0x10,
              ATK_LOG_LVL_API = 0x20
       } AtkLogLevel;

       typedef void (*fct_atkLoggerCallback)(size_t level, const char *file, size_t line, const char *description);
       
       ATK_API void atkLog(size_t level, const char *file, size_t line, const char *format, ...);
       ATK_API void atkSetLoggerCallback(fct_atkLoggerCallback logger_cb);
       ATK_API void atkEndMemory();

#define atk_info(...) atkLog(ATK_LOG_LVL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_warn(...) atkLog(ATK_LOG_LVL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_error(...) atkLog(ATK_LOG_LVL_ERROR, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_fatal(...) atkLog(ATK_LOG_LVL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__)
#ifdef ATK_DEBUG
#define atk_dbg_info(...) atkLog(ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_dbg_warn(...) atkLog(ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_dbg_error(...) atkLog(ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_ERROR, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_dbg_fatal(...) atkLog(ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_api_dbg_info(...) atkLog(ATK_LOG_LVL_API | ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_api_dbg_warn(...) atkLog(ATK_LOG_LVL_API | ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_api_dbg_error(...) atkLog(ATK_LOG_LVL_API | ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_ERROR, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_api_dbg_fatal(...) atkLog(ATK_LOG_LVL_API | ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__)
#define atk_assert(expr) ((expr) ? (void)(0) : atk_dbg_fatal("assertion failed"))
#define atk_vassert(expr, ...) ((expr) ? (void)(0) : atkLog(ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__))
#define atk_api_assert(expr) ((expr) ? (void)(0) : atk_api_dbg_fatal("assertion failed"))
#define atk_api_vassert(expr, ...) ((expr) ? (void)(0) : atkLog(ATK_LOG_LVL_API | ATK_LOG_LVL_DEBUG | ATK_LOG_LVL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__))
#else
#define atk_dbg_info(...)
#define atk_dbg_warn(...)
#define atk_dbg_error(...)
#define atk_dbg_fatal(...)
#define atk_api_dbg_info(...)
#define atk_api_dbg_warn(...)
#define atk_api_dbg_error(...)
#define atk_api_dbg_fatal(...)
#define atk_assert(expr)
#define atk_vassert(expr, ...)
#define atk_api_assert(expr)
#define atk_api_vassert(expr, ...)
#endif //ATK_DEBUG

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
        * Timer
        */
       typedef struct AtkTimer AtkTimer;

       ATK_API void atkTimerUpdate(AtkTimer *timer);

#ifdef __cplusplus
}
#endif //__cplusplus

struct AtkVector
{
       void *m_data;
       size_t m_count;
       size_t m_capacity;
       size_t m_size_of_element;
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
              if (m_data == nullptr)
                     return;
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
              atk_api_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       template <typename T>
       const T &get(size_t index) const
       {
              atk_api_assert(index < m_count);
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
              atk_api_assert(index < m_count);
              atkVectorInsert(this, index, &element);
       }
       void insert(size_t index, const void *element)
       {
              atk_api_assert(index < m_count);
              atkVectorInsert(this, index, element);
       }
       void remove(size_t index)
       {
              atk_api_assert(index < m_count);
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
       void *m_data;
       size_t m_count;
       size_t m_size_of_element;
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
              if (m_data == nullptr)
                     return;
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
              atk_api_assert(index < m_count);
              return atk_get(T, *this, index);
       }
       template <typename T>
       const T &get(size_t index) const
       {
              atk_api_assert(index < m_count);
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
       char *m_data;
       size_t m_size;
       size_t m_capacity;
#ifdef __cplusplus
       AtkString() : m_data(nullptr), m_size(0), m_capacity(0)
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
              if (m_data == nullptr)
                     return;
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
       void *m_handle;
       size_t m_size;
#ifdef __cplusplus
       AtkFile() : m_handle(nullptr), m_size(0)
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
              if (m_handle == nullptr)
                     return;
              atkFileClose(this);
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

struct AtkTimer
{
       int m_hour;
       int m_min;
       int m_sec;
       float m_progress;
       long m_last_clock;
#ifdef __cplusplus
       AtkTimer() : m_hour(0), m_min(0), m_sec(0), m_progress(0), m_last_clock(0)
       {
       }
       ~AtkTimer() = default;
       void update()
       {
              atkTimerUpdate(this);
       }
       inline int hour() const noexcept
       {
              return m_hour;
       }
       inline int min() const noexcept
       {
              return m_min;
       }
       inline int sec() const noexcept
       {
              return m_sec;
       }
       inline float progress() const noexcept
       {
              return m_progress;
       }
#endif //__cplusplus
};

#endif //__ATK_CORE_H__