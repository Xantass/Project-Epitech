/*
** EPITECH PROJECT, 2020
** do_op_expert.c
** File description:
** fonction
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_get_number(char *str);
int mult(int temp_res, char *tab);
int mod(int temp_res, char *tab);
int subs(int temp_res, char *tab);
int sum(int temp_res, char *tab);
int divi(int temp_res, char *tab);
int my_operator(char *str);

int do_op_expert(char *op, char **tab)
{
    int res = 0;
    int i = 0;
    int j = 1;
    int temp_res = my_get_number(tab[0]);
    while (op[i] != '\0') {
        if (op[i] == '+') {
            temp_res = sum(temp_res, tab[j]);
	    printf ("sum %d\n", sum(temp_res, tab[j]));
            j++;
        }
        if (op[i] == '-') {
            temp_res = subs(temp_res, tab[j]);
            j++;
        }
        if (op[i] == '*') {
            temp_res = mult(temp_res, tab[j]);
            j++;
        }
        if (op[i] == '/') {
            temp_res = divi(temp_res, tab[j]);
            j++;
        }
        if (op[i] == '%') {
            temp_res = mod(temp_res, tab[j]);
            j++;
        }
        i++;
    }
    res = temp_res;
    printf("res is %d\n", res);
    return (res);
}
