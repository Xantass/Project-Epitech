/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** get_line
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "get_line.h"

static int get_nb_line(matchstick_t *f)
{
    char *lineptr = NULL;
    size_t len = 0;
    int line = 0;

    my_putstr("Line: ");
    if (getline(&lineptr, &len, stdin) == -1)
        return -2;
    if ((line = check_line(lineptr, f)) == -1)
        return -1;
    return line;
}

static int get_nb_match(matchstick_t *f, int line)
{
    char *lineptr = NULL;
    size_t len = 0;
    int match = 0;

    my_putstr("Matches: ");
    if (getline(&lineptr, &len, stdin) == -1)
        return -2;
    if ((match = check_match(lineptr, f, line)) == -1)
        return -1;
    return match;
}

int *get_com(matchstick_t *f)
{
    int *cor = malloc(sizeof(int) * 2);

    if ((cor[0] = get_nb_line(f)) == -1)
        return get_com(f);
    if (cor[0] == -2) {
        cor[1] = 0;
        return cor;
    }
    if ((cor[1] = get_nb_match(f, cor[0])) == -1)
        return get_com(f);
    if (cor[1] == -2)
        return cor;
    return cor;
}