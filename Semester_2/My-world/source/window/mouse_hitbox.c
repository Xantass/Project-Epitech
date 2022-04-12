/*
** EPITECH PROJECT, 2021
** mouse_hitbox.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

void set_mouse_hitbox(info_t *info)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f new_pos = (sfVector2f) {info->mouse_pos.x, info->mouse_pos.y};
    sfVector2f size = {15, 15};

    new_pos.x += 20;
    new_pos.y -= 10;
    sfRectangleShape_setPosition(hitbox, new_pos);
    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRenderWindow_drawRectangleShape(info->window, hitbox, NULL);
    info->hitbox = hitbox;
}
