/*
** EPITECH PROJECT, 2020
** my_putnbr_p.c
** File description:
** function
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);

void my_putnbr_p(long long int nb)
{
    long long int mod = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }

    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_putnbr_p(nb);
            my_putchar(48 + mod);
        }
        else {
            my_putchar(48 + nb % 10);
            nb = 0;
        }
    }
}
