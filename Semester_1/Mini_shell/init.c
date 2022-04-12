/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** function
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int shell(char **env, info_t *f, int nb);

static char *check(char *env, char **new_env, info_t *f)
{
    int size = my_strlen(env);
    char *str = NULL;

    if ((str = malloc(sizeof(char) * size + 1)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(new_env, f, 139);
    }
    str[size] = '\0';
    if (my_strcmp(env, "PATH") == 0) {
        my_strcpy(str, env);
        str = str + 5;
        return str;
    }
    return NULL;
}

char *get_paths(info_t *f)
{
    char *str = NULL;

    for (int i = 0; f->new_env[i] != NULL; i++) {
        if ((str = check(f->new_env[i], f->new_env, f)) != NULL)
            return str;
    }
    return NULL;
}

char **add_slash(char **str)
{
    int size = 0;
    
    for (int i = 0; str[i] != NULL; i++) {
        size = my_strlen(str[i]) - 1;
        if (str[i][size] != '/')
            str[i] = my_strcat(str[i], "/");
    }
    return str;
}

char *get_com(void)
{
    char *lineptr = NULL;
    size_t len = 0;
    int res = 0;

    my_putstr("->");
    if (getline(&lineptr, &len, stdin) == -1) {
        return NULL;
    }
    res = my_strlen(lineptr);
    if (res == 1)
        return get_com();
    return lineptr;
}

char *valid_com(char *str, info_t *f)
{
    int size = my_strlen(str) - 1;
    char *new = 0;

    if ((new = malloc(sizeof(char) * size + 1)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    new[size] = '\0';
    for (int i = 0; str[i] != '\n'; i++) {
        new[i] = str[i];
    }
    return new;
}
