/*
** EPITECH PROJECT, 2021
** my_calloc_bis.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>

void *my_memset(char *s, int n, size_t size);

void *my_calloc_bis(size_t nmemb, size_t size)
{
    size_t rsize = nmemb * size;
    void *p = malloc(rsize);

    if (p == NULL)
        return NULL;
    return my_memset(p, '0', rsize);
}
