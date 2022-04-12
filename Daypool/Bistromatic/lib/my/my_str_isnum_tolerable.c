/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** fiewoduhewq
*/

#include "my.h"

int my_str_isnum_tolerable(char *str, char *base)
{
    int i = 0;

    while (*str == ' ')
        str++;
    while (*str == '-' || *str == '+')
        str++;
    for (; *(str + i) != '\0' && *(str + i) != ' '; i++)
        if (my_char_isnum(*(str + i), base) == 1)
            return 0;
    if (*(str + i) != ' ' && *(str + i) != '\0')
        return 0;
    for (int u = i; *(str + u) != '\0'; u++)
        if (*(str + u) != ' ')
            return 0;
    *(str + i) = '\0';
    return 1;
}
