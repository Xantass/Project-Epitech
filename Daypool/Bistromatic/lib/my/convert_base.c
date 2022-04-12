/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** abbbbmgfeiobbb
*/

#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *my_retnbr_base(int nbr, char const *base);

int my_charstr(char const nbr, char const *base)
{
    int i = 0;
    for (; nbr != *(base + i); i++);
    return i;
}

int recurplus(char *nbr, char const *base, int baselen)
{
    int i = 0;
    int num = my_charstr(*nbr, base);
    while (num >= 0) {
        if (*(nbr + 1) != '\0')
            i += recurplus(nbr + 1, base, baselen);
        if (num == 0) {
            *nbr = *(base + baselen - 1);
            break;
        } else {
            num--;
            i++;
        }
    }
    return i;
}

int recurminus(char *nbr, char const *base, int baselen)
{
    int i = 0;
    int num = my_charstr(*nbr, base);
    while (num >= 0) {
        if (*(nbr + 1) != '\0')
            i += recurminus(nbr + 1, base, baselen);
        if (num == 0) {
            *nbr = *(base + baselen - 1);
            break;
        } else {
            num--;
            i--;
        }
    }
    return i;
}

int my_getnbr_base(char const *nbr, char const *base)
{
    char nbr2[my_strlen(nbr) + 1];
    char *nbr22 = nbr2;
    int baselen = my_strlen(base);
    int i = 0;

    for (; my_char_isnum(*(nbr + i), base) == 1; i++)
        *(nbr22 + i) = *(nbr + i);
    *(nbr22 + i) = '\0';
    if (*nbr == 45) {
        return (recurminus(nbr22 + 1, base, baselen));
    } else {
        return (recurplus(nbr22, base, baselen));
    }
}

void recur(int nbr, char const *base, int baselen, char *toprintp, int power)
{
    int firstdigit = nbr / my_compute_power_rec(baselen, power);
    int numtopass = nbr % my_compute_power_rec(baselen, power);

    if (power > 0)
        recur(numtopass, base, baselen, toprintp + 1, power - 1);
    *toprintp = *(base + firstdigit);
}
