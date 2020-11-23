#include "atk_core_core.h"

void atkTimerUpdate(AtkTimer *timer)
{
       time_t t = time(NULL);
       struct tm *state = localtime(&t);
       timer->m_hour = state->tm_hour;
       timer->m_min = state->tm_min;
       timer->m_sec = state->tm_sec;
       long curr_clock = clock();
       timer->m_progress = (float)(curr_clock - timer->m_last_clock) / (float)CLOCKS_PER_SEC * 60.0f;//based on 60fps
       timer->m_last_clock = curr_clock;
}