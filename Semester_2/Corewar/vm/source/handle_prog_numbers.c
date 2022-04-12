/*
** EPITECH PROJECT, 2021
** handle_prog_numbers.c
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "info.h"
#include "handle_prog_numbers.h"

static unsigned int get_actual_empty_number(int *taken_numbers,
                                            unsigned int nb_progs)
{
    static unsigned int counter = 0;

    for (; counter < nb_progs; counter += 1) {
        if (taken_numbers[counter] == 0) {
            counter++;
            return counter;
        }
    }
    return 0;
}

static void swap_node(unsigned int to_swap, info_t *info,
                      unsigned int nb_progs)
{
    for (unsigned int j = 0; j < nb_progs; j++) {
        if (info->prog_info[j].prog_number == to_swap) {
            swap_prog_info_node(&info->prog_info[to_swap - 1],
                                &info->prog_info[j]);
            break;
        }
    }
}

static void sort_prog_info(info_t *info, unsigned int nb_progs)
{
    for (unsigned int i = 0; i < nb_progs; i++) {
        if (info->prog_info[i].prog_number != i + 1)
            swap_node(i + 1, info, nb_progs);
    }
}

int fill_empty_prog_number(info_t *info, int *taken_numbers,
                           unsigned int nb_progs)
{
    for (unsigned int i = 0; i < nb_progs; i++) {
        if (info->prog_info[i].prog_number == 0)
            info->prog_info[i].prog_number =
                get_actual_empty_number(taken_numbers, nb_progs);
    }
    sort_prog_info(info, nb_progs);
    free(taken_numbers);
    if (read_champions(info, nb_progs) == -1)
        return -1;
    return 0;
}
