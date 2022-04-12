/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm_
*/

#ifndef ASM__H_
#define ASM__H_

#include "struct.h"

int set_header(file_t *file, info_t *info);
int set_struct(info_t *a);
int parser(info_t *a);
int write_header(info_t *a);

#endif /* !ASM__H_ */
