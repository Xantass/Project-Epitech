/*
** EPITECH PROJECT, 2021
** check_bis.c
** File description:
** function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "proto.h"
#include "struct.h"

int check_pos(element_t *act, list_t *list)
{
    element_t *acts = list->first;

    for (int i = 0; i < list->size; i++) {
        if (acts->c == 'X' && (act->x == acts->x && act->y == acts->y)) {
            act->nb = 1;
            return 0;
        }
        else {
            act->nb = 0;
        }
        acts = acts->next;
    }
    return 0;
}

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and ‘O’ ");
    my_putstr("for storage locations.\n");
}

static int check(element_t *act, char **str)
{
    if (str[act->x][act->y] == 'O')
        return 0;
    if (str[act->x + 1][act->y] == '#' && str[act->x][act->y + 1] == '#')
        return -1;
    if (str[act->x - 1][act->y] == '#' && str[act->x][act->y - 1] == '#')
        return -1;
    if (str[act->x + 1][act->y] == '#' && str[act->x][act->y - 1] == '#')
        return -1;
    if (str[act->x - 1][act->y] == '#' && str[act->x][act->y + 1] == '#')
        return -1;
    return 0;
}

int check_end_game(char **str, list_t *list)
{
    element_t *act = list->first;

    for (int i = 0; i < list->size; i++) {
        if (act->c == 'X') {
            if (check(act, str) == -1) {
                endwin();
                exit(1);
            }
        }
        act = act->next;
    }
    return 0;
}
