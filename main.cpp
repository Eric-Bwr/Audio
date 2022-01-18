#include "Audio.h"
#include "iostream"

int main(){
    Audio audio;
    audio.init();
    Sound sound;
    audio.load(sound, "../test.mp3");
    audio.play(sound);
    audio.getLength(sound);
    std::cin.get();
    audio.stop(sound);
    std::cin.get();
}
