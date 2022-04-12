/*
** EPITECH PROJECT, 2020
** error_man.c
** File description:
** function
*/

#include <stddef.h>
#include "my.h"

int check_char(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return 84;
}

int check_temp(char **str)
{
    if (str[0][0] != 'A' && str[0][0] != 'T') {
        return 84;
    }
    for (int i = 1; str[i] != NULL; i++) {
        for (int j = 0; str[i][j] != '\0'; j++) {
            if (check_char(str[i][j]) == 84)
                return 84;
        }
    }
    return 0;
}

double *init_a(char **temp, double *cor)
{
    cor[0] = 1;
    cor[1] = my_getnbr(temp[1]);
    cor[2] = my_getnbr(temp[2]);
    cor[3] = my_getnbr(temp[3]);
    cor[4] = my_getnbr(temp[4]);
    cor[5] = my_getnbr(temp[5]);
    cor[6] = my_getnbr(temp[6]);
    cor[7] = my_getnbr(temp[7]);
    return cor;
}

double *init_t(char **temp, double *cor)
{
    cor[0] = 2;
    cor[1] = my_getnbr(temp[1]);
    cor[2] = my_getnbr(temp[2]);
    cor[3] = my_getnbr(temp[3]);
    return cor;
}
