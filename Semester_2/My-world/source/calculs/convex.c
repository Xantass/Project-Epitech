/*
** EPITECH PROJECT, 2021
** convex.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"

static sfConvexShape **alloc_tab_convex(info_t *info)
{
    int size = (info->size_map[0] - 1) * (info->size_map[1] - 1);
    sfConvexShape **shape = malloc(sizeof(sfConvexShape *) * size);

    return shape;
}

static sfConvexShape *create_convex(sfVector2f **point, int i, int j,
                                    sfVector2f **init)
{
    sfConvexShape *shape = sfConvexShape_create();
    sfTexture *texture = sfTexture_createFromFile("textures/convex/herbe.png", NULL);

    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, point[i][j]);
    sfConvexShape_setPoint(shape, 1, point[i][j + 1]);
    sfConvexShape_setPoint(shape, 2, point[i + 1][j + 1]);
    sfConvexShape_setPoint(shape, 3, point[i + 1][j]);
    init[i][j].x = init[i][j].x / 30;
    init[i][j].y = init[i][j].y / 30;
    sfConvexShape_setPosition(shape, init[i][j]);
    sfConvexShape_setTexture(shape, texture, sfTrue);
    //sfConvexShape_setFillColor(shape, sfGreen);
    //sfConvexShape_setOutlineThickness(shape, 1);
    //sfConvexShape_setOutlineColor(shape, sfWhite);
    return shape;
}

sfConvexShape **create_tab_convex(info_t *info, sfVector2f **point)
{
    sfConvexShape **shape = alloc_tab_convex(info);
    int h = 0;

    for (int i = 0; i != info->size_map[0] - 1; i++) {
        for (int j = 0; j != info->size_map[1] - 1; j++) {
            shape[h] = create_convex(point, i, j, info->map_zero);
            h++;
        }
    }
    return shape;
}
