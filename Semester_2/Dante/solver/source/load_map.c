/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "lib.h"
#include "load_map.h"
#include "struct.h"

static int **fill_in_2d_array_bis(char *map, vector_2ui_t *size, int **res)
{
    unsigned int counter = 0;
    unsigned int offset = 0;

    for (unsigned int i = 0; map[i] != '\0'; ++i) {
        if (map[i] == '\n') {
            counter++;
            size->x = offset;
            offset = 0;
            res[counter] = my_calloc(sizeof(int), (strlen(map) + 1));
        }
        if (map[i] == '*') {
            res[counter][offset] = 1;
            offset++;
        }
        if (map[i] == 'X') {
            res[counter][offset] = 0;
            offset++;
        }
        size->y = counter;
    }
    return res;
}

static int **fill_in_2d_array(char *map, vector_2ui_t *size)
{
    int **res = my_calloc(sizeof(int *), (strlen(map) + 1));

    if (res == NULL)
        exit(84);
    res[0] = my_calloc(sizeof(int), (strlen(map) + 1));
    return fill_in_2d_array_bis(map, size, res);
}

int **load_map(char *path, vector_2ui_t *size)
{
    char *map;
    struct stat temp = {0};
    __attribute__((cleanup(clean_fd)))int res_open = open(path, O_RDONLY);

    if (res_open == -1)
        return NULL;
    if (stat(path, &temp) == -1)
        return NULL;
    map = my_calloc(sizeof(char), (temp.st_size + 1));
    if (map == NULL)
        return NULL;
    if (read(res_open, map, temp.st_size) == -1)
        return NULL;
    return fill_in_2d_array(map, size);
}
