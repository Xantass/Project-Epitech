/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** free
*/

#include <stdlib.h>
#include "struct.h"

void free_file(file_t file)
{
    for (int i = 0; i < file.nb; ++i)
        free(file.file[i]);
    free(file.file);
}