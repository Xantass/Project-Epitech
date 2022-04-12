/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** fonction
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;
    int i = 0;

    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
