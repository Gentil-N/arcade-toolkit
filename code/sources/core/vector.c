#include "atk_core_core.h"

void atkNewVector(AtkVector *vector, size_t count, size_t size_of_element)
{
       atk_api_assert(vector != NULL);
       vector->m_count = count;
       vector->m_capacity = (count == 0 ? 10 : count * 2);
       vector->m_size_of_element = size_of_element;
       vector->m_data = atk_alloc(size_of_element * vector->m_capacity);
       atk_api_assert(vector->m_data != NULL);
}

void atkNewVectorFromOther(AtkVector *vector, const AtkVector *other)
{
       atk_api_assert(vector != NULL);
       atkNewVector(vector, other->m_count, other->m_size_of_element);
       memcpy(vector->m_data, other->m_data, other->m_capacity * other->m_size_of_element);
}

void atkDeleteVector(AtkVector *vector)
{
       atk_api_assert(vector != NULL);
       atk_free(vector->m_data);
       vector->m_data = NULL;
       /*vector->m_count = 0;
       vector->m_capacity = 0;
       vector->m_size_of_element = 0;*/
}

void atkVectorRecreate(AtkVector *vector, size_t count, size_t size_of_element)
{
       atk_api_assert(vector != NULL);
       atk_free(vector->m_data);
       atkNewVector(vector, count, size_of_element);
}

void atkVectorPushBack(AtkVector *vector, const void *element)
{
       atk_api_assert(vector != NULL && element != NULL);
       if (vector->m_count == vector->m_capacity)
              atkVectorResizeCapacity(vector, vector->m_count * 2);

       memcpy(((char *)vector->m_data) + vector->m_count * vector->m_size_of_element, element, vector->m_size_of_element);
       vector->m_count++;
}

void atkVectorPopBack(AtkVector *vector)
{
       atk_api_assert(vector != NULL);
       vector->m_count--;
       if (vector->m_capacity > vector->m_count * 2 && vector->m_count != 0)
              atkVectorResizeCapacity(vector, vector->m_count * 2);
}

void atkVectorInsert(AtkVector *vector, size_t index, const void *element)
{
       atk_api_assert(vector != NULL && index < vector->m_count && element != NULL);
       if (vector->m_count == vector->m_capacity)
              atkVectorResizeCapacity(vector, vector->m_count * 2);

       char *ptr = ((char *)vector->m_data) + index * vector->m_size_of_element;
       memmove(ptr + vector->m_size_of_element, ptr, vector->m_size_of_element * (vector->m_count - index));
       memcpy(ptr, element, vector->m_size_of_element);
       vector->m_count++;
}

void atkVectorRemove(AtkVector *vector, size_t index)
{
       atk_api_assert(vector != NULL && index < vector->m_count);
       char *ptr = ((char *)vector->m_data) + index * vector->m_size_of_element;
       memmove(ptr, ptr + vector->m_size_of_element, vector->m_size_of_element * (vector->m_count - (index + 1)));
       vector->m_count--;

       if (vector->m_capacity > vector->m_count * 2 && vector->m_count != 0)
              atkVectorResizeCapacity(vector, vector->m_count * 2);
}

void atkVectorResizeCapacity(AtkVector *vector, size_t new_capacity)
{
       atk_api_assert(vector != NULL);
       vector->m_capacity = new_capacity;
       vector->m_data = atk_realloc(vector->m_data, vector->m_capacity * vector->m_size_of_element);
       atk_api_assert(vector->m_data != NULL);
}

void atkVectorClear(AtkVector *vector)
{
       atk_api_assert(vector != NULL);
       if (vector->m_count == 0)
       {
              return;
       }
       vector->m_count = 0;
       atkVectorResizeCapacity(vector, 10);
}