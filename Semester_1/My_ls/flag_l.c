/*
** EPITECH PROJECT, 2020
** flag_l.c
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

char *check_l(struct stat *temp, char *mem);
char *stock_info_bis(char *mem, struct stat *temp);

char *perm(struct stat *temp)
{
    mode_t p = temp->st_mode;
    char *memo = malloc(sizeof(char) * 9 + 1);
    
    memo[0] = (p & S_IRUSR) ? 'r' : '-';
    memo[1] = (p & S_IWUSR) ? 'w' : '-';
    memo[2] = (p & S_IXUSR) ? 'x' : '-';
    memo[3] = (p & S_IRGRP) ? 'r' : '-';
    memo[4] = (p & S_IWGRP) ? 'w' : '-';
    memo[5] = (p & S_IXGRP) ? 'x' : '-';
    memo[6] = (p & S_IROTH) ? 'r' : '-';
    memo[7] = (p & S_IWOTH) ? 'w' : '-';
    memo[8] = (p & S_IXOTH) ? 'x' : '-';
    memo[9] = '\0';
    return memo;     
}

char *cut(struct stat *temp)
{
    char *str = ctime(&temp->st_mtime);

    str = str + 4;
    str[my_strlen(ctime(&temp->st_mtime)) - 13] = '\0';
    return str;
}

char *stock_info(char *mem, struct stat *temp, char const *name, int *total)
{
    char *str = perm(temp);

    *total = *total + temp->st_blocks;
    mem = check_l(temp, mem);
    my_strcat(mem, str);
    my_strcat(mem, ". ");
    my_strcat(mem, get_char(temp->st_nlink));
    my_strcat(mem, " ");
    mem = stock_info_bis(mem, temp);
    my_strcat(mem, get_char(temp->st_size));
    my_strcat(mem, " ");
    str = cut(temp);
    my_strcat(mem, str);
    my_strcat(mem, " ");
    my_strcat(mem, name);
    return mem;
}

char **init_mem(array_t *f, char **mem, int j, char const *name)
{
    struct stat temp;
    DIR *open;
    char *str;
    int total = 0;

    my_strcpy(mem[0], "total ");
    for (int i = 0; i < j - 1; i++) {
        if (name[0] == '.' || (open = opendir(name)) == NULL) {
            stat(f->result[i], &temp);
            mem[i + 1] = stock_info(mem[i + 1], &temp, f->result[i], &total);
        }
        else if (name[0] != '.') {
            str = my_calloc_bis(sizeof(char), my_strlen(name) + my_strlen(f->result[i]) + 1);
            my_strcpy(str, name);
            my_strcat(str, f->result[i]);
            stat(str, &temp);
            mem[i + 1] = stock_info(mem[i + 1], &temp, f->result[i], &total);
        }
    }
    my_strcat(mem[0], get_char(total / 2));
    return mem;
}

char **more_information(array_t *f, char const *name)
{
    char **mem;
    DIR *open;
    int j = 0;

    if ((open = opendir(name)) == NULL) {
        mem = malloc(sizeof(char *) * 2);
        mem[1] = NULL;
        mem[0] = malloc(sizeof(char) * my_strlen(name));
        my_strcpy(mem[0], name);
        f->result = mem;
    }
    for (; f->result[j] != NULL; j++);
    j = j + 1;
    mem = my_calloc_bis(sizeof(char *), (j + 1));
    mem[j] = NULL;
    for (int i = 0; i < j; i++) {
        mem[i] = my_calloc_bis(sizeof(char), 100);
    }
    mem = init_mem(f, mem, j, name);
    return mem;
}
