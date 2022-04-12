/*
** EPITECH PROJECT, 2021
** live.c
** File description:
** operation
*/

#include "lib.h"
#include "info.h"

int live(prog_info_t *prog_info)
{
    prog_info->last_live = prog_info->prog_number;
    my_putstr("The player ");
    my_put_number(prog_info->prog_number);
    my_putchar('(');
    my_putstr(prog_info->name);
    my_putchar(')');
    my_putstr(" is alive.\n");
    return 3;
}
