#include "atk_core_core.h"

struct AtkMutex
{
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_t handle;
#endif //ATK_PLATFORM_LINUX
};

AtkMutex *atkCreateMutex()
{
       AtkMutex *mutex = (AtkMutex *)atkAlloc(sizeof(struct AtkMutex));
       atk_api_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       mutex->handle = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
#endif //ATK_PLATFORM_LINUX
       return mutex;
}

void atkLockMutex(AtkMutex *mutex)
{
       atk_api_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_lock(&mutex->handle);
#endif //ATK_PLATFORM_LINUX
}

void atkUnlockMutex(AtkMutex *mutex)
{
       atk_api_assert(mutex != NULL);
#ifdef ATK_PLATFORM_LINUX
       pthread_mutex_unlock(&mutex->handle);
#endif //ATK_PLATFORM_LINUX
}

void atkDestroyMutex(AtkMutex *mutex)
{
       atk_api_assert(mutex != NULL);
       atkFree(mutex);
}