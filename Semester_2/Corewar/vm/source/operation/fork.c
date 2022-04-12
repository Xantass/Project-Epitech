/*
** EPITECH PROJECT, 2021
** fork.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"
#include "lib.h"
#include <stdlib.h>

static prog_info_t cpy_fork(prog_info_t *prog_info, int index)
{
    prog_info_t *fork = malloc(sizeof(prog_info_t));

    fork->name = my_strdup(prog_info->name);
    fork->load_address = prog_info->load_address;
    fork->exec = prog_info->exec;
    fork->pc = 0;
    fork->is_running = prog_info->is_running;
    fork->prog_size = prog_info->prog_size;
    fork->last_live = prog_info->last_live;
    fork->arena_pt = prog_info->arena_pt;
    fork->prog_number = prog_info->prog_number;
    fork->carry = prog_info->carry;
    fork->instructions = prog_info->instructions;
    fork->pc = prog_info->pc + (index % IDX_MOD);

    return *fork;
}

int op_fork(prog_info_t *prog_info)
{
    int index = prog_info->exec.params[0];

    cpy_fork(prog_info, index);
    return 0;
}
