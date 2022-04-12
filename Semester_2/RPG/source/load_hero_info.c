/*
** EPITECH PROJECT, 2021
** load_hero_info.c
** File description:
** functions
*/

#include "hero.h"
#include "lib.h"

void load_items_background_pos(hero_status_t *hero_status)
{
    hero_status->items_background_pos = my_calloc(sizeof(sfVector2f), (7) + 1);
    hero_status->items_background_pos[0] = (sfVector2f) {1589, 363};
    hero_status->items_background_pos[1] = (sfVector2f) {1780, 363};
    hero_status->items_background_pos[2] = (sfVector2f) {1685, 241};
    hero_status->items_background_pos[3] = (sfVector2f) {1685, 325};
    hero_status->items_background_pos[4] = (sfVector2f) {1685, 406};
    hero_status->items_background_pos[5] = (sfVector2f) {1685, 485};
    hero_status->items_background_pos[6] = (sfVector2f) {1780, 283};
}
