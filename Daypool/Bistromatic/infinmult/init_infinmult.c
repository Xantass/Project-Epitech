/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/calcinfostructure.h"

void initnbrspaces (struct calc_info *cv, char **nbr);
void initnbrsign (char **nbr, int *nbrispos, char *base);
void initnbrlen (char **nbr, int *nbrlen, char *base);

char *return_multend_if (struct calc_info *cv, char *returnstr)
{
    if (*(returnstr + 1) != (cv->base)[0]) {
        *returnstr = '-';
    } else {
        returnstr++;
        if (*(returnstr + 1) != (cv->base)[0])
            *returnstr = '-';
        else
            returnstr++;
    }
    return (returnstr);
}

void initmultdefs (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len > cv -> nbr2len) {
        cv -> primary = nb1;
        cv -> secondary = nb2;
        cv -> abslen = cv -> nbr1len;
        cv -> resnot = cv -> nbr2len;
    } else {
        cv -> primary = nb2;
        cv -> secondary = nb1;
        cv -> abslen = cv -> nbr2len;
        cv -> resnot = cv -> nbr1len;
    }
    if (cv -> nbr1ispos != cv -> nbr2ispos)
        cv -> primaryp = -1;
    else
        cv -> primaryp = 1;
}

void initmultvars(struct calc_info *cv, char **nbr1, char **nbr2, char *base)
{
    cv -> nbr1len = 1;
    cv -> nbr2len = 1;
    cv -> retain = 0;
    cv -> nbr1ispos = 1;
    cv -> nbr2ispos = 1;
    cv -> nbriszero = 0;
    cv->base = base;
    cv->baselen = my_strlen(base);
    initnbrspaces(cv, nbr1);
    initnbrspaces(cv, nbr2);
    initnbrsign (nbr1, &(cv -> nbr1ispos), base);
    initnbrsign (nbr2, &(cv -> nbr2ispos), base);
    if (**nbr1 == (cv->base)[0] || **nbr2 == (cv->base)[0])
        cv->nbriszero = 1;
    initnbrlen (nbr1, &(cv -> nbr1len), base);
    initnbrlen (nbr2, &(cv -> nbr2len), base);
    initmultdefs (cv, *nbr1, *nbr2);
}
