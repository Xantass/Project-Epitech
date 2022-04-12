/*
** EPITECH PROJECT, 2020
** calc_encrypted.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double **key_encrypted(char *str, double *div)
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

double **string_encrypted(char *str, double col, double div)
{
    double **matrix;
    int j = 0;
    int a = 0;

    matrix = malloc(sizeof(double *) * col);
    for (int i = 0; i < col; i++)
        matrix[i] = calloc(sizeof(double), div);
    for (int i = 0; str[i] != '\0'; i++) {
        if (j == div) {
            a++;
            j = 0;
        }
        matrix[a][j] = str[i];
        j++;
    }
    return matrix;
}

double **mult_3x3(double **matrix, double **matrixs, double col, double div)
{
    double **res;

    res = malloc(sizeof(double *) * col);
    for (int i = 0; i < col; i++)
        res[i] = calloc(sizeof(double), div);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < div; j++) {
            res[i][j] = 0;
            for (int k = 0; k < div; k++) {
                res[i][j] += matrix[i][k] * matrixs[k][j];
            }
        }
    }
    return res;
}

double **mult_2x2(double **matrix, double **matrixs, double col, double div)
{
    double **res;

    res = malloc(sizeof(double *) * col);
    for (int i = 0; i < col; i++)
        res[i] = calloc(sizeof(double), div);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < div; j++) {
            res[i][j] = (matrix[i][0] * matrixs[0][j]) + (matrix[i][1] * matrixs[1][j]);
        }
    }
    return res;
}

double **mult_1x1(double **matrix, double **matrixs, double col, double div)
{
   double **res;

    res = malloc(sizeof(double *) * col);
    for (int i = 0; i < col; i++)
        res[i] = calloc(sizeof(double), div);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < div; j++) {
            res[i][j] = (matrix[i][0] * matrixs[0][j]);
        }
    }
    return res; 
}
