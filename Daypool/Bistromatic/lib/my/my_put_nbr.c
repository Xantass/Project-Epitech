/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** PUvmewkiocdce
*/

#include "my.h"

void my_put_nbr_rec(int nb, int power)
{
    my_putchar(nb / power + 48);
    if (power > 1)
        my_put_nbr_rec(nb % power, power / 10);
}

int my_put_nbr(int nb)
{
    int power = 0;

    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    else {
        power = 1;
    }
    for (int nb2 = nb; nb2 > 9 || nb2 < -9; nb2 /= 10)
        power *= 10;
    if (nb < 0) {
        my_putchar('-');
        my_putchar(-(nb / power) + 48);
        if (power > 1)
            my_put_nbr_rec(-(nb % power), power / 10);
    } else {
        my_put_nbr_rec(nb, power);
    }
    return (0);
}
