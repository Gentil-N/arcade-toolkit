#include "../../include/atk_core.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Callback Info/Warning/Error
 */
/*
#ifdef ATK_DEBUG
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
#endif //ATK_DEBUG

/**
 * Init/End
 *//*
void atkInit(
    fct_atkMessageCallback msg_cb, fct_atkAllocCallback alloc_cb, fct_atkAllocAlignedCallback alloc_align_cb, fct_atkReallocCallback realloc_cb,
    fct_atkFreeCallback free_cb)
{
#ifdef ATK_DEBUG
       MSG_CALLBACK = msg_cb;
#endif //ATK_DEBUG
       ALLOC_CALLBACK = (alloc_cb == NULL ? malloc : alloc_cb);
#ifdef ATK_DEBUG
       MSG_CALLBACK_MUTEX = atkCreateMutex();
#endif //ATK_DEBUG
       ALLOC_ALIGNED_CALLBACK = (alloc_align_cb == NULL ? aligned_alloc : alloc_align_cb);
       REALLOC_CALLBACK = (realloc_cb == NULL ? realloc : realloc_cb);
       FREE_CALLBACK = (free_cb == NULL ? free : free_cb);
#ifdef ATK_DEBUG
       atkInitMemoryTracker();
#endif //ATK_DEBUG
       atk_api_dbg_info("arcade tool kit initialized");
}

void atkEnd()
{
       atk_api_dbg_info("arcade tool kit ended");
#ifdef ATK_DEBUG
       atkEndMemoryTracker();
       atkDestroyMutex(MSG_CALLBACK_MUTEX);
#endif //ATK_DEBUG
}*/