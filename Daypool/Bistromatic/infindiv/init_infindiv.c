/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** function
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/calcinfostructure.h"

void divelsee (struct calc_info *cv, char *nb1, char *nb2);

void initdivdefs (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len > cv -> nbr2len) {
        cv -> primary = nb1;
        cv -> secondary = nb2;
        cv -> primarynbrlen = cv -> nbr1len;
        cv -> absolutelen = cv -> nbr1len;
        cv -> secondarynbrlen = cv -> nbr2len;
        cv -> primaryy = 1;
        cv -> whichnbr = 0;
    } else {
        divelsee(cv, nb1, nb2);
    }
    if (cv -> nbr1ispos != cv -> nbr2ispos)
        cv -> primaryp = -1;
    else
        cv -> primaryp = 1;
}
