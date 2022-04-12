/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
        }
        else
            return (0);
        i = i + 1;
    }
    return (1);
}
