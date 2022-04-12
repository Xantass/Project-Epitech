/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** functions
*/

#include "info.h"
#include "lib.h"

static int is_valid_opt(char *opt)
{
    if (my_strcmp(opt, "-s") != 0 && my_strcmp(opt, "-n") != 0
        && my_strcmp(opt, "-dump") != 0)
        return -1;
    return 0;
}

int error_handling(char *argv[])
{
    for (unsigned int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] == '-' && is_valid_opt(argv[i]) == -1)
            return -1;
    }
    return 0;
}
