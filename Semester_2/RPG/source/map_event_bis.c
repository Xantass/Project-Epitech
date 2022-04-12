/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** map_event_bis
*/

#include "modif.h"

list_elem_t *map_four(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player_bis = {1325, 930};
    sfVector2f pos_player = {1500, 955};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1525 && info->position_player.x > 1490 &&
        info->position_player.y < 850 && info->position_player.y > 830) {
            switch_more_with_music(info, act, pos_player_bis);
    }
    if (info->position_player.x < 300 && info->position_player.x > 100 &&
        info->position_player.y < 50 && info->position_player.y > 0) {
            act = act->prev->prev;
            info->node_map = info->node_map - 2;
            info->position_player = pos_player;
            sfRectangleShape_setPosition(info->player[info->node_player]
            [info->node_player_bis], info->position_player);
    }
    return act;
}

list_elem_t *map_five(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {1395, 845};
    sfVector2f pos_player_bis = {880, 885};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1400 && info->position_player.x > 1300 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
            switch_less_with_music(info, act, pos_player);
    }
    if (info->position_player.x < 300 && info->position_player.x > 200 &&
        info->position_player.y < 40 && info->position_player.y > 0) {
            switch_more(info, act, pos_player_bis);
    }
    return act;
}

list_elem_t *map_six(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {245, 55};
    sfVector2f pos_player_bis = {305, 1005};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1000 && info->position_player.x > 700 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
            switch_less(info, act, pos_player);
    }
    if (info->position_player.x < 950 && info->position_player.x > 800 &&
        info->position_player.y < 40 && info->position_player.y > 0) {
            switch_more(info, act, pos_player_bis);
    }
    return act;
}

list_elem_t *map_seven(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {880, 90};
    sfVector2f pos_player_bis = {875, 925};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 200 && info->position_player.x > 100 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
            switch_less(info, act, pos_player);
    }
    if (info->position_player.x < 1000 && info->position_player.x > 800 &&
        info->position_player.y < 200 && info->position_player.y > 150) {
            switch_more(info, act, pos_player_bis);
    }
    return act;
}

list_elem_t *map_height(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {880, 295};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 900 && info->position_player.x > 800 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
            switch_less(info, act, pos_player);
    }
    if (info->position_player.x < 900 && info->position_player.x > 800 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
        act = act->next;
        info->node_map++;
        info->position_player = pos_player;
        sfRectangleShape_setPosition(info->player[info->node_player]
        [info->node_player_bis], info->position_player);
    }
    return act;
}