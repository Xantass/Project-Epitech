/*
** EPITECH PROJECT, 2020
** my_putchar_p.c
** File description:
** function
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void my_putchar_p(char c)
{
    write(1 , &c, 1);
}
