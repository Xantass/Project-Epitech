/*
** EPITECH PROJECT, 2020
** print.c
** File description:
** function
*/

#include <stddef.h>
#include "array.h"
#include "my.h"

void print(array_t *f)
{
    for (int i = 0; f->result[i] != NULL; i++) {
        if (f->result[i] == NULL)
            break;
        my_putstr(f->result[i]);
        my_putchar('\n');
    }
}
