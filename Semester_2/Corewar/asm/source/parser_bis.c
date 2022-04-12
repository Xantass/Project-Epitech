/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** parser_bis
*/

#include <stdlib.h>
#include "parser_bis.h"
#include "lib.h"

int has_points(char *str)
{
    return ((*str == LABEL_CHAR
            || (*str == DIRECT_CHAR && str[1] == LABEL_CHAR)) ? 0 : 84);
}

void update_size(int *size, inst_t **tmp)
{
    if ((*tmp)->op_code != 1 && (*tmp)->op_code != 9 && (*tmp)->op_code != 12
        && (*tmp)->op_code != 15) {
        *size += 1;
        (*tmp)->coding_byte = 1;
    }
}

static int get_byte(lbl_t *lab, int *current, char *str, int size)
{
    for (lbl_t *tmp = lab; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->label, str) == 0) {
            *current = tmp->byte - size;
            return 0;
        }
    return -1;
}

int check_label(int *tmp, info_t *a, char *str, int size)
{
    int ret;

    if (*str == DIRECT_CHAR) {
        if ((ret = search_label(a->label, put_label_behind(str + 1))) == 0)
            return get_byte(a->label, tmp, str + 1, size);
    }
    else if (*str == LABEL_CHAR)
        if ((ret = search_label(a->label, put_label_behind(str))) == 0)
            return get_byte(a->label, tmp, str, size);
    return -1;
}