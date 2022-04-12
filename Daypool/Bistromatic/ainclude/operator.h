/*
** EPITECH PROJECT, 2020
** operator.h
** File description:
** header
*/

typedef char *(*Function) (char *nbr1, char *nbr2, char *base);

struct operator {
    char *character;
    Function func;
};
