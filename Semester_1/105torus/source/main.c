/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function
*/

#include <stdio.h>
#include "proto.h"

void print_usage(void)
{
    printf("USAGE\n");
    printf("   ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n");
    printf("   opt       method option:\n");
    printf("                 1 for the bisection method\n");
    printf("                 2 for Newton’s method\n");
    printf("                 3 for the secant method\n");
    printf("   a[0-4]    coefficients of the equation\n");
    printf("   n         precision (the application of the polynomial to the solution should\n");
    printf("             be smaller than 10ˆ-n)\n");
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 84;
    if(argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc < 8 || argc > 8)
        return 84;
    if (choose(argv) == 84)
        return 84;
    return 0;
}
