/*
** EPITECH PROJECT, 2021
** boostrap.c
** File description:
** function
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "proto.h"

int check_bis(char c)
{
    if (c == '-')
        return 0;
    if (c == '.')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

int check_bisss(char c)
{
    if (c >= '1' && c <= '9')
        return 0;
    return 1;
}

int check(char **argv)
{
    for (int i = 2; argv[i] != NULL; i++) {
        if (i == 7)
            break;
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (check_bis(argv[i][j]) == 1) {
                return 84;
            }
        }
    }
    for (int i = 0; argv[7][i] != '\0'; i++) {
        if (check_bisss(argv[7][i]) == 1)
            return 84;
    }
    return 0;
}

function init(char **argv)
{
    function f = {atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]), atof(argv[7])};

    return f;
}

int choose(char **argv)
{
    function f = {0};

    if (check(argv) == 84)
        return 84;
    f = init(argv);
    if (argv[1][0] == '1' && strlen(argv[1]) == 1) {
        bisection(f, 0, 1);
        return 0;
    }
    if (argv[1][0] == '2' && strlen(argv[1]) == 1) {
        if (newton(f, 0.5) == 84)
            return 84;
        return 0;
    }
    if (argv[1][0] == '3' && strlen(argv[1]) == 1) {
        if (secant(f, 0, 1) == 84)
            return 84;
        return 0;
    }
    return 84;
}
