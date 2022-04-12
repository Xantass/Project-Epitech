/*
** EPITECH PROJECT, 2021
** get_rand.c
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

unsigned int get_random_pos_int(void)
{
    return  rand() % 2;
}
