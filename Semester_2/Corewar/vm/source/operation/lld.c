/*
** EPITECH PROJECT, 2021
** lld.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"

int lld(prog_info_t *prog_info)
{
    unsigned int value = prog_info->exec.params[0];

    if ((prog_info->exec.params[1]) > 16 || prog_info->exec.params[1] < 1) {
        prog_info->carry = 0;
        return 0;
    }
    prog_info->registers[prog_info->exec.params[1] - 1] = value;
    prog_info->carry = 1;
    return 0;
}
