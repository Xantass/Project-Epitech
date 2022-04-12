/*
** EPITECH PROJECT, 2020
** list.h
** File description:
** function
*/

#ifndef LIST_H
#define LIST_H

typedef struct element element;
struct element {
    int nb;
    element *prev;
    element *next;
};

typedef struct list list;
struct list {
    int size;
    element *first;
    element *last;
};

typedef struct info info;
struct info {
    int j;
    int size;
    int print;
    int bit_count;
};
#endif
