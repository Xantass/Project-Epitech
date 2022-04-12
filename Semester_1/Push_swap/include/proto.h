/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** function
*/

#ifndef PROTO_H
#define PROTO_H

void print_list(list *list_t);
void sup_front(list *list_t);
void inser_back(list *list_t, int new_nb);
void inser_front(list *list_t, int new_nb);
list *init(int nb, list *list_t);
#endif
