/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** error
*/

#include "lib.h"
#include "error.h"

int error_man(char **argv, int argc)
{
    int len = 0;

    if (argc != 2)
        return -1;
    if (my_strcmp("-h", argv[1]) == 0)
        return usage();
    len = my_strlen(argv[1]);
    if (argv[1][len - 1] != 's' || argv[1][len - 2] != '.')
        return -1;
    return 0;
}