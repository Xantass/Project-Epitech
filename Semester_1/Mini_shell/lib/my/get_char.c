/*
** EPITECH PROJECT, 2020
** get_char.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int size_(int nb, int *diviseur)
{
    int i = 10;
    int h = 0;
    int size_string = 0;

    while (nb / *diviseur < 1 && *diviseur > 1) {
        *diviseur = *diviseur / 10;
        h++;
    }
    size_string = i - h;
    return size_string;
}

char *get_char(int nb)
{
    int diviseur = 1000000000;
    int size_string = 0;
    int i = 0;
    char *mem;

    size_string = size_(nb, &diviseur);
    mem = malloc(sizeof(char) * (size_string + 1));
    if (nb == 0) {
        mem[0] = nb + '0';
        mem[1] = '\0';
        return mem;
    }
    mem[size_string] = '\0';
    while (i != size_string) {
        mem[i] = (nb / diviseur) + '0';
        nb = nb % diviseur;
        diviseur = diviseur / 10;
        i++;
    }
    return mem;
}
