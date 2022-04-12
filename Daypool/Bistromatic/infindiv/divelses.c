/*
** EPITECH PROJECT, 2020
** divelse.c
** File description:
** function
*/

#include "../include/calcinfostructure.h"

void divelseeelsee (struct calc_info *cv, char *nb1, char *nb2)
{
    cv -> primary = nb1;
    cv -> secondary = nb2;
    cv -> absolutelen = cv -> nbr1len;
    cv -> primaryy = 1;
    for (int i = 0; i < cv -> nbr1len; i++) {
        for (cv->pos1 = 0; *(nb1 - i) != cv->base[cv->pos1]; cv->pos1++);
        for (cv->pos2 = 0; *(nb2 - i) != cv->base[cv->pos2]; cv->pos2++);
        if (cv->pos2 > cv->pos1) {
            cv -> primary = nb2;
            cv -> secondary = nb1;
            cv -> absolutelen = cv -> nbr2len;
            cv -> primaryy = 2;
            break;
        }
        if (cv->pos1 > cv->pos2)
            break;
    }
}

void divelsee (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len < cv -> nbr2len) {
        cv -> primary = nb2;
        cv -> primaryy = 2;
        cv -> secondary = nb1;
        cv -> absolutelen = cv -> nbr2len;
    } else {
        divelseeelsee(cv, nb1, nb2);
    }
    cv -> primarynbrlen = cv -> nbr2len;
    cv -> absolutelen = cv -> nbr2len;
    cv -> secondarynbrlen = cv -> nbr1len;
    cv -> whichnbr = 1;
}
