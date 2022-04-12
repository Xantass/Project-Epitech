/*
** EPITECH PROJECT, 2020
** boostrap.c
** File description:
** function
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "my.h"
#include "../../include/my_printf.h"

void run_function(char const *format, int *index, va_list list)
{
    int i = 0;
    int h = 0;
    char pref;

    while (h < 8) {
        if (format[(*index)] == pre[h].c) {
            pref = format[(*index)];
            (*index)++;
            break;
        }
        h++;
    }
    while (i < 12) {
        if (format[(*index)] ==  op[i].c)
            op[i].func(list, pref);
        i++;
    }
}

void my_printf(char const *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            run_function(format, &i, list);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
}
