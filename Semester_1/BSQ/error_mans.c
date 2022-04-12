/*
** EPITECH PROJECT, 2020
** error_mans.c
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

int check_type(struct stat *temp)
{
    switch (temp->st_mode & S_IFMT) {
    case S_IFREG:  return 1;
    default: return 0;
    }
}
