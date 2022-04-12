/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm_
*/

#include <stddef.h>
#include "asm_.h"

int asm_(file_t *file)
{
    info_t info = {0};

    info.file = *file;
    info.filename = file->filename;
    if (set_header(file, &info) == -1)
        return -1;
    if (set_struct(&info) == -1)
        return -1;
    if (parser(&info) == -1)
        return -1;
    return 0;
}