#define MINIAUDIO_IMPLEMENTATION
#include "MiniAudio.h"
#include "iostream"

ma_result sound_get_length_in_seconds(ma_engine* engine, ma_sound* sound, float* length)
{
    ma_uint64 lengthPcm;
    ma_result result = ma_sound_get_length_in_pcm_frames(sound, &lengthPcm);
    if (result != MA_SUCCESS)
        return result;  // Failed to retrieve the length.

    *length = static_cast<float>(lengthPcm) / static_cast<float>(ma_engine_get_sample_rate(engine));
    return MA_SUCCESS;
}

int main(){
    ma_engine engine;
    ma_result result = ma_engine_init(nullptr, &engine);
    if(result != MA_SUCCESS)
        return result;
    ma_sound sound;
    ma_sound_init_from_file(&engine, "../test.mp3", 0, nullptr, nullptr, &sound);
    ma_sound_start(&sound);
    float res;
    sound_get_length_in_seconds(&engine, &sound, &res);
    std::cout << res << "\n";
    while(true);
}
