/*
** EPITECH PROJECT, 2021
** set_arena.c
** File description:
** functions
*/

#include "info.h"
#include "lib.h"
#include "op.h"

static int set_default_address(info_t *info, unsigned int temp_index)
{
    unsigned int space = MEM_SIZE / info->nb_progs;

    for (unsigned int i = 0; i < info->nb_progs; i++) {
        if (info->prog_info[i].pc == 0)
            info->prog_info[i].pc = (temp_index += space);
    }
    return 0;
}

int set_address(info_t *info)
{
    unsigned int tmp = 0;
    unsigned int temp_index = 0;

    for (unsigned int i = 0; i < info->nb_progs; i++) {
        if (info->prog_info[i].load_address != 0) {
            info->prog_info[i].pc = info->prog_info[i].load_address;
            temp_index = info->prog_info[i].pc;
        }
        else
            tmp = PC_NOT_SET;
    }
    if (tmp == PC_NOT_SET)
        return set_default_address(info, temp_index);
    return 0;
}

int calloc_arena(info_t *info)
{
    if ((info->arena = my_calloc(sizeof(unsigned char), (MEM_SIZE) + 1))
        == NULL)
        return -1;
    return 0;
}
