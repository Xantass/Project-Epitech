/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(int argc, char *argv[])
{
    char *file = NULL;

    if (check_args(argc, argv) != 0)
        return 84;
    file = load_file_in_mem(argv[1]);
    if (file == NULL)
        return 84;
    //printf("file = %s\n", file);
    send_string(file);
    free(file);
    return 0;
}
