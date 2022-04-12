/*
** EPITECH PROJECT, 2020
** my_get_number.c
** File description:
** function
*/

#include <stdio.h>

long long my_get_number_spe(char *str)
{
    int i = 0;
    long long n = 0;
    int negative = 1;

    while (str[i] == '-') {
        negative = negative * -1;
        i = i + 1;
    }
    for (; str[i] >= '0' && str[i] <= '9';) {
        n += str[i] - 48;
        n *= 10;
        i = i + 1;
    }
    n = n * negative;
    n = n / 10;
    return (n);
}
