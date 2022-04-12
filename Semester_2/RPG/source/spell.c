/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** spell
*/

#include "struct.h"

int attack(info_t *info)
{
    sfVector2f position = sfRectangleShape_getPosition
    (info->player[info->node_player][info->node_player_bis]);

    info->node_player = 4;
    info->node_player_bis = 2;
    sfRectangleShape_setPosition
    (info->player[info->node_player][info->node_player_bis], position);
    return 0;
}

int shield(info_t *info)
{
    sfVector2f position = sfRectangleShape_getPosition
    (info->player[info->node_player][info->node_player_bis]);

    info->node_player = 4;
    info->node_player_bis = 0;
    sfRectangleShape_setPosition
    (info->player[info->node_player][info->node_player_bis], position);
    return 0;
}

int roar(info_t *info)
{
    sfVector2f position = sfRectangleShape_getPosition
    (info->player[info->node_player][info->node_player_bis]);

    info->node_player = 4;
    info->node_player_bis = 4;
    sfRectangleShape_setPosition
    (info->player[info->node_player][info->node_player_bis], position);
    return 0;
}

int rest(info_t *info)
{
    sfVector2f position = sfRectangleShape_getPosition
    (info->player[info->node_player][info->node_player_bis]);

    info->node_player = 4;
    info->node_player_bis = 3;
    sfRectangleShape_setPosition
    (info->player[info->node_player][info->node_player_bis], position);
    return 0;
}