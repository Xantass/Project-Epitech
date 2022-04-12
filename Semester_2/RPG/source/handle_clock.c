/*
** EPITECH PROJECT, 2021
** handle_clock.c
** File description:
** functions
*/

#include "struct.h"

int handle_clock(info_t *info)
{
    info->time = sfClock_getElapsedTime(info->clock);
    info->times = sfTime_asSeconds(info->time);
    return 0;
}
