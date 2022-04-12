/*
** EPITECH PROJECT, 2020
** shape.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "my.h"
#include "list.h"

list *init(double *cor, list *list_t);
void inser_front(list *list_t, double *cor);
void inser_back(list *list_t, double *cor);
void sup_front(list *list_t);
int alea(void);

sfRectangleShape *spi(double *cor)
{
    sfRectangleShape *plane = sfRectangleShape_create();
    sfTexture *a = sfTexture_createFromFile("image/plane.png", NULL);
    sfVector2f position = {cor[1], cor[2]};
    int i = alea();
    sfVector2f size = {20 + i, 20 + i};

    sfRectangleShape_setTexture(plane, a, sfTrue);
    sfRectangleShape_setSize(plane, size);
    sfRectangleShape_setPosition(plane, position);
    sfRectangleShape_setOutlineThickness(plane, 1);
    sfRectangleShape_setOutlineColor(plane, sfGreen);
    return plane;
}

sfCircleShape *tow(double *cor)
{
    sfCircleShape *tower = sfCircleShape_create();
    sfVector2f position = {cor[1] - cor[3], cor[2] - cor[3]};

    sfCircleShape_setPosition(tower, position);
    sfCircleShape_setRadius(tower, cor[3]);
    sfCircleShape_setFillColor(tower, sfTransparent);
    sfCircleShape_setOutlineThickness(tower, 1);
    sfCircleShape_setOutlineColor(tower, sfRed);
    return tower;
}

sfSprite *tows(double *cor)
{
    sfSprite *towers = sfSprite_create();
    sfVector2f position = {cor[1], cor[2]};
    sfTexture *b = sfTexture_createFromFile("image/area.png", NULL);

    sfSprite_setPosition(towers, position);
    sfSprite_setTexture(towers, b, sfTrue);
    return towers;
}

list *create_circle(double **cor, int limit)
{
    list *list_t = malloc(sizeof(list));
    int i = 0;
    int j = 0;

    list_t->size = 0;
    for (; i < limit && cor[i][0] != 2; i++);
    for (; j < i; j++)
        inser_back(list_t, cor[j]);
    return list_t;
}

sfCircleShape **create_tower(double **cor, int limit, stock *f)
{
    sfCircleShape **tower;
    int i = 0;

    for (; i != limit && cor[i][0] != 2; i++);
    if (i == limit)
        return NULL;
    tower = malloc(sizeof(sfCircleShape *) * limit - i);
    f->towers = malloc(sizeof(sfSprite *) * limit - i);
    for (; i != limit; i++) {
        tower[f->j] = tow(cor[i]);
        f->towers[f->j] = tows(cor[i]);
        f->j++;
    }
    return tower;
}
