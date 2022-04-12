/*
** EPITECH PROJECT, 2021
** handle_inventory.c
** File description:
** functions
*/

#include <stdio.h>
#include "handle_inventory.h"

static int load_inventory(hero_status_t *hero_status, info_t *info)
{
    unsigned int pos_index = 0;

    for (unsigned int i = 0; i < 7; i++) {
        if (hero_status->inventory[i][0]) {
            load_item(info, hero_status, pos_index, i);
            pos_index++;
        }
    }
    return 0;
}

static int is_selected(sfFloatRect item_pos, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= (int) item_pos.left &&
        mouse_pos.y >= (int) item_pos.top &&
        mouse_pos.y <= (int) (item_pos.height + item_pos.top) &&
        mouse_pos.x <= (int) (item_pos.width + item_pos.left))
        return 1;
    return 0;
}

static int get_item(hero_status_t *hero_status, info_t *info)
{
    sfFloatRect coord = {0};

    for (unsigned int i = 0; i < 7; i++) {
        if (hero_status->loaded_items[i] != NULL) {
            coord = sfSprite_getGlobalBounds(hero_status->loaded_items[i]);
            if (is_selected(coord, info->mouse_pos) == 1)
                return i;
        }
    }
    return -1;
}

static int handle_drag_and_drop(hero_status_t *hero_status, info_t *info)
{
    static int is_pressed = -1;
    static int item_id = -1;
    static int is_equiped = -1;

    info->mouse_pos = sfMouse_getPosition(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (is_pressed == -1) {
            item_id = get_item(hero_status, info);
            is_pressed = 1;
        }
        else if (item_id != -1)
            is_equiped = reset_selection(hero_status, info, item_id);
    }
    else if (is_pressed == 1) {
        is_pressed = -1;
        key_released(is_equiped, item_id, hero_status);
        is_equiped = -1;
        is_pressed = -1;
        item_id = -1;
    }
    return 0;
}

int handle_inventory(hero_status_t *hero_status, info_t *info)
{
    if (hero_status->open > 0) {
        sfRenderWindow_drawRectangleShape(info->window,
                                          hero_status->inventory_shape, NULL);
        for (int i = 0; i < 3; ++i)
            sfRenderWindow_drawText(info->window, info->quest[i], NULL);
        handle_drag_and_drop(hero_status, info);
        load_equiped_stuff(hero_status, info);
        load_inventory(hero_status, info);
        print_stats(info, hero_status);
    }
    return 0;
}
