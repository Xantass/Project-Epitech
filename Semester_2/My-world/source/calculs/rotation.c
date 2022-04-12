/*
** EPITECH PROJECT, 2021
** rotation.c
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
void matrix_rotation(struct matrix *f, double nb);

static double *rotation(double *vector, struct matrix *f, double nb)
{
    matrix_rotation(f, nb);
    return vector;
}
static double *create_new_vector(void)
{
    double *new_vector = my_calloc(sizeof(double), 3);
    return new_vector;
}

static void create_struct_matrix(struct matrix *f)
{
    f->one = my_calloc(sizeof(double), 3);
    f->two = my_calloc(sizeof(double), 3);
    f->three = my_calloc(sizeof(double), 3);
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

sfVector2f rotations(int x, int y, int z, double nb)
{
    double *vector = create_vector(x, y);
    double *new_vector = create_new_vector();
    struct matrix f = {0};
    sfVector2f point = {0};

    create_struct_matrix(&f);
    vector = rotation(vector, &f, nb);
    new_vector = calcf(vector, &f);
    point = project_iso_point(new_vector[0], new_vector[1], z);
    return point;
}