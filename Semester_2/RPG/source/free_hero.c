/*
** EPITECH PROJECT, 2021
** free_hero.c
** File description:
** functions
*/

#include "hero.h"

static void free_int_tab(int **tab, unsigned int limit)
{
    for (unsigned int i = 0; i < limit; i++)
        free(tab[i]);
}

static void free_sprites_tab(sfSprite **tab, unsigned limit)
{
    for (unsigned int i = 0; i < limit; i++)
        sfSprite_destroy(tab[i]);
}

static void free_char_tab(char **tab, unsigned int limit)
{
    for (unsigned int i = 0; i < limit; i++)
        free(tab[i]);
}

void free_hero(hero_status_t *hero_status)
{
    free(hero_status->actual_stats);
    free_int_tab(hero_status->stats, 11);
    free(hero_status->stats);
    free_int_tab(hero_status->inventory, 8);
    free(hero_status->inventory);
    free_int_tab(hero_status->passive_skills, 3);
    free(hero_status->passive_skills);
    free_int_tab(hero_status->active_skills, 4);
    free(hero_status->active_skills);
    free_int_tab(hero_status->unlocked_skills, 6);
    free(hero_status->unlocked_skills);
    free(hero_status->equiped_stuff);
    free(hero_status->inventory_positions);
    free(hero_status->equiped_pos);
    free(hero_status->items_background_pos);
    sfRectangleShape_destroy(hero_status->inventory_shape);
    free_sprites_tab(hero_status->loaded_items, 11);
    free_char_tab(hero_status->paths_to_sprites, 8);
    free(hero_status->paths_to_sprites);
}
