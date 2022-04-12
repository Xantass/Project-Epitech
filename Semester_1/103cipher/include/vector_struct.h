/*
** EPITECH PROJECT, 2020
** vector_struct.h
** File description:
** fonction
*/

#ifndef VECTOR_STRUCT
#define VECTOR_STRUCT

#include "matrix.h"

double *translation(double *vector, struct matrix *f, double i, double j);
double *scaling(double *vector, struct matrix *f, double m, double n);
double *rotation(double *vector, struct matrix *f, double nb);
double *reflection(double *vector, struct matrix *f, double nb);

struct calc_mult {
    char c;
    double *(*func)(double *vector, struct matrix *f, double i, double j);
};

struct calc_angle {
    char c;
    double *(*func)(double *vector, struct matrix *f, double nb);
};

struct calc_mult arg[2] =
{
    {'t', translation},
    {'z', scaling},
};

struct calc_angle args[2] =
{
    {'r', rotation},
    {'s', reflection},
};
#endif
