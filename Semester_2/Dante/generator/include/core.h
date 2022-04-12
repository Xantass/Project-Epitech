/*
** EPITECH PROJECT, 2021
** core.h
** File description:
** functions
*/

#ifndef CORE_H
#define CORE_H

char **alloc_map(vector_2ui size);
void print_map(char **map, vector_2ui size);
int init_map(char **map, vector_2ui size);
void init_perfect_maze(char **maze, vector_2ui *size);

#endif
