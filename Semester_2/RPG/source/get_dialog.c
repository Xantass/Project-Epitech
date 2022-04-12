/*
** EPITECH PROJECT, 2021
** get_dialog.c
** File description:
** functions
*/

#include "struct.h"
#include "get_dialog.h"

int get_enter_key(info_t *info)
{
    display_sound(info, "./Music/sound_effects/classic_interaction.wav", 70);
    sfClock_restart(info->clock_bis);
    return 0;
}
