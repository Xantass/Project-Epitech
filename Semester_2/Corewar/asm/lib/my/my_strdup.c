/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *c);

char *my_strdup(char const *src)
{
    char *memoire;
    int j = 0;
    int i = 0;

    while (src[j] != '\0')
        j = j + 1;
    memoire = malloc(sizeof(char) + (j + 1));
    while (src[i] != '\0') {
        memoire[i] = src[i];
        i = i + 1;
    }
    memoire [i] = '\0';
    return (memoire);
}
