/*
** EPITECH PROJECT, 2020
** calc.c
** File description:
** function
*/

#include "my.h"
#include "list.h"
#include "proto.h"

void ra(list *list_t)
{
    my_putstr(" ra");
    list_t->first = list_t->first->next;
    list_t->last = list_t->last->next;
}

void pa(list *a, list *b)
{
    my_putstr(" pa");
    inser_front(a, b->first->nb);
    sup_front(b);
}

void pb(list *a, list *b)
{
    my_putstr(" pb");
    inser_front(b, a->first->nb);
    sup_front(a);
}

void rrb(list *list_t)
{
    my_putstr(" rrb");
    list_t->first = list_t->first->prev;
    list_t->last = list_t->last->prev;
}

void neg(list *list_one, list *list_two)
{
    while (list_one->last->nb < 0) {
        rra(list_one);
        pb(list_one, list_two);
    }
    while (list_two->size > 0) {
        rrb(list_two);
        pa(list_one, list_two);
    }
}
