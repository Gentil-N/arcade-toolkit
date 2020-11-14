#define MINIMP3_IMPLEMENTATION
#include "adi_core.h"

bool adiInit()
{
       ALCdevice *device = alcOpenDevice(NULL);
       if (!device)
       {
              atk_error(ATK_MSG_INIT_FAILED, "failed to open device");
              return false;
       }
       ALCcontext *context = alcCreateContext(device, NULL);
       if (!context)
       {
              atk_error(ATK_MSG_INIT_FAILED, "failed to create context");
              return false;
       }
       if (!alcMakeContextCurrent(context))
       {
              atk_error(ATK_MSG_INIT_FAILED, "failed to make current context");
              return false;
       }
       atk_info("audio module initialized");
       return true;
}

void adiEnd()
{
       ALCcontext *Context = alcGetCurrentContext();
       ALCdevice *Device = alcGetContextsDevice(Context);
       alcMakeContextCurrent(NULL);
       alcDestroyContext(Context);
       alcCloseDevice(Device);
       atk_info("audio module ended");
}
/*
ALuint buffer;
ALuint source;

void adiTest(const char* file_name)
{
       mp3dec_t mp3d;
       mp3dec_file_info_t info;
       if(mp3dec_load(&mp3d, file_name, &info, NULL, NULL))
       {
              atk_error(ATK_MSG_LIB_REPORT, "failed to load mp3 file");
       }
       ALenum format = AL_FORMAT_STEREO16;
       alGenBuffers(1, &buffer);
       alBufferData(buffer, format, info.buffer, info.samples * sizeof(mp3d_sample_t), info.hz);
       if(alGetError() != AL_NO_ERROR)
       {
              atk_error(ATK_MSG_LIB_REPORT, "failed to push data into buffer");
       }
       alGenSources(1, &source);
       alSourcei(source, AL_BUFFER, buffer);

       alSourcePlay(source);

       ALint status;
       do
       {
              ALfloat time = 0.f;
              alGetSourcef(source, AL_SEC_OFFSET, &time);
              atk_vinfo("%f", time);
              alGetSourcei(source, AL_SOURCE_STATE, &status);
       } while (status == AL_PLAYING);
       
       alSourceStop(source);
       alSourcei(source, AL_BUFFER, 0);
       alDeleteSources(1, &source);
       alDeleteBuffers(1, &buffer);
       free(info.buffer);
}*/