#include "atk_core_core.h"

fct_atkAllocCallback ALLOC_CALLBACK = malloc;
fct_atkAllocAlignedCallback ALLOC_ALIGNED_CALLBACK = aligned_alloc;
fct_atkReallocCallback REALLOC_CALLBACK = realloc;
fct_atkFreeCallback FREE_CALLBACK = free;

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
              FREE_CALLBACK(nptr);
              nptr = ALLOC_ALIGNED_CALLBACK(alignment, size);
       }
       return nptr;
}

void atkFree(void *ptr)
{
       FREE_CALLBACK(ptr);
}

#ifdef ATK_DEBUG

typedef struct AtkAllocInfo AtkAllocInfo;

struct AtkAllocInfo
{
       const char *file;
       size_t line;
       size_t info_size;
       AtkAllocInfo *next, *previous;
};

AtkAllocInfo *alloc_info_head = NULL;

void *atkAllocDbg(size_t size, size_t line, const char *file)
{
       if (size == 0)
       {
              return NULL;
       }
       AtkAllocInfo *alloc_info = atkAlloc(size + sizeof(struct AtkAllocInfo));
       if (alloc_info == NULL)
       {
              atk_api_dbg_error("failed to alloc");
              return NULL;
       }
       alloc_info->info_size = sizeof(struct AtkAllocInfo);
       alloc_info->file = file;
       alloc_info->line = line;
       alloc_info->previous = alloc_info_head;
       if (alloc_info_head)
       {
              alloc_info->previous->next = alloc_info;
       }
       alloc_info->next = NULL;
       alloc_info_head = alloc_info;
       return alloc_info + 1;
}

void *atkAllocAlignedDbg(size_t alignment, size_t size, size_t line, const char *file)
{
       atk_api_assert(alignment != 0);
       if (size == 0)
       {
              return NULL;
       }
       size_t remainder = sizeof(struct AtkAllocInfo) % alignment;
       size_t info_size = remainder == 0 ? sizeof(struct AtkAllocInfo) : sizeof(struct AtkAllocInfo) + alignment - (remainder);
       AtkAllocInfo *alloc_info = atkAllocAligned(alignment, size + info_size) + info_size - sizeof(struct AtkAllocInfo);
       if (alloc_info == NULL)
       {
              atk_api_dbg_error("failed to alloc aligned");
              return NULL;
       }
       alloc_info->info_size = info_size;
       alloc_info->file = file;
       alloc_info->line = line;
       alloc_info->previous = alloc_info_head;
       if (alloc_info_head)
       {
              alloc_info->previous->next = alloc_info;
       }
       alloc_info->next = NULL;
       alloc_info_head = alloc_info;
       return alloc_info + 1;
}

void *atkReallocDbg(void *ptr, size_t size, size_t line, const char *file)
{
       if (ptr == NULL)
       {
              if (size == 0)
              {
                     return NULL;
              }
              return atkAllocDbg(size, line, file);
       }
       else if (size == 0)
       {
              atkFreeDbg(ptr);
              return NULL;
       }
       AtkAllocInfo *past_ptr = (AtkAllocInfo *)ptr - 1;
       AtkAllocInfo past_alloc_info = *past_ptr;
       AtkAllocInfo *alloc_info = atkRealloc((char *)ptr - past_ptr->info_size, size + sizeof(struct AtkAllocInfo));
       if (alloc_info == NULL)
       {
              atk_api_dbg_error("failed to realloc");
              return NULL;
       }
       if (past_alloc_info.previous)
       {
              past_alloc_info.previous->next = alloc_info;
       }
       if (past_alloc_info.next)
       {
              past_alloc_info.next->previous = alloc_info;
       }
       else
       {
              alloc_info_head = alloc_info;
       }
       alloc_info->info_size = sizeof(struct AtkAllocInfo);
       return alloc_info + 1;
}

void *atkReallocAlignedDbg(void *ptr, size_t alignment, size_t size, size_t line, const char *file)
{
       atk_api_assert(alignment != 0);
       if (ptr == NULL)
       {
              if (size == 0)
              {
                     return NULL;
              }
              return atkAllocAlignedDbg(alignment, size, line, file);
       }
       else if (size == 0)
       {
              atkFreeDbg(ptr);
              return NULL;
       }
       size_t remainder = sizeof(struct AtkAllocInfo) % alignment;
       size_t info_size = remainder == 0 ? sizeof(struct AtkAllocInfo) : sizeof(struct AtkAllocInfo) + alignment - (remainder);
       AtkAllocInfo *past_ptr = (AtkAllocInfo *)ptr - 1;
       AtkAllocInfo past_alloc_info = *past_ptr;
       AtkAllocInfo *alloc_info = atkReallocAligned((char *)ptr - past_ptr->info_size, alignment, size + info_size) + info_size - sizeof(struct AtkAllocInfo);
       if (alloc_info == NULL)
       {
              atk_api_dbg_error("failed to realloc aligned");
              return NULL;
       }
       if (past_alloc_info.previous)
       {
              past_alloc_info.previous->next = alloc_info;
       }
       if (past_alloc_info.next)
       {
              past_alloc_info.next->previous = alloc_info;
       }
       else
       {
              alloc_info_head = alloc_info;
       }
       *alloc_info = past_alloc_info;
       alloc_info->info_size = info_size;
       return alloc_info + 1;
}

