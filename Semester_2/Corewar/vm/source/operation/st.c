/*
** EPITECH PROJECT, 2021
** st.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"

int st(prog_info_t *prog_info)
{
    unsigned int value = prog_info->exec.params[0];

    if (prog_info->exec.cmd == T_REG
        && (prog_info->exec.params[1] > 0 && prog_info->exec.params[1] < 17))
        prog_info->registers[prog_info->exec.params[1] - 1] = value;
    else if (prog_info->exec.cmd == T_IND)
        prog_info->arena_pt[(prog_info->pc + 34 - 3 % IDX_MOD)
                            % MEM_SIZE] = value;

    return 0;
}
