#include "atk_core_core.h"

bool atkFileCreate(AtkFile *file, const char *file_name, const char *access_mode)
{
       atk_api_assert(file != NULL);
       if ((file->m_handle = (void *)fopen(file_name, access_mode)) == NULL)
       {
              atk_api_dbg_error("failed to open file");
              return false;
       }
       if (fseek(file->m_handle, 0L, SEEK_END) != 0)
       {
              return false;
       }
       file->m_size = ftell(file->m_handle);
       if (fseek(file->m_handle, 0L, SEEK_SET) != 0)
       {
              return false;
       }
       return true;
}

bool atkFileClose(AtkFile *file)
{
       atk_api_assert(file != NULL);
       atk_api_assert(file->m_handle != NULL);
       if (fclose(file->m_handle) != 0)
       {
              atk_api_dbg_error("failed to close file");
              return false;
       }
       file->m_handle = NULL;
       /*file->m_size = 0;*/
       return true;
}

bool atkFileRead(AtkFile *file, void *buffer, size_t size)
{
       atk_api_assert(file != NULL);
       atk_api_assert(file->m_handle != NULL && buffer != NULL);
       size_t block_count = fread(buffer, 1, size, file->m_handle);
       return block_count == size;
}

bool atkWriteFile(AtkFile *file, void *buffer, size_t size)
{
       atk_api_assert(file != NULL);
       atk_api_assert(file->m_handle != NULL && buffer != NULL);
       size_t block_count = fwrite(buffer, 1, size, file->m_handle);
       return block_count == size;
}

bool atkFileSetCursor(AtkFile *file, size_t position)
{
       atk_api_assert(file != NULL);
       atk_api_assert(file->m_handle != NULL);
       return fseek(file->m_handle, position, SEEK_SET) == 0;
}