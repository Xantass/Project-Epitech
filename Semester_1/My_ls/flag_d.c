/*
** EPITECH PROJECT, 2020
** flag_d.c
** File description:
** function
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "array.h"
#include "my.h"

char **stock_folder(array_t *f, char const *name)
{
    char **mem;

    mem = my_calloc(sizeof(char *), 2);
    mem[0] = my_calloc(sizeof(char), (my_strlen(name) + 1));
    my_strcpy(mem[0], name);
    return mem;
}
