/*
** EPITECH PROJECT, 2021
** init_map.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"

sfVector2f **create_2d_map(int **map, info_t *info)
{
    sfVector2f **maps = malloc(sizeof(sfVector2f *) * info->size_map[0]);

    for (int i = 0; i != info->size_map[0]; i++)
        maps[i] = malloc(sizeof(sfVector2f) * info->size_map[1]);
    for (int i = 0; i != info->size_map[0]; i++) {
        for (int j = 0; j != info->size_map[1]; j++)
            maps[i][j] = project_iso_point(i, j, map[i][j]);
    }
    for (int i = 0; i != info->size_map[0]; i++) {
        for (int j = 0; j != info->size_map[1]; j++)
            maps[i][j] = translations(maps[i][j]);
    }
    return maps;
}

int **init_map_tab(info_t *info)
{
    int **map = {0};

    map = malloc(sizeof(int *) * 6);
    for (int i = 0; i != 6; i++)
        map[i] = malloc(sizeof(int) * 6);
    for (int i = 0; i != 6; i++) {
        for (int j = 0; j != 6; j++)
            map[i][j] = 0;
    }
    info->size_map = malloc(sizeof(int) * 2);
    info->size_map[0] = 6;
    info->size_map[1] = 6;
    return map;
}

