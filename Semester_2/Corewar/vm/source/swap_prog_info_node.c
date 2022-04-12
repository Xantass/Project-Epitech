/*
** EPITECH PROJECT, 2021
** swap_prog_info_node.c
** File description:
** functions
*/

#include "info.h"

void swap_prog_info_node(prog_info_t *a, prog_info_t *b)
{
    prog_info_t tmp = *a;

    *a = *b;
    *b = tmp;
}
