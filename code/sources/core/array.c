#include "atk_core_core.h"

void atkNewArray(AtkArray *array, size_t count, size_t size_of_element)
{
       atk_api_assert(array != NULL);
       array->m_count = count;
       array->m_data = (void *)atk_alloc(array->m_count * size_of_element);
       atk_api_assert(array->m_data != NULL);
}

void atkNewArrayFromOther(AtkArray *array, const AtkArray *other)
{
       atk_api_assert(array != NULL);
       atkNewArray(array, other->m_count, other->m_size_of_element);
       memcpy(array->m_data, other->m_data, other->m_count * other->m_size_of_element);
}

void atkDeleteArray(AtkArray *array)
{
       atk_api_assert(array != NULL);
       atk_free(array->m_data);
       array->m_data = NULL;
       /*array->m_count = 0;
       array->m_size_of_element = 0;*/
}

void atkArrayRecreate(AtkArray *array, size_t count, size_t size_of_element)
{
       atk_api_assert(array != NULL);
       atk_free(array->m_data);
       atkNewArray(array, count, size_of_element);
}