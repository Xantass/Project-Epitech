/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** fonction
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);

void my_swap(char *a, char *b);

char *my_revstr(char *str)
{
    int h = 0;
    int end = my_strlen(str) - 1;
    char stockage;

    while (end >= h) {
        stockage = str[end];
        str[end] = str[h];
        str[h] = stockage;
        h++;
        end--;
    }
    return (str);
}
