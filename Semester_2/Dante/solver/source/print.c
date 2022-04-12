/*
** EPITECH PROJECT, 2021
** dante
** File description:
** print
*/

#include <stdio.h>

void condition_print(int sol)
{
    if (sol == 1)
        printf("%c", 'o');
    else if (sol == 2)
        printf("%c", '*');
    else
        printf("%c", 'X');
}