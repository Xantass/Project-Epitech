/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** functions
*/

#include <string.h>
#include <stdio.h>

int error_handling(int argc, char *argv[])
{
    if (argc > 4)
        return -1;
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return -1;
    }
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return -1;
    }
    if (argv[3] != NULL) {
        if (strcmp(argv[3] ,"perfect") != 0)
            return -1;
    }
    return 0;
}
