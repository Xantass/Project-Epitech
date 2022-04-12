/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** moves
*/

#include <stdio.h>
#include "check_move.h"
#include "moves_bis.h"
#include "alea.h"
#include "hero.h"
#include "moves.h"

int move_up(info_t *info, hero_status_t *hero_status)
{
    float x = 0;
    float y = -15;

    if (check_map[info->node_map].my(info, x, y) == 0){
        move_up_bis(info, y);
        //alea(info, hero_status);
    }
    else {
        display_sound(info, "./Music/sound_effects/wall_sound.wav", 70);
    }
    return 0;
}

int move_down(info_t *info, hero_status_t *hero_status)
{
    float x = 0;
    float y = 15;

    if (check_map[info->node_map].my(info, x, y) == 0){
        move_down_bis(info, y);
        //alea(info, hero_status);
    }
    else
        display_sound(info, "./Music/sound_effects/wall_sound.wav", 70);
    return 0;
}

int move_right(info_t *info, hero_status_t *hero_status)
{
    float x = 15;
    float y = 0;

    if (check_map[info->node_map].my(info, x, y) == 0){
        move_right_bis(info, x);
        //alea(info, hero_status);
    }
    else
        display_sound(info, "./Music/sound_effects/wall_sound.wav", 70);
    return 0;
}

int move_left(info_t *info, hero_status_t *hero_status)
{
    float x = -15;
    float y = 0;

    if (check_map[info->node_map].my(info, x, y) == 0){
        move_left_bis(info, x);
        //alea(info, hero_status);
    }
    else
        display_sound(info, "./Music/sound_effects/wall_sound.wav", 70);
    return 0;
}
