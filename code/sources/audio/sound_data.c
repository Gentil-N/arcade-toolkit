#include "adi_core.h"

#include <stdlib.h>

bool adiLoadSoundData(AdiSoundData *sound_data, const AdiSoundDataSettings *settings)
{
       mp3dec_t mp3d;
       mp3dec_file_info_t info;
       if(mp3dec_load(&mp3d, settings->name, &info, NULL, NULL))
       {
              atk_api_dbg_error("failed to load mp3 file");
              goto error;
       }
       ALenum format;
       switch(info.channels)
       {
              case 1 :
              {
                     format = AL_FORMAT_MONO16;
                     break;
              }
              case 2 :
              {
                     format = AL_FORMAT_STEREO16;
                     break;
              }
              default :
              {
                     atk_api_dbg_error("invalid channel count");
                     goto error;
              }
       }
       alGenBuffers(1, &sound_data->m_buffer);
       alBufferData(sound_data->m_buffer, format, info.buffer, info.samples * sizeof(mp3d_sample_t), info.hz);
       if(alGetError() != AL_NO_ERROR)
       {
              atk_api_dbg_error("failed to push data into buffer");
              goto error;
       }
       free(info.buffer);
       return true;
error :
       free(info.buffer);
       return false;
}

void adiFreeSoundData(AdiSoundData *sound_data)
{
       alDeleteBuffers(1, &sound_data->m_buffer);
}