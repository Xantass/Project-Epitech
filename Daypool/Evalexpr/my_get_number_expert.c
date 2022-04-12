/*
** EPITECH PROJECT, 2020
** my_get_number_expert.c
** File description:
** function
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

int my_operator(char *str);
int my_char_isoperator(char c);
char *trans(int nb);
int print_my_error(char op, int nb_3);
int my_get_number(char *str);

int count_my_result(int nb_1, int nb_3, char op)
{
    long rest = 0;

    if (op == '+')
        rest = nb_1 + nb_3;
    else if (op == '-') {
        rest = nb_1 - nb_3;
    }
    else if (op == '*') {
        rest = nb_1 * nb_3;
    }
    else if  (op== '%') {
        if (print_my_error(op, nb_3) == 0)
            return (0);
        rest = nb_1 % nb_3;
    }
    else if (op  == '/') {
        if (print_my_error(op, nb_3) == 0)
            return (0);
        rest = nb_1 / nb_3;
    }
    return (rest);
}

int count_my_par(char *str, int *i)
{
    int nb_1 = 0;
    int nb_2 = 0;
    char op = 0;

    *i = *i + 1;
    nb_1 = my_get_number(&str[*i]);
    while (str[*i] != ')') {
        if (my_char_isoperator(str[*i]) == 1) {
            op = str[*i];
            *i = *i + 1;
            nb_2 = my_get_number(&str[*i]);
        }
        *i = *i + 1;
    }
    return (count_my_result(nb_1, nb_2, op));
}

char **get_nbr_expert(char *str, char  **tab_res)
{
    int i = 0;
    int j = 0;
    int h = 0;
    int nb = 0;

    while (str[i] != '\0' && str[i] != '+' && str[i] != '-') {
        if (str[i] == '*' || str[i] == '%' || str[i] == '/') {
            i++;
            j++;
            h = 0;
        }
        if (str[i] == '(') {
            nb = count_my_par(str, &i);
            tab_res[j] = trans(nb);
            j++;
        }
        tab_res[j][h] = str[i];
        tab_res[j][h + 1] = '\0';
        i++;
        h++;;
    }
    return tab_res;
}
