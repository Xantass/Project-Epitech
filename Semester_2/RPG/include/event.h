/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "hero.h"
#include "moves.h"
#include "map_event.h"
#include "struct.h"

int handle_inventory(hero_status_t *hero_status, info_t *info);
int alea(info_t *info, hero_status_t *hero_status);

typedef struct tab_t {
    sfKeyCode key;
    int (*link_my)(info_t *info, hero_status_t *hero_status);
}tab_t;

tab_t moves [4] = {
    {sfKeyUp, move_up},
    {sfKeyDown, move_down},
    {sfKeyRight, move_right},
    {sfKeyLeft, move_left},
};

typedef struct map_t {
    int nb;
    list_elem_t *(*my)(info_t *info);
} map_t;

map_t map [9] = {
    {0, map_zero},
    {1, map_one},
    {2, map_two},
    {3, map_three},
    {4, map_four},
    {5, map_five},
    {6, map_six},
    {7, map_seven},
    {8, map_height},
};
#endif /* !EVENT_H_ */
