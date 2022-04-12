/*
** EPITECH PROJECT, 2020
** none_printable.c
** File description:
** Function
*/

#include <stdio.h>
#include <string.h>

void my_putchar(char c);
void convert_octa_p(int nb);
int my_getnbr(char c);
int my_put_nbr(int nb);

void none_printable(char *str)
{
    char *base = "012345678";
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putchar('0');
            my_putchar('0');
            my_put_nbr(base[str[i] % 8] - 48);
            i++;
        }
        else {
            my_putchar(str[i]);
            i++;
        }
    }
}
