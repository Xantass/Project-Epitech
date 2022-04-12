/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** function
*/

#include <unistd.h>

void my_putstr(char *str)
{
    for (; *str != '\0'; str++)
        write(1, str, 1);
}
