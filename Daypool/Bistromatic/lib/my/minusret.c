/*
** EPITECH PROJECT, 2020
** minusret.c
** File description:
** function
*/

#include <stdlib.h>
#include "my.h"

char *minusret(char *nbr, int minus)
{
    if (minus == 1) {
        return (nbr);
    } else {
        char *ret = malloc(sizeof(char) * (my_strlen(nbr) + 2));
        *ret = '-';
        my_strcpy(ret + 1, nbr);
        return (ret);
    }
}
