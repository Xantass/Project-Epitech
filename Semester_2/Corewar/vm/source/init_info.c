/*
** EPITECH PROJECT, 2021
** init_info.c
** File description:
** functions
*/

#include <stdlib.h>
#include "info.h"
#include "lib.h"
#include "op.h"
#include "init_info.h"

static int insert_champ(prog_info_t prog_info, info_t *info)
{
    unsigned int j = 0;

    for (unsigned int i = prog_info.pc, lim = 0;
         lim != prog_info.prog_size; ++i, ++lim) {
        if (i > MEM_SIZE)
            i = 0;
        if (info->arena[i] != '\0')
            return -1;
        info->arena[i] = prog_info.instructions[j++];
    }
    return 0;
}

static int set_buffer_arena(info_t *info)
{
    for (unsigned int i = 0; i < info->nb_progs; ++i) {
        if (insert_champ(info->prog_info[i], info) == -1)
            return -1;
    }
    return 0;
}

int init_info(info_t *info)
{
    if (calloc_arena(info) == -1)
        return -1;
    set_address(info);
    for (unsigned int i = 0; i < info->nb_progs; i++) {
        set_bool(&info->living_process, info->prog_info[i].prog_number);
        info->prog_info[i].last_live = CYCLE_TO_DIE;
        info->prog_info[i].arena_pt = info->arena;
        info->prog_info[i].registers[0] = i;
    }
    if (set_buffer_arena(info) == -1)
        return -1;
    actual_cycle_to_die = CYCLE_TO_DIE;
    return 0;
}