void atkFreeDbg(void *ptr)
{
       if (ptr == NULL)
       {
              return;
       }
       AtkAllocInfo *alloc_info_ptr = (AtkAllocInfo *)ptr - 1;
       if (alloc_info_ptr->next == NULL)
       {
              atk_api_assert(alloc_info_ptr == alloc_info_head);
              alloc_info_head = alloc_info_ptr->previous;
       }
       else
       {
              alloc_info_ptr->next->previous = alloc_info_ptr->previous;
       }
       if (alloc_info_ptr->previous)
       {
              alloc_info_ptr->previous->next = alloc_info_ptr->next;
       }
       atkFree((char *)ptr - alloc_info_ptr->info_size);
}

void atkCheckMemoryLeak()
{
       AtkAllocInfo *alloc_info = alloc_info_head;
       while (alloc_info)
       {
              atk_api_dbg_warn("%s%lu%s%s", "memory leak at ", alloc_info->line, " in ", alloc_info->file);
              alloc_info = alloc_info->previous;
       }
}
#endif //ATK_DEBUG
/*
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

#ifdef ATK_DEBUG
void atkInitMemoryTracker()
{
       MEMORY_TRACKER.m_mutex = atkCreateMutex();
       MEMORY_TRACKER.m_capacity = 10;
       MEMORY_TRACKER.m_count = 0;
       MEMORY_TRACKER.m_mem_alloc_handles = atkAlloc(MEMORY_TRACKER.m_capacity * sizeof(AtkMemAllocHandle));
       atk_api_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
}

void atkEndMemoryTracker()
{
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_handle = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              atk_api_dbg_warn("%s%lu%s%s", "Memory leak at ", curr_mem_handle->m_line, " in ", curr_mem_handle->m_file_name);
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
              atk_api_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
       }
       memcpy(((char *)MEMORY_TRACKER.m_mem_alloc_handles) + MEMORY_TRACKER.m_count * sizeof(AtkMemAllocHandle), mem_alloc, sizeof(AtkMemAllocHandle));
       MEMORY_TRACKER.m_count++;
}

void *atkAllocDebug(size_t size, size_t line, const char *file_name)
{
       atk_api_assert(size > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       AtkMemAllocHandle mem_alloc;
       mem_alloc.m_line = line;
       mem_alloc.m_file_name = file_name;
       void *ptr = atkAlloc(size);
       atk_api_assert(ptr != NULL);
       mem_alloc.m_ptr = ptr;
       atkMemAllocHandlePush(&mem_alloc);
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       return ptr;
}

void *atkAllocAlignedDebug(size_t alignment, size_t size, size_t line, const char *file_name)
{
       atk_api_assert(size > 0 && alignment > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       AtkMemAllocHandle mem_alloc;
       mem_alloc.m_line = line;
       mem_alloc.m_file_name = file_name;
       void *ptr = atkAllocAligned(alignment, size);
       atk_api_assert(ptr != NULL);
       mem_alloc.m_ptr = ptr;
       atkMemAllocHandlePush(&mem_alloc);
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       return ptr;
}

void *atkReallocDebug(void *ptr, size_t size)
{
       atk_api_assert(ptr != NULL);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_alloc = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              if (curr_mem_alloc->m_ptr == ptr)
              {
                     void *new_ptr = atkRealloc(ptr, size);
                     atk_api_assert(new_ptr != NULL);
                     curr_mem_alloc->m_ptr = new_ptr;
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return new_ptr;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_api_dbg_warn("failed to find memory allocation handle");
       return NULL;
}

void *atkReallocAlignedDebug(void *ptr, size_t alignment, size_t size)
{
       atk_api_assert(ptr != NULL && alignment > 0);
       atkLockMutex(MEMORY_TRACKER.m_mutex);
       for (size_t i = 0; i < MEMORY_TRACKER.m_count; ++i)
       {
              AtkMemAllocHandle *curr_mem_alloc = &((AtkMemAllocHandle *)MEMORY_TRACKER.m_mem_alloc_handles)[i];
              if (curr_mem_alloc->m_ptr == ptr)
              {
                     void *new_ptr = atkReallocAligned(ptr, alignment, size);
                     atk_api_assert(new_ptr != NULL);
                     curr_mem_alloc->m_ptr = new_ptr;
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return new_ptr;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_api_dbg_warn("failed to find memory allocation handle");
       return NULL;
}

void atkFreeDebug(void *ptr)
{
       if (ptr == NULL)
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
                                   atk_api_assert(MEMORY_TRACKER.m_mem_alloc_handles != NULL);
                            }
                     }
                     atkFree(ptr);
                     atkUnlockMutex(MEMORY_TRACKER.m_mutex);
                     return;
              }
       }
       atkUnlockMutex(MEMORY_TRACKER.m_mutex);
       atk_api_dbg_warn("failed to find memory allocation handle");
}
#endif //ATK_DEBUG
*/
void atkSetMemoryFunctions(fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback aligned_alloc_cb, fct_atkReallocCallback realloc_cb, fct_atkFreeCallback free_cb)
{
       atk_api_assert(alloc_cb != NULL && aligned_alloc_cb != NULL && realloc_cb != NULL && free_cb != NULL);
       ALLOC_CALLBACK = alloc_cb == NULL ? malloc : alloc_cb;
       ALLOC_ALIGNED_CALLBACK = aligned_alloc_cb == NULL ? aligned_alloc : aligned_alloc_cb;
       REALLOC_CALLBACK = realloc_cb == NULL ? realloc : realloc_cb;
       FREE_CALLBACK = free_cb == NULL ? free : free_cb;
}
/*
void atkEndMemory()
{
#ifdef ATK_DEBUG
       atkEndMemoryTracker();
#endif //ATK_DEBUG
}*/