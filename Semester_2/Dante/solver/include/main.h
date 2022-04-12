/*
** EPITECH PROJECT, 2021
** main.h
** File description:
** header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int **load_map(char *path, vector_2ui_t *size);
int core(int **map, vector_2ui_t *size);

#endif /* !MAIN_H_ */
