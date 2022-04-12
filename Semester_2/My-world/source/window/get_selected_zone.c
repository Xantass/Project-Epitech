/*
** EPITECH PROJECT, 2021
** get_selected_zone.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

void close_selected_zone(info_t *info)
{
    sfVector2f new = sfRenderWindow_mapPixelToCoords
    (info->window, info->mouse_pos, info->view);

    info->select_zone.end_point = new;
    info->select_zone.is_selected = 0;
}

void get_selected_zone(info_t *info)
{
    sfVector2f new = sfRenderWindow_mapPixelToCoords
    (info->window, info->mouse_pos, info->view);

    info->select_zone.starting_point = new;
    info->select_zone.is_selected = 1;
}
