/*
** EPITECH PROJECT, 2021
** calc.c
** File description:
** functions
*/

#include <stdio.h>
#include "lib.h"
#include "info.h"
#include "op.h"

unsigned int get_execution_index(unsigned int prog_index, info_t *info)
{
    return info->prog_info[prog_index].pc % MEM_SIZE;
}
