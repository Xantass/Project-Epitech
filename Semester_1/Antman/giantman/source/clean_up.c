/*
** EPITECH PROJECT, 2021
** clean_up.c
** File description:
** function
*/

#include <unistd.h>

void clean_fd(int* fd)
{
    if (*fd != -1)
        close(*fd);
}
