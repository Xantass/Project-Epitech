/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;
    int i = 0;

    while (i <= n) {
        dest[i] = 0;
        i = i + 1;
    }
    i = 0;
    while (j < n) {
        while (i != n) {
            dest[i] = src[i];
            i = i + 1;
        }
        j++;
    }
    return (dest);
}
