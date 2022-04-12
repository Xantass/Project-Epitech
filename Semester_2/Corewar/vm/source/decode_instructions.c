/*
** EPITECH PROJECT, 2021
** decode_instructions.c
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "info.h"
#include "ist_tab.h"
#include "lib.h"
#include "decode_instructions.h"

static int load_instructions_following(prog_info_t *prog_info, unsigned int i)
{
    prog_info->exec.params = my_calloc(sizeof(int), (3) + 1);
    if (prog_info->exec.params == NULL)
        return -1;
    prog_info->is_running = prog_info->exec.duration;
    exec_tab[i].link(&prog_info->exec);
    get_param(prog_info, &prog_info->pc);
    if (ist_tab[i].link(prog_info) == 3) {
        prog_info->last_live = actual_cycle_to_die + 1;
        return 3;
    }
    return 0;
}

static int load_instructions(prog_info_t *prog_info)
{
    unsigned int is_param = 0;

    for (unsigned int i = 0; i < 16; i++) {
        if (prog_info->arena_pt[prog_info->pc % MEM_SIZE] ==
            ist_tab[i].ist_code) {
            is_param = 1;
            return load_instructions_following(prog_info, i);
        }
    }
    if (is_param == 0)
        prog_info->pc = (prog_info->pc % MEM_SIZE) + 1;
    return 0;
}

int decode_instructions(prog_info_t *prog_info)
{
    return load_instructions(prog_info);
}
