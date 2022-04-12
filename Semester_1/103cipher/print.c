/*
** EPITECH PROJECT, 2020
** print.c
** File description:
** function
*/

#include <stdio.h>

void printed_encrypted(double **matrix, double **matrixs, double col, double div)
{
    int t = 0;

    printf("Key matrix:\n");
    for (int u = 0; u < div; u++) {
        printf("%.0f", matrix[u][t]);
        for (t = 1; t < div; t++) {
            printf("\t%.0f", matrix[u][t]);
        }
        printf("\n");
        t = 0;
    }
    printf("\n");
    printf("Encrypted message:\n");
    printf("%.0f", matrixs[0][0]);
    for (int u = 0; u < col; u++) {
        if (u >= 1)
            printf(" %.0f", matrixs[u][t]);
        for (int t = 1; t < div; t++)
            printf(" %.0f", matrixs[u][t]);
        t = 0;
    }
    printf("\n");
}

void printed_descrypted(double **matrix, char *str, double div)
{
    int t = 0;
    
    printf("Key matrix:\n");
    for (int u = 0; u < div; u++) {
        printf("%.3f", matrix[u][t]);
        for (t = 1; t < div; t++) {
            printf("\t%.3f", matrix[u][t]);
        }
        printf("\n");
        t = 0;
    }
    printf("\n");
    printf("Descrypted message:\n");
    printf("%s\n", str);
}

void printed_usage(void)
{
    printf("USAGE\n");
    printf("   ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("   message     a message, made of ASCII characters\n");
    printf("   key         the encryption key, made of ASCII characters\n");
    printf("   flag        0 for the message to be encrypted, 1 to be decrypted\n");
}

void print_matrice(double **matrix, double div)
{
    int t = 0;
    
    printf("Key matrix:\n");
    for (int u = 0; u < div; u++) {
        printf("%.0f", matrix[u][t]);
        for (t = 1; t < div; t++)
            printf("\t%.0f", matrix[u][t]);
        printf("\n");
        t = 0;
    }
    printf("\nEncrypted message:\n\n");
}

void print_matrices(double **matrix, double div)
{
    int t = 0;
    
    printf("Key matrix:\n");
    for (int u = 0; u < div; u++) {
        printf("%.0f", matrix[u][t]);
        for (t = 1; t < div; t++)
            printf("\t%.0f", matrix[u][t]);
        printf("\n");
        t = 0;
    }
    printf("\nDescrypted message:\n\n");
}
