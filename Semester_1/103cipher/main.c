/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function
*/

#include "proto.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        printed_usage();
        return 0;
    }
    if (argc < 4)
        return 84;
    if (choose(argc, argv) == 84)
        return 84;
    return 0;
}
