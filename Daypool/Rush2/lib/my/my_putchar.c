/*
** EPITECH PROJECT, 2018
** rush2
** File description:
** my put char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
