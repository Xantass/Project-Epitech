/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** parser
*/

#include <stdlib.h>
#include "parser.h"

static void handle(int *i, int *j, inst_t *tmp)
{
    *j = 1;
    *i = 1;
    if (is_label(tmp->args[*j], 0) == 0) {
        *j += 1;
        *i += 1;
    }
    if (is_instruction(tmp->args[*j]) != 84) {
        *j += 1;
        *i += 1;
    }
}

static int place_byte_in_labels(info_t *a)
{
    int j;
    int i;
    int size = 0;
    int error = 0;

    for (inst_t *tmp = a->ins; tmp != OK; tmp = tmp->next) {
        handle(&i, &j, tmp);
        for (int i = 0; tmp->size[i] != -1 && tmp->args[j] != OK; i++, j++) {
            if (has_points(tmp->args[j]) == 0 && (error =
                check_label(&(tmp->hex[j]), a, tmp->args[j], tmp->byte)) != 0)
                return error;
        }
        for (int i = 0; tmp->size[i] != -1; i++)
            size += tmp->size[i];
        update_size(&size, &tmp);
    }
    return write_new_file(a);
}

static int get_values_of_args(inst_t *tmp, int *size, int i, int j)
{
    for (; tmp->size[i] != -1; i++, j++) {
        tmp->size[i] = get_type(tmp->args[j], tmp->op_code);
        tmp->hex[i] = is_instruction(tmp->args[j]);
        if (tmp->hex[i] == 84)
            tmp->hex[i] = get_value(tmp->args[j]);
        *size += tmp->size[i];
    }
    return 0;
}

static void manage_label(lbl_t **lab, int size, int line)
{
    while ((*lab)->line <= line) {
        (*lab)->byte = size;
        if ((*lab)->next != OK)
            (*lab) = (*lab)->next;
        else
            return;
    }
}

int parser(info_t *a)
{
    int size = 0;
    lbl_t *lab = a->label;
    inst_t *tmp = a->ins;
    int error = 0;

    for (int i = 0, j = 0; tmp != OK; tmp = tmp->next, i = 0, j = 0) {
        if (tmp->is_label == true)
            manage_label(&lab, size, tmp->line);
        tmp->byte = size;
        update_size(&size, &tmp);
        if (is_label(tmp->args[j], 0) == 0) {
            j += 1;
            i += 1;
        }
        if ((error = get_values_of_args(tmp, &size, i, j)) != 0)
            return error;
    }
    ending_labels(&lab, size);
    a->head.prog_size = SWAP_ENDIAN(size);
    return place_byte_in_labels(a);
}