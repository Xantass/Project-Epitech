/*
** EPITECH PROJECT, 2021
** free_tab.c
** File description:
** functions
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (unsigned int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
