/*
** EPITECH PROJECT, 2020
** my_list_size.c
** File description:
** fonction
*/

#include "mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int nb = 0;

    while (begin != NULL) {
        begin = begin->next;
        nb++;
    }
    return (nb);
}
