/*
** EPITECH PROJECT, 2020
** map.h
** File description:
** header
*/

#ifndef MAP_H
#define MAP_H

typedef struct map_t {
    char **map_player;
    char **map_enemy;
    int shipe;
    int is_win;
    char *win_cord;
} map_t;
#endif
