/*
** EPITECH PROJECT, 2021
** menu_particules.c
** File description:
** functions
*/

#include <stdio.h>
#include "struct.h"

static float get_rand(unsigned int limit)
{
    float res = rand() % limit;

    return res;
}

static void handle_circle(info_t *info)
{
    info->circle = sfCircleShape_create();
    sfCircleShape_setPosition(info->circle,
                              (sfVector2f) {get_rand(1920),
                                  get_rand(1080)});
    sfCircleShape_setRadius(info->circle, get_rand(50));
    sfCircleShape_setFillColor(info->circle,
                               sfColor_fromRGB((unsigned int)
                                               get_rand(250),
                                               (unsigned int)
                                               get_rand(250),
                                               (unsigned int)
                                               get_rand(250)));
}

int mouse_ptl(info_t *info)
{
    static float last_mod = 0;
    static int first_time = -1;

    if (last_mod + (0.3) <= info->times) {
        if (first_time == 1)
            sfCircleShape_destroy(info->circle);
        handle_circle(info);
        last_mod = info->times;
        first_time = 1;
    }
    else if (info->circle != NULL)
        sfRenderWindow_drawCircleShape(info->window, info->circle, NULL);
    return 0;
}
