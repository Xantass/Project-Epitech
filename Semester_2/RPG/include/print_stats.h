/*
** EPITECH PROJECT, 2021
** print_stats.h
** File description:
** header
*/

#ifndef PRINT_STATS_H
#define PRINT_STATS_H

#include "struct.h"

void load_stats_value(info_t *info, sfVector2f pos, int value, unsigned int max);
int load_magic_armor(info_t *info, hero_status_t *hero_status);
int load_speed(info_t *info, hero_status_t *hero_status);
void update_stats(hero_status_t *hero_status);

#endif
