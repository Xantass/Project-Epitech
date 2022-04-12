/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** label
*/

#include <stdlib.h>
#include "struct.h"
#include "lib.h"

char *put_label_behind(char *str)
{
    int i = 1;

    for (; str[i] != 0; i++)
        str[i - 1] = str[i];
    str[i - 1] = LABEL_CHAR;
    return str;
}

int search_label(lbl_t *lab, char *str)
{
    for (lbl_t *tmp = lab; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->label, str) == 0)
            return 0;
    return 84;
}

int label_id(lbl_t *lab, char *str)
{
    int id = 1;

    for (lbl_t *tmp = lab; tmp != NULL; tmp = tmp->next, id += 1)
        if (my_strcmp(tmp->label, str) == 0)
            return id;
    return 0;
}

void update_label_byte(inst_t *tmp, int size, lbl_t **lab)
{
    if (tmp->is_label == true) {
        (*lab)->byte = size;
        *lab = (*lab)->next;
    }
}