/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** function
*/

#ifndef PROTO_H
#define PROTO_H

char **my_str_to_word_array(char *str);
double **key(char *str, double *div);
double **string(char **str, double *col, double div);
double **transpo(double **matrix, double div, double col);
double **inver(double **temp);
double **inverse_key(double **matrix, double div);
double **transpo_key(double **matrix, double div);
double **key_encrypted(char *str, double *div);
double **string_encrypted(char *str, double col, double div);
double **mult_3x3(double **matrix, double **matrixs, double col, double div);
double **mult_2x2(double **matrix, double **matrixs, double col, double div);
double **mult_1x1(double **matrix, double **matrixs, double col, double div);
void printed_encrypted(double **matrix, double **matrixs, double col, double div);
void printed_descrypted(double **matrix, char *str, double div);
void print_matrice(double **matrix, double div);
int choose(int argc, char **argv);
void printed_usage(void);
void print_matrices(double **matrix, double div);
#endif
