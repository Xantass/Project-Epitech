/*
** EPITECH PROJECT, 2020
** filepath.c
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
#include "array.h"
#include "my.h"

char *check(struct stat *temp)
{
    char *str = my_calloc(sizeof(char), 8);
    str[7] = '\0';
    str = my_strcpy(str, "Type: ");
    switch (temp->st_mode & S_IFMT) {
    case S_IFBLK:  str[6] = 'b'; return str;
    case S_IFCHR:  str[6] = 'c'; return str;
    case S_IFDIR:  str[6] = 'd'; return str;
    case S_IFIFO:  str[6] = 'p'; return str;
    case S_IFLNK:  str[6] = 'l'; return str;
    case S_IFREG:  str[6] = '-'; return str;
    case S_IFSOCK: str[6] = 's'; return str;
    default: str[6] = '?'; return str;
    }
}

char **stock(char **mem, struct stat *temp, char *str, char const *name)
{
    mem[0] = my_strcpy(mem[0], "Name: ");
    mem[0] = my_strcat(mem[0], name);
    mem[1] = my_strcat(mem[1], str);
    mem[2] = my_strcpy(mem[2], "Inode: ");
    mem[2] = my_strcat(mem[2], get_char(temp->st_ino));
    mem[3] = my_strcpy(mem[3], "Hard Link: ");
    mem[3] = my_strcat(mem[3], get_char(temp->st_nlink));
    mem[4] = my_strcpy(mem[4], "Size: ");
    mem[4] = my_strcat(mem[4], get_char(temp->st_size));
    mem[5] = my_strcpy(mem[5], "Allocated space: ");
    mem[5] = my_strcat(mem[5], get_char(temp->st_blocks));
    mem[6] = my_strcpy(mem[6], "Minor: ");
    mem[6] = my_strcat(mem[6], get_char(minor(temp->st_dev)));
    mem[7] = my_strcpy(mem[7], "Major: ");
    mem[7] = my_strcat(mem[7], get_char(major(temp->st_dev)));
    mem[8] = my_strcpy(mem[8], "UID: ");
    mem[8] = my_strcat(mem[8], get_char(temp->st_uid));
    mem[9] = my_strcpy(mem[9], "GID: ");
    mem[9] = my_strcat(mem[9], get_char(temp->st_gid));
    return mem;
}

char **stock_info_file(char const *name, array_t *f)
{
    struct stat temp;
    char **mem;
    char *str;

    mem = my_calloc(sizeof(char *), 11);
    mem[10] = NULL;
    for (int i = 0; i < 10; i++)
        mem[i] = my_calloc_bis(sizeof(char), 50);
    stat(name, &temp);
    str = check(&temp);
    mem = stock(mem, &temp, str, name);
    return mem;
}
