/*
** EPITECH PROJECT, 2021
** unset_env.c
** File description:
** function
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

int shell(char **env, info_t *f, int nb);

static int check(const char *name, info_t *f)
{
    if (my_strlen(name) == 1)
        return -2;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '=')
            return -2;
    }
    for (int i = 0; f->new_env[i] != NULL; i++) {
        if (my_strcmp(f->new_env[i], name) == 0)
            return i;
    }
    return -1;
}

int delete_name(int res, info_t *f)
{
    char **env = NULL;
    int size = 0;
    int j = 0;

    for (; f->new_env[size] != NULL; size++);
    if ((env = malloc(sizeof(char *) * size)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    env[size - 1] = NULL;
    for (int i = 0; f->new_env[i] != NULL; i++) {
        if (i == res)
            i++;
        env[j] = f->new_env[i];
        j++;
    }
    f->new_env = env;
    return 0;
}

int unset_env(info_t *f)
{
    int res = 0;

    for (int i = 1; f->com[i] != NULL; i++) {
        res = check(f->com[i], f);
        if (res == -1)
            return 0;
        if (res == -2)
            return -1;
        delete_name(res, f);
    }
    return 0;
}
