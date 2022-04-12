/*
** EPITECH PROJECT, 2020
** boostrap_architect.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector_struct.h"
#include "print.h"
#include "proto.h"
#include "matrix.h"

void create_struct_matrix(struct matrix *f);
double *calcf(double *vector, struct matrix *f);
void print_usage(void);
int char_is_nb(char *c);

int check_argv(char c)
{
    if (c == 't')
        return 0;
    if (c == 'z')
        return 0;
    if (c == 'r')
        return 0;
    if (c == 's')
        return 0;
    return 1;
}

double *choose(char **argv, int *i, double *vector, struct matrix *f)
{
    int h = 0;
    int j = *i + 1;
    int u = 0;

    for (;argv[j] != NULL && check_argv(argv[j][1]) == 1; j++) {
        u++;
    }
    while (h < 2) {
        if (argv[*i][1] == arg[h].c) {
            if (u != 2) {
                vector = NULL;
                return vector;
            }
            if (char_is_nb(argv[*i + 1]) == 0 || char_is_nb(argv[*i + 2]) == 0) {
                vector = NULL;
                return vector;
            }
            else {
                vector = arg[h].func(vector, f, atof(argv[*i + 1]), atof(argv[*i + 2]));
                return vector;
            }
        }
        h++;
    }
    h = 0;
    while (h < 2) {
        if (argv[*i][1] == args[h].c) {
            if (u != 1) {
                vector = NULL;
                return vector;
            }
            if (char_is_nb(argv[*i + 1]) == 0) {
                vector = NULL;
                return vector;
            }
            else {
                vector =  args[h].func(vector, f, atof(argv[*i + 1]));
                return vector;
            }
        }
        h++;
    }
    return vector;
}

double *calc(double *vector, struct matrix *f, char **argv, int argc)
{
    int i = argc - 1;
    int o = 0;

    for (; i != 0; i--) {
        if (check_argv(argv[i][1]) == 0) {
            vector = choose(argv, &i, vector, f);
            if (vector == NULL)
                return vector;
            o++;
        }
    }
    if (o == 0) {
        vector = NULL;
        return vector;
    }
    vector = calcf(vector, f);
    return vector;
}

void print(double *new_vector, char **argv, struct matrix *f)
{
    int i = 0;
    int h = 0;

    for (i = 0 ;argv[i] != 0; i++) {
        for (h = 0; h < 4; h++) {
            if (argv[i][1] == p[h].c) {
                p[h].func(argv, &i);
                break;
            }
        }
    }
    print_matrix(f);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(argv[1]), atof(argv[2]), new_vector[0], new_vector[1]);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 84;
    if (argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    if (argc < 5)
        return 84;
    if (char_is_nb(argv[1]) == 0)
        return 84;
    if (char_is_nb(argv[2]) == 0)
        return 84;
    else {
    double *vector = create_vector(atof(argv[1]), atof(argv[2]), vector);
    double *new_vector = create_new_vector(new_vector);
    struct matrix f;
    create_struct_matrix(&f);
    new_vector = calc(vector, &f, argv, argc);
    if (new_vector == NULL)
        return 84;
    print(new_vector, argv, &f);
    return 0;
    }
}
