/*
** EPITECH PROJECT, 2020
** usage.c
** File description:
** fonction
*/

#include <stdio.h>
#include <unistd.h>

void print_usage(void)
{
    printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...\n\n\n");
    printf("DESCRIPTION\n");
    printf("    x  abscissa of the original point\n");
    printf("    y  ordinate of the original point\n\n\n");
    printf("    transfo arg1 [arg2]\n");
    printf("    -t i j  translation along vector (i, j)\n");
    printf("    -z m n  scaling by factors m (x-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in O by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through O with an inclination)\n");
    printf("            angle of d degrees\n");
}
