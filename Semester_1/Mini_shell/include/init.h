/*
** EPITECH PROJECT, 2021
** init.h
** File description:
** function
*/

#ifndef INIT_H
#define INIT_H
#include "struct.h"

char *get_paths(info_t *f);
char **add_slash(char **str);
char *get_com(void);
char *valid_com(char *str, info_t *f);
#endif
