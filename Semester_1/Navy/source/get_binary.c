/*
** EPITECH PROJECT, 2020
** my_put_binary.c
** File description:
** functions
*/

#include <stdio.h>
#include "my.h"

char *get_binary(int nb)
{
    char *my_base = "01";
    char *hexa_result = my_calloc(sizeof(char), (100));
    int j = 0;

    while ((nb / 2) > 0) {
        hexa_result[j] = my_base[(nb % 2)];
        nb = nb / 2;
        j = j + 1;
    }
    hexa_result[j] = my_base[(nb % 2)];
    hexa_result[j + 1] = '\0';
    while (my_strlen(hexa_result) < 8)
        my_strcat(hexa_result, "0");
    my_revstr(hexa_result);
    return hexa_result;
}
