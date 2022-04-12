/*
** EPITECH PROJECT, 2020
** my_inesg.c
** File description:
** fonction
*/

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
