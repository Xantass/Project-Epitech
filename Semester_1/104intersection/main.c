/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function
*/

#include "matrix.h"
#include "proto.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc < 9 || argc >= 10)
        return 84;
    if ((choose(argv)) == 84)
        return 84;
    return 0;
}
