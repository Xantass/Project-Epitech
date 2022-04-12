/*
** EPITECH PROJECT, 2021
** calc_rotation.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "graph.h"
#include "my.h"

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

void matrix_rotation_bis(struct matrix *f, struct matrixs p, double **matrix)
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

void matrix_rotation(struct matrix *f, double nb)
{
    double **matrix = create_matrix();
    double pi = (3.1415926535);
    struct matrixs p;

    create_m(&p);
    matrix[0][0] = cos(nb / 180 * pi);
    matrix[1][1] = cos(nb / 180 * pi);
    matrix[0][1] = -sin(nb / 180 * pi);
    matrix[1][0] = sin(nb / 180 * pi);
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
    
}

sfVector2f **modif_rotation(sfVector2f **point, info_t *info, double nb)
{
    for (int i = 0; i != info->size_map[0]; i++) {
        for (int j = 0; j != info->size_map[1]; j++) {
            point[i][j] = rotations(i, j, info->map[i][j], nb);
            info->map_zero[i][j] = rotations(i, j, info->map[i][j], nb);
        }
    }
    return point;
}