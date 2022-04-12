/*
** EPITECH PROJECT, 2020
** alpha_tri.c
** File description:
** function
*/

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <time.h>
#include "array.h"
#include "my.h"

static void swap(char **a,char **b)
{
    char *e = 0;

    e = *a;
    *a = *b;
    *b = e;
}

char **sort_alpha(char **str)
{
    int size = 0;

    for (int i = 0; str[i] != NULL; i++) {
        size++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (my_strcmp(str[i], str[j]) > 0) {
                swap(&str[i], &str[j]);
            }
        }
    }
    return str;
}
