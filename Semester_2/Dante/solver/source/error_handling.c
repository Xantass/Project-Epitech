/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** function
*/

#include <unistd.h>

void clean_fd(int* fd)
{
    if (*fd != -1)
        close(*fd);
}
