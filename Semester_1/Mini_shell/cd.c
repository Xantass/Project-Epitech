/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** function
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int shell(char **env, info_t *f, int nb);
int set_env(const char *name, const char *value, info_t *f);
int print_error(char *str);
int cd_bis(info_t *f);

static int check(char **com)
{
    int i = 0;

    while (com[i] != NULL)
        i++;
    return i;
}

static char *check_bis(char *env, char **new_env, info_t *f)
{
    int size = my_strlen(env);
    char *str = NULL;

    if ((str = malloc(sizeof(char) * size + 1)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(new_env, f, 139);
    }
    str[size] = '\0';
    if (my_strcmp(env, "HOME") == 0) {
        my_strcpy(str, env);
        str = str + 5;
        my_strcat(str, "/");
        return str;
    }
    return NULL;
}

char *get_root(char **new_env, info_t *f)
{
    char *str = NULL;

    for (int i = 0; new_env[i] != NULL; i++) {
        if ((str = check_bis(new_env[i], new_env, f)) != NULL)
            return str;
    }
    return NULL;
}

int reset_env(char *line, info_t *f)
{
    char *str = NULL;

    str = getcwd(line, 1000);
    set_env("PWD", str, f);
    return 0;
}

int cd(info_t *f)
{
    char *root = NULL;

    if ((root = get_root(f->new_env, f)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    if (check(f->com) == 1 || (f->com[1][0] == '~' && f->com[1][1] == '\0')) {
        if (chdir(root) == -1)
            return -1;
        reset_env(root, f);
        return 0;
    }
    if (f->com[1][0] == '*' && f->com[1][1] == '\0') {
        write(2, &"*: Ambiguous.\n", 14);
        return -1;
    }
    if (cd_bis(f) == -1)
        return -1;
    return 0;
}
