/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** check_move_part_three
*/

#include "struct.h"

int check_map_zero_bis(info_t *info, float x, float y)
{
    if (info->position_player.y+ y < 500 && info->position_player.x+ x > 840
        && info->position_player.x+ x < 1920)
        return -1;
    if (info->position_player.x+ x >= 1665 && info->position_player.x+ x <1920)
        return -1;
    return 0;
}

int check_map_five_bis(info_t *info, float x, float y)
{
    if (info->position_player.x + x > 1385 && info->position_player.y + y >720)
        return -1;
    if (info->position_player.y + y > 510 && info->position_player.y + y<750 &&
        info->position_player.x + x > 725 && info->position_player.x + x <1295)
        return -1;
    if (info->position_player.y + y > 240 && info->position_player.y + y <750&&
        info->position_player.x + x > 1280 && info->position_player.x + x<1400)
        return -1;
    if (info->position_player.x + x > 245 && info->position_player.x + x < 1280&&
        info->position_player.y + y< 345)
        return -1;
    if (info->position_player.y + y > 340 && info->position_player.y + y <490&&
        info->position_player.x + x > 725 && info->position_player.x + x <1280)
        return -1;
    return 0;
}

int check_map_seven_bis(info_t *info, float x, float y)
{
    if (info->position_player.x + x > 1085 && info->position_player.y + y > 945
        && info->position_player.x + x < 1565)
        return -1;
    if (info->position_player.x + x < 1910 && info->position_player.x+ x>1810&&
        info->position_player.y + y < 960 && info->position_player.y+ y > 860)
            return -1;
    return 0;
}

int check_map_height_bis(info_t *info, float x, float y)
{
    if (info->position_player.y + y < 250 && info->position_player.x + x >1385)
        return -1;
    if (info->position_player.x + x > 935 && info->position_player.x + x<1385&&
        info->position_player.y + y > 115 && info->position_player.y + y<250)
        return -1;
    if (info->position_player.x + x > 485 && info->position_player.x + x<1280&&
        info->position_player.y + y > 450 && info->position_player.y + y<685)
        return -1;
    if (info->position_player.x + x > 950 && info->position_player.x + x<1280&&
        info->position_player.y + y > 235 && info->position_player.y + y<490)
        return -1;
    if (info->position_player.x + x > 380 && info->position_player.x + x<830&&
        info->position_player.y + y > 115 && info->position_player.y + y<250)
        return -1;
    if (info->position_player.x + x > 485 && info->position_player.x + x<815&&
        info->position_player.y + y > 235 && info->position_player.y + y<490)
        return -1;
    return 0;
}