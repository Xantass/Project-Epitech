/*
** EPITECH PROJECT, 2021
** and.c
** File description:
** opration
*/

#include <stdio.h>
#include "info.h"
#include "op.h"

int op_and(prog_info_t *prog_info)
{
    unsigned int register_a = prog_info->exec.params[0];
    unsigned int register_b = prog_info->exec.params[1];

    if ((prog_info->exec.params[2]) > 16 || prog_info->exec.params[2] < 1) {
        prog_info->carry = 0;
        return 0;
    }
    prog_info->registers[prog_info->exec.params[2] - 1] =
        register_a & register_b;
    prog_info->carry = 1;
    return 0;
}
