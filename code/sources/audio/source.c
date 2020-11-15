#include "adi_core.h"

void adiCreateSource(AdiSource *source)
{
       alGenSources(1, &source->m_id);
}

void adiDestroySource(AdiSource *source)
{
       alSourcei(source->m_id, AL_BUFFER, 0);
       alDeleteSources(1, &source->m_id);
}

void adiSourceBindSoundData(AdiSource *source, const AdiSoundData *sound_data)
{
       alSourcei(source->m_id, AL_BUFFER, sound_data->m_buffer);
}

void adiSourcePlay(AdiSource *source)
{
       alSourcePlay(source->m_id);
}

void adiSourcePause(AdiSource *source)
{
       alSourcePause(source->m_id);
}

void adiSourceStop(AdiSource *source)
{
       alSourceStop(source->m_id);
}

bool adiSourceIsPlaying(AdiSource *source)
{
       ALint state;
       alGetSourcei(source->m_id, AL_SOURCE_STATE, &state);
       return state == AL_PLAYING;
}

void adiSourceEnableLooping(AdiSource *source)
{
       alSourcei(source->m_id, AL_LOOPING, AL_TRUE);
}

void adiSourceDisableLooping(AdiSource *source)
{
       alSourcei(source->m_id, AL_LOOPING, AL_FALSE);
}

void adiSourceSetPosition(AdiSource *source, float x, float y, float z)
{
       alSource3f(source->m_id, AL_POSITION, x, y, z);
}

void adiSourceSetVelocity(AdiSource *source, float x, float y, float z)
{
       alSource3f(source->m_id, AL_VELOCITY, x, y, z);
}