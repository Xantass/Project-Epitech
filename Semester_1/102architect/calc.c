/*
** EPITECH PROJECT, 2020
** calc.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include "matrix.h"

void matrix_translation(struct matrix *f, double i, double j);
void matrix_scaling(struct matrix *f, double m, double n);
void matrix_rotation(struct matrix *f, double nb);
void matrix_reflection(struct matrix *f, double nb);

double *translation(double *vector, struct matrix *f, double i, double j)
{
    matrix_translation(f, i, j);
    return vector;
}

double *scaling(double *vector, struct matrix *f, double m, double n)
{
    matrix_scaling(f, m, n);
    return vector;
}

double *rotation(double *vector, struct matrix *f, double nb)
{
    matrix_rotation(f, nb);
    return vector;
}

double *reflection(double *vector, struct matrix *f, double nb)
{
    matrix_reflection(f, nb);
    return vector; 
}

double *calcf(double *vector, struct matrix *f)
{
    double result_one = 0;
    double result_two = 0;
    double result_three = 0;

    result_one = (vector[0] * f->one[0]) + (vector[1] * f->one[1]) + (vector[2] * f->one[2]);
    result_two = (vector[0] * f->two[0]) + (vector[1] * f->two[1]) + (vector[2] * f->two[2]);
    result_three = (vector[0] * f->three[0]) + (vector[1] * f->three[1]) + (vector[3] * f->three[2]);
    vector[0] = result_one;
    vector[1] = result_two;
    vector[2] = result_three;
    return vector;
}
