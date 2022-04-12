/*
** EPITECH PROJECT, 2020
** pass_two.c
** File description:
** function
*/

#include <stdarg.h>
#include "my.h"

int check_unsigned(char pref, unsigned int nb);
int check_int(char pref, int nb);
int check_char(char pref, char c);
int check_string(char pref, char *str);

int pass_none_assigned(va_list list, char pref)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int res = check_unsigned(pref, nb);

    if (res == 0) {
        none_assigned_p(nb);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_convert_hexa(va_list list, char pref)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int res = check_unsigned(pref, nb);

    if (res == 0) {
        convert_hexa_p(nb);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_convert_hexaup(va_list list, char pref)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int res = check_unsigned(pref, nb);

    if (res == 0) {
        convert_hexaup_p(nb);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_none_printable(va_list list, char pref)
{
    char *str = va_arg(list, char *);
    int res = check_string(pref, str);

    if (res == 0) {
        none_printable(str);
        return 0;
    }
    else {
        return 84;
    }
}

int pass_convert_binaire(va_list list, char pref)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int res = check_unsigned(pref, nb);

    if (res == 0) {
        convert_binaire_p(nb);
        return 0;
    }
    else {
        return 84;
    }
}
