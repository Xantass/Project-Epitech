/*
** EPITECH PROJECT, 2021
** clean_str.c
** File description:
** functions
*/

#include <stdlib.h>
#include "lib.h"

char *clean_str(char *str)
{
    char *new_str = my_calloc(sizeof(char), (my_strlen(str)) + 1);
    unsigned int i = 0;
    unsigned int end = my_strlen(str) - 1;
    unsigned int offset = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[end] == ' ' || str[i] == '\t'; end--);
    for (; i <= end; i++, offset++)
        new_str[offset] = str[i];
    return new_str;
}
