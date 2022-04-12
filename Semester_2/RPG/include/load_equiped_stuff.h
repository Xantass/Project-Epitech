/*
** EPITECH PROJECT, 2021
** load_equiped_stuff.h
** File description:
** header
*/

#ifndef LOAD_EQUIPED_STUFF_H
#define LOAD_EQUIPED_STUFF_H

#include "hero.h"

void display_background(hero_status_t *hero_status, info_t *info,
                        unsigned int item_id);
void up_bracelet(hero_status_t *hero_status, int reset_code);
void up_boots(hero_status_t *hero_status, int reset_code);
void up_sword(hero_status_t *hero_status, int reset_code);
void up_shield(hero_status_t *hero_status, int reset_code);
void up_helmet(hero_status_t *hero_status, int reset_code);
void up_armor(hero_status_t *hero_status, int reset_code);
void up_belt(hero_status_t *hero_status, int reset_code);

typedef struct up_stats_t {
    unsigned int item_id;
    void (*link)(hero_status_t *hero_status, int reset_code);
} up_stats_t;

up_stats_t up_stats [8] = {
    {0, up_sword},
    {1, up_shield},
    {2, up_helmet},
    {3, up_armor},
    {4, up_belt},
    {5, up_boots},
    {6, up_bracelet},
};
#endif
