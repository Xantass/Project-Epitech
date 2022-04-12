/*
** EPITECH PROJECT, 2020
** pass_one.c
** File description:
** function
*/

#include <stdarg.h>
#include "my.h"

int check_int(char pref, int nb);
int check_unsigned(char pref, unsigned int nb);
int check_string(char pref, char *str);
int check_char(char pref, char c);

int pass_putstr(va_list list, char pref)
{
    char *str = va_arg(list, char *);
    int res = check_string(pref, str);

    if (res == 0) {
        my_putstr_p(str);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_putnbr(va_list list, char pref)
{
    long long int nb = va_arg(list, long long int);
    int res = check_int(pref, nb);

    if (res == 0) {
        my_putnbr_p(nb);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_putchar(va_list list, char pref)
{
    char c = va_arg(list, int);
    int res = check_char(pref, c);

    if (res == 0) {
        my_putchar_p(c);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_convert_base(va_list list, char pref)
{
    unsigned long long adresse = va_arg(list, unsigned long long);
    int res = check_unsigned(pref, adresse);

    if (res == 0) {
        convert_base_p(adresse);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_convert_octa(va_list list, char pref)
{
    long long int init = va_arg(list, long long int);
    int res = check_int(pref, init);

    if (res == 0) {
        convert_octa_p(init);
        return 0;
    }
    else {
        return 84;
    }
}
