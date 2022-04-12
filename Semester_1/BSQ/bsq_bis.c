/*
** EPITECH PROJECT, 2020
** bsq_bis.c
** File description:
** function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *load_file_in_mem(char const *filepath);
int **alloc_map_2d_arr(char const *filepath, int *u, int *h);

int **init_map(char const *filepath, int *u, int *h)
{
    int **map = alloc_map_2d_arr(filepath, u, h);

    for (int i = 0; i < (*u); i++) {
        for (int j = 0; j < (*h); j++)
            map[i][j] = 0;
    }
    return map;
}
