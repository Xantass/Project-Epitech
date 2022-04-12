/*
** EPITECH PROJECT, 2020
** cipher.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my.h"
#include "proto.h"

char *get_str(double **matrixs, double div, double col)
{
    char *str = malloc(sizeof(char) * (div * col));
    int **matrix = malloc(sizeof(int *) * col);
    int h = 0;

    for (int i = 0; i < col; i++) {
        matrix[i] = calloc(sizeof(int), div);
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < div; j++) {;
            str[h] = round(matrixs[i][j]);
            h++;
        }
    }
    return str;
}

int encrypted(char **argv)
{
    char *strings = calloc(sizeof(char), strlen(argv[1]) + 1);
    char *keys = calloc(sizeof(char), strlen(argv[2]) + 1);
    double div = 0;
    double col = 0;
    double **matrix;
    double **matrixs;

    strcpy(strings, argv[1]);
    if (argv[2][0] == '\0')
        exit(84);
    strcpy(keys, argv[2]);
    matrix = key_encrypted(keys, &div);
    if (strings[0] == '\0') {
        print_matrice(matrix, div);
        return 0;
    }   
    col = ceil(strlen(strings) / div);
    matrixs = string_encrypted(strings, col, div);
    matrixs = mult_3x3(matrixs, matrix, col, div);
    printed_encrypted(matrix, matrixs, col, div);
    return 0;
}

int descrypted(char **argv)
{
    char *str = calloc(sizeof(char), strlen(argv[1]) + 1);
    char *keys = calloc(sizeof(char), strlen(argv[2]) + 1);
    char *result;
    char **stri;
    double div = 0;
    double col = 0;
    double **matrix;
    double **matrixs;

    strcpy(str, argv[1]);
    if (argv[2][0] == '\0')
        exit(84);
    strcpy(keys, argv[2]);
    stri = my_str_to_word_array(argv[1]);
    matrix = key(keys, &div);
    if (str[0] == '\0') {
        print_matrices(matrix, div);
        return 0;
    }
    matrixs = string(stri, &col, div);
    if (div == 2) {
        matrix = inver(matrix);
        matrixs = mult_2x2(matrixs, matrix, col, div);
    }
    if (div == 3) {
        matrix = inverse_key(matrix, div);
        matrixs = mult_3x3(matrixs, matrix, col, div);
    }
    if (div == 1) {
        matrix[0][0] = 1 / matrix[0][0];
        matrixs = mult_1x1(matrixs, matrix, col, div);
    }
    result = get_str(matrixs, div, col);
    printed_descrypted(matrix, result, div);
    return 0;
}

int choose(int argc, char **argv)
{
    if (argv[argc - 1][0] == '0') {
        encrypted(argv);
        return 0;
    }
    if (argv[argc - 1][0] == '1') {
        descrypted(argv);
        return 0;
    }
    else
        return 84;
    return 0;
}
