#include "adi_core.h"

void adiListenerSetPosition(float x, float y, float z)
{
       alListener3f(AL_POSITION, x, y, z);
}

void adiListenerSetPositionPack(const AtkPack3f *pack)
{
       alListener3f(AL_POSITION, pack->x, pack->y, pack->z);
}

void adiListenerSetOrientation(float at_x, float at_y, float at_z, float up_x, float up_y, float up_z)
{
       ALfloat orientation[] = {at_x, at_y, at_z, up_x, up_y, up_z};
       alListenerfv(AL_ORIENTATION, orientation);
}

void adiListenerSetOrientationPack(const AtkPack3f *at_pack, const AtkPack3f *up_pack)
{
       ALfloat orientation[] = {at_pack->x, at_pack->y, at_pack->z, up_pack->x, up_pack->y, up_pack->z};
       alListenerfv(AL_ORIENTATION, orientation);
}

void adiListenerSetVelocity(float x, float y, float z)
{
       alListener3f(AL_VELOCITY, x, y, z);
}

void adiListenerSetVelocityPack(const AtkPack3f *pack)
{
       alListener3f(AL_VELOCITY, pack->x, pack->y, pack->z);
}