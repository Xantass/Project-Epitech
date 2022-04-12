/*
** EPITECH PROJECT, 2021
** dante
** File description:
** algo
*/

#ifndef ALGO_H_
#define ALGO_H_

#include <stdio.h>
#include <stdbool.h>
#include "struct.h"

static bool is_safe(int **maze, unsigned int x, unsigned int y, vector_2ui_t *size);
int **alloc_sol(vector_2ui_t *size);
int modif_map(int maze, int sol);
void condition_print(int sol);

#endif /* !ALGO_H_ */