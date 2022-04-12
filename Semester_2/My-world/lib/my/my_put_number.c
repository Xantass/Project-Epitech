/*
** EPITECH PROJECT, 2020
** my_put_number.c
** File description:
** function
*/

void my_putchar(char c);

int check_negative(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    return nb;
}

int my_put_number(int result)
{
    int mod;

    if (result == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        result = 147483648;
    }
    result = check_negative(result);
    if (result >= 10) {
        mod = result % 10;
        result = result / 10;
        my_put_number(result);
        my_putchar(mod + 48);
    }
    else
        my_putchar(result + 48);
    return 0;
}
