/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>

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
