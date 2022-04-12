/*
** EPITECH PROJECT, 2021
** set_env.c
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
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '=')
            return -2;
    }
    for (int i = 0; f->new_env[i] != NULL; i++) {
        if (my_strcmp(name, f->new_env[i]) == 0)
            return i;
    }
    return -1;
}

int modif_name(const char *name, const char *value, info_t *f, int res)
{
    int name_ = my_strlen(name) - 1;
    int value_ = 0;
    int size = 0;
    char *str = NULL;

    if (value == NULL)
        value_ = 1;
    else
        value_ = my_strlen(value) - 1;
    size = name_ + value_ + 1;
    if ((str = malloc(sizeof(char) * size + 1)) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    str = my_strcpy(str, name);
    str = my_strcat(str, "=");
    if (value == NULL);
    else
        str = my_strcat(str, value);
    f->new_env[res] = str;
    return 0;
}

int add_name_bis(info_t *f, char *str, const char *value)
{
    char **stock = f->new_env;
    char **env = NULL;
    int size = 0;
    int i = 0;

    if (value == NULL);
    else
        str = my_strcat(str, value);
    for (; f->new_env[size] != NULL; size++);
    size += 1;
    if ((env = malloc(sizeof(char *) * (size + 1))) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    env[size] = NULL;
    for (; stock[i] != NULL; i++) {
        env[i] = stock[i];
    }
    env[i] = str;
    f->new_env = env;
    return 0;
}

int add_name(const char *name, const char *value, info_t *f)
{
    int name_ = my_strlen(name) - 1;
    int value_ = 0;
    int size = 0;
    char *str = NULL;

    if (value == NULL)
        value_ = 1;
    else
        value_ = my_strlen(value) - 1;
    size = name_ + value_ + 1;
    if ((str = malloc(sizeof(char) * (size + 1))) == NULL) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    str = my_strcpy(str, name);
    str = my_strcat(str, "=");
    add_name_bis(f, str, value);
    return 0;
}

int set_env(const char *name, const char *value, info_t *f)
{
    int res = 0;

    res = check(name, f);
    if (res == -2)
        return -1;
    if (res == -1) {
        add_name(name, value, f);
        return 0;
    }
    else {
        if (modif_name(name, value, f, res) == -1)
            return -1;
        return 0;
    }
    return 0;
}
