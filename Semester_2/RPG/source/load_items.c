/*
** EPITECH PROJECT, 2021
** load_items.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

int load_item(info_t *info, hero_status_t *hero_status,
              unsigned int pos_index, unsigned int path_index)
{
    sfTexture *t_sword = sfTexture_createFromFile
    (hero_status->paths_to_sprites[path_index], NULL);

    hero_status->loaded_items[path_index] = sfSprite_create();
    sfSprite_setTexture(hero_status->loaded_items[path_index], t_sword,sfTrue);
    sfSprite_setPosition(hero_status->loaded_items[path_index],
                         hero_status->inventory_positions[pos_index]);
    sfRenderWindow_drawSprite(info->window,
                              hero_status->loaded_items[path_index], NULL);
    return 0;
}
