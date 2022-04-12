/*
** EPITECH PROJECT, 2021
** set_perfect_maze.c
** File description:
** function
*/

void perfect_maze_following(char **map, int i, int j)
{
    if (i == 0)
        map[i][j] = '*';
}

void fill_perfect_maze(char **map, int i, int j)
{
    if (j % 2 == 0 && i % 2 == 0)
        map[i][j] = '*';
    else if (j % 2 != 0 && i % 2 == 0)
        map[i][j] = 'X';
    else if (i % 2 != 0)
        map[i][j] = 'X';
}
