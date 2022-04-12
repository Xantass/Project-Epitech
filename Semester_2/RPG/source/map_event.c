/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** map_event
*/

#include "modif.h"

list_elem_t *map_zero(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {932, 57};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1700 && info->position_player.x > 1400 &&
        info->position_player.y < 1050 && info->position_player.y > 1000)
            switch_more(info, act, pos_player);
    return act;
}

list_elem_t *map_one(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {1490, 990};
    sfVector2f pos_player_bis = {825, 115};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1200 && info->position_player.x > 800 &&
        info->position_player.y < 40 && info->position_player.y > 0)
            switch_less(info, act, pos_player);
    if (info->position_player.x < 1200 && info->position_player.x > 800 &&
        info->position_player.y < 1050 && info->position_player.y > 1000) {
            switch_more(info, act, pos_player_bis);
    }
    return act;
}

static list_elem_t *map_two_bis(info_t *info, list_elem_t *act)
{
    sfVector2f pos_player_biss = {195, 65};

    if (info->position_player.x < 1600 && info->position_player.x > 1400 &&
        info->position_player.y < 1040 && info->position_player.y > 1000) {
            act = act->next->next;
            info->node_map = info->node_map + 2;
            info->position_player = pos_player_biss;
            sfRectangleShape_setPosition(info->player[info->node_player]
            [info->node_player_bis], info->position_player);
    }
    return act;
}

list_elem_t *map_two(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {932, 990};
    sfVector2f pos_player_bis = {1645, 515};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 900 && info->position_player.x > 700 &&
        info->position_player.y < 40 && info->position_player.y > 0) {
            switch_less(info, act, pos_player);
    }
    if (info->position_player.x < 40 && info->position_player.x > 0 &&
        info->position_player.y < 400 && info->position_player.y > 200) {
            switch_more(info, act, pos_player_bis);
    }
    return map_two_bis(info, act);
}

list_elem_t *map_three(info_t *info)
{
    list_elem_t *act = info->map->head;
    sfVector2f pos_player = {102, 300};

    for (int i = 0; i < info->node_map; ++i)
        act = act->next;
    if (info->position_player.x < 1900 && info->position_player.x > 1700 &&
        info->position_player.y < 550 && info->position_player.y > 500) {
            switch_less(info, act, pos_player);
    }
    return act;
}