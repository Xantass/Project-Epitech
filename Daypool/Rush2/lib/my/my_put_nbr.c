/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** this is the recoding of my put nbr
*/

#include <stdio.h>
#include <unistd.h>

int my_mult(int nb)
{
    int count = 0;
    int op = 0;
    int res = 1;

    while (nb > 9) {
        nb = nb / 10;
        count = count + 1;
    }
    while (op != count) {
        res = res * 10 ;
        op = op + 1;
    }
    return (res);
}

int my_put_nbr(int i)
{
    int result;
    int resultb;

    if (i < 0) {
        my_putchar('-');
        i = i * -1;
    }
    resultb = my_mult(i);
    while (resultb > 0) {
        result = i / resultb;
        i = i - (result * resultb);
        resultb = resultb / 10;
        my_putchar(result + 48);
    }
}
