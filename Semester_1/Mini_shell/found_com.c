/*
** EPITECH PROJECT, 2021
** found_com.c
** File description:
** function
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"

void exec(char *path, info_t *f);
int cd(info_t *f);
int set_env(const char *name, const char *value, info_t *f);
int execute_file(char *path, info_t *f);
int check_com_bis(info_t *f);
void print_env(info_t *f);
int check_arg(char **str);

char *add_com(char *path, char *str)
{
    path = my_strcat(path, str);
    return path;
}

static int check_bis(char *path, info_t *f)
{
    path = add_com(path, f->com[0]);
    if (open(path, O_RDONLY) != -1) {
        exec(path, f);
        return 0;
    }
    return -1;
}

static int check(char *path, info_t *f)
{
    if (opendir(path) != NULL) {
        if (check_bis(path, f) == 0)
            return 0;
        return -1;
    }
    return -1;
}

static int check_com(info_t *f)
{
    int res = 0;

    if (my_strcmp_bis(f->com[0], "cd") == 0) {
        if (cd(f) == -1)
            return -1;
        return 1;
    }
    if (my_strcmp_bis(f->com[0], "setenv") == 0) {
        if (f->com[1] == NULL) {
            print_env(f);
            return 1;
        }
        if (check_arg(f->com) > 3 || set_env(f->com[1], f->com[2], f) == -1)
            return -1;
        return 1;
    }
    if ((res = check_com_bis(f)) == 1)
        return 1;
    if (res == -1)
        return -1;
    return 0;
}

int exe_com(info_t *f)
{
    int res = 0;

    if (f->com[0][0] == '.' && f->com[0][1] == '/') {
        if (execute_file(&f->com[0][2], f) == -1)
            return 1;
        return 0;
    }
    if ((res = check_com(f)) == 1)
        return 0;
    if (res == -1) {
        return 1;
    }
    for (int i = 0; f->path[i] != NULL; i++) {
        if (check(f->path[i], f) == 0)
            return 0;
    }
    write(2, f->com[0], my_strlen(f->com[0]));
    write(2, &": Command not found.\n", 21);
    return 1;
}
