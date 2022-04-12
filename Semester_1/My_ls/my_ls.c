/*
** EPITECH PROJECT, 2020
** my_ls.c
** File description:
** function
*/

#include <stdio.h>
#include <dirent.h>
#include "array.h"
#include "my.h"
#include "ls.h"

char **stock_root(char const *name, array_t *f);
char **stock_info_file(char const *name, array_t *f);
void print(array_t *f);

char *tri_flags(array_t *f)
{
    char *mem = my_calloc_bis(sizeof(char), 5);
    int u = 0;

    for (int i = 0; i < 4; i++) {
        for (int h = 0; f->flags[h] != '\0'; h++) {
            if (f->flags[h] == op[i].c) {
                mem[u] = op[i].c;
                u++;
                break;
            }
        }
    }
    return mem;
}

void loop(array_t *f)
{
    int j = 0;

    for (int i = 0; f->name[i] != NULL; i++) {
        if (opendir(f->name[i]) != NULL)
            f->result = stock_root(f->name[i], f);
        else
            f->result = stock_info_file(f->name[i], f);
        for (int h = 0; f->flags[h] != '\0'; j++) {
            if (f->flags[h] == op[j].c) {
                f->result = op[j].func(f, f->name[i]);
                j = 0;
                h++;
            }
        }
        print(f);
        j = 0;
    }
}

void no_flag(array_t *f)
{
    for (int i = 0; f->name[i] != NULL; i++) {
        if (opendir(f->name[i]) != NULL) {
            f->result = stock_root(f->name[i], f);
        }
        else {
            f->result = stock_info_file(f->name[i], f);
        }
        print(f);
    }
}

void flag_bis(array_t *f)
{
    int j = 0;
    
    for (int h = 0; f->flags[h] != '\0'; j++) {
        if (f->flags[h] == op[j].c) {
            f->result = op[j].func(f, ".");
            j = 0;
            h++;
        }
    }
    print(f);
}

int flag(array_t *f)
{
    f->flags = tri_flags(f);
    if (f->name[0] == NULL) {
        f->result = stock_root(".", f);
        flag_bis(f);
        return 0;
    }
    else {
        loop(f);
        return 0;
    }
    return 0;
}

