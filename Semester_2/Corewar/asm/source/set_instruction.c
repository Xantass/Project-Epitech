/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** set_instruction
*/

#include <stdbool.h>
#include <stdlib.h>
#include "set_instruction.h"

static void clean(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == SEPARATOR_CHAR)
            str[i] = ' ';
}

static int get_size(inst_t *cur, verif_t ind, inst_t **start, int line)
{
    int c = 0;

    cur->size = malloc(sizeof(int) * (ind.j + 1));
    cur->hex = malloc(sizeof(int) * (ind.j + 1));
    if (cur->size == NULL || cur->hex == NULL)
        return -1;
    cur->size[ind.j] = -1;
    while (c != ind.j)
        cur->size[c++] = 0;
    c = 0;
    while (c != ind.j)
        cur->hex[c++] = 0;
    node_instruct(start, &cur, line);
    return 0;
}

static int instruction(int line, inst_t *cur,
                       inst_t **start, lbl_t **lab)
{
    verif_t ind = {0};
    int error = 0;

    if (is_label(cur->args[0], 0) == 0) {
        ind.i = 1;
        cur->is_label = true;
        error = node_lb(lab, cur->args[0], line);
        if (error != 0)
            return error;
    }
    if ((cur->op_code = is_instruction(cur->args[ind.i++])) == 84
        && cur->args[1] == NULL)
        return 0;
    if (cur->op_code == 84 && cur->args[1] != NULL)
        return -1;
    for (; cur->args[ind.j] != NULL; ind.j++);
    if (ind.j - ind.i != op_tab[cur->op_code - 1].nbr_args)
        return -1;
    if (check_type(cur) == -1)
        return -1;
    return get_size(cur, ind, start, line);
}

static int init(inst_t *current,bool *next_is_label,
                int nb_line, lbl_t **label)
{
    int line = nb_line;
    int error = 0;

    if (is_label(current->args[0], 0) == 0 && current->args[1] == NULL) {
        if ((error = node_lb(label, current->args[0], line)) != 0)
            return error;
        *next_is_label = true;
        return 0;
    }
    current->is_label = false;
    current->coding_byte = -1;
    if (*next_is_label == true) {
        current->is_label = true;
        *next_is_label = false;
    }
    return 0;
}

int set_struct(info_t *a)
{
    inst_t *current;
    bool next_is_label = false;
    int error = 0;

    for (int i = 2; i < a->file.nb; ++i) {
        clean(a->file.file[i]);
        if (((current = malloc(sizeof(inst_t))) == NULL) ||
            ((current->args = my_str_to_word_array(a->file.file[i])) == NULL))
            return -1;
        error = init(current, &next_is_label, i, &(a->label));
        if (error != 0)
            continue;
        if (error != 0 || (error
                           = instruction(i, current,
                                         &(a->ins), &(a->label))) != 0) {
            return -1;
        }
    }
    return 0;
}
