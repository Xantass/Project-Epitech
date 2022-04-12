/*
** EPITECH PROJECT, 2020
** algo.c
** File description:
** function
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"
#include "list.h"
#include "proto.h"

void rra(list *list_t)
{
    my_putstr(" rra");
    list_t->first = list_t->first->prev;
    list_t->last = list_t->last->prev;
}

void pbs(list *list_one , list *list_two)
{
    my_putstr("pb");
    inser_front(list_two, list_one->first->nb);
    sup_front(list_one);
}

void bit_one(list *list_one, list *list_two, info *info_t, int most)
{
    if (most == info_t->print && info_t->j == 0)
        pbs(list_one, list_two);
    else
        pb(list_one, list_two);
}

int get_bit(int val, int pos)
{
    int mask = 0b00000001;

    mask = mask << pos;
    return (val & mask);
}

int check(int n, int most)
{
    if (n < 0)
        n *= -1;
    if (n > most)
        most = n;
    return most;
}
