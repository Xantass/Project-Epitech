/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int print_my_error(char op, int nb_3);
char *stock_my_op(char *str);
int count_my_par(char *str, int i);

char *count_op(char *str)
{
    int i = 0;
    int j = 0;
    char *op = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '+' && str[i] != '-' && str[i] != '\0') {
        if (str[i] == '*' || str[i] == '/' || str[i] == '%') {
            op[j] = str[i];
            j = j + 1;
        }
        if (str[i] == ')') {
            op[j - 1] = 0;
            j = j - 1;
        }
        i = i + 1;
    }
    return (op);
}

int is_alphanum(char c)
{
    if (c >= '(' && c <= '+')
        return 0;
    if (c == '-')
        return 0;
    if (c == '/')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    if (c == ' ')
        return 0;
    else
        return 1;
}
