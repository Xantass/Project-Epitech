/*
** EPITECH PROJECT, 2020
** print.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

void print_translation(char **argv, int *i)
{
    printf("Translation along vector (%d, %d)\n", atoi(argv[*i + 1]), atoi(argv[*i + 2]));
    *i = *i + 2;
}

void print_scaling(char **argv, int *i)
{
    printf("Scaling by factors %d and %d\n", atoi(argv[*i + 1]), atoi(argv[*i + 2]));
    *i = *i + 2;
}

void print_rotation(char **argv, int *i)
{
    printf("Rotation by a %d degree angle\n", atoi(argv[*i + 1]));
    *i = *i + 1;
}

void print_reflection(char **argv, int *i)
{
    printf("Reflection over an axis with an inclination angle of %d degrees\n", atoi(argv[*i + 1]));
    *i = *i + 1;
}

void print_matrix(struct matrix *f)
{
    printf("%.2f\t", f->one[0]);
    printf("%.2f\t", f->one[1]);
    printf("%.2f\n", f->one[2]);
    printf("%.2f\t", f->two[0]);
    printf("%.2f\t", f->two[1]);
    printf("%.2f\n", f->two[2]);
    printf("%.2f\t", f->three[0]);
    printf("%.2f\t", f->three[1]);
    printf("%.2f\n", f->three[2]);
}
