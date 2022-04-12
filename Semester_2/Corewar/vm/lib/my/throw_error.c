/*
** EPITECH PROJECT, 2021
** throw_error.c
** File description:
** functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

void throw_error(int code, char *error_message)
{
    my_putstr(error_message);
    write(1, "\n", 1);
    exit(code);
}
