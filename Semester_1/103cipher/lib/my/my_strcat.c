/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int size = my_strlen(dest);

    while (src[i] != '\0') {
        dest[size + i] = src[i];
        i++;
    }
    return (dest);
}
