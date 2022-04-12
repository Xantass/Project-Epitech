/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "list.h"
#include "proto.h"
#include "struct.h"

int check_pos(element_t *act, list_t *list);

static int check_bis(int *cor, element_t *act, char **str, list_t *list)
{
    element_t *acts = list->first;

    for (int i = 0; i < list->size; i++) {
        if (acts->c=='X' &&(act->x+cor[0]==acts->x && act->y+cor[1]==acts->y)) {
            return -1;
        }
        acts = acts->next;
    }
    if (str[act->x + cor[0]][act->y + cor[1]] != '#') {
        act->x = act->x + cor[0];
        act->y = act->y + cor[1];
        return 0;
    }
    return -1;
}

static int check_biss(list_t *list)
{
    element_t *act = list->first;
    int max = 0;

    for (int i = 0; i < list->size; i++) {
        if (act->c == 'O')
            check_pos(act, list);
        act = act->next;
    }
    act = list->first;
    for (int i = 0; i < list->size; i++) {
        max = max + act->nb;
        act = act->next;
    }
    list->score = max;
    return 0;
}

int check(int x, int y, list_t *list, char **str)
{
    element_t *act = list->first;
    int cor[2] = {x, y};

    x = list->first->x + x;
    y = list->first->y + y;
    if (str[x][y] == '#')
        return -1;
    for (int i = 0; i < list->size; i++) {
        if (act->c == 'X' && (x == act->x && y == act->y)) {
            if (check_bis(cor, act, str, list) == -1)
                return -1;
            else {
                check_biss(list);
                return 0;
            }
        }
        act = act->next;
    }
    return 0;
}

static int check_bisss(char c)
{
    if (c == ' ')
        return 0;
    if (c == '\n')
        return 0;
    if (c == '#')
        return 0;
    if (c == 'X')
        return 0;
    if (c == 'O')
        return 0;
    if (c == 'P')
        return 0;
    return -1;
}

int check_map(char **str, info_t *f)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != NULL; i++) {
        for (j = 0; str[i][j] != '\0'; j++) {
            if (check_bisss(str[i][j]) == -1)
                return -1;
            if (str[i][j] == 'O')
                f->nb_O++;
            if (str[i][j] == 'X')
                f->nb_X++;
        }
    }
    f->col = j;
    f->line = i;
    if (f->nb_O != f->nb_X)
        return -1;
    return 0;
}
