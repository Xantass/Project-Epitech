/*
** EPITECH PROJECT, 2021
** ldi.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"

int ldi(prog_info_t *prog_info)
{
    unsigned int value1 = prog_info->exec.params[0];
    unsigned int value2 = prog_info->exec.params[1];
    unsigned int value3 = 0;
    unsigned int addr = (prog_info->pc + (value1 + value2) % IDX_MOD);

    value3 = ((prog_info->arena_pt[addr % MEM_SIZE] << 24) +
              (prog_info->arena_pt[(addr + 1) % MEM_SIZE] << 16) +
              (prog_info->arena_pt[(addr + 2) % MEM_SIZE] << 8) +
              prog_info->arena_pt[(addr + 3) % MEM_SIZE]);
    prog_info->registers[0] = value3;
    prog_info->carry = 1;
    return 0;
}
