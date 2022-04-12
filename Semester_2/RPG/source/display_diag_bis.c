/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** display_diag_bis
*/

#include "hero.h"

int display_diag_zero(info_t *info)
{
    static int mod = 0;
    char *str = "Explore \nthe world";
    if (mod == 0) {
        mod++;
        sfText_setString(info->quest[0], str);
    }
    info->time = sfClock_getElapsedTime(info->clock_bis);
    info->times = sfTime_asSeconds(info->time);
    if (info->times < 5) {
        sfRenderWindow_drawRectangleShape(info->window, info->box[0], NULL);
        sfRenderWindow_drawText(info->window, info->diag[0], NULL);
    }
    if (info->times >= 5 && info->times < 10) {
        sfRenderWindow_drawRectangleShape(info->window, info->box[1], NULL);
        sfRenderWindow_drawText(info->window, info->diag[1], NULL);
    }
    if (info->times >= 10)
        return -1;
    return 0;
}

int display_diag_three(info_t *info)
{
    static int mod = 0;
    char *str = "Search \nteammates";
    if (mod == 0) {
        mod++;
        sfText_setString(info->quest[1], str);
    }
    info->time = sfClock_getElapsedTime(info->clock_bis);
    info->times = sfTime_asSeconds(info->time);
    if (info->times < 5) {
        sfRenderWindow_drawRectangleShape(info->window, info->box[2], NULL);
        sfRenderWindow_drawText(info->window, info->diag[2], NULL);
    }
    if (info->times >= 5)
        return -1;
    return 0;
}

int display_diag_five(info_t *info)
{

    info->time = sfClock_getElapsedTime(info->clock_bis);
    info->times = sfTime_asSeconds(info->time);
    if (info->times < 5) {
        sfRenderWindow_drawRectangleShape(info->window, info->box[3], NULL);
        sfRenderWindow_drawText(info->window, info->diag[3], NULL);
    }
    if (info->times >= 5)
        return -1;
    return 0;
}

int display_diag_seven(info_t *info)
{
    static int mod = 0;
    char *str = "Fight the \nforeign force";
    if (mod == 0) {
        mod++;
        sfText_setString(info->quest[2], str);
    }
    info->time = sfClock_getElapsedTime(info->clock_bis);
    info->times = sfTime_asSeconds(info->time);
    if (info->times < 5) {
        sfRenderWindow_drawRectangleShape(info->window, info->box[4], NULL);
        sfRenderWindow_drawText(info->window, info->diag[4], NULL);
    }
    if (info->times >= 5)
        return -1;
    return 0;
}
