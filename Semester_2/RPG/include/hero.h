/*
** EPITECH PROJECT, 2021
** hero.h
** File description:
** functions
*/

#ifndef HERO_H
#define HERO_H

#include "graph.h"
#include "struct.h"

typedef struct hero_status_t {
    unsigned int max_xp;
    int *actual_stats;
    int **stats;
    int **inventory;
    int **passive_skills;
    int **active_skills;
    int **unlocked_skills;
    sfVector2f *locked_skills_pos;
    sfRectangleShape *inventory_shape;
    int open;
    char **paths_to_sprites;
    sfVector2f *inventory_positions;
    sfSprite **loaded_items;
    sfVector2f *equiped_pos;
    sfVector2f *items_background_pos;
    unsigned int *equiped_stuff;
} hero_status_t;

#endif /* !HERO_H */
