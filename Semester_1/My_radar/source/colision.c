/*
** EPITECH PROJECT, 2021
** colision.c
** File description:
** function
*/

#include <math.h>
#include "graph.h"
#include "my.h"
#include "list.h"

void sup_front(list *list_t);

void destroy(list *list_t, int lim)
{
    for (int i = 0; i != lim; i++) {
        list_t->first = list_t->first->next;
        list_t->last = list_t->last->next;
    }
    sfRectangleShape_destroy(list_t->first->plane);
    sup_front(list_t);
}

int check(element *one, list *list_t)
{
    sfVector2f p_one = sfRectangleShape_getPosition(one->plane);
    sfVector2f p_two;
    element *f = list_t->first->next;
    sfVector2f s_one = sfRectangleShape_getSize(one->plane);
    sfVector2f s_two;

    for (int j = 1; j < list_t->size; j++) {
        p_two = sfRectangleShape_getPosition(f->plane);
        s_two = sfRectangleShape_getSize(f->plane);
        if (round(p_one.x) < round(p_two.x) + s_two.x &&
            round(p_one.x) + s_one.x > round(p_two.x) &&
            round(p_one.y) < round(p_two.y) + s_two.y &&
            round(p_one.y) + s_one.y > round(p_two.y)) {
            return j;
        }
        f = f->next;
    }
    return 0;
}

int area(element *one, stock f)
{
    float radius;
    sfVector2f dis;
    sfVector2f pos = sfRectangleShape_getPosition(one->plane);
    sfVector2f posit;

    for (int i = 0; i < f.j; i++) {
        posit = sfSprite_getPosition(f.towers[i]);
        radius = sfCircleShape_getRadius(f.tower[i]);
        dis.x = posit.x - pos.x;
        dis.y = posit.y - pos.y;
        if (dis.x < 0)
            dis.x *= (-1);
        if (dis.y < 0)
            dis.y *= (-1);
        if (dis.x < radius && dis.y < radius)
            return 0;
    }
    return 1;
}

void coli(list *list_t, stock f)
{
    int lim = 0;
    int res = 0;

    for (int i = 0; i < list_t->size; i++) {
        if ((res = area(list_t->first, f)) == 1 &&
            (lim = check(list_t->first, list_t)) != 0) {
            sfRectangleShape_destroy(list_t->first->plane);
            sup_front(list_t);
            lim -= 1;
            destroy(list_t, lim);
        }
        list_t->first = list_t->first->next;
        list_t->last = list_t->last->next;
    }
}
