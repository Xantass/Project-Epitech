/*
** EPITECH PROJECT, 2020
** flag_l_bis.c
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

char *check_l(struct stat *temp, char *mem)
{
    switch (temp->st_mode & S_IFMT) {
    case S_IFDIR:  mem[0] = 'd'; return mem;
    default: mem[0] = '-'; return mem;
    }
}

char *stock_info_bis(char *mem, struct stat *temp)
{
    uid_t id = temp->st_uid;
    struct passwd *pwnam = getpwuid(id);
    gid_t gid = pwnam->pw_gid;
    struct group *grnam = getgrgid(gid);

    my_strcat(mem, pwnam->pw_name);
    my_strcat(mem, " ");
    my_strcat(mem, grnam->gr_name);
    my_strcat(mem, " ");
    return mem;
}
