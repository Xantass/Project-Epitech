/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** desc
*/

#include "lib.h"

int usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_name file in assembly ");
    my_putstr("language to be converted into file_name.cor, an\n");
    my_putstr("executable in the Virtual Machine.\n");
    return 0;
}