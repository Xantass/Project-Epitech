
/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

int my_char_isoperator(char c)
{
    if (c == '%' || c == '*' || c == '/' || c == '+' ||
        c == '-')
        return (1);
    return (0);
}
