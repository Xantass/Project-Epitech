/*
** EPITECH PROJECT, 2021
** read_from_file.c
** File description:
** functions
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"

char **read_from_file(char *path, char *mode)
{
    FILE *file = fopen(path, mode);
    struct stat statbuf = {0};
    char *content = NULL;
    char **tab = NULL;

    if (stat(path, &statbuf) == -1)
        return NULL;
    content = my_calloc(sizeof(char), (statbuf.st_size) + 1);
    fread(content, statbuf.st_size, statbuf.st_blocks, file);
    tab = twa(content, NULL);
    if (tab == NULL)
        return NULL;
    fclose(file);
    free(content);
    return tab;
}
