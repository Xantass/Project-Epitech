/*
** EPITECH PROJECT, 2020
** main.c
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

int number_cro(int **map, int i, int j);
char **load_map(char const *filepath);
int **load_map_mod(char const *filepath, int *u, int *h);
int **alloc_map_2d_arr(char const *filepath, int *u, int *h);
char **alloc_map_2d_arr_from_file(char const *filepath);
char *load_file_in_mem(char const *filepath);
int error_man(int argc, char **argv);

int **check(int **map, int i, int j)
{
    int biggest_number;

    if (i == 0 || j == 0)
        return map;
    if (map[i][j] == 0)
        return map;
    if (map[i - 1][j] == 0)
        return map;
    if (map[i][j - 1] == 0)
        return map;
    if (map[i - 1][j - 1] == 0)
        return map;
    biggest_number = number_cro(map, i, j);
    map[i][j] = (map[i][j] + biggest_number);
    return map;
}

char *print_square(int pos, int *h, char const *filepath, int square)
{
    char *check = load_file_in_mem(filepath);
    int i = 0;
    int j = 0;
    int p = 0;

    for (; check[p] != '\n'; p++);
    pos = pos + p + 1;
    for (; i < square; j++) {
        if (j == (square)) {
            j = 0;
            pos = pos - ((*h) - square + 1);
            i++;
        }
        if (i == square)
            break;
        check[pos] = 'x';
        pos--;
    }
    check = &check[p + 1];
    return check;
}

void print(char *map, char const *filepath)
{
    struct stat temp;
    char *check = load_file_in_mem(filepath);
    int p = 0;

    for (; check[p] != '\n'; p++);
    stat(filepath, &temp);
    write(1 , map, temp.st_size -(p + 1));
}

void find_biggest_square(int **map, char const *filepath, int *u, int *h)
{
    int x = 0;
    int y = 0;
    int pos = 0;
    int square = 0;
    char *mapf;

    for (int i = 0; i < *u; i++) {
        for (int j = 0; j < *h; j++) {
            map = check(map, i, j);
            if (map[i][j] > square) {
                square = map[i][j];
                x = i;
                y = j;
            }
        }
    }
    pos = x * (*h + 1) - ((*h) - y + 1);
    mapf = print_square(pos, h, filepath, square);
    print(mapf, filepath);
}

int main(int argc, char **argv)
{
    if (argc == 1 || error_man(argc, argv) == 0)
        return 84;
    else {
        int u = 0;
        int h = 0;

        find_biggest_square(load_map_mod(argv[1], &u, &h), argv[1], &u, &h);
        return 0;
    }
}
