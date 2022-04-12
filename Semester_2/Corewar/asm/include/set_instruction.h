/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** set_instruction
*/

#ifndef SET_INSTRUCTION_H_
#define SET_INSTRUCTION_H_

#include "struct.h"

int node_lb(lbl_t **start, char *str, int line);
char **my_str_to_word_array(char *str);
void node_instruct(inst_t **start, inst_t **current, int line);
int is_instruction(char const *str);
int is_label(char const *str, int start);
int check_type(inst_t *cur);

#endif /* !SET_INSTRUCTION_H_ */
