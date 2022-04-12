/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** function
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/calcinfostructure.h"

void elsee(struct calc_info *cv, char *nb1, char *nb2);

void initnbrspaces (struct calc_info *cv, char **nbr)
{
    char *nothing = malloc(sizeof(char) * 2);

    *nothing = (cv->base)[0];
    *(nothing + 1) = '\0';
    while (**nbr == ' ')
        (*nbr)++;
    if (**nbr == '\0')
        *nbr = nothing;
}

void initnbrsign (char **nbr, int *nbrispos, char *base)
{
    for (; **nbr == '-' || **nbr == '+' || **nbr == ' '; (*nbr)++)
        if (**nbr == '-')
            *nbrispos = -(*nbrispos);
    while (**nbr == base[0])
        (*nbr)++;
    if (!my_char_isnum(**nbr, base))
        (*nbr)--;
}

void initnbrlen (char **nbr, int *nbrlen, char *base)
{
    while (my_char_isnum((*(*nbr + 1)), base)) {
        (*nbr)++;
        (*nbrlen)++;
    }
}

void initdefs (struct calc_info *cv, char *nb1, char *nb2)
{
    cv->w = 0;
    if (cv -> nbr1len > cv -> nbr2len) {
        cv -> primary = nb1;
        cv -> secondary = nb2;
        cv -> sign = cv -> nbr1ispos;
        cv -> resultuse = &(cv -> nbr1len);
        cv -> abslen = cv -> nbr1len;
        cv -> resnot = (cv -> nbr2len);
    } else {
        elsee(cv, nb1, nb2);
        cv -> resultuse = &(cv -> nbr2len);
        cv -> abslen = cv -> nbr2len;
        cv -> resnot = (cv -> nbr1len);
    }
}
