/*
** EPITECH PROJECT, 2020
** print.h
** File description:
** function
*/

#ifndef PRINT_H
#define PRINT_H

void print_translation(char **argv, int *i);
void print_scaling(char **argv, int *i);
void print_rotation(char **argv, int *i);
void print_reflection(char **argv, int *i);

struct print {
    char c;
    void(*func)(char **argv, int *i);
};

struct print p[4] =
{
    {'t', print_translation},
    {'z', print_scaling},
    {'r', print_rotation},
    {'s', print_reflection},
};
#endif
