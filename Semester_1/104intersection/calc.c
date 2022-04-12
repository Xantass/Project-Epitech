/*
** EPITECH PROJECT, 2020
** calc.c
** File description:
** function
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "proto.h"

double discriminant(double a, double b, double c)
{
    double dis = 0;

    dis = (pow(b, 2)) - (4 * a * c);
    return dis;
}

int nb_soluce(double a, double b, double c)
{
    double dis = discriminant(a, b, c);
    
    if (dis > 0)
        return 2;
    if (dis == 0)
        return 1;
    else
        return 0;
    return 0;
}

void calc_point_l(point_p p, vecteur_t v, double t)
{
    point_l l = {0};

    l.x = p.x + t * v.x;
    l.y = p.y + t * v.y;
    l.z = p.z + t * v.z;
    printf("(%.3f, %.3f, %.3f)\n", l.x, l.y, l.z);
}
