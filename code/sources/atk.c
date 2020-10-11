#include "../include/atk.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Memory
 */
fct_atkAllocCallback ALLOC_CALLBACK;
fct_atkAllocAlignedCallback ALLOC_ALIGNED_CALLBACK;
fct_atkReallocCallback REALLOC_CALLBACK;
fct_atkFreeCallback FREE_CALLBACK;

void *atkAlloc(size_t size)
{
       return ALLOC_CALLBACK(size);
}

void *atkAllocAligned(size_t alignment, size_t size)
{
       return ALLOC_ALIGNED_CALLBACK(alignment, size);
}

void *atkRealloc(void *ptr, size_t size)
{
       return REALLOC_CALLBACK(ptr, size);
}

void *atkReallocAligned(void *ptr, size_t alignment, size_t size)
{
       void *nptr = REALLOC_CALLBACK(ptr, size);
       if ((uint64_t)nptr % alignment != 0)
       {
              free(nptr);
              nptr = ALLOC_ALIGNED_CALLBACK(alignment, size);
       }
       return nptr;
}

void atkFree(void *ptr)
{
       FREE_CALLBACK(ptr);
}

/**
 * Mutex
 */
#ifdef ATK_PLATFORM_LINUX
#include <pthread.h>
#endif //ATK_PLATFORM_LINUX

struct AtkMutex
{
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_t handle;
#endif //ATK_PLATFORM_LINUX
};

AtkMutex *atkCreateMutex()
{
       AtkMutex *mutex = (AtkMutex *)atkAlloc(sizeof(struct AtkMutex));
       atk_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       mutex->handle = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
#endif //ATK_PLATFORM_LINUX
       return mutex;
}

void atkLockMutex(AtkMutex *mutex)
{
       atk_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_lock(&mutex->handle);
#endif //ATK_PLATFORM_LINUX
}

void atkUnlockMutex(AtkMutex *mutex)
{
       atk_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_unlock(&mutex->handle);
#endif //ATK_PLATFORM_LINUX
}

void atkDestroyMutex(AtkMutex *mutex)
{
       atk_assert(mutex != NULL);
       atkFree(mutex);
}

/**
 * Callback Info/Warning/Error
 */

AtkMutex *MSG_CALLBACK_MUTEX;
fct_atkMessageCallback MSG_CALLBACK;

void atkPushMessage(AtkMsgType code, const char *description, const char *file, size_t line)
{
       if (MSG_CALLBACK == NULL)
       {
              return;
       }
       atkLockMutex(MSG_CALLBACK_MUTEX);
       MSG_CALLBACK(code, description, file, line);
       atkUnlockMutex(MSG_CALLBACK_MUTEX);
}

void atkConcatAndPushMsg(AtkMsgType code, const char *file, size_t line, const char *format, ...)
{
       va_list argptr;
       va_list argptr_2;
       va_start(argptr, format);
       va_start(argptr_2, format);
       size_t size = (size_t)vsnprintf(NULL, 0, format, argptr) + 1; //to put a null byte
       char *msg_buf = (char *)atkAlloc(size);
       size = vsnprintf(msg_buf, size, format, argptr_2);
       va_end(argptr_2);
       va_end(argptr);

       atkPushMessage(code, msg_buf, file, line);

       atkFree(msg_buf);
}

/**
 * Vector
 */
void atkNewVector(AtkVector *vector, size_t count, size_t size_of_element)
{
       atk_assert(vector != NULL);
       vector->m_count = count;
       vector->m_capacity = (count == 0 ? 10 : count * 2);
       vector->m_size_of_element = size_of_element;
       vector->m_data = atk_alloc(size_of_element * vector->m_capacity);
       atk_assert(vector->m_data != NULL);
}

void atkNewVectorFromOther(AtkVector *vector, const AtkVector *other)
{
       atk_assert(vector != NULL);
       atkNewVector(vector, other->m_count, other->m_size_of_element);
       memcpy(vector->m_data, other->m_data, other->m_capacity * other->m_size_of_element);
}

