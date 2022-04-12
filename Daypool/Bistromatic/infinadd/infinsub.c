/*
** EPITECH PROJECT, 2020
** infinsub.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_macro_abs.h"
#include "../include/calcinfostructure.h"

void initnbrspaces (struct calc_info *cv, char **nbr);
void initnbrsign (char **nbr, int *nbrispos, char *base);
void initnbrlen (char **nbr, int *nbrlen, char *base);
void initsubdefs (struct calc_info *cv, char *nb1, char *nb2);
void infin_add (struct calc_info *cv, char *sec, char *secp, char *resultp);
void infin_sub (struct calc_info *cv, char *sec, char *secp, char *resultp);
char *end (struct calc_info *cv, char *resultp);

void initsubvars(struct calc_info *cv, char **nbr1, char **nbr2, char *base)
{
    cv->w = 0;
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
    initnbrlen (nbr1, &(cv -> nbr1len), base);
    initnbrlen (nbr2, &(cv -> nbr2len), base);
    initsubdefs (cv, *nbr1, *nbr2);
}

char *subend (struct calc_info *cv, char *resultp)
{
    if (cv -> retain == 0) {
        resultp += 2;
        while (*resultp == (cv->base)[0])
            resultp++;
        if (*resultp == '\0')
            resultp--;
        if (cv -> sign == -1) {
            if (*resultp != (cv->base)[0]) {
                resultp--;
                *resultp = '-';
            }
        }
    } else {
        *(resultp + 1) = (cv->base)[1];
        if (cv -> sign == -1)
            *resultp = '-';
        else
            resultp++;
    }
    return resultp;
}

char *infinsub (char *nbr1, char *nbr2, char *base)
{
    struct calc_info cv;
    initsubvars (&cv, &nbr1, &nbr2, base);
    int abssss = cv.abslen;
    char result[sizeof(char) * *(cv.resultuse) + 2];
    char *resultp = result;
    char secondaryn[cv.abslen];
    char *secondarynp = secondaryn + cv.abslen - 1;

    result[0] = '\n';
    if (cv.nbr1ispos == cv.nbr2ispos)
        infin_sub(&cv, secondaryn, secondarynp, resultp + 1);
    else
        infin_add(&cv, secondaryn, secondarynp, resultp + 1);
    *(resultp + abssss + 2) = '\0';
    resultp = end(&cv, resultp);
    char *returnstr = malloc(sizeof(char) * my_strlen(resultp) + 1);
    my_strcpy(returnstr, resultp);
    *(returnstr + my_strlen(resultp)) = '\0';
    return (returnstr);
}
