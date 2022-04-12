/*
** EPITECH PROJECT, 2021
** dante
** File description:
** algo
*/

#include "algo.h"

static bool solve_maze_util(int **maze, unsigned int x,
                             unsigned int y, vector_2ui_t *size)
{
    if (x == size->x - 1 && y == size->y && maze[x][y] == 1) {
        size->sol[x][y] = 1;
        return true;
    }
    if (is_safe(maze, x, y, size) == true) {
        if (size->sol[x][y] == 1)
            return false;
        size->sol[x][y] = 1;
        if (solve_maze_util(maze, x + 1, y, size) == true)
            return true;
        if (solve_maze_util(maze, x, y + 1, size) == true)
            return true;
        if (solve_maze_util(maze, x - 1, y, size) == true)
            return true;
        if (solve_maze_util(maze, x, y - 1, size) == true)
            return true;
        size->sol[x][y] = 2;
        return false;
    }
    return false;
}

static void modif_solution(int **sol, vector_2ui_t *size, int **maze)
{
    for (unsigned int i = 0; i < size->x; i++) {
        for (unsigned int j = 0; j <= size->y; j++) {
            sol[i][j] = modif_map(maze[i][j], sol[i][j]);
        }
    }
}

static bool is_safe(int **maze, unsigned int x,
                    unsigned int y, vector_2ui_t *size)
{
    unsigned int zero = 0;

    if (x >= zero && x < size->x && y >= zero && y < size->y
        && maze[x][y] == 1)
        return true;
    return false;
}

bool solve_maze(int **maze, vector_2ui_t *size)
{
    size->sol = alloc_sol(size);
    if (solve_maze_util(maze, 0, 0, size) == false) {
        printf("no solution found");
        return false;
    }
    modif_solution(size->sol, size, maze);
    for (unsigned int i = 0; i < size->x; i++) {
        for (unsigned int j = 0; j <= size->y; j++)
            condition_print(size->sol[i][j]);
        if (i != 19)
            printf("\n");
    }
    return true;
}
