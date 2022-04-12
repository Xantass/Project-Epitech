/*
** EPITECH PROJECT, 2021
** handle_args.c
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "info.h"
#include "lib.h"
#include "handle_args.h"
#include "op.h"

int actual_cycle_to_die = CYCLE_TO_DIE;
unsigned int actual_cycle = 1;

static unsigned int get_number_of_progs(char *argv[])
{
    unsigned int res = 0;
    unsigned int i = 1;

    if (my_strcmp(argv[1], "-dump") == 0)
        i = 3;
    for (; argv[i] != NULL; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-')
            res++;
    }
    return res;
}

static int alloc_prog_info(info_t *info, unsigned int nb_progs)
{
    info->prog_info = my_calloc(sizeof(prog_info_t), (nb_progs) + 1);
    if (info->prog_info == NULL) {
        return -1;
    }
    return 0;
}

static int fill_prog_info(info_t *info, char *argv[])
{
    unsigned int offset = 0;
    int program_counter = 0;
    unsigned int i = 1;

    if (my_strcmp(argv[1], "-dump") == 0)
        i = 3;
    for (; argv[i] != NULL; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            info->prog_info[offset].name = argv[i];
            offset++;
        }
        if (my_strcmp(argv[i], "-n") == 0) {
            info->prog_info[offset].prog_number = my_get_number(argv[i + 1]);
            program_counter++;
        }
        if (my_strcmp(argv[i], "-s") == 0) {
            info->prog_info[offset].load_address = my_get_number(argv[i + 1]);
        }
    }
    return program_counter;
}

static int assign_program_number(info_t *info, unsigned int nb_progs)
{
    int *taken_numbers = my_calloc(sizeof(int), (nb_progs) + 1);

    if (taken_numbers == NULL)
        return -1;
    for (unsigned int i = 0; i < nb_progs; i++) {
        for (unsigned int j = 0; j < nb_progs; j++) {
            if (i + 1 == info->prog_info[j].prog_number) {
                taken_numbers[i] = i + 1;
            }
        }
    }
    return fill_empty_prog_number(info, taken_numbers, nb_progs);
}

int handle_args(int argc, char *argv[], info_t *info)
{
    unsigned int nb_progs = 0;

    if (argc <= 2)
        return -1;
    if (error_handling(argv) == -1)
        return -1;
    if (my_strcmp(argv[1], "-dump") == 0)
        info->dump_cycle = my_get_number(argv[2]);
    else
        info->dump_cycle = -1;
    nb_progs = get_number_of_progs(argv);
    if (nb_progs < 2 || nb_progs > 4)
        return -1;
    if (alloc_prog_info(info, nb_progs) == -1)
        return -1;
    if (fill_prog_info(info, argv) < (int) nb_progs) {
        if (assign_program_number(info, nb_progs) == -1)
            return -1;
    }
    info->nb_progs = nb_progs;
    return 0;
}
