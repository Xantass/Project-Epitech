/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "proto.h"

int main(int ac, char **av, char **env)
{
    matchstick_t f = {0};
    int *cor = {0};

    if (*env == NULL)
        return 84;
    if (error_handling(ac, av) == -1)
        return 84;
    f = init_struct(av);
    f.str = create_map(f);
    f.matchsticks = matchstick_by_line(&f);
    return game(&f, cor);
}