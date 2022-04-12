/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** event
*/

#include <stdio.h>
#include "event.h"

static int move_event(info_t *info, hero_status_t *hero_status)
{
    for (int i = 0; i < 4; ++i) {
        if (sfKeyboard_isKeyPressed(moves[i].key))
            moves[i].link_my(info, hero_status);
    }
    return 0;
}

static int map_event(info_t *info)
{
    info->node_act = map[info->node_map].my(info);
    return 0;
}

static int special_input(hero_status_t *hero_status, info_t *info)
{
    static float last_mod = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        return -1;
    else if (sfKeyboard_isKeyPressed(sfKeyI) && last_mod +(0.1)<=info->times) {
        hero_status->open *= -1;
        last_mod = info->times;
    }
    return 0;
}

int events(info_t *info, hero_status_t *hero_status)
{
    if (special_input(hero_status, info) == -1)
        return -1;
    move_event(info, hero_status);
    map_event(info);
    if (info->node_map == 9)
        alea(info, hero_status);
    return 0;
}