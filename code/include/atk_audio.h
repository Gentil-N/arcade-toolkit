#ifndef __AUDIO_H__
#define __AUDIO_H__

#ifndef __ATK_H__
#include "atk.h"
#endif //__ATK_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

       ATK_API bool adiInit();
       ATK_API void adiEnd();

       typedef struct AdiSoundData AdiSoundData;

       typedef struct AdiSoundDataSettings
       {
              const char *name;
       } AdiSoundDataSettings;

       ATK_API bool adiLoadSoundData(AdiSoundData *sound_data, const AdiSoundDataSettings *settings);
       ATK_API void adiFreeSoundData(AdiSoundData *sound_data);

       typedef struct AdiSource AdiSource;

       ATK_API void adiCreateSource(AdiSource *source);
       ATK_API void adiDestroySource(AdiSource *source);
       ATK_API void adiSourceBindSoundData(AdiSource *source, const AdiSoundData *sound_data);
       ATK_API void adiSourcePlay(AdiSource *source);
       ATK_API void adiSourcePause(AdiSource *source);
       ATK_API void adiSourceStop(AdiSource *source);
       ATK_API bool adiSourceIsPlaying(AdiSource *source);
       ATK_API void adiSourceEnableLooping(AdiSource *source);
       ATK_API void adiSourceDisableLooping(AdiSource *source);
       ATK_API void adiSourceSetPosition(AdiSource *source, float x, float y, float z);
       ATK_API void adiSourceSetPositionPack(AdiSource *source, const AtkPack3f *pack);
       ATK_API void adiSourceSetVelocity(AdiSource *source, float x, float y, float z);
       ATK_API void adiSourceSetVelocityPack(AdiSource *source, const AtkPack3f *pack);

       ATK_API void adiListenerSetPosition(float x, float y, float z);
       ATK_API void adiListenerSetPositionPack(const AtkPack3f *pack);
       ATK_API void adiListenerSetOrientation(float at_x, float at_y, float at_z, float up_x, float up_y, float up_z);
       ATK_API void adiListenerSetOrientationPack(const AtkPack3f *at_pack, const AtkPack3f *up_pack);
       ATK_API void adiListenerSetVelocity(float x, float y, float z);
       ATK_API void adiListenerSetVelocityPack(const AtkPack3f *pack);

#ifdef __cplusplus
}
#endif //__cplusplus

struct AdiSoundData
{
       uint32_t m_buffer;
#ifdef __cplusplus
       AdiSoundData() : m_buffer(0)
       {
       }
       AdiSoundData(const AdiSoundDataSettings &settings) : m_buffer(0)
       {
              adiLoadSoundData(this, &settings);
       }
       AdiSoundData(const AdiSoundData &sound_data) = delete; //to avoid destroy errors
       AdiSoundData(AdiSoundData &&sound_data)
       {
              m_buffer = sound_data.m_buffer;
              sound_data.m_buffer = 0;
       }
       ~AdiSoundData()
       {
              if (m_buffer == 0)
              {
                     return;
              }
              adiFreeSoundData(this);
       }
       AdiSoundData &operator=(const AdiSoundData &sound_data) = delete;
       AdiSoundData &operator=(AdiSoundData &&sound_data)
       {
              m_buffer = sound_data.m_buffer;
              sound_data.m_buffer = 0;
              return *this;
       }
       void load(const AdiSoundDataSettings &settings)
       {
              adiLoadSoundData(this, &settings);
       }
       void free()
       {
              adiFreeSoundData(this);
              m_buffer = 0;
       }
#endif //___cplusplus
};

struct AdiSource
{
       uint32_t m_id;
#ifdef __cplusplus
       AdiSource() : m_id(0) //create must be called
       {
       }
       AdiSource(const AdiSource &source) = delete; //to avoid destroy errors
       AdiSource(AdiSource &&source)
       {
              m_id = source.m_id;
              source.m_id = 0;
       }
       ~AdiSource()
       {
              if(m_id == 0)
              {
                     return;
              }
              adiDestroySource(this);
       }
       AdiSource &operator=(const AdiSource &source) = delete;
       AdiSource &operator=(AdiSource &&source)
       {
              m_id = source.m_id;
              source.m_id = 0;
              return *this;
       }
       void create()
       {
              adiCreateSource(this);
       }
       void destroy()
       {
              adiDestroySource(this);
       }
       void bindSource(AdiSoundData &sound_data)
       {
              adiSourceBindSoundData(this, &sound_data);
       }
       void play()
       {
              adiSourcePlay(this);
       }
       void pause()
       {
              adiSourcePause(this);
       }
       void stop()
       {
              adiSourceStop(this);
       }
       bool isPlaying()
       {
              return adiSourceIsPlaying(this);
       }
       void enableLooping()
       {
              adiSourceEnableLooping(this);
       }
       void disableLooping()
       {
              adiSourceDisableLooping(this);
       }
       void setPosition(float x, float y, float z)
       {
              adiSourceSetPosition(this, x, y, z);
       }
       void setPosition(const AtkPack3f &pack)
       {
              adiSourceSetPositionPack(this, &pack);
       }
       void setVelocity(float x, float y, float z)
       {
              adiSourceSetVelocity(this, x, y, z);
       }
       void setVelocity(const AtkPack3f &pack)
       {
              adiSourceSetVelocityPack(this, &pack);
       }
#endif //___cplusplus
};

#endif //__AUDIO_H__