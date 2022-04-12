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

sfRectangleShape *spi(double *cor);

list *init(double *cor, list *list_t)
{
    element *element_t = malloc(sizeof(element));

    list_t->size = 1;
    element_t->plane = spi(cor);
    element_t->start.x = cor[1];
    element_t->start.y = cor[2];
    element_t->finish.x = cor[3];
    element_t->finish.y = cor[4];
    element_t->speed = cor[5];
    element_t->pop = cor[6];
    element_t->alt = cor[7];
    list_t->first = element_t;
    list_t->last = element_t;
    element_t->next = list_t->last;
    element_t->prev = list_t->first;
    return list_t;
}

void inser_front(list *list_t, double *cor)
{
    element *new = malloc(sizeof(element));
    element *stock;

    if (list_t->size == 0)
        list_t = init(cor, list_t);
    else {
        stock = list_t->first;
        list_t->size = list_t->size + 1;
        new->plane = spi(cor);
        new->start.x = cor[1];
        new->start.y = cor[2];
        new->finish.x = cor[3];
        new->finish.y = cor[4];
        new->speed = cor[5];
        new->next = list_t->first;
        new->prev = list_t->last;
        list_t->last->next = new;
        new->next = stock;
        stock->prev = new;
        list_t->first = new;
    }
}

element *yes(list *list_t, double *cor)
{
    element *new = malloc(sizeof(element));
    element *stock;

    stock = list_t->last;
    list_t->size = list_t->size + 1;
    new->plane = spi(cor);
    new->start.x = cor[1];
    new->start.y = cor[2];
    new->finish.x = cor[3];
    new->finish.y = cor[4];
    new->speed = cor[5];
    new->alt = cor[7];
    new->next = list_t->first;
    new->prev = list_t->last;
    list_t->last->next = new;
    new->prev = stock;
    stock->next = new;
    list_t->last = new;
    return new;
}

void inser_back(list *list_t, double *cor)
{
    element *new = malloc(sizeof(element));

    if (list_t->size == 0)
        list_t = init(cor, list_t);
    else {
        new = yes(list_t, cor);
        new->pop = cor[6];
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
