/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get
*/

#include "struct.h"
#include "get.h"
#include "lib.h"

char get_type(char const *str, int code)
{
    int ret;

    if ((ret = is_instruction(str)) != 84)
        return 1;
    if (str[0] == 'r' && is_number(str + 1) == 0)
        return 1;
    if ((str[0] == DIRECT_CHAR && is_number(str + 1) == 0)
        || (str[0] == DIRECT_CHAR && is_label(str + 1, 1) == 0))
        return direct_size[code - 1];
    if (is_number(str) != -1 || is_label(str, 1) == 0)
        return 2;
    return 84;
}

int my_getnbr_base(char const *str, char const *base)
{
    int i = 0;
    int result = 0;
    int negativ = 1;

    if (str[0] == '\0')
        return (0);
    for (; str[i] < '0' || str[i] > '9'; i++) {
        if (str[i] == '-')
            negativ = -negativ;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        result *= my_strlen(base);
        result = result + (str[i] - '0');
    }
    return (result * negativ);
}

int get_nbr(char *str)
{
    int ret = 0;
    int neg = 1;
    int i = 0;

    if (str[0] == '-') {
        neg *= -1;
        i = 1;
    }
    for (; str[i]; i++) {
        ret *= 10;
        ret += str[i] - 48;
    }
    return ret * neg;
}

int get_value(char *str)
{
    if (str[0] == 'r')
        return get_nbr(str + 1);
    if (str[0] == DIRECT_CHAR && is_number(str + 1) == 0)
        return get_nbr(str + 1);
    if (is_number(str) == 0)
        return get_nbr(str);
    return 0;
}