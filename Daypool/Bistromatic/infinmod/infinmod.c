/*
** EPITECH PROJECT, 2020
** infinmod.c
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
void initmodvars(struct calc_info *cv, char **nbr1, char **nbr2, char *base);

char *modend (struct calc_info *cv, char *resultp)
{
    while (*(resultp + 1) == (cv->base)[0])
        resultp++;
    if (!(my_char_isnum(*(resultp + 1), cv->base))) {
        *(resultp + 1) = '\0';
        resultp--;
    }
    if (cv->primaryp == -1)
        *resultp = '-';
    else
        resultp++;
    return (resultp);
}

void teeeeeest(char character, char *base, char *nump)
{
    if (my_char_isnum(character, base))
        *nump = character;
    else
        *nump = '\0';
}

char *actual_modulo (struct calc_info *cv,
                     char *primary, int n2len, char **multiples)
{
    char *num = malloc(n2len + 1);
    char *nump = num;
    char *nump2 = num;
    int it;
    int u;
    int i;

    num[n2len] = '\0';
    my_strncpy(num, primary - n2len, n2len);
    for (i = 0; my_char_isnum(*(primary - 1), cv->base); i++) {
        for (it = 0;*(infinsub(nump, multiples[it + 1], cv->base)) != '-';it++);
        nump2 = infinsub(nump, multiples[it], cv->base);
        my_strcpy(nump, nump2);
        for (u = 0; nump[u] != '\0'; u++);
        teeeeeest(*primary, cv->base, &(nump[u]));
        nump[u + 1] = '\0';
        primary++;
    }
    return (nump);
}

char *infin_modulo (struct calc_info *cv, char *second, int nbr2len)
{
    int i;
    char *multiples[cv->baselen];
    char iteration[3];

    iteration[2] = '\0';
    for (i = 0; i < cv->baselen + 1; i++) {
        iteration[0] = (cv->base)[i / cv->baselen];
        iteration[1] = (cv->base)[i % cv->baselen];
        multiples[i] = infinmult(second, iteration, cv->base);
    }
    return (actual_modulo(cv, cv->primary + nbr2len, nbr2len, multiples));
}

char *infinmod (char *nbr1, char *nbr2, char *base)
{
    struct calc_info cv;
    char *result;
    char *zero = malloc (sizeof(char) * 2);
    char *returnstr;

    initmodvars (&cv, &nbr1, &nbr2, base);
    zero[0] = (cv.base)[0];
    zero[1] = '\0';
    if (*nbr2 == (cv.base)[0])
        return (zero + 1);
    if (cv.primaryy == 2) {
        returnstr = malloc(sizeof(char) * my_strlen(nbr1) + 2);
        my_strcpy(returnstr + 1, nbr1);
        return (modend(&cv, returnstr));
    }
    result = infin_modulo(&cv, cv.secondary, cv.nbr2len);
    returnstr = malloc(sizeof(char) * my_strlen(result) + 2);
    my_strcpy(returnstr + 1, result);
    return (modend(&cv, returnstr));
}
