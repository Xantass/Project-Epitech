/*
** EPITECH PROJECT, 2020
** my_memset.c
** File description:
** fonction
*/

#include <stdlib.h>

void *my_memset(char *tab, int value, size_t size)
{
    int i = 0;

    while (i != size) {
        tab[i] = value;
        i = i + 1;
    }
    return tab;
}
