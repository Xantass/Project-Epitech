/*
** EPITECH PROJECT, 2020
** my_get_number_mod.c
** File description:
** functions
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

long long binary_to_decimal(long long nb)
{
    long long dec = 0;
    long long num = nb;
    long long base = 1;
    long long rest;

    while (num > 0) {
        rest = num % 10;
        dec = dec + rest * base;
        num = num / 10;
        base = base * 2;
    }
    return dec;
}

int my_get_number_mod(char c)
{
    int n = c;

    return n;
}
