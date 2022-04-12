/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int check_nb(char nb)
{
    if (nb == '1')
        return 0;
    if (nb == '2')
        return 0;
    if (nb == '3')
        return 0;
    else
        return 1;
}

static char *get_ext(char *file, int nb)
{
    char **known_types = {0};
    char *res = {0};

    if ((known_types = my_calloc(sizeof(char*), (4))) == NULL)
        return NULL;
    if ((res = my_calloc(sizeof(char), (5))) == NULL)
        return NULL;
    known_types[0] = "lyr";
    known_types[1] = "html";
    known_types[2] = "ppm";
    my_revstr(file);
    for (int i = 0; file[i] != '.'; i++)
        res[i] = file[i];
    my_revstr(res);
    my_revstr(file);
    if (my_strcmp(res, known_types[nb]) != 0)
        return NULL;
    for (int i = 2; i >= 0; i--)
        known_types[i] = NULL;
    free(known_types);
    return res;
}

int check_args(int argc, char *argv[])
{
    char *res;

    if (argc != 3)
        return 84;
    if (my_strlen(argv[2]) >= 2)
        return 84;
    if (check_nb(argv[2][0]) == 1)
        return 84;
    res = get_ext(argv[1], my_get_number(&argv[2][0]) - 1);
    if (res == NULL)
        return 84;
    else
        free(res);
    return 0;
}
