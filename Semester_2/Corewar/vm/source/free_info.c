/*
** EPITECH PROJECT, 2021
** free_info.c
** File description:
** functions
*/

#include <stdlib.h>
#include "info.h"

static int free_prog_info(prog_info_t *prog_info)
{
    if (prog_info->name != NULL)
        free(prog_info->name);
    if (prog_info->instructions != NULL)
        free(prog_info->instructions);
    if (prog_info->exec.params != NULL)
        free(prog_info->exec.params);
    return 0;
}

int free_info(info_t *info)
{
    if (info->arena != NULL)
        free(info->arena);
    if (info->prog_info != NULL) {
        for (unsigned int i = 0; i < info->nb_progs; i++)
            free_prog_info(&info->prog_info[i]);
        free(info->prog_info);
    }
    return 0;
}
