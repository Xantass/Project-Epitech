/*
** EPITECH PROJECT, 2020
** 
** File description:
** my_print_revalpha.c
*/

int my_print_revalpha(void)
{
    int l;

    l = 122;
    while (l >= 97)
    {
        my_putchar(l);
        l = l -1;
    }
}

