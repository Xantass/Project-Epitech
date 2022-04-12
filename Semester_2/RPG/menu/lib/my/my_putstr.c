/*
** EPITECH PROJECT, 2020
** d3
** File description:
** my_putstr
*/

#include "my_hunter.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
