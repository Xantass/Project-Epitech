/*
** EPITECH PROJECT, 2020
** list.h
** File description:
** function
*/

#ifndef LIST_H
#define LIST_H

typedef struct element_t element_t;
struct element_t {
    int nb;
    char c;
    int x;
    int y;
    element_t *prev;
    element_t *next;
};

typedef struct list_t list_t;
struct list_t {
    int size;
    int score;
    element_t *first;
    element_t *last;
};
#endif
