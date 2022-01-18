#pragma once

#ifndef MINIAUDIO_IMPLEMENTATION
#define MINIAUDIO_IMPLEMENTATION
#endif
#include "MiniAudio.h"

typedef ma_sound Sound;

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
private:
    ma_engine* engine;
};

Audio::Audio() {
    engine = new ma_engine;
}

int Audio::init(const ma_engine_config* pConfig) {
    ma_result result = ma_engine_init(pConfig, engine);
    return result;
}

int Audio::load(Sound* sound, const char *file, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence) {
    return ma_sound_init_from_file(engine, file, flags, pGroup, pDoneFence, sound);
}

int Audio::load(Sound& sound, const char *file, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence) {
    return load(&sound, file, flags, pGroup, pDoneFence);
}

int Audio::play(Sound *sound) {
    return ma_sound_start(sound);
}

int Audio::play(Sound &sound) {
    return play(&sound);
}

int Audio::stop(Sound *sound) {
    return ma_sound_stop(sound);
}

int Audio::stop(Sound &sound) {
    return stop(&sound);
}

float Audio::getLength(Sound* sound) {
    ma_uint64 lengthPcm;
    ma_result result = ma_sound_get_length_in_pcm_frames(sound, &lengthPcm);
    if (result != MA_SUCCESS)
        return result;
    return static_cast<float>(lengthPcm) / static_cast<float>(ma_engine_get_sample_rate(engine));
}

float Audio::getLength(Sound& sound){
    return getLength(&sound);
}
