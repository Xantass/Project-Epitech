/*
** EPITECH PROJECT, 2021
** up_items.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

void up_sword(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[4] += 3;
        hero_status->stats[4][0] += 3;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[4] -= 3;
        hero_status->stats[4][0] -= 3;
        is_equiped = -1;
    }
}

void up_shield(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[6] += 2;
        hero_status->stats[6][0] += 2;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[6] -= 2;
        hero_status->stats[6][0] -= 2;
        is_equiped = -1;
    }
}

void up_helmet(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[6] += 2;
        hero_status->stats[6][0] += 2;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[6] -= 2;
        hero_status->stats[6][0] -= 2;
        is_equiped = -1;
    }
}

void up_armor(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->actual_stats[6] += 3;
        hero_status->actual_stats[7] += 3;
        hero_status->stats[6][0] += 3;
        hero_status->stats[7][0] += 3;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->actual_stats[6] -= 3;
        hero_status->actual_stats[7] -= 3;
        hero_status->stats[6][0] -= 3;
        hero_status->stats[7][0] -= 3;
        is_equiped = -1;
    }
}

void up_belt(hero_status_t *hero_status, int reset_code)
{
    static int is_equiped = -1;

    if (is_equiped == -1) {
        hero_status->stats[0][0] += 25;
        is_equiped *= -1;
    }
    if (reset_code == 1) {
        hero_status->stats[0][0] -= 25;
        is_equiped = -1;
    }
}
