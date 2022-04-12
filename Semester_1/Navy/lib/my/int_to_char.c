/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** functions
*/

#include <stdlib.h>
#include <unistd.h>

int my_operator(char *str);
int my_strlen(char const *str);

char *final_count_op(char *str)
{
    int i = 0;
    int j = 0;
    char *f_op = malloc(sizeof(char) * (my_strlen(str) + 1));

    f_op[my_strlen(str)] = '\0';
    while (i != my_strlen(str)) {
        if (str[i] == '+' || str[i] == '-') {
            f_op[j] = str[i];
            j = j + 1;
        }
        i = i + 1;
    }
    return f_op;
}

int size(int nb, int *diviseur)
{
    int a = 10;
    int b = 0;
    int size = 0;

    while (nb / *diviseur < 1 && *diviseur > 1) {
        *diviseur = *diviseur / 10;
        b++;
    }
    size = a - b;
    return size;
}

char *trans(int nb)
{
    int diviseur = 1000000000;
    int size_ = 0;
    int i = 0;
    char *str;

    size_ = size(nb, &diviseur);
    str = malloc(sizeof(char) * (size_ + 1));
    if (nb == 0) {
        str[0] = nb + '0';
        str[1] = '\0';
        return str;
    }
    str[size_] = '\0';
    while (i != size_) {
        str[i] = (nb / diviseur) + '0';
        nb = nb % diviseur;
        diviseur = diviseur / 10;
        i++;
    }
    return str;
}
