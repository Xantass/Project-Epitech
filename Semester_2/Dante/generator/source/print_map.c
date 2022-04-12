/*
** EPITECH PROJECT, 2021
** print_map.c
** File description:
** functions
*/

#include <string.h>
#include <unistd.h>
#include "struct.h"

void print_map(char **map, vector_2ui size)
{
    unsigned int row_size = strlen(map[0]);

    for (unsigned int i = 0; i < size.y; i++) {
        write(1, map[i], row_size);
        if (i != size.y - 1)
            write(1, "\n", 1);
    }
}
