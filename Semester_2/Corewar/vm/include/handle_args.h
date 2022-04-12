/*
** EPITECH PROJECT, 2021
** handlde_args.c
** File description:
** functions
*/

#ifndef HANDLE_ARGS_H
#define HANDLE_ARGS_H

void print_prog_info(info_t *info, unsigned int size);
int fill_empty_prog_number(info_t *info, int *taken_numbers,
                        unsigned int nb_progs);
void swap_prog_info_node(prog_info_t **a, prog_info_t **b);
int error_handling(char *argv[]);
void swapbytes(void *mem, unsigned int size);

#endif
