/*
** EPITECH PROJECT, 2020
** matrix.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include "matrix.h"

double **create_matrix(double **matrix);
void create_m(struct matrixs *p);

void matrix_translation(struct matrix *f, double i, double j)
{
    double **matrix = create_matrix(matrix);
    struct matrixs p;

    create_m(&p);
    matrix[0][2] = i;
    matrix[1][2] = j;
    p.one[0] = (f->one[0] * matrix[0][0]) + (f->one[1] * matrix[1][0]) + (f->one[2] * matrix[2][0]);
    p.one[1] = (f->one[0] * matrix[0][1]) + (f->one[1] * matrix[1][1]) + (f->one[2] * matrix[2][1]);
    p.one[2] = (f->one[0] * matrix[0][2]) + (f->one[1] * matrix[1][2]) + (f->one[2] * matrix[2][2]);
    p.two[0] = (f->two[0] * matrix[0][0]) + (f->two[1] * matrix[1][0]) + (f->two[2] * matrix[2][0]);
    p.two[1] = (f->two[0] * matrix[0][1]) + (f->two[1] * matrix[1][1]) + (f->two[2] * matrix[2][1]);
    p.two[2] = (f->two[0] * matrix[0][2]) + (f->two[1] * matrix[1][2]) + (f->two[2] * matrix[2][2]);
    p.three[0] = (f->three[0] * matrix[0][0]) + (f->three[1] * matrix[1][0]) + (f->three[2] * matrix[2][0]);
    p.three[1] = (f->three[0] * matrix[0][1]) + (f->three[1] * matrix[1][1]) + (f->three[2] * matrix[2][1]);
    p.three[2] = (f->three[0] * matrix[0][2]) + (f->three[1] * matrix[1][2]) + (f->three[2] * matrix[2][2]);
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

void matrix_scaling(struct matrix *f, double m, double n)
{
    double **matrix = create_matrix(matrix);
    struct matrixs p;

    create_m(&p);
    matrix[0][0] = m;
    matrix[1][1] = n;
    p.one[0] = (f->one[0] * matrix[0][0]) + (f->one[1] * matrix[1][0]) + (f->one[2] * matrix[2][0]);
    p.one[1] = (f->one[0] * matrix[0][1]) + (f->one[1] * matrix[1][1]) + (f->one[2] * matrix[2][1]);
    p.one[2] = (f->one[0] * matrix[0][2]) + (f->one[1] * matrix[1][2]) + (f->one[2] * matrix[2][2]);
    p.two[0] = (f->two[0] * matrix[0][0]) + (f->two[1] * matrix[1][0]) + (f->two[2] * matrix[2][0]);
    p.two[1] = (f->two[0] * matrix[0][1]) + (f->two[1] * matrix[1][1]) + (f->two[2] * matrix[2][1]);
    p.two[2] = (f->two[0] * matrix[0][2]) + (f->two[1] * matrix[1][2]) + (f->two[2] * matrix[2][2]);
    p.three[0] = (f->three[0] * matrix[0][0]) + (f->three[1] * matrix[1][0]) + (f->three[2] * matrix[2][0]);
    p.three[1] = (f->three[0] * matrix[0][1]) + (f->three[1] * matrix[1][1]) + (f->three[2] * matrix[2][1]);
    p.three[2] = (f->three[0] * matrix[0][2]) + (f->three[1] * matrix[1][2]) + (f->three[2] * matrix[2][2]);
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
    double **matrix = create_matrix(matrix);
    double pi = (3.1415926535);
    struct matrixs p;

    create_m(&p);
    matrix[0][0] = cos(nb / 180 * pi);
    matrix[1][1] = cos(nb / 180 * pi);
    matrix[0][1] = -sin(nb / 180 * pi);
    matrix[1][0] = sin(nb / 180 * pi);
    p.one[0] = (f->one[0] * matrix[0][0]) + (f->one[1] * matrix[1][0]) + (f->one[2] * matrix[2][0]);
    p.one[1] = (f->one[0] * matrix[0][1]) + (f->one[1] * matrix[1][1]) + (f->one[2] * matrix[2][1]);
    p.one[2] = (f->one[0] * matrix[0][2]) + (f->one[1] * matrix[1][2]) + (f->one[2] * matrix[2][2]);
    p.two[0] = (f->two[0] * matrix[0][0]) + (f->two[1] * matrix[1][0]) + (f->two[2] * matrix[2][0]);
    p.two[1] = (f->two[0] * matrix[0][1]) + (f->two[1] * matrix[1][1]) + (f->two[2] * matrix[2][1]);
    p.two[2] = (f->two[0] * matrix[0][2]) + (f->two[1] * matrix[1][2]) + (f->two[2] * matrix[2][2]);
    p.three[0] = (f->three[0] * matrix[0][0]) + (f->three[1] * matrix[1][0]) + (f->three[2] * matrix[2][0]);
    p.three[1] = (f->three[0] * matrix[0][1]) + (f->three[1] * matrix[1][1]) + (f->three[2] * matrix[2][1]);
    p.three[2] = (f->three[0] * matrix[0][2]) + (f->three[1] * matrix[1][2]) + (f->three[2] * matrix[2][2]);
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

void matrix_reflection(struct matrix *f, double nb)
{
    double **matrix = create_matrix(matrix);
    double pi = (3.1415926535);
    struct matrixs p;

    create_m(&p);
    matrix[0][0] = cos(2 * (nb / 180 * pi));
    matrix[1][1] = -cos(2 * (nb / 180 * pi));
    if (-cos(2 * (nb / 180 * pi)) < 0.00 && -cos(2 * (nb / 180 * pi)) >= -0.05) {
        matrix[1][1] = matrix[1][1] * (-1);
    }
    matrix[0][1] = sin(2 * (nb / 180 * pi));
    matrix[1][0] = sin(2 * (nb / 180 * pi));
    p.one[0] = (f->one[0] * matrix[0][0]) + (f->one[1] * matrix[1][0]) + (f->one[2] * matrix[2][0]);
    p.one[1] = (f->one[0] * matrix[0][1]) + (f->one[1] * matrix[1][1]) + (f->one[2] * matrix[2][1]);
    p.one[2] = (f->one[0] * matrix[0][2]) + (f->one[1] * matrix[1][2]) + (f->one[2] * matrix[2][2]);
    p.two[0] = (f->two[0] * matrix[0][0]) + (f->two[1] * matrix[1][0]) + (f->two[2] * matrix[2][0]);
    p.two[1] = (f->two[0] * matrix[0][1]) + (f->two[1] * matrix[1][1]) + (f->two[2] * matrix[2][1]);
    p.two[2] = (f->two[0] * matrix[0][2]) + (f->two[1] * matrix[1][2]) + (f->two[2] * matrix[2][2]);
    p.three[0] = (f->three[0] * matrix[0][0]) + (f->three[1] * matrix[1][0]) + (f->three[2] * matrix[2][0]);
    p.three[1] = (f->three[0] * matrix[0][1]) + (f->three[1] * matrix[1][1]) + (f->three[2] * matrix[2][1]);
    p.three[2] = (f->three[0] * matrix[0][2]) + (f->three[1] * matrix[1][2]) + (f->three[2] * matrix[2][2]);
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

int char_is_nb(char *c)
{
    int i = 0;

    if (c == NULL)
        return 0;
    while (c[i] != '\0') {
        if (c[i] == '-') {
            i++;
        }
        if (c[i] == '.') {
            i++;
        }
        if (c[i] >= '0' && c[i] <= '9') {
            i++;
        }
        else
            return 0;
    }
    return 1;
}
