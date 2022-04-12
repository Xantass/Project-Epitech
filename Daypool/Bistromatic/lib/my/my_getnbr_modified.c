/*
** EPITECH PROJECT, 2020
** my_getnbr_modified
** File description:
** fmewoifnewi
*/

#include "my.h"

int my_getpos_getnbr_modified(char **numstr, char const *base)
{
    int resultnbr = 0;

    for (; my_char_isnum(**numstr, base) == 1; (*numstr)++) {
        for (int u = 10; u > 0; u--)
            if (((u * resultnbr) + (**numstr - 48)) < 0)
                return (0);
        resultnbr = (10 * resultnbr) + **numstr - 48;
    }
    return (resultnbr);
}

int my_getneg_getnbr_modified(char **numstr, char const *base)
{
    int resultnbr = 0;

    for (; my_char_isnum(**numstr, base) == 1; (*numstr)++) {
        for (int u = 10; u > 0; u--)
            if (((u * resultnbr) - (**numstr - 48)) > 0)
                return (0);
        resultnbr = (10 * resultnbr) - **numstr + 48;
    }
    return (resultnbr);
}

int my_getnbr_modified(char **numstr, char const *base)
{
    int neg = 1;

    while (**numstr == ' ')
        (*numstr)++;
    for (; **numstr == '-' || **numstr == '+' || **numstr == ' '; (*numstr)++)
        if (**numstr == '-')
            neg = -neg;
    if (neg == -1)
        return (my_getneg_getnbr_modified(numstr, base));
    else
        return (my_getpos_getnbr_modified(numstr, base));
}
