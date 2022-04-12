/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** moves
*/

#ifndef MOVES_H_
#define MOVES_H_

#include "struct.h"

int move_up(info_t *info, hero_status_t *hero_status);
int move_down(info_t *info, hero_status_t *hero_status);
int move_right(info_t *info, hero_status_t *hero_status);
int move_left(info_t *info, hero_status_t *hero_status);
void display_sound(info_t *info, char *path, float volume);

#endif /* !MOVES_H_ */
