#include "atk_core_core.h"

fct_atkLoggerCallback LOGGER_CALLBACK = NULL;

void atkLog(size_t level, const char *file, size_t line, const char *format, ...)
{
       if(LOGGER_CALLBACK == NULL)
       {
              return;
       }
       va_list argptr;
       va_list argptr_2;
       va_start(argptr, format);
       va_start(argptr_2, format);
       size_t size = (size_t)vsnprintf(NULL, 0, format, argptr) + 1; //to put a null byte
       char *msg_buf = (char *)atkAlloc(size);
       size = vsnprintf(msg_buf, size, format, argptr_2);
       va_end(argptr_2);
       va_end(argptr);

       LOGGER_CALLBACK(level, file, line, msg_buf);

       atkFree(msg_buf);
}

void atkSetLoggerCallback(fct_atkLoggerCallback logger_cb)
{
       LOGGER_CALLBACK = logger_cb;
}