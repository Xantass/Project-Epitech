/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** check_move
*/

#include "check_move_bis.h"

int check_map_zero(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x + x < 1365 && info->position_player.y+ y >650&&
         info->position_player.y + y < 1080)
        return -1;
    if (info->position_player.x + x < 915 && info->position_player.y+ y >590&&
         info->position_player.y + y < 1080)
        return -1;
    if (info->position_player.x + x < 675 && info->position_player.y+ y >515&&
         info->position_player.y + y < 1080)
        return -1;
    if (info->position_player.x + x < 450 && info->position_player.y+ y > 0&&
         info->position_player.y + y < 1080)
        return -1;
    if (info->position_player.y+ y > 0 && info->position_player.y+ y < 245)
        return -1;
    if (info->position_player.x + x < 535 && info->position_player.x+ x > 400&&
        info->position_player.y + y < 340 && info->position_player.y+ y > 250)
        return -1;
    return check_map_zero_bis(info, x, y);
}

int check_map_one(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x+ x < 572 && info->position_player.x+ x > 0)
        return -1;
    if (info->position_player.x+ x > 1307 && info->position_player.x+ x < 1920)
        return -1;
    if (info->position_player.y+ y > 432 && info->position_player.y+ y< 657 &&
        info->position_player.x+ x < 917 && info->position_player.x+ x> 0)
        return -1;
    if (info->position_player.y+ y > 432 && info->position_player.y+ y< 657 &&
        info->position_player.x+ x > 962 && info->position_player.x+ x< 1920)
        return -1;
    return 0;
}

int check_map_two(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x+ x < 700 && info->position_player.y+ y < 190)
        return -1;
    if (info->position_player.x+ x > 1065 && info->position_player.y+ y < 580)
        return -1;
    if (info->position_player.x+ x < 915 && info->position_player.y+ y > 445)
        return -1;
    return 0;
}

int check_map_three(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.y + y < 350)
        return -1;
    if (info->position_player.y + y > 710)
        return -1;
    if (info->position_player.x + x < 192 && info->position_player.x+ x > 57 &&
        info->position_player.y + y < 578 && info->position_player.y+ y > 468)
        return -1;
    return 0;
}

int check_map_four(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.y + y > 850)
        return -1;
    if (info->position_player.x + x < 225 && info->position_player.y + y > 290)
        return -1;
    if (info->position_player.x + x > 1305 && info->position_player.y + y <665)
        return -1;
    return 0;
}