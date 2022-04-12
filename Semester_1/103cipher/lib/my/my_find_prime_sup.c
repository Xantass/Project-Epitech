/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** foction
*/

#include <stdio.h>

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb))
        nb = nb + 2;
    return (nb);
}
