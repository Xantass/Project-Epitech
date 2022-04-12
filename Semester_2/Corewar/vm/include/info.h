/*
** EPITECH PROJECT, 2021
** info.h
** File description:
** functions
*/

#ifndef INFO_H
#define INFO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "op.h"

typedef struct exec_t {
    int *params;
    unsigned short cmd;
    unsigned int nb_params;
    unsigned int duration;
} exec_t;

typedef struct prog_info_t {
    char *name;
    unsigned int load_address;
    unsigned char *instructions;
    unsigned int prog_size;
    unsigned int prog_number;
    unsigned int is_running;
    unsigned int registers[REG_NUMBER];
    unsigned int last_live;
    unsigned int carry;
    unsigned int pc;
    unsigned char *arena_pt;
    exec_t exec;
} prog_info_t;

typedef struct info_t {
    unsigned char *arena;
    unsigned int total_live;
    unsigned int nb_progs;
    short int living_process;
    prog_info_t *prog_info;
    unsigned int l_live_prog;
    int dump_cycle;
} info_t;

extern  int actual_cycle_to_die;
extern unsigned int actual_cycle;

#endif /* INFO_H */

