/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** fonction
*/

void my_swap(int *a,int *b)
{
    int e = 0;

    e = *a;
    *a = *b;
    *b = e;
}
