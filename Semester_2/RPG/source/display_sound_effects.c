/*
** EPITECH PROJECT, 2021
** display_sound_effects.c
** File description:
** functions
*/

#include <stdio.h>
#include "struct.h"

void display_sound(info_t *info, char *path, float volume)
{
    static float last_sound = 0;
    static int is_first = -1;
    float vol = 0;

    if (last_sound + (0.1) <= info->times) {
        if (is_first == 1)
            sfMusic_destroy(info->actual_sound);
        info->actual_sound = sfMusic_createFromFile(path);
        if (volume <= (float) info->sound_volume)
            vol = volume;
        else
            vol = (float) info->sound_volume;
        if (info->is_sound_effects == 1) {
            sfMusic_setVolume(info->actual_sound, vol);
            sfMusic_play(info->actual_sound);
        }
        is_first = 1;
        last_sound = info->times;
    }
}
