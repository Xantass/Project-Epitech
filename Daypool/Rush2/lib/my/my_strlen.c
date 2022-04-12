/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** error management function
*/

#include <unistd.h>
#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
