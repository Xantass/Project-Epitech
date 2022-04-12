/*
** EPITECH PROJECT, 2020
** comparative_fonction.c
** File description:
** fonction
*/

#include <unistd.h>

void my_print_res(char c, int amatch, int atotal)
{
    write(1, &c, 1);
    write(1, ":", 1);
    my_put_nbr(amatch);
    write(1, " ()", 2);
    print_percent(amatch, atotal);
    if (amatch == 0)
        write(1, "0", 1);
    write(1, "%)", 2);
    write(1, "\n", 1);
}
