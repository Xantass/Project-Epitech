/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

void *my_memset(char *s, int n, size_t size);

void *my_calloc(size_t nmemb, size_t size)
{
    size_t rsize = nmemb * size;
    void *p = malloc(rsize);

    if (p == NULL)
        return NULL;
    return my_memset(p, 0, rsize);
}
