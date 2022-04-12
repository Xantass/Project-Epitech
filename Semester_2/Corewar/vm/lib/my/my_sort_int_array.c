/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** function
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

void my_swap(int *a, int *b);

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int *tab_one = tab;
    int *tab_two = tab;

    while (i != size - 1)
    {
        if (tab_one[i] > tab_two[i + 1]) {
            my_swap(&tab_one[i], &tab_two[i + 1]);
        }
        i = i + 1;
    }
    tab = tab_one;
}
