#define MINIAUDIO_IMPLEMENTATION
#include "MiniAudio.h"
#include "Audio.h"

void Sound::setPosition(float x, float y, float z){
    ma_sound_set_position(&sound, x, y, z);
}

void Sound::setDirection(float x, float y, float z){
    ma_sound_set_direction(&sound, x, y, z);
}

void Sound::setVelocity(float x, float y, float z){
    ma_sound_set_velocity(&sound, x, y, z);
}

void Sound::setDirectionalAttenuationFactor(float attenuationFactor){
    ma_sound_set_directional_attenuation_factor(&sound, attenuationFactor);
}

void Sound::setDopplerFactor(float dopperFactor){
    ma_sound_set_doppler_factor(&sound, dopperFactor);
}

void Sound::setMinDistance(float minDistance){
    ma_sound_set_min_distance(&sound, minDistance);
}

void Sound::setMaxDistance(float maxDistance){
    ma_sound_set_max_distance(&sound, maxDistance);
}

void Sound::setMinGain(float minGain){
    ma_sound_set_min_gain(&sound, minGain);
}

void Sound::setMaxGain(float maxGain){
    ma_sound_set_max_gain(&sound, maxGain);
}

void Sound::setPitch(float pitch){
    ma_sound_group_set_pitch(&sound, pitch);
}

void Sound::setVolume(float volume){
    ma_sound_set_volume(&sound, volume);
}

void Sound::setLooping(bool looping) {
    ma_sound_set_looping(&sound, looping);
}

Sound::~Sound() {
    ma_sound_uninit(&sound);
}

Audio::Audio() {
    engine = new ma_engine;
}

int Audio::init(const ma_engine_config* pConfig) {
    return ma_engine_init(pConfig, engine);
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

Audio::~Audio(){
    ma_engine_uninit(engine);
}
