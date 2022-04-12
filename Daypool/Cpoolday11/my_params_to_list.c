/*
** EPITECH PROJECT, 2020
** my_params_to_list.c
** File description:
** fonction
*/

#include "mylist.h"
#include <stdlib.h>

linked_list_t *add_new_struct(void *data, linked_list_t *list)
{
    linked_list_t *new;

    new = malloc(sizeof(linked_list_t));
    new->data = data;
    new->next = list;
    return (new);
}

linked_list_t *my_params_to_list(int argc, char * const *argv)
{
    linked_list_t *list;
    int i = 0;

    list = NULL;
    while (i < argc) {
        list = add_new_struct(argv[i], list);
        i++;
    }
    return (list);
}
