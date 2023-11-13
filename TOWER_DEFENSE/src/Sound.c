#include "../include/Sound.h"

void play_sound(MLV_Music* music) {
    MLV_init_audio();

    music = MLV_load_music("res/game.ogg");
    MLV_play_music(music, 100.0, -1);
}

void free_music(MLV_Music* music) {
    MLV_stop_music();
    MLV_free_music(music);
}