/*
** EPITECH PROJECT, 2020
** convert_base_bis.c
** File description:
** function
*/

#include <stdlib.h>
#include "my.h"

char *my_retnbr_base(int nbr, char const *base)
{
    int toprintlen = 1;
    int baselen = my_strlen(base);
    int tempnbr = nbr;
    int power = 0;
    int numtopass = nbr;
    int firstdigit = nbr;

    if (nbr == 0) {
        toprintlen++;
    } else if (baselen > 1) {
        while (tempnbr >= 1 || tempnbr <= -1) {
            toprintlen++;
            tempnbr /= baselen;
        }
    }
    if (nbr < 0)
        toprintlen++;
    char *toprintp = malloc(toprintlen);
    if (baselen <= 1)
        return 0;
    if (nbr < 0) {
        while (firstdigit <= -baselen) {
            firstdigit /= baselen;
            power++;
        }
        numtopass = numtopass % my_compute_power_rec(baselen, power);
        *toprintp = '-';
        *(toprintp + 1) = *(base - firstdigit);
        if (nbr <= -baselen)
            recur(-numtopass, base, baselen, toprintp + 2, power - 1);
    }
    if (nbr > 0) {
        while (firstdigit >= baselen) {
            firstdigit /= baselen;
            power++;
        }
        numtopass = numtopass % my_compute_power_rec(baselen, power);
        *toprintp = *(base + firstdigit);
        if (nbr >= baselen)
            recur(numtopass, base, baselen, toprintp + 1, power - 1);
    }
    if (nbr == 0)
        *toprintp = *base;
    *(toprintp + toprintlen - 1) = '\0';
    return toprintp;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    return my_retnbr_base(my_getnbr_base(nbr, base_from), base_to);
}
