/*
** EPITECH PROJECT, 2020
** flag_t.c
** File description:
** function
*/

#include <stdio.h>
#include <dirent.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <features.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "array.h"
#include "my.h"

unsigned long **tri(unsigned long **time, int i)
{
    int j = i - 1;
    unsigned long temps = 0;
    unsigned long temp = 0;

    i = i - 1;
    for (; i >= 0; i--) {
        j = i;
        for (; j >= 0; j--) {
            if (time[i][1] > time[j][1]) {
                temps = time[i][0];
                temp = time[i][1];
                time[i][0] = time[j][0];
                time[i][1] = time[j][1];
                time[j][0] = temps;
                time[j][1] = temp;
                j = i;
            }
        }
    }
    return time;
}

unsigned long **init_int_2d_array(unsigned long **time, int i, array_t *f)
{
    struct stat temp;

    for (int j = 0; j < i; j++) {
        stat(f->result[j], &temp);
        time[j][0] = j;
        time[j][1] = temp.st_mtime;
    }
    return time;
}

char **tri_time(array_t *f, char const *name)
{
    char **mem;
    unsigned long **time;
    int i = 0;

    for (; f->result[i] != NULL; i++);
    mem = my_calloc(sizeof(char *), i + 1);
    time = malloc(sizeof(unsigned long *) * i);
    mem[i] = NULL;
    for (int j = 0; j < i; j++) {
        mem[j] = my_calloc_bis(sizeof(char), my_strlen(f->result[j]) + 1);
        time[j] = malloc(sizeof(unsigned long) * 2);
    }
    time = init_int_2d_array(time, i, f);
    time = tri(time, i);
    for (int j = 0; j < i; j++) {
        my_strcpy(mem[j], f->result[time[j][0]]);
    }
    return mem;
}
