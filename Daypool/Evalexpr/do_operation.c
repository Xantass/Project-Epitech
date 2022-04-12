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

int print_my_error(char op, int nb_3)
{
    char str_1[] = "Stop: division by zero\n";
    char str_2[] = "Stop: modulo by zero\n";
    int i = 0;

    if (op == '/' && nb_3 == 0) {
        while (str_1[i] != '\0') {
            my_putchar(str_1[i]);
            i = i + 1;
        }
        return (0);
    }
    i = 0;
    if (op == '%' && nb_3 == 0) {
        while (str_2[i] != '\0') {
            my_putchar(str_2[i]);
            i = i + 1;
        }
        return (0);
    }
    return (1);
}

char *stock_my_op(char *str, int i)
{
    char *operator = malloc(sizeof(char) * (my_strlen(str) + 1));
    int o = 0;

    operator[my_strlen(str)] = '\0';
    while (str[i] != '\0') {
        if (str[i] == '-' || str[i] == '+') {
            operator[o] = str[i];
            o = o + 1;
        }
        i = i + 1;
    }
    return (operator);
}

