/*
** EPITECH PROJECT, 2021
** sti.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"

int sti(prog_info_t *prog_info)
{
    unsigned int value1 = prog_info->exec.params[1];
    unsigned int value2 = prog_info->exec.params[2];
    int reg_val = prog_info->exec.params[0];

    if ((prog_info->exec.params[0]) > 16 || prog_info->exec.params[0] < 1)
        return 0;
    if ((reg_val != -1)) {
        prog_info->arena_pt[(prog_info->pc - 3 + (value1 + value2) % IDX_MOD)
               % MEM_SIZE] = reg_val;
    }
    return 0;
}