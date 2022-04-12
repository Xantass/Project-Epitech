/*
** EPITECH PROJECT, 2021
** calloc_tab.c
** File description:
** functions
*/

#include "lib.h"

char **calloc_tab(unsigned int nb_array, unsigned int line_size)
{
    char **tab = my_calloc(sizeof(char *), (nb_array) + 1);

    if (tab == NULL)
        return NULL;
    for (unsigned int i = 0; i < nb_array; i++) {
        tab[i] = my_calloc(sizeof(char), (line_size) + 1);
        if (tab[i] == NULL)
            return NULL;
    }
    return tab;
}
