/*
** EPITECH PROJECT, 2020
** my_putstr_p.c
** File description:
** function
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);

void my_putstr_p(char *res)
{
    for (int i = 0; res[i] != '\0'; i++)
        my_putchar(res[i]);
}
