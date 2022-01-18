#pragma once

#include "MiniAudio.h"

struct Sound {
    ma_sound sound;
    void setLooping(bool looping = true);
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