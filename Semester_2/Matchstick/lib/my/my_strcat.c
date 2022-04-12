/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *tmp = dest;
    int dest_ = my_strlen(dest);
    int src_ = my_strlen(src);
    int size = dest_ + src_;
    
    dest = malloc(sizeof(char) * size + 1);
    dest[size] = '\0';
    my_strcpy(dest, tmp);
    while (src[i] != '\0') {
        dest[dest_ + i] = src[i];
        i++;
    }
    return (dest);
}
