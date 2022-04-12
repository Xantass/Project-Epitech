/*
** EPITECH PROJECT, 2020
** draw.c
** File description:
** function
*/

#include <math.h>
#include "graph.h"
#include "my.h"
#include "list.h"

void sup_front(list *list_t);

void circ(stock f)
{
    for (int i = 0; i < f.j; i++) {
        sfRenderWindow_drawCircleShape(f.window, f.tower[i], NULL);
        sfRenderWindow_drawSprite(f.window, f.towers[i], NULL);
    }
}

int check_pos(list *list_t)
{
    sfVector2f position;

    position = sfRectangleShape_getPosition(list_t->first->plane);
    if (round(position.x) == list_t->first->finish.x &&
        round(position.y) == list_t->first->finish.y)
        return 1;
    else
        return 0;
}

int move(list *list_t, stock f, int time)
{
    sfVector2f offset;

    if (list_t->first->pop > time)
        return 0;
    offset.x = ((list_t->first->finish.x - list_t->first->start.x) /
                (list_t->first->speed * (120 * list_t->first->speed)) *
                (list_t->first->speed * 0.5));
    offset.y = ((list_t->first->finish.y - list_t->first->start.y) /
                (list_t->first->speed * (120 * list_t->first->speed)) *
                (list_t->first->speed * 0.5));
    sfRectangleShape_move(list_t->first->plane, offset);
    if (f.s == -1)
        return 0;
    if (f.l == 1)
        sfRectangleShape_setOutlineColor(list_t->first->plane, sfGreen);
    if (f.l == -1)
        sfRectangleShape_setOutlineColor(list_t->first->plane, sfTransparent);
    sfRenderWindow_drawRectangleShape(f.window, list_t->first->plane, NULL);
    return 0;
}

void spri(stock f, list *list_t, int time)
{
    for (int j = 0; j < list_t->size; j++) {
        if (check_pos(list_t) == 1) {
            sfRectangleShape_destroy(list_t->first->plane);
            sup_front(list_t);
        }
        else
            move(list_t, f, time);
        if (list_t->size == 0)
            break;
        list_t->first = list_t->first->next;
        list_t->last = list_t->last->next;
    }
}

void draw(list *list_t, stock f)
{
    f.time = sfClock_getElapsedTime(f.clock);
    f.times = sfTime_asSeconds(f.time);
    sfText_setString(f.text, get_char(f.times));
    sfText_setStyle(f.text, sfTextRegular);
    sfText_setColor(f.text, sfRed);
    sfRenderWindow_drawText(f.window, f.text, NULL);
    circ(f);
    spri(f, list_t, f.times);
}
