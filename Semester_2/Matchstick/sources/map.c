/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** map
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "proto.h"

int *matchstick_by_line(matchstick_t *f)
{
    int *matchstick = malloc(sizeof(int) * f->line_nb);
    int size = 1;

    f->total_matchsticks = 0;
    for (int i = 0; i != f->line_nb; ++i, size += 2) {
        matchstick[i] = size;
        f->total_matchsticks += size;
    }
    return matchstick;
}

static char **init_map(char **str, matchstick_t f, int space, int size)
{
    int j = 0;

    for (int i = 0; i != f.nb_last_l + 2; i++)
        str[0][i] = '*';
    str[0][f.nb_last_l + 2] = '\n';
    for (int i = 1; i != f.line_nb + 1; i++, space -= 1, size += 2) {
        str[i][0] = '*';
        j = 1;
        for (int h = 0; h != space; j++, h++)
            str[i][j] = ' ';
        for (int h = 0; h != size; j++, h++)
            str[i][j] = '|';
        for (int h = 0; h != space; j++, h++)
            str[i][j] = ' ';
        str[i][j] = '*';
        str[i][j + 1] = '\n';
    }
    for (int i = 0; i != f.nb_last_l + 2; i++)
        str[f.line_nb + 1][i] = '*';
    str[f.line_nb + 1][f.nb_last_l + 2] = '\n';
    return str;
}

char **create_map(matchstick_t f)
{
    char **str = malloc(sizeof(char *) * (f.line_nb + 3));
    int space = 0;
    int size = 1;

    str[f.line_nb + 2] = NULL;
    for (int i = 0; i != (f.line_nb + 2); i++) {
        str[i] = malloc(sizeof(char) * (f.nb_last_l + 4));
        str[i][f.nb_last_l + 3] = '\0';
    }
    space = f.nb_last_l / 2;
    str = init_map(str, f, space, size);
    return str;
}