/*
** EPITECH PROJECT, 2021
** translation.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "graph.h"
#include "my.h"

double *calcf(double *vector, struct matrix *f);
void matrix_translation(struct matrix *f, double i, double j);

double *translation(double *vector, struct matrix *f, double i, double j)
{
    matrix_translation(f, i, j);
    return vector;
}

static double *create_new_vector(void)
{
    double *new_vector = calloc(sizeof(double), 3);
    return new_vector;
}

static void create_struct_matrix(struct matrix *f)
{
    f->one = calloc(sizeof(double), 3);
    f->two = calloc(sizeof(double), 3);
    f->three = calloc(sizeof(double), 3);
    f->one[0] = 1;
    f->two[1] = 1;
    f->three[2] = 1;
}

static double *create_vector(double x, double y)
{
    double *vector = malloc(sizeof(double) * 3);

    vector[0] = x;
    vector[1] = y;
    vector[2] = 1;

    return vector;
}

sfVector2f translations(sfVector2f point)
{
    double *vector = create_vector(point.x, point.y);
    double *new_vector = create_new_vector();
    struct matrix f = {0};

    create_struct_matrix(&f);
    vector = translation(vector, &f, 400, 400);
    new_vector = calcf(vector, &f);
    point.x = new_vector[0];
    point.y = new_vector[1];
    return point;
}
