/*
** EPITECH PROJECT, 2021
** core.c
** File description:
** functions
*/

#include <stdio.h>
#include "core.h"
#include "struct.h"

int core(int **map, vector_2ui_t *size)
{
    solve_maze(map, size);
    return 0;
}
