/*
** EPITECH PROJECT, 2021
** print_tab.c
** File description:
** functions
*/

#include "lib.h"

void print_tab(char **tab)
{
    for (unsigned int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
