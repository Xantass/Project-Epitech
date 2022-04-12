/*
** EPITECH PROJECT, 2021
** algo.c
** File description:
** functions
*/
#include <stdio.h>
#include <string.h>
#include "lib.h"
#include "struct.h"
#include "algo.h"

int build_line(char *line, vector_2ui size)
{
    for (unsigned int i = 1; i < size.x - 1; i++) {
        if (i == size.x - 1)
            break;
        if (get_random_pos_int()) {
            line[i] = '*';
            line[i + 1] = '*';
            i++;
        }
        else {
            line[i] = '*';
            i++;
        }
    }
    return 0;
}

int init_map(char **map, vector_2ui size)
{
    for (unsigned int i = 0; i < size.x; i++)
        map[0][i] = '*';
    for (unsigned int i = 1; i < size.y; i++) {
        build_line(map[i], size);
        if (i == size.y - 1) {
            map[i][size.x - 1] = '*';
            map[i][size.x - 2] = '*';
            map[i][size.x - 3] = '*';
        }
    }
    return 0;
}
