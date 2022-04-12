/*
** EPITECH PROJECT, 2020
** infinmodbis.c
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

void initmodvars(struct calc_info *cv, char **nbr1, char **nbr2, char *base)
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
