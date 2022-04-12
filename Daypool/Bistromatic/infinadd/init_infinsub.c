/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/calcinfostructure.h"

void subelsee(struct calc_info *cv, char *nb1, char *nb2);

void initsubdefs (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len > cv -> nbr2len) {
        cv -> primary = nb1;
        cv -> secondary = nb2;
        cv -> sign = cv -> nbr1ispos;
        cv -> resultuse = &(cv -> nbr1len);
        cv -> abslen = cv -> nbr1len;
        cv -> resnot = (cv -> nbr2len);
    } else {
        subelsee(cv, nb1, nb2);
        cv -> resultuse = &(cv -> nbr2len);
        cv -> abslen = cv -> nbr2len;
        cv -> resnot = (cv -> nbr1len);
    }
}
