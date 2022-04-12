/*
** EPITECH PROJECT, 2021
** alloc_tab.c
** File description:
** functions
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include "lib.h"

void fill_line(char *line, vector_2ui size, char c)
{
    for (unsigned int i = 0; i < size.x; i++)
        line[i] = c;
}

static char **filled_map(char **map, vector_2ui size)
{
    for (unsigned int i = 0; i < size.y; i++) {
        map[i] = my_calloc(sizeof(char), (size.x));
        if (map[i] == NULL) {
            write(2, "calloc failed\n", 14);
            exit(84);
        }
        fill_line(map[i], size, 'X');
    }
    return map;
}

char **alloc_map(vector_2ui size)
{
    char **map = my_calloc(sizeof(char*), (size.y));

    if (map == NULL) {
        write(2, "calloc failed\n", 14);
        exit(84);
    }
    return filled_map(map, size);
}
