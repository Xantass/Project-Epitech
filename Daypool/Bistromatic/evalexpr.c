/*
** EPITECH PROJECT, 2020
** one_recur
** File description:
** fewmdoewmio
*/

char *one_recur(char **myopstr, char const *operators, char *base);

#include <stdlib.h>
#include "../include/my.h"
#include "ainclude/evalexpr_vars_struct.h"
#include "ainclude/operator.h"
#include "ainclude/my_opp.h"

int nonums(char **numstr, int *minus, char *base, const char *ops)
{
    char *num = *numstr;

    *minus = 1;
    for (; *num == '-' || *num == '+' || *num == ' '; num++)
        if (*num == '-')
            *minus = -(*minus);
    if (my_char_isnum(*num, base) == 1)
        return (0);
    if (*num == ops[0]) {
        *numstr = num + 1;
        return (1);
    }
}

void init_struct_vars
(struct evst_ *evst, char **opstr, char const *ops, char *base)
{
    evst -> minus = 1;
    evst -> result = "";
    evst -> stored_nums = malloc(sizeof(char) * 999);
    evst -> stored_ops = malloc(sizeof(int) * 999);
    if (nonums(opstr, &(evst -> minus), base, ops)) {
        evst -> result = minusret(one_recur(opstr, ops, base), evst->minus);
    } else {
        evst -> result = *opstr;
        move_ptr_to_next_op(opstr, base);
    }
    evst -> i = 0;
    evst -> u = 0;
    evst -> stored_ops[0] = 99;
}

void prepare_for_operation
(struct evst_ *evst, char **opstr, char const *ops, char *base)
{
    int looped = 0;

    evst -> opindex = 0;
    while (**opstr != ops[evst->opindex + 2]) {
        if (OP_FNS[evst -> opindex].character == "")
            break;
        evst -> opindex++;
    }
    if (OP_FNS[evst -> opindex].character != "") {
        add_nums_to_array(evst, opstr, ops, base);
        (*opstr)--;
    }
}

char *one_recur(char **myopstr, char const *operators, char *base)
{
    struct evst_ evst;

    init_struct_vars(&evst, myopstr, operators, base);
    for (;**myopstr != '\0' && **myopstr != operators[1]; (*myopstr)++)
        prepare_for_operation(&evst, myopstr, operators, base);
    (*myopstr)++;
    evst.stored_ops[evst.u] = 99;
    evst.i = 0;
    evst.u = 0;
    while (evst.stored_ops[evst.u] != 99) {
        evst.result = (OP_FNS[evst.stored_ops[evst.u]].func
                (evst.result, evst.stored_nums[evst.i], base));
        evst.i++;
        evst.u++;
    }
    free(evst.stored_nums);
    free(evst.stored_ops);
    return (evst.result);
}
