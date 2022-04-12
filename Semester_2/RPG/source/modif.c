/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** modif
*/

#include <stdio.h>
#include "struct.h"

int switch_more(info_t *info, list_elem_t *act, sfVector2f pos_player)
{
    act = act->next;
    info->node_map++;
    info->position_player = pos_player;
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int switch_less(info_t *info, list_elem_t *act, sfVector2f pos_player)
{
    act = act->prev;
    info->node_map--;
    info->position_player = pos_player;
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int switch_more_with_music(info_t *info, list_elem_t *act,
                           sfVector2f pos_player)
{
    act = act->next;
    info->node_map++;
    info->position_player = pos_player;
    //sfMusic_stop(info->music[info->node_music]);
    info->node_music++;
    //sfMusic_play(info->music[info->node_music]);
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}

int switch_less_with_music(info_t *info, list_elem_t *act,
                           sfVector2f pos_player)
{
    act = act->prev;
    info->node_map--;
    info->position_player = pos_player;
    //sfMusic_stop(info->music[info->node_music]);
    info->node_music--;
    //sfMusic_play(info->music[info->node_music]);
    sfRectangleShape_setPosition(info->player[info->node_player]
    [info->node_player_bis], info->position_player);
    return 0;
}