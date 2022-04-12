/*
** EPITECH PROJECT, 2021
** calc_translation.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "graph.h"
#include "my.h"

double *calcf(double *vector, struct matrix *f)
{
    double result_one = 0;
    double result_two = 0;
    double result_three = 0;

    result_one = (vector[0] * f->one[0]) +
        (vector[1] * f->one[1]) + (vector[2] * f->one[2]);
    result_two = (vector[0] * f->two[0]) +
        (vector[1] * f->two[1]) + (vector[2] * f->two[2]);
    result_three = (vector[0] * f->three[0]) +
        (vector[1] * f->three[1]) + (vector[2] * f->three[2]);
    vector[0] = result_one;
    vector[1] = result_two;
    vector[2] = result_three;
    return vector;
}

static double **create_matrix(void)
{
    double **matrix = malloc(sizeof(double *) * 3);

    for (int i = 0; i < 3; i++) {
        matrix[i] = my_calloc(sizeof(double), 3);
    }
    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    return matrix;
}

static void create_m(struct matrixs *p)
{
    p->one = my_calloc(sizeof(double), 3);
    p->two = my_calloc(sizeof(double), 3);
    p->three = my_calloc(sizeof(double), 3);
    p->one[0] = 1;
    p->two[1] = 1;
    p->three[2] = 1;
}

void matrix_translation_bis(struct matrix *f, struct matrixs p, double **matrix)
{
    p.three[0] = (f->three[0] * matrix[0][0]) +
        (f->three[1] * matrix[1][0]) + (f->three[2] * matrix[2][0]);
    p.three[1] = (f->three[0] * matrix[0][1]) +
        (f->three[1] * matrix[1][1]) + (f->three[2] * matrix[2][1]);
    p.three[2] = (f->three[0] * matrix[0][2]) +
        (f->three[1] * matrix[1][2]) + (f->three[2] * matrix[2][2]);
    f->one[0] = p.one[0];
    f->one[1] = p.one[1];
    f->one[2] = p.one[2];
    f->two[0] = p.two[0];
    f->two[1] = p.two[1];
    f->two[2] = p.two[2];
    f->three[0] = p.three[0];
    f->three[1] = p.three[1];
    f->three[2] = p.three[2];
}

void matrix_translation(struct matrix *f, double i, double j)
{
    double **matrix = create_matrix();
    struct matrixs p;

    create_m(&p);
    matrix[0][2] = i;
    matrix[1][2] = j;
    p.one[0] = (f->one[0] * matrix[0][0]) +
        (f->one[1] * matrix[1][0]) + (f->one[2] * matrix[2][0]);
    p.one[1] = (f->one[0] * matrix[0][1]) +
        (f->one[1] * matrix[1][1]) + (f->one[2] * matrix[2][1]);
    p.one[2] = (f->one[0] * matrix[0][2]) +
        (f->one[1] * matrix[1][2]) + (f->one[2] * matrix[2][2]);
    p.two[0] = (f->two[0] * matrix[0][0]) +
        (f->two[1] * matrix[1][0]) + (f->two[2] * matrix[2][0]);
    p.two[1] = (f->two[0] * matrix[0][1]) +
        (f->two[1] * matrix[1][1]) + (f->two[2] * matrix[2][1]);
    p.two[2] = (f->two[0] * matrix[0][2]) +
        (f->two[1] * matrix[1][2]) + (f->two[2] * matrix[2][2]);
    matrix_translation_bis(f, p, matrix);
}
