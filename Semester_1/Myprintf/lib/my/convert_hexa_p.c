/*
** EPITECH PROJECT, 2020
** convert_hexa_p.c
** File description:
** function
*/

#include <stdio.h>

void my_putchar(char c);
char *my_revstr(char *str);

void convert_hexa_p(unsigned long long init)
{
    char *base = "0123456789abcdef";
    char res[100];
    int i = 0;

    while ((init / 16) > 0) {
        res[i] = (base[init % 16]);
        init = init / 16;
        i++;
    }
    res[i] = (base[init % 16]);
    res[i + 1] = '\0';
    for (; i >= 0; i--)
        my_putchar(res[i]);
}
