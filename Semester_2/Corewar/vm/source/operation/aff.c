/*
** EPITECH PROJECT, 2021
** aff.c
** File description:
** operation
*/

#include "info.h"
#include "op.h"
#include "lib.h"

int aff(prog_info_t *prog_info)
{
    int reg = prog_info->exec.params[0];
    unsigned int value = 0;

    if ((reg) == -1) {
        prog_info->carry = 0;
        return 0;
    }
    value = prog_info->registers[reg - 1];
    my_putchar(value == 42 ? '*' : value % 256);
    prog_info->carry = 1;
    return 0;
}
