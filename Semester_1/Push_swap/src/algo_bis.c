/*
** EPITECH PROJECT, 2020
** algo_bis.c
** File description:
** function
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"
#include "list.h"
#include "proto.h"

void bit(list *list_one, list *list_two, info *info_t, int most)
{
    for (int j = 0; j < info_t->size; j++) {
        if (get_bit(list_one->first->nb, info_t->bit_count)) {
            info_t->j = j;
            bit_two(list_one, info_t, most);
        }
        else {
            info_t->j = j;
            bit_one(list_one, list_two, info_t, most);
        }
    }
    info_t->bit_count++;
}

void radix(list *list_one, list *list_two, int most, info info_t)
{
    const int most_bis = most;

    info_t.size = list_one->size;
    for (; 0 < most; most--) {
        info_t.print = most;
        bit(list_one, list_two, &info_t, most_bis);
        while (list_two->size > 0)
            pa(list_one, list_two);
    }
    neg(list_one, list_two);
    my_putchar('\n');
}

int get_most(int most)
{
    int result = 0;

    while (most != 0) {
        most = most / 2;
        result = result + 1;
    }
    return result;
}

list *lists(char **argv)
{
    info info_t = {0};
    list *list_one = malloc(sizeof(list));
    list *list_two = malloc(sizeof(list));
    int most = 0;
    int count = 0;

    list_one->size = 0;
    list_two->size = 0;
    for (int u = 1; argv[u] != NULL; u++) {
        if (argv[u + 1] != NULL && my_getnbr(argv[u]) > my_getnbr(argv[u + 1]))
            count++;
        most = check(my_getnbr(argv[u]), most);
        inser_back(list_one, my_getnbr(argv[u]));
    }
    if (count != 0) {
        most = get_most(most);
        radix(list_one, list_two, most, info_t);
        return list_one;
    }
    my_putstr("\n");
    return NULL;
}
