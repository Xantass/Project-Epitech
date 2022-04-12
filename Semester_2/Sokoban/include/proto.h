/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** function
*/

#ifndef PROTO_H
#define PROTO_H

list_t *init(int *cor, char c, list_t *list);
void inser_front(list_t *list, int *cor, char c);
void inser_back(list_t *list, int *cor, char c);
void sup_front(list_t *list);
void print_list(list_t *list);
#endif
