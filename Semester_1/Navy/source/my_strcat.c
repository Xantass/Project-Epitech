/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** functions
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    return dest;
}

char *strcat_with_space(char *dest, char *src)
{
    int size;

    my_strcat(dest, src);
    size = my_strlen(dest);
    dest[size] = ' ';
    return dest;
}
