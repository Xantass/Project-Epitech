/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** fonction
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int j = 0;

    while (src[j] != '\0') {
        j++;
    }

    char *memoire = malloc(sizeof(char) * (j + 1));

    while (src[i] != '\0') {
        memoire[i] = src[i];
        i++;
    }
    return (memoire);
}
