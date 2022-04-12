/*
** EPITECH PROJECT, 2021
** compute_map.c
** File description:
** functions
*/

#include <stdio.h>
#include "graph.h"
#include "my.h"

sfVector2f translations(sfVector2f point);

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point = {0};

    point.x = cos(45) * x - cos(45) * y;
    point.y = (sin(35) * y + sin(35) * x) - z;
    point.x = point.x * 40 + x;
    point.y = point.y * 40 + y;
    return point;
}
