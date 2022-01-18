#define MINIAUDIO_IMPLEMENTATION
#include "MiniAudio.h"
#include "Audio.h"

void Sound::setLooping(bool looping) {
    ma_sound_set_looping(&sound, looping);
}

Audio::Audio() {
    engine = new ma_engine;
}

int Audio::initEngine(const ma_engine_config* pConfig) {
    return ma_engine_init(pConfig, engine);
}

void Audio::stopEngine() {
    ma_engine_uninit(engine);
}

int Audio::load(Sound* sound, const char *file, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence) {
    return ma_sound_init_from_file(engine, file, flags, pGroup, pDoneFence, &sound->sound);
}

int Audio::load(Sound& sound, const char *file, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence) {
    return load(&sound, file, flags, pGroup, pDoneFence);
}

int Audio::play(Sound *sound) {
    return ma_sound_start(&sound->sound);
}

int Audio::play(Sound &sound) {
    return play(&sound);
}

int Audio::stop(Sound *sound) {
    return ma_sound_stop(&sound->sound);
}

int Audio::stop(Sound &sound) {
    return stop(&sound);
}

float Audio::getLength(Sound* sound) {
    ma_uint64 lengthPcm;
    ma_result result = ma_sound_get_length_in_pcm_frames(&sound->sound, &lengthPcm);
    if (result != MA_SUCCESS)
        return result;
    return static_cast<float>(lengthPcm) / static_cast<float>(ma_engine_get_sample_rate(engine));
}

float Audio::getLength(Sound& sound){
    return getLength(&sound);
}
