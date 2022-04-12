/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_args
*/

#include <stdbool.h>
#include <stdlib.h>
#include "info.h"
#include "instruction.h"
#include "op.h"
#include "lib.h"
#include "get_args.h"
#define FILL_TMP tmp_buff[j] = buffer[++(*pc)]

const instr_t instr_tab[17] = {
    {1, 4, false},
    {2, 4, true},
    {3, 2, true},
    {4, 2, true},
    {5, 2, true},
    {6, 4, true},
    {7, 4, true},
    {8, 4, true},
    {9, 2, false},
    {10, 2, true},
    {11, 2, true},
    {12, 2, false},
    {13, 4, true},
    {14, 2, true},
    {15, 2, false},
    {16, 2, true},
    {0, 0, 0}
};

static int arg_swap(const unsigned char *v)
{
    return (int) __builtin_bswap32(*((int *)v));
}

static short arg(const unsigned char *v)
{
    int swapped = arg_swap(v);

    return *((short *)&swapped);
}

static void get_params(unsigned char *coding, unsigned int *pc,
                unsigned char *buffer, prog_info_t *prog_info)
{
    unsigned char tmp_buff[4] = {0, 0, 0, 0};
    size_t dsz = 0;

    for (unsigned int i = 0; i != prog_info->exec.nb_params;
         prog_info->exec.params[i] = 0, i++);
    for (unsigned int i = 0; i != prog_info->exec.nb_params; i++) {
        dsz = instr_tab[prog_info->exec.cmd].dir_size;
        if (coding[i] == 1)
            prog_info->exec.params[i] = buffer[(++(*pc) % MEM_SIZE)];
        if (coding[i] == 2 && dsz == 4) {
            for (unsigned int j = 0; j != 4; FILL_TMP, j++);
            prog_info->exec.params[i] = arg_swap(tmp_buff);
        } else if ((coding[i] == 2 && dsz == 2) || coding[i] == 3) {
            for (unsigned int j = 2; j != 4; FILL_TMP, j++);
            prog_info->exec.params[i] = arg(tmp_buff);
        }
        *(int *)tmp_buff = 0;
    }
}

static void get_one_arg(unsigned char *buffer,
                        unsigned int *pc, prog_info_t *prog_info)
{
    unsigned char tmp_buff[4] = {0, 0, 0, 0};

    for (unsigned int i = 0; i != prog_info->exec.nb_params;
         prog_info->exec.params[i] = 0, i++);
    if (prog_info->exec.cmd == 1) {
        for (unsigned int j = 0; j != 4; FILL_TMP, j++);
        prog_info->exec.params[0] = arg_swap(tmp_buff);
        return;
    }
    for (unsigned int j = 2; j != 4; FILL_TMP, j++);
    prog_info->exec.params[0] = arg(tmp_buff);
}

int get_param(prog_info_t *prog_info, unsigned int *pc)
{
    unsigned char *coding_byte = {0};
    unsigned int tmp_pc = prog_info->pc;

    for (int i = 0; instr_tab[i].ist_num != 0; i++) {
        if (instr_tab[i].ist_num == prog_info->arena_pt[tmp_pc % MEM_SIZE])
            prog_info->exec.cmd = i;
    }
    if (instr_tab[prog_info->exec.cmd].coding_byte == true) {
        coding_byte = get_coding_byte(
            prog_info->arena_pt[++(*pc) % MEM_SIZE], prog_info->exec.cmd);
        if (coding_byte == NULL)
            return -1;
        get_params(coding_byte, pc, prog_info->arena_pt, prog_info);
    } else
        get_one_arg(prog_info->arena_pt, pc, prog_info);
    ++(*pc);
    return 0;
}
