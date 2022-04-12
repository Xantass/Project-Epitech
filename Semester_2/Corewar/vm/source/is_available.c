/*
** EPITECH PROJECT, 2021
** is_availlable.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdbool.h>
#include "info.h"
#include "is_available.h"

int is_available(prog_info_t *prog_info, short int living_process)
{
    if (get_state(&living_process, prog_info->prog_number) == 0)
        return 0;
    if (prog_info->is_running != 0) {
        prog_info->is_running--;
        return 0;
    }
    return 1;
}

