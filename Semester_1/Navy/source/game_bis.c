/*
** EPITECH PROJECT, 2020
** game_bis.c
** File description:
** functions
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int check(char *str)
{
    if (str[0] >= 'A' && str[0] <= 'H') {
        if (str[1] >= '1' && str[1] <= '8') {
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

char *get_attack()
{
    char *lineptr = NULL;
    size_t len = 0;

    my_putstr("\nattack: ");
    if (getline(&lineptr, &len, stdin) == -1) {
        return NULL;
    }
    if (check(lineptr) == 0) {
        my_putstr("wrong position");
        return get_attack();
    }
    else
        return lineptr;
}
