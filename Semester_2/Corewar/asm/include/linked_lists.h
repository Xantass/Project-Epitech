/*
** EPITECH PROJECT, 2021
** linked_lists.h
** File description:
** header
*/

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stddef.h>

typedef struct list_elem_t list_elem_t;
struct list_elem_t {
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
void push_front(list_t *my_list, int i);
list_t *inits(int i, list_t *my_list);
int fill_list(char *argv[]);
void sa(list_elem_t **my_list);
void clear_list(list_t *my_list);
void push_back(list_t *my_list, int i);
#endif
