/*
** EPITECH PROJECT, 2021
** build_perfect_maze.h
** File description:
** header
*/

#ifndef BUILD_PERFECT_MAZE_H
#define BUILD_PERFECT_MAZE_H

void fill_line(char *line, vector_2ui size, char c);
void print_map(char **map, vector_2ui size);
void build_exit(char **map, vector_2ui *size);
void fill_perfect_maze(char **map, int i, int j);
void perfect_maze_following(char **map, int i, int j);
#endif
