/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** function
*/

void my_uchar_swap(unsigned char *a, unsigned char *b)
{
    unsigned char tmp = *a;

    *a = *b;
    *b = tmp;
}

void my_swap(int *a, int *b)
{
    int e = 0;

    e = *a;
    *a = *b;
    *b = e;
}
