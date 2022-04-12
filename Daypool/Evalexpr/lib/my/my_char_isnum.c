/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}
