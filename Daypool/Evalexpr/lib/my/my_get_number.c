/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/


int my_get_number(char *str)
{
    int i = 0;
    long n = 0;
    int negative = 1;

    while (str[i] == '-') {
        negative = negative * -1;
        i = i + 1;
    }
    for (; str[i] >= '0' && str[i] <= '9';) {
        if ((n * 10) > 2147483647 || (n * 10) < -2147483648)
            return (0);
        n += str[i] - 48;
        n *= 10;
        i = i + 1;
    }
    n = n * negative;
    n = n / 10;
    return (n);
}
