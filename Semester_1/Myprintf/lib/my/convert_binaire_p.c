/*
** EPITECH PROJECT, 2020
** convert_binaire_p.c
** File description:
** function
*/

#include <stdio.h>

void my_putchar(char c);
char *my_revstr(char *str);

void convert_binaire_p(unsigned long long init)
{
    char *base = "01";
    char res[100];
    int i = 0;

    while ((init / 2) > 0) {
        res[i] = (base[init % 2]);
        init = init / 2;
        i++;
    }
    res[i] = (base[init % 2]);
    res[i + 1] = '\0';
    for (; i >= 0; i--)
        my_putchar(res[i]);
}
