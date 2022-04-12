/*
** EPITECH PROJECT, 2021
** init_inventory.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"
#include "graph.h"

int init_inventory(hero_status_t *hero_status)
{
    sfVector2f size = {830, 850};
    hero_status->inventory_shape = sfRectangleShape_create();
    sfVector2f pos = {1100, 40};
    const sfTexture *fouque = sfTexture_createFromFile
        ("./sprites/inventory/inventory.png", NULL);

    sfRectangleShape_setPosition(hero_status->inventory_shape, pos);
    sfRectangleShape_setTexture(hero_status->inventory_shape, fouque, sfTrue);
    sfRectangleShape_setSize(hero_status->inventory_shape, size);
    return 0;
}
