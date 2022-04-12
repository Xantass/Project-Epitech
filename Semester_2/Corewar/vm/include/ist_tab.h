/*
** EPITECH PROJECT, 2021
** ist_tab.h
** File description:
** header
*/

#ifndef IST_TAB_H
#define IST_TAB_H

#include <stddef.h>
#include "info.h"

int add(prog_info_t *prog_info);
int aff(prog_info_t *prog_info);
int op_and(prog_info_t *prog_info);
int op_fork(prog_info_t *prog_info);
int ld(prog_info_t *prog_info);
int ldi(prog_info_t *prog_info);
int op_lfork(prog_info_t *prog_info);
int live(prog_info_t *prog_info);
int lld(prog_info_t *prog_info);
int op_or(prog_info_t *prog_info);
int lldi(prog_info_t *prog_info);
int st(prog_info_t *prog_info);
int sti(prog_info_t *prog_info);
int sub(prog_info_t *prog_info);
int op_xor(prog_info_t *prog_info);
int zjmp(prog_info_t *prog_info);

typedef struct ist_tab_t {
    unsigned char ist_code;
    int (*link)(prog_info_t *prog_info);
} ist_tab_t;

ist_tab_t ist_tab [17] = {
    {'1' - '0', live},
    {'2' - '0', ld},
    {'3' - '0', st},
    {'4' - '0', add},
    {'5' - '0', sub},
    {'6' - '0', op_and},
    {'7' - '0', op_or},
    {'8' - '0', op_xor},
    {'9' - '0', zjmp},
    {':' - '0', ld},
    {';' - '0', sti},
    {'<' - '0', op_fork},
    {'=' - '0', lld},
    {'>' - '0', lldi},
    {'?' - '0', op_lfork},
    {'@' - '0', aff},
};

void arg_add(exec_t *arg);
void arg_aff(exec_t *arg);
void arg_and(exec_t *arg);
void arg_fork(exec_t *arg);
void arg_ldi(exec_t *arg);
void arg_lfork(exec_t *arg);
void arg_ld(exec_t *arg);
void arg_ldi(exec_t *arg);
void arg_lfork(exec_t *arg);
void arg_live(exec_t *arg);
void arg_lld(exec_t *arg);
void arg_lldi(exec_t *arg);
void arg_or(exec_t *arg);
void arg_st(exec_t *arg);
void arg_sti(exec_t *arg);
void arg_sub(exec_t *arg);
void arg_xor(exec_t *arg);
void arg_zjmp(exec_t *arg);

typedef struct exec_tab_t {
    unsigned char ist_code;
    void (*link)(exec_t *arg);
} exec_tab_t;

exec_tab_t exec_tab [17] = {
    {'1' - '0', arg_live},
    {'2' - '0', arg_ld},
    {'3' - '0', arg_st},
    {'4' - '0', arg_add},
    {'5' - '0', arg_sub},
    {'6' - '0', arg_and},
    {'7' - '0', arg_or},
    {'8' - '0', arg_xor},
    {'9' - '0', arg_zjmp},
    {':' - '0', arg_ld},
    {';' - '0', arg_sti},
    {'<' - '0', arg_fork},
    {'=' - '0', arg_lld},
    {'>' - '0', arg_lldi},
    {'?' - '0', arg_lfork},
    {'@' - '0', arg_aff},
};

#endif /* IST_TAB_H */
