#pragma once

#include "MiniAudio.h"

struct Sound {
    void setPosition(float x, float y, float z);
    void setDirection(float x, float y, float z);
    void setVelocity(float x, float y, float z);
    void setDirectionalAttenuationFactor(float attenuationFactor);
    void setDopplerFactor(float setDopplerFactor);
    void setMinDistance(float minDistance);
    void setMaxDistance(float maxDistance);
    void setMinGain(float minGain);
    void setMaxGain(float maxGain);
    void setPitch(float pitch);
    void setVolume(float volume);
    void setLooping(bool looping = true);
    ~Sound();
    ma_sound sound;
};

class Audio {
public:
    Audio();
    int init(const ma_engine_config* pConfig = nullptr);
    int load(Sound* sound, const char* file, ma_uint32 flags = 0, ma_sound_group* pGroup = nullptr, ma_fence* pDoneFence = nullptr);
    int load(Sound& sound, const char* file, ma_uint32 flags = 0, ma_sound_group* pGroup = nullptr, ma_fence* pDoneFence = nullptr);
    int play(Sound* sound);
    int play(Sound& sound);
    int stop(Sound* sound);
    int stop(Sound& sound);
    float getLength(Sound* sound);
    float getLength(Sound& sound);
    ~Audio();
private:
    ma_engine* engine;
};