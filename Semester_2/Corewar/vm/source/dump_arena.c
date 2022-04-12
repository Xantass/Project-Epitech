/*
** EPITECH PROJECT, 2021
** dump_arena.c
** File description:
** functions
*/

#include <stdlib.h>
#include "info.h"
#include "lib.h"
#include "op.h"

static int hex_length(int nbr)
{
    unsigned int size = 16;
    unsigned int i = nbr / size;
    unsigned int j = 0;

    for (; i > 0; j++, i = i / size);
    return (j + 1);
}

int convert_hexa_p(int init)
{
    char *base = "0123456789ABCDEF";
    char res[100];
    int i = 0;
    int nb = 0;

    while ((init / 16) > 0) {
        res[i] = (base[init % 16]);
        init = init / 16;
        i++;
    }
    res[i] = (base[init % 16]);
    res[i + 1] = '\0';
    nb = my_strlen(res);
    if (nb == 1) {
        my_putchar('0');
        my_putchar(res[0]);
        return 0;
    }
    for (; i >= 0; i--)
        my_putchar(res[i]);
    return 0;
}

static void print_hex(int nbr)
{
    char *base = "0123456789ABCDEF";
    int a = nbr / my_strlen(base);
    int b = 0;

    for (; a > 0; b++, a = a / my_strlen(base));
    if (nbr == 0) {
        my_putchar('0');
        return;
    }
    if (b == 0)
        my_putchar('0');
    convert_hexa_p(nbr);
}

void dump_arena(info_t *info)
{
    for (unsigned int i = 0; i < MEM_SIZE; i++) {
        if ((i % 32) == 0) {
            print_hex(i);
            for (int a = 0; a != 5 - hex_length(i); my_putstr(" "), a++);
            my_putstr(":");
        }
        my_putchar(' ');
        convert_hexa_p(info->arena[i]);
        if ((i + 1) % 32 == 0)
            my_putstr("\n");
    }
    throw_error(0, "");
}
