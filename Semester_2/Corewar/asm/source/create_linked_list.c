/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_linked_list
*/

#include "struct.h"
#include <stdlib.h>

void ending_labels(lbl_t **lab, int size)
{
    for (; (*lab) != OK; (*lab) = (*lab)->next) {
        if ((*lab)->byte == -1)
            (*lab)->byte = size;
    }
}

int node_lb(lbl_t **start, char *str, int line)
{
    lbl_t *node = malloc(sizeof(lbl_t));
    lbl_t *tmp = *start;

    if (node == NULL)
        return -1;
    node->label = str;
    node->byte = -1;
    node->line = line;
    node->next = NULL;
    if (*start == NULL) {
        *start = node;
        return 0;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
    return 0;
}

void node_instruct(inst_t **start, inst_t **current, int line)
{
    inst_t *tmp = *start;

    (*current)->line = line;
    if (*start == NULL) {
        *start = *current;
        (*current)->next = NULL;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = *current;
    (*current)->next = NULL;
}