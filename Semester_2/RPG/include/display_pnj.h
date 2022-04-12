/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** display_pnj
*/

#ifndef DISPLAY_PNJ_H_
#define DISPLAY_PNJ_H_

#include "struct.h"

int pnj_zero(info_t *info, hero_status_t *hero_status);
int pnj_three(info_t *info, hero_status_t *hero_status);
int pnj_five(info_t *info, hero_status_t *hero_status);
int pnj_seven(info_t *info, hero_status_t *hero_status);
void quest_one(hero_status_t *hero_status);
void quest_two(hero_status_t *hero_status);
void quest_three(hero_status_t *hero_status);
void quest_four(hero_status_t *hero_status);

#endif /* !DISPLAY_PNJ_H_ */
