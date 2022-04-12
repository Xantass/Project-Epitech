/*
** EPITECH PROJECT, 2021
** found_com_bis.c
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

int unset_env(info_t *f);

void exit_(int error)
{
    exit(error);
}

static int check_bis(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return -1;
}

static int check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_bis(str[i]) == -1)
            return -1;
    }
    return 0;
}

void print_env(info_t *f)
{
    for (int i = 0; f->new_env[i] != NULL; i++) {
        my_putstr(f->new_env[i]);
        my_putchar('\n');
    }
}

int check_com_bis(info_t *f)
{
    if (my_strcmp_bis(f->com[0], "unsetenv") == 0) {
        if (f->com[1] == NULL) {
            write(2, f->com[0], my_strlen(f->com[0]));
            write(2, &": Too few arguments.\n", 21);
            return -1;
        }
        if (unset_env(f) == -1)
            return -1;
        return 1;
    }
    if (my_strcmp_bis(f->com[0], "exit") == 0) {
        if (f->com[1] == NULL)
            exit_(0);
        if (check(f->com[1]) == -1) {
            write(2, &"exit: Expression Syntax.\n", 25);
            return -1;
        }
        exit_(my_getnbr(f->com[1]));
    }
    return 0;
}
