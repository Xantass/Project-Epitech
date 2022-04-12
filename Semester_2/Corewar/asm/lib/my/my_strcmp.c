/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** function
*/

#include <stdlib.h>

int my_strlen(char *str);

int my_strcmp(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return -1;
    if (my_strlen(s1) != my_strlen(s2))
        return -1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
