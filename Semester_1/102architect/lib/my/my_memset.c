/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

void *my_memset(char *s, int n, size_t size)
{
    for (size_t i = 0; i != size; i += 1)
        s[i] = n;
    return s;
}
