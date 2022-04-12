/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "proto.h"
#include "struct.h"

char **modif(char **str, list_t *list);
char **load_script(char const *filepath);

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->size = 0;
    list->score = 0;
    return list;
}

void reset(char *path, info_t *f)
{
    f->list = init_list();
    f->str = modif(load_script(path), f->list);
}
