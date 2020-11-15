#include "adi_core.h"

void adiListenerSetPosition(float x, float y, float z)
{
       alListener3f(AL_POSITION, x, y, z);
}

void adiListenerSetOrientation(float at_x, float at_y, float at_z, float up_x, float up_y, float up_z)
{
       ALfloat orientation[] = {at_x, at_y, at_z, up_x, up_y, up_z};
       alListenerfv(AL_ORIENTATION, orientation);
}

void adiListenerSetVelocity(float x, float y, float z)
{
       alListener3f(AL_VELOCITY, x, y, z);
}