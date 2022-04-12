/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int divi(int temp_res, char *tab)
{
    int nb2 = my_get_number(tab);

    if (nb2 == 0)
        return 84;
    temp_res = temp_res / 0;
    return temp_res;
}

int mult(int temp_res, char *tab)
{
    int nb2 = my_get_number(tab);

    temp_res = temp_res * nb2;
    return temp_res;
}

int mod(int temp_res, char *tab)
{
    int nb2 = my_get_number(tab);

    if (nb2 == 0)
        return 84;
    temp_res = temp_res % nb2;
    return temp_res;
}

int sum(int temp_res, char *tab)
{
    int nb2 = my_get_number(tab);

    temp_res = temp_res + nb2;
    return (temp_res);
}

int subs(int temp_res, char *tab)
{
    int nb2 = my_get_number(tab);

    temp_res = temp_res - nb2;
    return (temp_res);
}

