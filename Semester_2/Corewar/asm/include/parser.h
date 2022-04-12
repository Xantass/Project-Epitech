/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "struct.h"

int has_points(char *str);
void update_size(int *size, inst_t **tmp);
int check_label(int *tmp, info_t *a, char *str, int size);
int is_label(char const *str, int start);
int is_instruction(char const *str);
void ending_labels(lbl_t **lab, int size);
char get_type(char const *str, int code);
int get_value(char *str);
int write_new_file(info_t *a);

#endif /* !PARSER_H_ */
