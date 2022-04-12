/*
** EPITECH PROJECT, 2020
** linked_lists.c
** File description:
** functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "linked_lists.h"

void push_front(list_t *my_list, sfTexture *texture, int i, sfTexture *texture_)
{
    list_elem_t *new = malloc(sizeof(list_elem_t));
    list_elem_t *first;

    if (my_list->length == 0)
        my_list = inits(texture, i, my_list, texture_);
    else {
        first = my_list->head;
        my_list->length += 1;
        new->nb = i;
        new->map = create_rectangle(texture, texture_);
        new->next = my_list->head;
        new->prev = my_list->tail;
        my_list->tail->next = new;
        new->next = first;
        first->prev = new;
        my_list->head = new;
    }
}

void push_back(list_t *my_list, sfTexture *texture, int i, sfTexture *texture_)
{
    list_elem_t *new = malloc(sizeof(list_elem_t));
    list_elem_t *last;

    if (my_list->length == 0)
        my_list = inits(texture, i, my_list, texture_);
    else {
        last = my_list->tail;
        my_list->length += 1;
        new->nb = i;
        new->map = create_rectangle(texture, texture_);
        new->next = my_list->head;
        new->prev = my_list->tail;
        last->next = new;
        my_list->head->prev = new;
        my_list->tail = new;
    }
}

list_t *inits(sfTexture *texture, int i, list_t *my_list, sfTexture *texture_)
{
    list_elem_t *my_list_elem = malloc(sizeof(list_elem_t));

    my_list->length = 1;
    my_list_elem->nb = i;
    my_list_elem->map = create_rectangle(texture, texture_);
    my_list->head = my_list_elem;
    my_list->tail = my_list_elem;
    my_list_elem->next = my_list->head;
    my_list_elem->prev = my_list->tail;
    return my_list;
}
