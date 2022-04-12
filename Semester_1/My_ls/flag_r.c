/*
** EPITECH PROJECT, 2020
** flag_r.c
** File description:
** function
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "my.h"

char **tri_reverse(array_t *f, char const *name)
{
    char **mem;
    int i = 0;
    int j = 0;

    for (; f->result[j] != NULL; j++);
    mem = malloc(sizeof(char *) * (j + 1));
    mem[j] = NULL;
    j = j - 1;
    for (; j > -1; j--) {
        mem[i] = malloc(sizeof(char) * (my_strlen(f->result[j]) + 1));
        mem[i] = my_strcpy(mem[i], f->result[j]);
        i++;
    }
    return mem;
}
