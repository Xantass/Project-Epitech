/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** error_handling
*/

#include <stdlib.h>
#include "my.h"

static int check(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return -1;
}

int error_handling(int ac, char **av)
{
    if (ac != 3)
        return -1;
    for (int i = 1; av[i] != NULL; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (check(av[i][j]) == -1)
                return -1;
        }
    }
    return 0;
}