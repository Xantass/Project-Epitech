/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** fonction
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
