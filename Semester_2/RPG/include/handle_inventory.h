/*
** EPITECH PROJECT, 2021
** handle_inventory.h
** File description:
** header
*/

#ifndef HANDLE_INVENTORY_H
#define HANDLE_INVENTORY_H

#include "hero.h"

int load_item(info_t *info, hero_status_t *hero_status,
              unsigned int pos_index, unsigned int path_index);
int reset_selection(hero_status_t *hero_status, info_t *info, unsigned int item_id);
void load_equiped_stuff(hero_status_t *hero_status, info_t *info);
void key_released(int is_equiped, int item_id, hero_status_t *hero_status);
int print_stats(info_t *info, hero_status_t *hero_status);

#endif /* !HANDLE_INVENTORY_H */
