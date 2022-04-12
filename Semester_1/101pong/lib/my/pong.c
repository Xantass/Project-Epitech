/*
** EPITECH PROJECT, 2020
** pong.c
** File description:
** function
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pong.h"

void intia_pos0(char **argv, struct conste *one)
{
    one->x = atof(argv[1]);
    one->y = atof(argv[2]);
    one->z = atof(argv[3]);
}

void intia_pos1(char **argv, struct conste *two)
{
    two->x = atof(argv[4]);
    two->y = atof(argv[5]);
    two->z = atof(argv[6]);
}

void intia_vecvelo(struct conste *velocity, struct conste *one,
                 struct conste *two)
{
    velocity->x = (two->x) - (one->x);
    velocity->y = (two->y) - (one->y);
    velocity->z = (two->z) - (one->z);
}

void intia_vecf(struct conste *f, struct conste *one,
                 struct conste *two)
{
    f->x = (two->x) - (one->x);
    f->y = (two->y) - (one->y);
    f->z = (two->z) - (one->z);
}

float norm(struct conste *velocity)
{
    float res_norm = 0;
    float dx = 0;
    float dy = 0;
    float dz = 0;

    dx = (velocity->x * velocity->x);
    dy = (velocity->y * velocity->y);
    dz = (velocity->z * velocity->z);
    res_norm = sqrtf(dx + dy + dz);
    return res_norm;
}
