/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** init
*/

#include <stdio.h>
#include "my.h"
#include "struct.h"

matchstick_t init_struct(char **av)
{
    matchstick_t f = {0};
    int size = 1;
    f.line_nb = my_getnbr(av[1]);
    f.matches = my_getnbr(av[2]);

    for (int i = 1; i != f.line_nb; i++) {
        size = size + 2;
    }
    f.nb_last_l = size;
    return f;
}