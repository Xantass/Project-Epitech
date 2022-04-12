/*
** EPITECH PROJECT, 2020
** main.c
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

void flag(array_t *f);
void print(array_t *f);
void no_flag(array_t *f);
char **sort_alpha(char **str);

char **stock_root(char const *name, array_t *f)
{
    DIR *count = opendir(name);
    DIR *open = opendir(name);
    struct dirent *read;
    char *str;

    for (int h = 0; (read = readdir(count)) != NULL; h++)
        f->result = my_calloc(sizeof(char *), (h + 1));
    for (int i = 0; (read = readdir(open)) != NULL;) {
        str = read->d_name;
        if (str[0] == '.') { }
        if (str[0] != '.') {
            f->result[i] = my_calloc(sizeof(char),
                                     (my_strlen(read->d_name) + 1));
            f->result[i][my_strlen(read->d_name)] = '\0';
            my_strcpy(f->result[i], read->d_name);
            i++;
            f->result[i] = NULL;
        }
    }
    f->result = sort_alpha(f->result);
    return f->result;
}

int stock_flag(char *argv, array_t *f, int *h)
{
    int i = 1;

    for (; argv[i] != '\0'; i++) {
        if (argv[i] == 'l')
            f->flags[(*h)] = argv[i];
        if (argv[i] == 'R')
            f->flags[(*h)] = argv[i];
        if (argv[i] == 'r')
            f->flags[(*h)] = argv[i];
        if (argv[i] == 't')
            f->flags[(*h)] = argv[i];
        if (argv[i] == 'd')
            f->flags[(*h)] = argv[i];
        if (argv[i] != 'l' && argv[i] != 'R' &&
            argv[i] != 'r' && argv[i] != 't' && argv[i] != 'd')
            return 0;
        (*h)++;
    }
    f->flags[(*h)] = '\0';
    return 1;
}

int stock_arg(array_t *f, char **argv, int argc, int fd)
{
    int h = 0;
    int p = 0;

    f->name = my_calloc(sizeof(char *), (argc + 1));
    f->name[0] = NULL;
    for (int i = 1; argv[i] != NULL; ++i) {
        if (argv[i][0] == '-')
            stock_flag(argv[i], f, &h);
        else if (opendir(argv[i]) != NULL && argv[i][0] != '-') {
            f->name[p] = my_calloc(sizeof(char), (my_strlen(argv[i]) + 1));
            my_strcpy(f->name[p], argv[i]);
            p++;
            f->name[p] = NULL;
        }
        else if (opendir(argv[i]) == NULL && argv[i][0] != '-') {
            f->name[p] = my_calloc(sizeof(char), (my_strlen(argv[i]) + 1));
            my_strcpy(f->name[p], argv[i]);
            p++;
            f->name[p] = NULL;
        }
    }
    return 1;
}

int my_ls(char **argv, int argc, array_t *f)
{
    int fd = 0;
    
    f->flags = my_calloc(sizeof(char), 5);
    if (argv[1] == NULL) {
        f->result = stock_root(".", f);
        print(f);
        return 0;
    }
    if (stock_arg(f, argv, argc, fd) == 0) {
        return 84;
    }
    f->name[argc] = NULL;
    if (f->flags[0] == '0') {
        no_flag(f);
        return 0;
    }
    else {
        flag(f);
        return 0;
    }
    return 0;
}

int main(int argc, char **argv)
{
    array_t f;
    
    if (my_ls(argv, argc, &f) == 84)
        return 84;
    free(f.flags);
    return 0;
}
