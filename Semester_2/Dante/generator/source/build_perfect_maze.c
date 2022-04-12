/*
** EPITECH PROJECT, 2021
** build_perfect_maze.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "struct.h"
#include "lib.h"
#include "build_perfect_maze.h"

static void switch_up_left(char **map, int i, int j, vector_2ui *size)
{
    if (i - 1 >= 0 && map[i - 1][j] == 'X')
        size->up = 1;
    if (j - 1 >= 0 && map[i][j - 1] == 'X')
        size->left = 1;
}

static void near_to_one_wall(char **map, int i, int j, vector_2ui *size)
{
    if (i - 1 >= 0 && size->up == 1 && size->left == 0)
        map[i - 1][j] = '*';
    if (j - 1 >= 0 && size->up == 0 && size->left == 1)
        map[i][j - 1] = '*';
}

static void near_to_two_walls(char **map, int i, int j, int random)
{
    random = rand() % 2;
    if (j - 1 >= 0 && random == 0)
        map[i][j - 1] = '*';
    else if (i - 1 >= 0 && random == 1)
        map[i - 1][j] = '*';
}

static void perfect_maze(char **map, vector_2ui *size)
{
    int random = 0;

    for (unsigned int i = 0; i < size->y; i += 2) {
        size->up = 0;
        size->left = 0;
        for (unsigned int j = 0; j < size->x; j += 2) {
            perfect_maze_following(map, i, j);
            switch_up_left(map, i, j, size);
            near_to_one_wall(map, i, j, size);
            if (size->up == 1 && size->left == 1)
                near_to_two_walls(map, i, j, random);
        }
    }
}

void init_perfect_maze(char **map, vector_2ui *size)
{
    for (unsigned int i = 0; i < size->y; i++) {
        for (unsigned int j = 0; j < size->x; j++)
            fill_perfect_maze(map, i, j);
    }
    perfect_maze(map, size);
    build_exit(map, size);
}
