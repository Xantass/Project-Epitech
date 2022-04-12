/*
** EPITECH PROJECT, 2020
** comparative_fonction.c
** File description:
** fonction
*/

#include <stddef.h>

void print_percent(int amatch, int atotal)
{
    int decimal = 0;
    int unit = 0;
    int freq = 0;

    amatch = amatch * 10000;
    atotal = atotal * 100;
    freq = (amatch * 100) / atotal;
    decimal = freq % 100;
    unit = freq / 100;
    my_put_nbr(unit);
    write(1, ".", 1);
    my_put_nbr(decimal);
}

void comparative_function(char *str, char c)
{
    int i = 0;
    int amatch = 0;
    int j = 0;
    int atotal = 0;

    while (str[i] != '\0') {
        if ((str[i] == c) || (str[i] == c + 32))
            amatch++;
        i++;
    }
    while (str[j] != '\0') {
        if (my_char_is_alpha(str[j]) == 0)
            atotal++;
        j++;
    }
    my_print_res(c , amatch, atotal);
}
