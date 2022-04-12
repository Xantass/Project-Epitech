/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** fonction
*/

int alphanumber(char c)
{
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}

int limite_getnbr(int h, int j, char const *str)
{
    j = h;
    while (str[h] != '\0') {
        if (alphanumber(str[h]) == 1) {
            j++;
            h++;
        } else {
            return (j);
        }
    }
    return (j);
}

int sign(char const *str)
{
    int h = 0;

    while (str[h] == '-') {
        h++;
    }
    return (h);
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int h = sign(str);
    int j = limite_getnbr(h, j, str);

    while (h < j) {
        if ((nb * 10) > 2147483647 || (nb * 10) < -2147483648)
            return (0);
        else {
        nb = nb * 10;
        nb = nb + (str[h] - 48);
        h++;
        }
    }
    if (str[0] == '-') {
        nb = nb * (-1);
    }
    return nb;
}
