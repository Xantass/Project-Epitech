/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char *my_strdup(char *src)
{
    char *memoire;
    int j = 0;
    int i = 0;

    while(src[j] != '\0')
        j = j + 1;
    memoire = my_calloc(sizeof(char), (j + 1));
    while (src[i] != '\0') {
        memoire[i] = src[i];
        i = i + 1;
    }
    return (memoire);
}
