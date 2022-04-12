/*
** EPITECH PROJECT, 2021
** fill_tab_with_char.c
** File description:
** functions
*/

#include "lib.h"

static void fill_filled_tab(char **tab, char c)
{
    for (unsigned int i = 0; tab[i] != NULL; i++) {
        for (unsigned int j = 0; tab[i][j] != '\0'; j++)
            tab[i][j] = c;
    }
}

static void fill_non_filled_tab(char **tab, char c,
                               unsigned int x, unsigned int y)
{
    for (unsigned int i = 0; i < y; i++) {
        for (unsigned int j = 0; (j < x) != '\0'; j++)
            tab[i][j] = c;
    }
}

void fill_tab_with_char(char **tab, char c, unsigned int x, unsigned int y)
{
    if (y == 0 && x == 0)
        fill_filled_tab(tab, c);
    else
        fill_non_filled_tab(tab, c, x, y);
}
