/*
** EPITECH PROJECT, 2020
** chain_list.c
** File description:
** function
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"
#include "list.h"
#include "proto.h"

list *init(int nb, list *list_t)
{
    element *element_t = malloc(sizeof(element));

    list_t->size = 1;
    element_t->nb = nb;
    list_t->first = element_t;
    list_t->last = element_t;
    element_t->next = list_t->last;
    element_t->prev = list_t->first;
    return list_t;
}

void inser_front(list *list_t, int new_nb)
{
    element *new = malloc(sizeof(element));
    element *stock;

    if (list_t->size == 0)
        list_t = init(new_nb, list_t);
    else {
        stock = list_t->first;
        list_t->size = list_t->size + 1;
        new->nb = new_nb;
        new->next = list_t->first;
        new->prev = list_t->last;
        list_t->last->next = new;
        new->next = stock;
        stock->prev = new;
        list_t->first = new;
    }
}

void inser_back(list *list_t, int new_nb)
{
    element *new = malloc(sizeof(element));
    element *stock;

    if (list_t->size == 0)
        list_t = init(new_nb, list_t);
    else {
        stock = list_t->last;
        list_t->size = list_t->size + 1;
        new->nb = new_nb;
        new->next = list_t->first;
        new->prev = list_t->last;
        list_t->last->next = new;
        new->prev = stock;
        stock->next = new;
        list_t->last = new;
    }
}

void sup_front(list *list_t)
{
    element *sup = list_t->first;

    list_t->size = list_t->size - 1;
    list_t->first = list_t->first->next;
    list_t->last->next = list_t->first;
    list_t->first->prev = list_t->last;
    free(sup);
}

void print_list(list *list_t)
{
    element *act = list_t->first;

    for (int i = 0; i < list_t->size; i++) {
        my_put_nbr(act->nb);
        my_putchar('\n');
        act = act->next;
    }
    for (int i = 0; i < list_t->size; i++) {
        sup_front(list_t);
    }
}
