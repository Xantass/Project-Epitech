/*
** EPITECH PROJECT, 2021
** handle_drag_and_drop.c
** File description:
** functions
*/

#include "hero.h"

void key_released(int is_equiped, int item_id, hero_status_t *hero_status)
{
    if (is_equiped == 0 && is_equiped != -1) {
        hero_status->inventory[item_id][0] = 1;
        hero_status->equiped_stuff[item_id] = 0;
    }
    else if (is_equiped != 0 && is_equiped != -1)
        hero_status->equiped_stuff[item_id] = 1;
}
