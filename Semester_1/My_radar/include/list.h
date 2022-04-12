/*
** EPITECH PROJECT, 2020
** list.h
** File description:
** function
*/

#ifndef LIST_H
#define LIST_H

#include "graph.h"

typedef struct element element;
struct element {
    sfRectangleShape *plane;
    sfVector2f start;
    sfVector2f finish;
    double speed;
    int pop;
    int alt;
    element *prev;
    element *next;
};

typedef struct list list;
struct list {
    int size;
    element *first;
    element *last;
};

typedef struct stock stock;
struct stock {
    sfRenderWindow *window;
    sfEvent event;
    sfKeyEvent key;
    sfTexture *b;
    sfSprite *back;
    sfVector2f position;
    sfVector2f pos;
    int j;
    sfCircleShape **tower;
    sfSprite **towers;
    int radius;
    int s;
    int l;
    sfClock *clock;
    sfTime time;
    int times;
    sfText *text;
    sfFont *font;
};
#endif
