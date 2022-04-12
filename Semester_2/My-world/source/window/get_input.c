/*
** EPITECH PROJECT, 2021
** get_input.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

void get_new_input(info_t *info)
{
    if (info->event.type != 0)
        info->last_event = info->event;
    info->event = info->last_event;
}
