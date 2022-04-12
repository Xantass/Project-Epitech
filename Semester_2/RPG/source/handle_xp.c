/*
** EPITECH PROJECT, 2021
** handle_xp.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

static void up_all_stats(hero_status_t *hero_status)
{
    hero_status->stats[0][0] += (hero_status->stats[0][0] / 12);
    hero_status->actual_stats[0] = hero_status->stats[0][0];
    if (hero_status->actual_stats[3] % 3 == 0) {
        hero_status->stats[5][0] += 1;
        hero_status->actual_stats[5] += 1;
    }
    if (hero_status->actual_stats[3] % 5 == 0) {
        hero_status->actual_stats[8] += 2;
        hero_status->stats[8][0] += 2;
    }
}

int handle_xp_from_lvl(hero_status_t *hero_status)
{
    static int lvl = 1;

    if (hero_status->actual_stats[3] > lvl) {
        up_all_stats(hero_status);
        lvl++;
    }
    return 0;
}

int handle_xp(hero_status_t *hero_status)
{
    if (hero_status->actual_stats[2] >= (int) hero_status->max_xp) {
        hero_status->actual_stats[2] = hero_status->actual_stats[2] -
            hero_status->max_xp;
        hero_status->actual_stats[3]++;
        hero_status->max_xp += (hero_status->max_xp / 20);
    }
    return 0;
}