void atkDeleteVector(AtkVector *vector)
{
       atk_free(vector->m_data);
       vector->m_data = NULL;
       vector->m_count = 0;
       vector->m_capacity = 0;
       vector->m_size_of_element = 0;
}

void atkVectorRecreate(AtkVector *vector, size_t count, size_t size_of_element)
{
       atk_assert(vector != NULL);
       atk_free(vector->m_data);
       atkNewVector(vector, count, size_of_element);
}

void atkVectorPushBack(AtkVector *vector, const void *element)
{
       atk_assert(vector != NULL && element != NULL);
       if (vector->m_count == vector->m_capacity)
              atkVectorResizeCapacity(vector, vector->m_count * 2);

       memcpy(((char *)vector->m_data) + vector->m_count * vector->m_size_of_element, element, vector->m_size_of_element);
       vector->m_count++;
}

void atkVectorPopBack(AtkVector *vector)
{
       atk_assert(vector != NULL);
       vector->m_count--;
       if (vector->m_capacity > vector->m_count * 2 && vector->m_count != 0)
              atkVectorResizeCapacity(vector, vector->m_count * 2);
}

void atkVectorInsert(AtkVector *vector, size_t index, const void *element)
{
       atk_assert(vector != NULL && index < vector->m_count && element != NULL);
       if (vector->m_count == vector->m_capacity)
              atkVectorResizeCapacity(vector, vector->m_count * 2);

       char *ptr = ((char *)vector->m_data) + index * vector->m_size_of_element;
       memmove(ptr + vector->m_size_of_element, ptr, vector->m_size_of_element * (vector->m_count - index));
       memcpy(ptr, element, vector->m_size_of_element);
       vector->m_count++;
}

void atkVectorRemove(AtkVector *vector, size_t index)
{
       atk_assert(vector != NULL && index < vector->m_count);
       char *ptr = ((char *)vector->m_data) + index * vector->m_size_of_element;
       memmove(ptr, ptr + vector->m_size_of_element, vector->m_size_of_element * (vector->m_count - (index + 1)));
       vector->m_count--;

       if (vector->m_capacity > vector->m_count * 2 && vector->m_count != 0)
              atkVectorResizeCapacity(vector, vector->m_count * 2);
}

void atkVectorResizeCapacity(AtkVector *vector, size_t new_capacity)
{
       atk_assert(vector != NULL);
       vector->m_capacity = new_capacity;
       vector->m_data = atk_realloc(vector->m_data, vector->m_capacity * vector->m_size_of_element);
       atk_assert(vector->m_data != NULL);
}

void atkVectorClear(AtkVector *vector)
{
       atk_assert(vector != NULL);
       if (vector->m_count == 0)
       {
              return;
       }
       vector->m_count = 0;
       atkVectorResizeCapacity(vector, 10);
}

/**
 * Array
 */
void atkNewArray(AtkArray *array, size_t count, size_t size_of_element)
{
       atk_assert(array != NULL);
       array->m_count = count;
       array->m_data = (void *)atk_alloc(array->m_count * size_of_element);
       atk_assert(array->m_data != NULL);
}

void atkNewArrayFromOther(AtkArray *array, const AtkArray *other)
{
       atk_assert(array != NULL);
       atkNewArray(array, other->m_count, other->m_size_of_element);
       memcpy(array->m_data, other->m_data, other->m_count * other->m_size_of_element);
}

void atkDeleteArray(AtkArray *array)
{
       atk_assert(array != NULL);
       atk_free(array->m_data);
       array->m_data = NULL;
       array->m_count = 0;
       array->m_size_of_element = 0;
}

void atkArrayRecreate(AtkArray *array, size_t count, size_t size_of_element)
{
       atk_assert(array != NULL);
       atk_free(array->m_data);
       atkNewArray(array, count, size_of_element);
}

