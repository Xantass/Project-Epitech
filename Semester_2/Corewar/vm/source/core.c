/*
** EPITECH PROJECT, 2021
** core.c
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "info.h"
#include "lib.h"
#include "core.h"
#include "op.h"

static void remove_dead_prog(info_t *info)
{
    for (unsigned int i = 0; i < info->nb_progs; i++) {
        if (info->prog_info[i].last_live == 0 &&
            get_state(&info->living_process,
                      info->prog_info[i].prog_number) == 1)
            set_bool(&info->living_process, info->prog_info[i].prog_number);
        else
            info->prog_info[i].last_live--;
    }
}

static void refresh_arena(info_t *info)
{
    int winner = 0;

    remove_dead_prog(info);
    if ((winner = check_win(info)) != -1) {
        print_winner(info->prog_info[winner]);
        free_info(info);
        exit(0);
    }
    if (info->total_live >= 40) {
        printf("act = %d\n", actual_cycle_to_die);
        actual_cycle_to_die -= CYCLE_DELTA;
    }
    if (actual_cycle_to_die == 1) {
        print_winner(info->prog_info[info->l_live_prog]);
    }
}

static int run_instruction(prog_info_t *prog_info)
{
    return decode_instructions(prog_info);
}

static int find_instructions(info_t *info)
{
    int res = 0;

    for (unsigned int i = 0; i < info->nb_progs; i++) {
        if (is_available(&info->prog_info[i], info->living_process) == 1) {
            res = run_instruction(&info->prog_info[i]);
        }
        if (res == -1) {
            return -1;
        }
        else if (res == 3) {
            info->l_live_prog = i;
            info->total_live++;
        }
    }
    return 0;
}

int core(info_t *info)
{
    if (init_info(info) == -1)
        return -1;
    while (actual_cycle) {
        if (find_instructions(info) == -1)
            return -1;
        if ((unsigned int) info->dump_cycle == actual_cycle)
            dump_arena(info);
        refresh_arena(info);
        actual_cycle++;
    }
    return 0;
}
