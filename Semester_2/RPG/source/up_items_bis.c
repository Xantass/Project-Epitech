/*
** EPITECH PROJECT, 2021
** up_items_bis.c
** File description:
** functions
*/

#include "hero.h"

void up_boots(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[8] += 3;
        hero_status->stats[8][0] += 3;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[8] -= 3;
        hero_status->stats[8][0] -= 3;
        is_equiped = -1;
    }
}

void up_bracelet(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[5] += 2;
        hero_status->stats[5][0] += 2;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[5] -= 2;
        hero_status->stats[5][0] -= 2;
        is_equiped = -1;
    }
}
