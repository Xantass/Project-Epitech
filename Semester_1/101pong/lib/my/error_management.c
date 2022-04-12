/*
** EPITECH PROJECT, 2020
** error_management.c
** File description:
** function
*/

#include <stdio.h>

void print_h(void)
{
    printf("USAGE\n");
    printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    printf("DESCRIPTION\n");
    printf("    x0  ball abscissa at time t - 1\n");
    printf("    y0  ball abscissa at time t - 1\n");
    printf("    z0  ball abscissa at time t - 1\n");
    printf("    x1  ball abscissa at time t\n");
    printf("    y1  ball abscissa at time t\n");
    printf("    z1  ball abscissa at time t\n");
    printf("    n   time shift (greater than or equal to zero, integer\n");
}

int char_is_nb(char c)
{
    if (c == '-')
        return 1;
    if (c == '.')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int error(int argc, char **argv)
{   
    if (argv[1][1] == 'h') {
        print_h();
        return 0;
    }
    if (argc <= 7 || argc > 8)
        return 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (char_is_nb(argv[i][j]) == 0)
                return 0;
        }
    }
    for (int h = 0; argv[7][h] != '\0'; h++) {
        if (argv[7][h] == '.')
            return 0;
    }
    if (argv[7][0] == '-')
        return 0;
    else
        return 1;
}
