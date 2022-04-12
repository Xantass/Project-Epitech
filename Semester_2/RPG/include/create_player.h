/*
** EPITECH PROJECT, 2021
** create_player.h
** File description:
** header
*/

#ifndef CREATE_PLAYER_H
#define CREATE_PLAYER_H

#include "hero.h"

int load_hero_status(hero_status_t *hero_status);
int init_inventory(hero_status_t *hero_status);
sfRectangleShape ***create_player_bis(void);
void load_items_background_pos(hero_status_t *hero_status);

#endif
