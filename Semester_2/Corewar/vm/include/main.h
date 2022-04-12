/*
** EPITECH PROJECT, 2021
** main.h
** File description:
** header
*/

#ifndef MAIN_H
#define MAIN_H

#include "info.h"

int handle_args(int argc, char *argv[], info_t *info);
int free_info(info_t *info);
int core(info_t *info);

#endif
