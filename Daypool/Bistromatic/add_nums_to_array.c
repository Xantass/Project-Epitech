/*
** EPITECH PROJECT, 2020
** add_nums_to_array
** File description:
** fekwpoem
*/

#include "evalexpr.c"
#include "../include/my.h"

void nums_to_arr_if_if
(struct evst_ *evst, char **opstr, char const *ops, char *base)
{
    if (nonums(opstr, &(evst -> minus), base, ops)) {
        evst->result = OP_FNS[evst->opindex].func
            (evst->result, minusret(one_recur(opstr, ops, base),
                    evst->minus), base);
    } else {
        evst->result = OP_FNS[evst->opindex].func
            (evst->result, *opstr, base);
        move_ptr_to_next_op(opstr, base);
    }
}

void nums_to_arr_if_else
(struct evst_ *evst, char **opstr, char const *ops, char *base)
{
    if (nonums(opstr, &(evst -> minus), base, ops)) {
        evst->stored_nums[evst->i - 1] = OP_FNS[evst->opindex].func
            (evst->stored_nums[evst->i - 1],
             minusret(one_recur(opstr, ops, base), evst->minus), base);
    } else {
        evst->stored_nums[evst->i - 1] = OP_FNS[evst->opindex].func
            (evst->stored_nums[evst->i - 1], *opstr, base);
        move_ptr_to_next_op(opstr, base);
    }
}

void add_nums_to_array
(struct evst_ *evst, char **opstr, char const *ops, char *base)
{
    if (evst -> opindex > 1) {
        (*opstr)++;
        if (evst -> i == 0) {
            nums_to_arr_if_if (evst, opstr, ops, base);
        } else {
            nums_to_arr_if_else(evst, opstr, ops, base);
        }
    } else {
        (*opstr)++;
        if (nonums(opstr, &(evst -> minus), base, ops)) {
            evst -> stored_nums[evst -> i] =
                minusret(one_recur(opstr, ops, base), evst->minus);
        } else {
            evst -> stored_nums[evst -> i] = *opstr;
            move_ptr_to_next_op(opstr, base);
        }
        evst -> stored_ops[evst -> u] = evst -> opindex;
        evst -> u++;
        evst -> i++;
    }
}
