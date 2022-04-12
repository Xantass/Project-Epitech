/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** functions
*/

#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    unsigned int perfect = 0;

    if (error_handling(argc, argv) == -1)
        return 84;
    if (argv[3] != NULL)
        perfect = 1;
    if (core(atoi(argv[1]), atoi(argv[2]), perfect) == -1)
        return 84;
    return 0;
}
