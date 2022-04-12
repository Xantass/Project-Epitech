/*
** EPITECH PROJECT, 2021
** core.h
** File description:
** header
*/

#ifndef CORE_H
#define CORE_H

#include <stdbool.h>

int init_info(info_t *info);
unsigned int get_execution_index(unsigned int prog_index, info_t *info);
int decode_instructions(prog_info_t *prog_info);
void print_winner(prog_info_t prog_info);
unsigned int check_win(info_t *info);
int is_available(prog_info_t *prog_info, short int living_process);
int get_state(short int *bool_tab, unsigned int index);
void set_bool(short int *bool_tab, unsigned int index);
void dump_arena(info_t *info);
int free_info(info_t *info);

#endif
