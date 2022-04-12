/*
** EPITECH PROJECT, 2020
** else.c
** File description:
** function
*/

#include "../include/calcinfostructure.h"

void elseeelsee (struct calc_info *cv, char *nb1, char *nb2)
{
    cv -> primary = nb1;
    cv -> secondary = nb2;
    cv -> sign = cv -> nbr1ispos;
    for (int i = cv -> nbr1len - 1; i >= 0; i--) {
        for (cv->pos1 = 0; *(nb1 - i) != cv->base[cv->pos1]; cv->pos1++);
        for (cv->pos2 = 0; *(nb2 - i) != cv->base[cv->pos2]; cv->pos2++);
        if (cv->pos2 > cv->pos1) {
            cv -> primary = nb2;
            cv -> secondary = nb1;
            cv -> sign = cv -> nbr2ispos;
            break;
        }
        if (cv->pos1 > cv->pos2)
            break;
    }
}

void elsee (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len < cv -> nbr2len) {
        cv -> primary = nb2;
        cv -> secondary = nb1;
        cv -> sign = cv -> nbr2ispos;
    } else {
        elseeelsee(cv, nb1, nb2);
    }
    cv -> resultuse = &(cv -> nbr2len);
    cv -> abslen = cv -> nbr2len;
    cv -> resnot = cv -> nbr1len;
}

void subelseeelsee (struct calc_info *cv, char *nb1, char *nb2)
{
    cv -> primary = nb1;
    cv -> secondary = nb2;
    cv -> sign = cv -> nbr1ispos;
    for (int i = cv -> nbr1len - 1; i >= 0; i--) {
        for (cv->pos1 = 0; *(nb1 - i) != cv->base[cv->pos1]; cv->pos1++);
        for (cv->pos2 = 0; *(nb2 - i) != cv->base[cv->pos2]; cv->pos2++);
        if (cv->pos2 > cv->pos1) {
            cv -> primary = nb2;
            cv -> secondary = nb1;
            cv -> sign = -(cv -> nbr2ispos);
            break;
        }
        if (cv->pos1 > cv->pos2)
            break;
    }
}

void subelsee (struct calc_info *cv, char *nb1, char *nb2)
{
    if (cv -> nbr1len < cv -> nbr2len) {
        cv -> primary = nb2;
        cv -> secondary = nb1;
        cv -> sign = -(cv -> nbr2ispos);
    } else {
        subelseeelsee(cv, nb1, nb2);
    }
    cv -> resultuse = &(cv -> nbr2len);
    cv -> abslen = cv -> nbr2len;
    cv -> resnot = cv -> nbr1len;
}
