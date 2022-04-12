/*
** EPITECH PROJECT, 2021
** init_info.h
** File description:
** functions
*/

#ifndef INIT_INFO_H
#define INIT_INFO_H

int calloc_arena(info_t *info);
int init_info(info_t *info);
int set_address(info_t *info);
void set_bool(short int *bool_tab, unsigned int index);
int get_state(short int *bool_tab, unsigned int index);

#endif /* INIT_INFO_H */
