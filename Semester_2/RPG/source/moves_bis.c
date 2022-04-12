/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** moves_bis
*/

#include <stdio.h>
#include "struct.h"

int move_up_bis(info_t *info, float y)
{
    info->position_player.y = info->position_player.y + y;
    if (info->node_player != 3) {
        info->node_player = 3;
        info->node_player_bis = 0;
    }
    else {
        info->node_player_bis++;
        if (info->node_player_bis > 2)
            info->node_player_bis = 0;
    }
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int move_down_bis(info_t *info, float y)
{
    info->position_player.y = info->position_player.y + y;
    if (info->node_player != 0) {
        info->node_player = 0;
        info->node_player_bis = 0;
    }
    else {
        info->node_player_bis++;
        if (info->node_player_bis > 2)
            info->node_player_bis = 0;
    }
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int move_right_bis(info_t *info, float x)
{
    info->position_player.x = info->position_player.x + x;
    if (info->node_player != 2) {
        info->node_player = 2;
        info->node_player_bis = 0;
    }
    else {
        info->node_player_bis++;
        if (info->node_player_bis > 2)
            info->node_player_bis = 0;
    }
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int move_left_bis(info_t *info, float x)
{
    info->position_player.x = info->position_player.x + x;
    if (info->node_player != 1) {
        info->node_player = 1;
        info->node_player_bis = 0;
    }
    else {
        info->node_player_bis++;
        if (info->node_player_bis > 2)
            info->node_player_bis = 0;
    }
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}