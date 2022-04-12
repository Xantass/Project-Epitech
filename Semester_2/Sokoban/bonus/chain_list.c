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

list_t *init(int *cor, char c, list_t *list)
{
    element_t *element = malloc(sizeof(element_t));

    list->size = 1;
    element->x = cor[0];
    element->y = cor[1];
    element->c = c;
    element->nb = 0;
    list->first = element;
    list->last = element;
    element->next = list->last;
    element->prev = list->first;
    return list;
}

void inser_front(list_t *list, int *cor, char c)
{
    element_t *new = malloc(sizeof(element_t));
    element_t *stock;

    if (list->size == 0)
        list = init(cor, c, list);
    else {
        stock = list->first;
        list->size = list->size + 1;
        new->x = cor[0];
        new->y = cor[1];
        new->c = c;
        new->nb = 0;
        new->next = list->first;
        new->prev = list->last;
        list->last->next = new;
        new->next = stock;
        stock->prev = new;
        list->first = new;
    }
}

void inser_back(list_t *list, int *cor, char c)
{
    element_t *new = malloc(sizeof(element_t));
    element_t *stock;

    if (list->size == 0)
        list = init(cor, c, list);
    else {
        stock = list->last;
        list->size = list->size + 1;
        new->x = cor[0];
        new->y = cor[1];
        new->c = c;
        new->nb = 0;
        new->next = list->first;
        new->prev = list->last;
        list->last->next = new;
        new->prev = stock;
        stock->next = new;
        list->last = new;
    }
}

void sup_front(list_t *list)
{
    element_t *sup = list->first;

    list->size = list->size - 1;
    list->first = list->first->next;
    list->last->next = list->first;
    list->first->prev = list->last;
    free(sup);
}

void print_list(list_t *list)
{
    element_t *act = list->first;

    for (int i = 0; i < list->size; i++) {
        my_put_nbr(act->x);
        my_put_nbr(act->y);
        my_putchar(act->c);
        my_putchar('\n');
        act = act->next;
    }
    for (int i = 0; i < list->size; i++) {
        sup_front(list);
    }
}
