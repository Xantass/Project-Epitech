/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** function
*/

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

double *create_vector(double x, double y, double *vector)
{
    vector = malloc(sizeof(double) * 3);

    vector[0] = x;
    vector[1] = y;
    vector[2] = 1;

    return vector;
}

double *create_new_vector(double *new_vector)
{
    new_vector = calloc(sizeof(double), 3);
    return new_vector;
}

double **create_matrix(double **matrix)
{
    matrix = malloc(sizeof(double *) * 3);

    for (int i = 0; i < 3; i++) {
        matrix[i] = calloc(sizeof(double), 3);
    }
    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    return matrix;
}

void create_struct_matrix(struct matrix *f)
{
    f->one = calloc(sizeof(double), 3);
    f->two = calloc(sizeof(double), 3);
    f->three = calloc(sizeof(double), 3);
    f->one[0] = 1;
    f->two[1] = 1;
    f->three[2] = 1;
}

void create_m(struct matrixs *p)
{
    p->one = calloc(sizeof(double), 3);
    p->two = calloc(sizeof(double), 3);
    p->three = calloc(sizeof(double), 3);
    p->one[0] = 1;
    p->two[1] = 1;
    p->three[2] = 1;
}
