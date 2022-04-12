/*
** EPITECH PROJECT, 2020
** pass_three.c
** File description:
** function
*/

#include <stdarg.h>
#include "my.h"

int my_strlen(char *str);

int check_unsigned(char pref, unsigned long long nb)
{
    unsigned long long limit = 1844674407370955161;
    unsigned long long limits = 4294967295;

    if (pref == 'h' || pref == 'z') {
        if (nb <= 65535 && nb > 0)
            return 0;
        return 84;
    }
    if (pref == 'l') {
        if (nb > 0 && nb <= limits) {
            return 0;
        }
        return 84;
    }
    if (pref == 'j') {
        if (nb > 0 && nb <= limit)
            return 0;
        return 84;
    }
    return 0;
}

int check_int(char pref, long long int nb)
{
    long long int limit_ = -9223372036854775807;
    long long int limit = 9223372036854775807;
    long int limits_ = -2147483648;
    long int limits = 2147483647;

    if (pref == 'h' || pref == 'z') {
        if (nb >= -32768 && nb <= 32767)
            return 0;
        return 84;
    }
    if (pref == 'l') {
        if (nb >= limits_ && nb <= limits)
            return 0;
        return 84;
    }
    if (pref == 'j') {
        if (nb >= limit_ && nb <= limit)
            return 0;
        return 84;
    }
    return 0;
}

int check_char(char pref, char c)
{
    if (pref == 'l') {
        if (c > -128 && c < 127)
            return 0;
        return 84;
    }
    return 0;
}

int check_string(char pref, char *str)
{
    if (pref == 'l') {
        if (my_strlen(str) >= -32768 && my_strlen(str) <= 32767)
            return 0;
        return 84;
    }
    return 0;
}

int pass_pourcen(va_list list, char pref)
{
    char c = va_arg(list, int);
    int res = check_char(pref, c);

    if (res == 0) {
        pourcen(c);
        return 0;
    }
    else {
        return 84;
    }
}
