/*
** EPITECH PROJECT, 2020
** infinmult.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/calcinfostructure.h"

char *infinadd (char *nbr1, char *nbr2, char *base);
void initnbrspaces (char **nbr);
void initnbrsign (char **nbr, int *nbrispos, int *nbriszero);
void initnbrlen (char **nbr, int *nbrlen);
void initmultdefs (struct calc_info *cv, char *nb1, char *nb2);
void initmultvars (struct calc_info *cv, char **nbr1, char **nbr2, char *base);
char *return_multend_if (struct calc_info *cv, char *returnstr);

char *multend (struct calc_info *cv, char *returnstr)
{
    if (cv -> primaryp == -1) {
        return (return_multend_if (cv, returnstr));
    }
    else {
        returnstr++;
        if (*returnstr == (cv->base)[0])
            returnstr++;
        return (returnstr);
    }
}

void actuuu(struct calc_info *cv, char ***resarr, int i)
{
    while (cv -> abslen > 0) {
        for (cv->pos1 = 0; *(cv->primary)   != cv->base[cv->pos1]; cv->pos1++);
        for (cv->pos2 = 0; *(cv->secondary) != cv->base[cv->pos2]; cv->pos2++);
        *((*resarr)[i] + cv->abslen + 1) =
            (cv->base)[(cv->pos1 * cv->pos2 + cv->retain) % cv->baselen];
        cv->retain =
            (cv->pos1 * cv->pos2 + cv->retain) / cv->baselen;
        cv -> primary--;
        cv -> abslen--;
    }
}

char **actual_multiplication(struct calc_info *cv, char **resarr)
{
    int absolute = cv -> abslen;
    char *primary = cv -> primary;

    for (int i = 0; i < cv -> resnot; i++) {
        cv -> abslen = absolute;
        cv -> primary = primary;
        cv -> retain = 0;
        resarr[i] = malloc(sizeof(char) * (absolute + 3) + i);
        *(resarr[i] + absolute + 2 + i) = '\0';
        for (int u = i; u > 0; u--)
            *(resarr[i] + absolute + 1 + u) = (cv->base)[0];
        actuuu(cv, &resarr, i);
        *(resarr[i] + 1) = (cv->base)[cv -> retain];
        cv -> secondary--;
    }
    return (resarr);
}

char *infin_multiplication (struct calc_info *cv, char *resultp)
{
    char *resultsarray[cv -> resnot];
    char **resarr;

    resarr = actual_multiplication(cv, resultsarray);
    resultp = resarr[0] + 1;
    for (int i = 1; i < cv->resnot; i++) {
        resultp = infinadd(resultp, resarr[i] + 1, cv->base);
        free(resarr[i]);
    }
    return resultp;
}

char *infinmult (char *nbr1, char *nbr2, char *base)
{
    struct calc_info cv;
    char *zero = malloc(sizeof(char) * 2);
    zero[0] = base[0];
    zero[1] = '\0';
    initmultvars (&cv, &nbr1, &nbr2, base);
    int totallen = cv.abslen + cv.resnot;

    char result[sizeof(char) * totallen + 2];
    char *resultp = result;

    result[0] = '\n';
    if (cv.nbriszero == 1) {
        return (zero);
    }
    free (zero);
    resultp = infin_multiplication(&cv, resultp + 1);
    char *returnstr = malloc(sizeof(char) * my_strlen(resultp + 1) + 2);
    my_strcpy(returnstr + 1, resultp);
    *(returnstr + my_strlen(resultp) + 1) = '\0';
    return multend(&cv, returnstr);
}