/**
 * String
 */
void atkNewString(AtkString *string)
{
       atk_assert(string != NULL);
       string->m_size = 0;
       string->m_capacity = 10;
       string->m_data = atk_alloc(string->m_capacity);
       atk_assert(string->m_data != NULL);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkNewStringFromChars(AtkString *string, const char *str)
{
       atk_assert(string != NULL);
       string->m_size = strlen(str);
       string->m_capacity = string->m_size * 2 + 1; // "+1" to ensure space for the null byte
       string->m_data = atk_alloc(string->m_capacity);
       atk_assert(string->m_data != NULL);
       memcpy(string->m_data, str, string->m_size);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkNewStringFromOther(AtkString *string, const AtkString *other)
{
       atk_assert(string != NULL && other != NULL);
       string->m_size = other->m_size;
       string->m_capacity = string->m_capacity;
       string->m_data = atk_alloc(string->m_capacity);
       atk_assert(string->m_data != NULL);
       memcpy(string->m_data, other->m_data, other->m_size);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkDeleteString(AtkString *string)
{
       atk_assert(string != NULL);
       atk_free(string->m_data);
       string->m_data = NULL;
       string->m_capacity = 0;
       string->m_size = 0;
}

AtkString *atkStringAppend(AtkString *string, const char *str)
{
       atk_assert(string != NULL);
       size_t str_size = strlen(str);
       size_t new_size = string->m_size + str_size;
       if (new_size + 1 > string->m_capacity)
       {
              atkStringResizeCapacity(string, new_size * 2 + 1);
       }
       memcpy((char *)string->m_data + string->m_size, str, str_size);
       string->m_size = new_size;
       ((char *)string->m_data)[new_size] = '\0';
       return string;
}

AtkString *atkStringRemove(AtkString *string, size_t position, size_t count)
{
       size_t total = position + count;
       atk_assert(string != NULL && total <= string->m_size);
       memmove((char *)string->m_data + position, (char *)string->m_data + total, string->m_size - total);
       string->m_size -= count;
       if (string->m_capacity > string->m_size * 2 + 1 && string->m_size != 0)
       {
              atkStringResizeCapacity(string, string->m_size * 2 + 1);
       }
       ((char *)string->m_data)[string->m_size] = '\0';
       return string;
}

AtkString *atkStringInsert(AtkString *string, size_t position, const char *str)
{

       atk_assert(string != NULL && position < string->m_size);
       size_t str_size = strlen(str);
       if (string->m_size + str_size + 1 > string->m_capacity)
       {
              atkStringResizeCapacity(string, (string->m_size + str_size) * 2 + 1);
       }
       memmove((char *)string->m_data + position + str_size, (char *)string->m_data + position, string->m_size - position);
       memcpy((char *)string->m_data + position, str, str_size);
       string->m_size += str_size;
       ((char *)string->m_data)[string->m_size] = '\0';
       return string;
}

void atkStringResizeCapacity(AtkString *string, size_t new_capacity)
{
       atk_assert(string != NULL);
       string->m_capacity = new_capacity;
       string->m_data = atk_realloc(string->m_data, string->m_capacity);
       atk_assert(string->m_data != NULL);
}

/**
 * File
 */
bool atkFileCreate(AtkFile *file, const char *file_name, const char *access_mode)
{
       atk_assert(file != NULL);
       if((file->m_handle = (void*)fopen(file_name, access_mode)) == NULL)
       {
              atk_error(ATK_MSG_PROC_FAILED, "failed to open file");
              return false;
       }
       if(fseek(file->m_handle, 0L, SEEK_END) != 0)
       {
              return false;
       }
       file->m_size = ftell(file->m_handle);
       if(fseek(file->m_handle, 0L, SEEK_SET) != 0)
       {
              return false;
       }
       return true;
}

bool atkFileClose(AtkFile *file)
{
       atk_assert(file != NULL);
       atk_assert(file->m_handle != NULL);
       if(fclose(file->m_handle) != 0)
       {
              atk_error(ATK_MSG_PROC_FAILED, "failed to close file");
              return false;
       }
       file->m_handle = NULL;
       file->m_size = 0;
       return true;
}

bool atkFileRead(AtkFile *file, void *buffer, size_t size)
{
       atk_assert(file != NULL);
       atk_assert(file->m_handle != NULL && buffer != NULL);
       size_t block_count = fread(buffer, 1, size, file->m_handle);
       return block_count == size;
}

bool atkWriteFile(AtkFile *file, void *buffer, size_t size)
{
       atk_assert(file != NULL);
       atk_assert(file->m_handle != NULL && buffer != NULL);
       size_t block_count = fwrite(buffer, 1, size, file->m_handle);
       return block_count == size;
}

bool atkFileSetCursor(AtkFile *file, size_t position)
{
       atk_assert(file != NULL);
       atk_assert(file->m_handle != NULL);
       return fseek(file->m_handle, position, SEEK_SET) == 0;
}

/**
 * Debug
 */
typedef struct AtkMemoryTracker
{
       AtkMutex *m_mutex;
       void *m_mem_alloc_handles;
       size_t m_count;
       size_t m_capacity;
} AtkMemoryTracker;

typedef struct AtkMemAllocHandle
{
       size_t m_line;
       const char *m_file_name;
       void *m_ptr;
} AtkMemAllocHandle;

AtkMemoryTracker MEMORY_TRACKER;

void atkInitMemoryTracker()
{
       MEMORY_TRACKER.m_mutex = atkCreateMutex();
       MEMORY_TRACKER.m_capacity = 10;
       MEMORY_TRACKER.m_count = 0;
       MEMORY_TRACKER.m_mem_alloc_handles = atkAlloc(MEMORY_TRACKER.m_capacity * sizeof(AtkMemAllocHandle));
       atk_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
}

void atkEndMemoryTracker()
{
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_handle = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              atk_vwarn(ATK_MSG_VOID, "%s%lu%s%s", "Memory leak at ", curr_mem_handle->m_line, " in ", curr_mem_handle->m_file_name);
       }
       MEMORY_TRACKER.m_capacity = 0;
       MEMORY_TRACKER.m_count = 0;
       atkFree(MEMORY_TRACKER.m_mem_alloc_handles);
       atkDestroyMutex(MEMORY_TRACKER.m_mutex);
}

void atkMemAllocHandlePush(AtkMemAllocHandle *mem_alloc)
{
       if (MEMORY_TRACKER.m_count == MEMORY_TRACKER.m_capacity)
       {
              MEMORY_TRACKER.m_capacity = MEMORY_TRACKER.m_count * 2;
              MEMORY_TRACKER.m_mem_alloc_handles = atkRealloc(MEMORY_TRACKER.m_mem_alloc_handles, MEMORY_TRACKER.m_capacity * sizeof(AtkMemAllocHandle));
              atk_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
       }
       memcpy(((char *)MEMORY_TRACKER.m_mem_alloc_handles) + MEMORY_TRACKER.m_count * sizeof(AtkMemAllocHandle), mem_alloc, sizeof(AtkMemAllocHandle));
       MEMORY_TRACKER.m_count++;
}

void *atkAllocDebug(size_t size, size_t line, const char *file_name)
{
       atk_assert(size > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       AtkMemAllocHandle mem_alloc;
       mem_alloc.m_line = line;
       mem_alloc.m_file_name = file_name;
       void *ptr = atkAlloc(size);
       atk_assert(ptr != NULL);
       mem_alloc.m_ptr = ptr;
       atkMemAllocHandlePush(&mem_alloc);
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       return ptr;
}

void *atkAllocAlignedDebug(size_t alignment, size_t size, size_t line, const char *file_name)
{
       atk_assert(size > 0 && alignment > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       AtkMemAllocHandle mem_alloc;
       mem_alloc.m_line = line;
       mem_alloc.m_file_name = file_name;
       void *ptr = atkAllocAligned(alignment, size);
       atk_assert(ptr != NULL);
       mem_alloc.m_ptr = ptr;
       atkMemAllocHandlePush(&mem_alloc);
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       return ptr;
}

void *atkReallocDebug(void *ptr, size_t size)
{
       atk_assert(ptr != NULL);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_alloc = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              if (curr_mem_alloc->m_ptr == ptr)
              {
                     void *new_ptr = atkRealloc(ptr, size);
                     atk_assert(new_ptr != NULL);
                     curr_mem_alloc->m_ptr = new_ptr;
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return new_ptr;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find memory allocation handle");
       return NULL;
}

void *atkReallocAlignedDebug(void *ptr, size_t alignment, size_t size)
{
       atk_assert(ptr != NULL && alignment > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_alloc = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              if (curr_mem_alloc->m_ptr == ptr)
              {
                     void *new_ptr = atkReallocAligned(ptr, alignment, size);
                     atk_assert(new_ptr != NULL);
                     curr_mem_alloc->m_ptr = new_ptr;
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return new_ptr;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find memory allocation handle");
       return NULL;
}

void atkFreeDebug(void *ptr)
{
       if(ptr == NULL)
       {
              return;
       }
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_alloc = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              if (curr_mem_alloc->m_ptr == ptr)
              {
                     {
                            char *ptr = ((char *)MEMORY_TRACKER.m_mem_alloc_handles) + i * sizeof(AtkMemAllocHandle);
                            memmove(ptr, ptr + sizeof(AtkMemAllocHandle), sizeof(AtkMemAllocHandle) * (MEMORY_TRACKER.m_count - (i + 1)));
                            MEMORY_TRACKER.m_count--;
                            if (MEMORY_TRACKER.m_capacity > MEMORY_TRACKER.m_count * 2 && MEMORY_TRACKER.m_count != 0)
                            {
                                   MEMORY_TRACKER.m_capacity = MEMORY_TRACKER.m_count;
                                   MEMORY_TRACKER.m_mem_alloc_handles = atkRealloc(MEMORY_TRACKER.m_mem_alloc_handles, MEMORY_TRACKER.m_capacity * sizeof(AtkMemAllocHandle));
                                   atk_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
                            }
                     }
                     atkFree(ptr);
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_warn(ATK_MSG_RESOURCE_MISSING, "failed to find memory allocation handle");
}

/**
 * Init/End
 */
void atkInit(
    fct_atkMessageCallback msg_cb, fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback alloc_align_cb, fct_atkReallocCallback realloc_cb,
    fct_atkFreeCallback free_cb)
{
       MSG_CALLBACK = msg_cb;
       ALLOC_CALLBACK = (alloc_cb == NULL ? malloc : alloc_cb);
       MSG_CALLBACK_MUTEX = atkCreateMutex();
       ALLOC_ALIGNED_CALLBACK = (alloc_align_cb == NULL ? aligned_alloc : alloc_align_cb);
       REALLOC_CALLBACK = (realloc_cb == NULL ? realloc : realloc_cb);
       FREE_CALLBACK = (free_cb == NULL ? free : free_cb);
       atk_info("arcade tool kit initialized");
}

void atkEnd()
{
       atk_info("arcade tool kit ended");
       atkDestroyMutex(MSG_CALLBACK_MUTEX);
}

void atkInitDebug(
    fct_atkMessageCallback msg_cb, fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback alloc_align_cb, fct_atkReallocCallback realloc_cb,
    fct_atkFreeCallback free_cb)
{
       atkInit(msg_cb, alloc_cb, alloc_align_cb, realloc_cb, free_cb);
       atkInitMemoryTracker();
}

void atkEndDebug()
{
       atkEndMemoryTracker();
       atkEnd();
}