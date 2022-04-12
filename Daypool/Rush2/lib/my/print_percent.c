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
