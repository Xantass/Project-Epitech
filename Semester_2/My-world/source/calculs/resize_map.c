/*
** EPITECH PROJECT, 2021
** rezize_map.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"

int **rezize_map_up(info_t *info, int **old_map)
{
    int **map = {0};

    map = malloc(sizeof(int *) * (info->size_map[0] + 2));
    for (int i = 0; i != (info->size_map[0] + 1); i++)
        map[i] = malloc(sizeof(int) * (info->size_map[1] + 1));
    for (int i = 0; i != (info->size_map[0] + 1); i++) {
        for (int j = 0; j != (info->size_map[1] + 1); j++)
            map[i][j] = 0;
    }
    info->size_map[0]++;
    info->size_map[1]++;
    info->map_zero = create_2d_map(map, info);
    for (int i = 0; i != info->size_map[0] - 1; i++) {
        for (int j = 0; j != info->size_map[1] - 1; j++)
            map[i][j] = old_map[i][j];
    }
    return map;
}

int **rezize_map_down(info_t *info, int **old_map)
{
    int **map = {0};

    map = malloc(sizeof(int *) * info->size_map[0] - 1);
    for (int i = 0; i != info->size_map[0] - 1; i++)
        map[i] = malloc(sizeof(int) * info->size_map[1] - 1);
    for (int i = 0; i != info->size_map[0] - 1; i++) {
        for (int j = 0; j != info->size_map[1] - 1; j++)
            map[i][j] = 0;
    }
    info->size_map[0]--;
    info->size_map[1]--;
    info->map_zero = create_2d_map(map, info);
    for (int i = 0; i != info->size_map[0]; i++) {
        for (int j = 0; j != info->size_map[1]; j++)
            map[i][j] = old_map[i][j];
    }
    return map;
}
