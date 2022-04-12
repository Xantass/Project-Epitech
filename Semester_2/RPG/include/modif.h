/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** modif
*/

#ifndef MODIF_H_
#define MODIF_H_

#include "graph.h"
#include "struct.h"


int switch_more(info_t *info, list_elem_t *act, sfVector2f pos_player);
int switch_less(info_t *info, list_elem_t *act, sfVector2f pos_player);
int switch_more_with_music(info_t *info, list_elem_t *act, sfVector2f pos_player);
int switch_less_with_music(info_t *info, list_elem_t *act, sfVector2f pos_player);

#endif /* !MODIF_H_ */
