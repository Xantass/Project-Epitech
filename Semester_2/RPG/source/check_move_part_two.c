/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** check_move_bis
*/

#include "check_move_bis.h"

int check_map_five(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x + x < 1265 && info->position_player.y + y > 780)
        return -1;
    if (info->position_player.x + x < 575 && info->position_player.y + y > 360)
        return -1;
    if (info->position_player.x + x < 245)
        return -1;
    if (info->position_player.x + x < 1460 && info->position_player.x + x > 250
        && info->position_player.y + y < 190)
        return -1;
    if (info->position_player.x + x > 1460 && info->position_player.y + y >345)
        return -1;
    if (info->position_player.x + x < 1475 && info->position_player.x+ x>1340&&
        info->position_player.y + y < 360 && info->position_player.y+ y > 195)
            return -1;
    if (info->position_player.x + x < 1750 && info->position_player.x+ x>1650&&
        info->position_player.y + y < 120 && info->position_player.y+ y > 20)
            return -1;
    return check_map_five_bis(info, x, y);
}

int check_map_six(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x + x < 805 && info->position_player.y + y > 690)
        return -1;
    if (info->position_player.x + x < 370 && info->position_player.y + y > 270
        && info->position_player.y + y < 715)
        return -1;
    if (info->position_player.x + x < 805 && info->position_player.y + y < 285)
        return -1;
    if (info->position_player.x + x > 955 && info->position_player.y + y > 690)
        return -1;
    if (info->position_player.x + x > 1375 && info->position_player.y + y > 270
        && info->position_player.y + y < 715)
        return -1;
    if (info->position_player.x + x > 955 && info->position_player.y + y < 285)
        return -1;
    return 0;
}

int check_map_seven(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x + x< 110)
        return -1;
    if (info->position_player.x + x < 680 && info->position_player.y + y < 990)
        return -1;
    if (info->position_player.x + x > 665 && info->position_player.y + y <840&&
        info->position_player.x + x < 800)
        return -1;
    if (info->position_player.x + x > 950 && info->position_player.y + y <840&&
        info->position_player.x + x < 1100)
        return -1;
    if (info->position_player.x + x > 1085 && info->position_player.y + y < 930
        && info->position_player.x + x < 1565)
        return -1;
    if (info->position_player.y + y <840 && info->position_player.x + x > 1550)
        return -1;
    return check_map_seven_bis(info, x, y);
}

int check_map_height(info_t *info, float x, float y)
{
    if (info->position_player.x + x <= 0 || info->position_player.x+ x > 1870||
        info->position_player.y + y <= 0 || info->position_player.y+ y > 1030)
        return -1;
    if (info->position_player.x + x < 815 && info->position_player.y + y > 760)
        return -1;
    if (info->position_player.x + x < 260 && info->position_player.y + y < 775
        && info->position_player.y + y > 235)
        return -1;
    if (info->position_player.y + y < 250 && info->position_player.x + x < 365)
        return -1;
    if (info->position_player.y + y < 100)
        return -1;
    if (info->position_player.x + x > 935 && info->position_player.y + y > 760)
        return -1;
    if (info->position_player.x + x > 1490  && info->position_player.y + y <775
        && info->position_player.y + y > 235)
        return -1;
    return check_map_height_bis(info, x, y);
}