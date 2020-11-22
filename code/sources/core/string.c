#include "atk_core_core.h"

void atkNewString(AtkString *string)
{
       atk_api_assert(string != NULL);
       string->m_size = 0;
       string->m_capacity = 10;
       string->m_data = atk_alloc(string->m_capacity);
       atk_api_assert(string->m_data != NULL);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkNewStringFromChars(AtkString *string, const char *str)
{
       atk_api_assert(string != NULL);
       string->m_size = strlen(str);
       string->m_capacity = string->m_size * 2 + 1; // "+1" to ensure space for the null byte
       string->m_data = atk_alloc(string->m_capacity);
       atk_api_assert(string->m_data != NULL);
       memcpy(string->m_data, str, string->m_size);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkNewStringFromOther(AtkString *string, const AtkString *other)
{
       atk_api_assert(string != NULL && other != NULL);
       string->m_size = other->m_size;
       string->m_capacity = string->m_capacity;
       string->m_data = atk_alloc(string->m_capacity);
       atk_api_assert(string->m_data != NULL);
       memcpy(string->m_data, other->m_data, other->m_size);
       ((char *)string->m_data)[string->m_size] = '\0';
}

void atkDeleteString(AtkString *string)
{
       atk_api_assert(string != NULL);
       atk_free(string->m_data);
       string->m_data = NULL;
       /*string->m_capacity = 0;
       string->m_size = 0;*/
}

AtkString *atkStringAppend(AtkString *string, const char *str)
{
       atk_api_assert(string != NULL);
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
       atk_api_assert(string != NULL && total <= string->m_size);
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

       atk_api_assert(string != NULL && position < string->m_size);
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
       atk_api_assert(string != NULL);
       string->m_capacity = new_capacity;
       string->m_data = atk_realloc(string->m_data, string->m_capacity);
       atk_api_assert(string->m_data != NULL);
}