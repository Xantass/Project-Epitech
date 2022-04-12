/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_map
*/

#include "graph.h"

sfRectangleShape **create_rectangle(sfTexture *texture, sfTexture *texture_)
{
    sfRectangleShape **rectangle = {0};
    sfVector2f position = {0, 0};
    sfVector2f size = {1920, 1080};

    rectangle = malloc(sizeof(sfRectangleShape *) * 2);
    rectangle[0] = sfRectangleShape_create();
    rectangle[1] = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle[0], position);
    sfRectangleShape_setSize(rectangle[0], size);
    sfRectangleShape_setTexture(rectangle[0], texture, sfFalse);
    sfRectangleShape_setPosition(rectangle[1], position);
    sfRectangleShape_setSize(rectangle[1], size);
    sfRectangleShape_setTexture(rectangle[1], texture_, sfFalse);
    return rectangle;
}