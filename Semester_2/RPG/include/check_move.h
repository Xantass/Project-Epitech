/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** check_move
*/

#ifndef CHECK_MOVE_H_
#define CHECK_MOVE_H_

#include "struct.h"

int check_map_zero(info_t *info, float x, float y);
int check_map_one(info_t *info, float x, float y);
int check_map_two(info_t *info, float x, float y);
int check_map_three(info_t *info, float x, float y);
int check_map_four(info_t *info, float x, float y);
int check_map_five(info_t *info, float x, float y);
int check_map_six(info_t *info, float x, float y);
int check_map_seven(info_t *info, float x, float y);
int check_map_height(info_t *info, float x, float y);

typedef struct map_t {
    int nb;
    int (*my)(info_t *info, float x, float y);
} map_t;

map_t check_map [9] = {
    {0, check_map_zero},
    {1, check_map_one},
    {2, check_map_two},
    {3, check_map_three},
    {4, check_map_four},
    {5, check_map_five},
    {6, check_map_six},
    {7, check_map_seven},
    {8, check_map_height},
};
#endif /* !CHECK_MOVE_H_ */
