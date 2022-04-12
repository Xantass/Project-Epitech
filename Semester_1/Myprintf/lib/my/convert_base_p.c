/*
** EPITECH PROJECT, 2020
** convert_base_p.c
** File description:
** function
*/

#include <stdio.h>
#include <string.h>

void my_putchar(char c);

void convert_base_p(unsigned long long adresse)
{
    char *base = "0123456789abcdef\0";
    char convert[12];
    int j = 11;

    while ((adresse / 16) > 0 || j == 11) {
        convert[j] = (base[adresse % 16]);
        adresse = adresse / 16;
        j--;
    }
    convert[j] = (base[adresse % 16]);
    my_putchar('0');
    my_putchar('x');
    for (; j < 12; j++)
        my_putchar(convert[j]);
}
