/*
** EPITECH PROJECT, 2021
** move_sprites.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

static void display_item(info_t *info,
                         hero_status_t *hero_status, unsigned int item_id)
{
    sfRenderWindow_drawSprite(info->window,
                              hero_status->loaded_items[item_id], NULL);
}

static int is_correctly_set(hero_status_t *hero_status,
                            info_t *info, unsigned int item_id)
{
    sfVector2f equipement_pos = hero_status->items_background_pos[item_id];

    if (info->mouse_pos.x >= equipement_pos.x &&
        info->mouse_pos.y >= equipement_pos.y &&
        info->mouse_pos.y <= (equipement_pos.y + 50) &&
        info->mouse_pos.x <= (equipement_pos.x + 50)) {
        return 1;
    }
    return 0;
}

static int move_item(hero_status_t *hero_status, info_t *info
                     , unsigned int item_id)
{
    sfVector2f pos = {(float) info->mouse_pos.x, (float) info->mouse_pos.y};

    sfSprite_setPosition(hero_status->loaded_items[item_id], pos);
    if (is_correctly_set(hero_status, info, item_id) == 1)
        return 1;
    display_item(info, hero_status, item_id);
    return 0;
}

int reset_selection(hero_status_t *hero_status, info_t *info, 
                    unsigned int item_id)
{
    hero_status->inventory[item_id][0] = 0;
    return move_item(hero_status, info, item_id);
}

void display_background(hero_status_t *hero_status, info_t *info,
                               unsigned int item_id)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfTexture *bg =
        sfTexture_createFromFile("./sprites/inventory/fond_gris.png", NULL);
    sfRectangleShape_setTexture(background, bg, 0);
    sfRectangleShape_setPosition(background,
                                 hero_status->items_background_pos[item_id]);
    sfRectangleShape_setSize(background, (sfVector2f) {71, 60});
    sfRenderWindow_drawRectangleShape(info->window, background, NULL);
}
