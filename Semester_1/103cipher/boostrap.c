/*
** EPITECH PROJECT, 2020
** boostrap.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proto.h"

double **key(char *str, double *div)
{
    double temp = 0;
    int j = 0;
    int a = 0;
    double size = strlen(str);
    double **matrix;

    for (; (temp = size / (*div)) > (*div); (*div)++) {
        if (temp > (*div) && temp < (*div) + 1) {
            (*div)++;
            break;
        }
    }
    matrix = malloc(sizeof(double *) * (*div));
    for (int i = 0; i < (*div); i++)
        matrix[i] = calloc(sizeof(double), (*div));
    for (int i = 0; str[i] != '\0'; i++) {
        if (j == (*div)) {
            a++;
            j = 0;
        }
        matrix[a][j] = str[i];
        j++;
    }
    return matrix;
}

double **string(char **str, double *col, double div)
{
    double **matrix;
    int j = 0;
    int a = 0;

    for (int i = 0; str[i] != NULL; i++) {
        (*col)++;
    }
    (*col) = ceil(*col / div);
    matrix = malloc(sizeof(double *) * (*col));
    for (int i = 0; i < (*col); i++)
        matrix[i] = calloc(sizeof(double), div);
    for (int i = 0; str[i] != NULL; i++) {
        if (j == div) {
            a++;
            j = 0;
        }
        matrix[a][j] = atoi(str[i]);
        j++;
    }
    return matrix;
}

double **transpo_key(double **matrix, double div)
{
    double **transpose = malloc(sizeof(double *) * div);
    
    for (int i = 0; i < div; i++)
        transpose[i] = calloc(sizeof(double), div);
    for (int i = 0; i < div; i++) {
        for (int j = 0; j < div; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}

double determinant(double **matrix)
{
    double deter = 0;
    
    deter = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    return deter;
}

double **inver(double **temp)
{
    double **temps = malloc(sizeof(double *) * 2);
    double deter = determinant(temp);

    for (int i = 0; i < 2; i++)
        temps[i] = calloc(sizeof(double), 2);
    if (deter == 0)
        exit(84);
    deter = 1 / deter;
    temps[0][0] = deter * temp[1][1];
    temps[0][1] = deter * (-temp[0][1]);
    temps[1][0] = deter * (-temp[1][0]);
    temps[1][1] = deter * temp[0][0];
    return temps;
}

double cofactor(double **matrix)
{
    double A_1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    double A_2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    double A_3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
    double A_4 = matrix[0][2] * matrix[1][1] * matrix[2][0];
    double A_5 = matrix[0][0] * matrix[1][2] * matrix[2][1];
    double A_6 = matrix[0][1] * matrix[1][0] * matrix[2][2];
    double A = 0;
    
    A = A_1 + A_2 + A_3 - A_4 - A_5 - A_6;
    return A;
}

double **matrix_minor(double **matrix)
{
    double A1 = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]);
    double A2 = (-1) * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]));
    double A3 = (matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]);
    double A4 = (-1) * ((matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]));
    double A5 = (matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]);
    double A6 = (-1) * ((matrix[0][0] * matrix[2][1]) - (matrix[0][1] * matrix[2][0]));
    double A7 = (matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]);
    double A8 = (-1) * ((matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]));
    double A9 = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);;

    matrix[0][0] = A1;
    matrix[0][1] = A2;
    matrix[0][2] = A3;
    matrix[1][0] = A4;
    matrix[1][1] = A5;
    matrix[1][2] = A6;
    matrix[2][0] = A7;
    matrix[2][1] = A8;
    matrix[2][2] = A9;
    return matrix;
}

double **inverse_key(double **matrix, double div)
{
    double A = 0;

    A = cofactor(matrix);
    if (A == 0)
        exit(84);
    matrix = matrix_minor(matrix);
    matrix = transpo_key(matrix, div);
    A = 1 / A;
    matrix[0][0] = matrix[0][0] * A;
    matrix[0][1] = matrix[0][1] * A;
    matrix[0][2] = matrix[0][2] * A;
    matrix[1][0] = matrix[1][0] * A;
    matrix[1][1] = matrix[1][1] * A;
    matrix[1][2] = matrix[1][2] * A;
    matrix[2][0] = matrix[2][0] * A;
    matrix[2][1] = matrix[2][1] * A;
    matrix[2][2] = matrix[2][2] * A;
    return matrix;
}
