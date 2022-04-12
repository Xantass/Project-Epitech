/*
** EPITECH PROJECT, 2021
** display_int_map.c
** File description:
** functions
*/

#include "hero.h"

void print_map(info_t *info, char *path);

int display_int_map(info_t *info)
{
    static float last_mod = 0;
    static int is_pressed = -1;

    if (sfKeyboard_isKeyPressed(sfKeyX) && last_mod + (0.2) <= info->times) {
        last_mod = info->times;
        is_pressed *= -1;
    }
    if (is_pressed == 1)
        print_map(info, "./sprites/Get_map/map_int.png");
    return 0;
}
