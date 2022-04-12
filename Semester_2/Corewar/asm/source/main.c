/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include <stdio.h>
#include "lib.h"
#include "main.h"
#include "struct.h"

int main(int argc, char *argv[])
{
    file_t file = {0};

    if (error_man(argv, argc) == -1)
        return 84;
    if (get_file(argv[1], &file) == -1)
        return 84;
    file.filename = argv[1];
    if (asm_(&file) == -1) {
        free_file(file);
        return 84;
    }
    free_file(file);
    return 0;
}