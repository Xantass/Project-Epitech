/*
** EPITECH PROJECT, 2021
** zjmp.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"

int zjmp(prog_info_t *prog_info)
{
    if (prog_info->carry == 1)
        prog_info->pc = prog_info->pc - 3 +
            (prog_info->exec.params[0] % IDX_MOD);
    prog_info->pc = ((prog_info->pc +
                      prog_info->exec.params[0] % IDX_MOD)% MEM_SIZE);
    return 0;
}
