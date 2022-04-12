/*
** EPITECH PROJECT, 2020
** move_ptr_to_next_nbr
** File description:
** azertyuioplkpo
*/

#include "my.h"

void move_ptr_to_next_op(char **str, char const *base)
{
    for (; **str == '-' || **str == '+' || **str == ' '; (*str)++);
    for (; my_char_isnum(**str, base) == 1; (*str)++);
}
