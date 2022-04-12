/*
** EPITECH PROJECT, 2021
** linked_lists.h
** File description:
** header
*/

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stddef.h>
#include "graph.h"

typedef struct list_elem_t list_elem_t;
struct list_elem_t {
    sfRectangleShape **map;
    int nb;
    list_elem_t *next;
    list_elem_t *prev;
};

typedef struct list_t list_t;
struct list_t {
    int length;
    list_elem_t *head;
    list_elem_t *tail;
};

void print_list(list_t *my_list);
void pop_front(list_t *my_list);
void push_front(list_t *my_list, sfTexture *texture, int i, sfTexture *texture_);
list_t *inits(sfTexture *texture, int i, list_t *my_list, sfTexture *texture_);
int fill_list(char *argv[]);
void sa(list_elem_t **my_list);
void clear_list(list_t *my_list);
void push_back(list_t *my_list, sfTexture *texture, int i, sfTexture *texture_);
sfRectangleShape **create_rectangle(sfTexture *texture, sfTexture *texture_);
#endif
