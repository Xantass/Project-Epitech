/*
** EPITECH PROJECT, 2020
** ls.h
** File description:
** function
*/

#ifndef LS_H
#define LS_H
#include "my.h"

struct flag {
    char c;
    char **(*func)(array_t *f, char const *name);
};

struct flag op[4] =
{
    {'t', tri_time},
    {'d', stock_folder},
    {'l', more_information},
    {'r', tri_reverse},
};
#endif
