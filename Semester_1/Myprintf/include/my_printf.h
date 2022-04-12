/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** struct
*/

#include "pass.h"

struct arg {
    char c;
    int (*func)(va_list list, char pref);
};

struct arg op[12] =
{
    {'s', pass_putstr},
    {'i', pass_putnbr},
    {'c', pass_putchar},
    {'p', pass_convert_base},
    {'d', pass_putnbr},
    {'o', pass_convert_octa},
    {'u', pass_none_assigned},
    {'x', pass_convert_hexa},
    {'X', pass_convert_hexaup},
    {'S', pass_none_printable},
    {'b', pass_convert_binaire},
    {'%', pass_pourcen},
};

extern void *func;

struct size {
    char c;
};

struct size pre[8] =
{
    {'h'},
    {'j'},
    {'l'},
    {'L'},
    {'t'},
    {'I'},
    {'z'},
    {'w'},
};
