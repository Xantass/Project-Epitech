/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** fonction
*/

void my_putchar(char c);

int my_put_nbr(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9)
        my_put_nbr((nb / 10));
    my_putchar((nb % 10) + '0');
    return (0);
}
