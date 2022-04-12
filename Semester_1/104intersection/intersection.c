/*
** EPITECH PROJECT, 2020
** intersection.c
** File description:
** function
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "proto.h"

int check_bis(char c)
{
    if (c == '-')
        return 0;
    if (c == '.')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

int check(char **argv)
{
    for (int i = 1; argv[i] != NULL; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (check_bis(argv[i][j]) == 1) {
                return 84;
            }
        }
    }
    return 0;
}

int init(point_p *p, vecteur_t *v, double *r, char **argv)
{
    if ((check(argv)) == 84)
        return 84;
    p->x = strtod(argv[2], '\0');
    p->y = strtod(argv[3], '\0');
    p->z = strtod(argv[4], '\0');
    v->x = strtod(argv[5], '\0');
    v->y = strtod(argv[6], '\0');
    v->z = strtod(argv[7], '\0');
    *r = strtod(argv[8], '\0');
    if (v->x == 0 && v->y == 0 && v->z == 0)
        return 84;
    return 0;
}

int choose(char **argv)
{
    point_p p = {0};
    vecteur_t v = {0};
    double r = 0;
    
    if (atoi(argv[1]) == 1) {
        if ((init(&p, &v, &r, argv)) == 84)
            return 84;
        sphere(p, v, r);
        return 0;
    }
    if (atoi(argv[1]) == 2) {
        if ((init(&p, &v, &r, argv)) == 84)
            return 84;
        cylinder(p, v, r);
        return 0;
    }
    if (atoi(argv[1]) == 3) {
        if ((init(&p, &v, &r, argv)) == 84)
            return 84;
        cone(p, v, r);
        return 0;
    }
    return 84;
}
