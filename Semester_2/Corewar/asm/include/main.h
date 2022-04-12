/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "struct.h"

int usage(void);
int error_man(char **argv, int argc);
int get_file(char *filepath, file_t *file);
int asm_(file_t *file);
void free_file(file_t file);

#endif /* !MAIN_H_ */
