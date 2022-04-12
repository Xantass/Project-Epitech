/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** function
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct info_t info_t;
struct info_t {
    int nb_O;
    int nb_X;
    int col;
    int line;
    list_t *list;
    char **str;
};
#endif
