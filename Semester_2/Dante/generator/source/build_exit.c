/*
** EPITECH PROJECT, 2021
** build_exit.c
** File description:
** function
*/

#include "struct.h"
#include "build_exit.h"

void build_exit(char **map, vector_2ui *size)
{
    unsigned int i = size->y - 1;
    unsigned int j = size->x - 1;

    if (map[i][j - 1] == 'X' && map[i - 1][j] == 'X')
        map[i][j - 1] = '*';
    map[size->y - 1][size->x - 1] = '*';
    print_map(map, *size);
}
