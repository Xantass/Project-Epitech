/*
** EPITECH PROJECT, 2021
** dante
** File description:
** alloc
*/

#include "struct.h"
#include "lib.h"

int **alloc_sol(vector_2ui_t *size)
{
    int **sol = my_calloc(sizeof(int *), size->x);

    for (unsigned int i = 0; i < size->x; ++i)
        sol[i] = my_calloc(sizeof(int), size->y + 1);
    return sol;
}