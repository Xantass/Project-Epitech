/*
** EPITECH PROJECT, 2021
** core.c
** File description:
** functions
*/

#include <struct.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "core.h"

int core(int x, int y, int perfect)
{
    vector_2ui size = {0, 0, x, y,};
    char **map = alloc_map(size);

    srand((unsigned) time(NULL));
    if (perfect)
        init_perfect_maze(map, &size);
    else {
        init_map(map, size);
        print_map(map, size);
    }
    return 0;
}
