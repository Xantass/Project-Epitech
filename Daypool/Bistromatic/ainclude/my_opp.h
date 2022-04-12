/*
** EPITECH PROJECT, 2020
** my_opp.h
** File description:
** function
*/

#ifndef OP_FNS_H_
#define OP_FNS_H_
char *infinadd (char *nbr1, char *nbr2, char *base);
char *infinsub (char *nbr1, char *nbr2, char *base);
char *infinmult (char *nbr1, char *nbr2, char *base);
char *infindiv (char *nbr1, char *nbr2, char *base);
char *infinmod (char *nbr1, char *nbr2, char *base);
char *my_usage(char *nbr1, char *nbr2, char *base);

const struct operator OP_FNS[] = {{"+", &infinadd},
    {"-", &infinsub},
    {"*", &infinmult},
    {"/", &infindiv},
    {"%", &infinmod},
    {"", &my_usage}};
#endif
