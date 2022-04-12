/*
** EPITECH PROJECT, 2020
** game_biss.c
** File description:
** functions
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int check_map(char c)
{
    if (c >= '2' && c <= '5')
        return 0;
    return 1;
}

int get_attack_bis(map_t *f, char *str)
{
    int row = 2;
    int col = 2;
    int *cor = malloc(sizeof(int) * 2);

    cor[0] = str[0] - 65;
    cor[1] = str[1] - 48;
    row = row + cor[1] - 1;
    col = col + (2 * cor[0]);
    my_putstr(str);
    if (check_map(f->map_player[row][col]) == 0) {
        my_putstr(": hit\n");
        f->map_player[row][col] = 'x';
        f->shipe--;
        return 1;
    }
    else {
        f->map_player[row][col] = 'o';
        my_putstr(": missed\n");
        return 0;
    }
    return 2;
}

void hit(map_t *f, char *str)
{
    int row = 2;
    int col = 2;
    int *cor = malloc(sizeof(int) * 2);

    cor[0] = str[0] - 65;
    cor[1] = str[1] - 48;
    row = row + cor[1] - 1;
    col = col + (2 * cor[0]);
    f->map_enemy[row][col] = 'x';
}

void missed(map_t *f, char *str)
{
    int row = 2;
    int col = 2;
    int *cor = malloc(sizeof(int) * 2);

    cor[0] = str[0] - 65;
    cor[1] = str[1] - 48;
    row = row + cor[1] - 1;
    col = col + (2 * cor[0]);
    f->map_enemy[row][col] = 'o';
}
