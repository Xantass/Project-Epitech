/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** fonction
*/

#include <stdlib.h>

void *my_calloc(unsigned int size_elem, unsigned int block)
{
    char *str = malloc(size_elem * block);
    int i = 0;

    while (i < block) {
        str[i] = '0';
        i++;
    }
    return (str);
}
