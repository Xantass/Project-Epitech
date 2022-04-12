/*
** EPITECH PROJECT, 2020
** my_char_isnum.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>

int my_char_isnum(char c)
{
    if (c >= 48 && c <= 57)
        return (0);
    return (1);
}
