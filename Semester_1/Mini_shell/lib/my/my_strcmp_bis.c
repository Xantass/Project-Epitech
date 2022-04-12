/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** fonction
*/

#include <stdio.h>
#include "my.h"

int my_strcmp_bis(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return -1;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
