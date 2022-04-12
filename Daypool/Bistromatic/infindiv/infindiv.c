/*
** EPITECH PROJECT, 2020
** infindiv.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/calcinfostructure.h"

char *infinmult (char *nbr1, char *nbr2, char *base);
char *infinsub (char *nbr1, char *nbr2, char *base);
void initnbrspaces (struct calc_info *cv, char **nbr);
void initnbrsign (char **nbr, int *nbrispos, char *base);
void initnbrlen (char **nbr, int *nbrlen, char *base);
void initdivdefs (struct calc_info *cv, char *nb1, char *nb2);

void initdivvars (struct calc_info *cv, char **nbr1, char **nbr2, char *base)
{
    char *nb1;
    char *nb2;

    cv -> nbr1len = 1;
    cv -> nbr2len = 1;
    cv -> retain = 0;
    cv -> nbr1ispos = 1;
    cv -> nbr2ispos = 1;
    cv->base = base;
    cv->baselen = my_strlen(base);
    initnbrspaces(cv, nbr1);
    initnbrspaces(cv, nbr2);
    initnbrsign (nbr1, &(cv -> nbr1ispos), base);
    initnbrsign (nbr2, &(cv -> nbr2ispos), base);
    nb1 = *nbr1;
    nb2 = *nbr2;
    initnbrlen (&nb1, &(cv -> nbr1len), base);
    initnbrlen (&nb2, &(cv -> nbr2len), base);
    initdivdefs (cv, *nbr1, *nbr2);
}

char *divend (struct calc_info *cv, char *resultp)
{
    while (*(resultp + 1) == (cv->base)[0])
        resultp++;
    if (cv -> primaryp == -1)
        *resultp = '-';
    else
        resultp++;
    return (resultp);
}

void actual_division (struct calc_info *cv, char *primary,
                      char **mults, char *resp)
{
    char numerator[cv->nbr2len + 1];
    char *nump = numerator;
    char *nump2 = numerator;
    int it;
    int u;
    int i;

    numerator[cv->nbr2len] = '\0';
    my_strncpy(numerator, primary - cv->nbr2len, cv->nbr2len);
    for (i = 0; my_char_isnum(*(primary - 1), cv->base); i++) {
        for (it = 0; *(infinsub(nump, mults[it + 1], cv->base)) != '-'; it++);
        resp[i] = (cv->base)[it];
        nump2 = infinsub(nump, mults[it], cv->base);
        my_strcpy(nump, nump2);
        for (u = 0; nump[u] != '\0'; u++);
        nump[u] = *(primary);
        nump[u + 1] = '\0';
        (primary)++;
    }
    resp[i] = '\0';
}

void infin_division (struct calc_info *cv, char *resultp)
{
    int i;
    char *multiples[cv->baselen];
    char iteration[3];

    iteration[2] = '\0';
    for (i = 0; i < (cv->baselen) + 1; i++) {
        iteration[0] = (cv->base)[i / cv->baselen];
        iteration[1] = (cv->base)[i % cv->baselen];
        multiples[i] = infinmult(cv->secondary, iteration, cv->base);
    }
    actual_division(cv, cv->primary + cv->nbr2len, multiples, resultp);
}

char *infindiv (char *nbr1, char *nbr2, char *base)
{
    struct calc_info cv;
    initdivvars (&cv, &nbr1, &nbr2, base);
    char result[sizeof(char) * cv.primarynbrlen + 2];
    char *resultp = result;
    char *zero = malloc (sizeof(char) * 2);

    zero[0] = (cv.base)[0];
    zero[1] = '\0';
    result[0] = '\n';
    if (*nbr2 == (cv.base)[0])
        return (zero + 1);
    if (cv.primaryy == 2)
        return (zero);
    infin_division(&cv, resultp + 1);
    resultp = divend(&cv, resultp);
    char *returnstr = malloc(sizeof(char) * my_strlen(resultp) + 1);
    my_strcpy(returnstr, resultp);
    return (returnstr);
}
