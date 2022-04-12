/*
** EPITECH PROJECT, 2021
** found_com_bisss.c
** File description:
** function
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"

void exec(char *path, info_t *f);

int execute_file(char *path, info_t *f)
{
    exec(path, f);
    return -1;
}

int check_arg(char **str)
{
    int i = 0;

    for (; str[i] != NULL; i++);
    if (i > 3)
        write(2, "setenv: Too many arguments.\n", 28);
    return i;
}
