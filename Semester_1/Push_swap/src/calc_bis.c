/*
** EPITECH PROJECT, 2020
** calc_bis.c
** File description:
** function
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"
#include "list.h"
#include "proto.h"

void bit_two(list *list_t, info *info_t, int most)
{
    if (most == info_t->print && info_t->j == 0)
        ras(list_t);
    else
        ra(list_t);
}

void ras(list *list_t)
{
    my_putstr("ra");
    list_t->first = list_t->first->next;
    list_t->last = list_t->last->next;
}
