/*
** EPITECH PROJECT, 2021
** load_equiped_stuff.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"
#include "load_equiped_stuff.h"

static void load_equiped_item(hero_status_t *hero_status,
                              info_t *info, unsigned int item_id)
{
    sfTexture *t_item =
        sfTexture_createFromFile(hero_status->paths_to_sprites[item_id], NULL);

    sfSprite_setTexture(hero_status->loaded_items[item_id], t_item, sfTrue);
    sfSprite_setPosition(hero_status->loaded_items[item_id],
                         hero_status->equiped_pos[item_id]);
    sfRenderWindow_drawSprite(info->window,
                              hero_status->loaded_items[item_id], NULL);
}

static int get_upgrade(hero_status_t *hero_status, unsigned int itm_id)
{
    up_stats[itm_id].link(hero_status, 0);
    return 0;
}

void load_equiped_stuff(hero_status_t *hero_status, info_t *info)
{
    for (unsigned int item_id = 0; item_id < 7; item_id++) {
        if (hero_status->equiped_stuff[item_id] == 1) {
            display_background(hero_status, info, item_id);
            load_equiped_item(hero_status, info, item_id);
            get_upgrade(hero_status, item_id);
        }
        else {
            up_stats[item_id].link(hero_status, 1);
        }
    }
}
