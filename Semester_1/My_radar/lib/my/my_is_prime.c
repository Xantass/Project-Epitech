/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** fonction
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int a = 3;

    if (nb == 1)
        return (0);
    if (nb == 2)
        return (1);
    if (nb % 2 == 0)
        return (0);
    while (a * a <= nb) {
        if (nb % a == 0)
            return (0);
        a = a + 2;
    }
    return (1);
}
