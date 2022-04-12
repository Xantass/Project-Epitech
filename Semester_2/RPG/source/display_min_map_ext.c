/*
** EPITECH PROJECT, 2021
** display_min_map_ext.c
** File description:
** functions
*/

#include "hero.h"

void print_map(info_t *info, char *path)
{
    sfRectangleShape *map = sfRectangleShape_create();
    sfTexture *t_map =
        sfTexture_createFromFile(path, NULL);

    sfRectangleShape_setTexture(map, t_map, sfTrue);
    sfRectangleShape_setPosition(map, (sfVector2f) {100, 400});
    sfRectangleShape_setSize(map, (sfVector2f) {650, 650});
    sfRectangleShape_setOutlineThickness(map, 6);
    sfRectangleShape_setOutlineColor(map, sfColor_fromRGB(100, 100, 100));
    sfRenderWindow_drawRectangleShape(info->window, map, NULL);
    sfRectangleShape_destroy(map);
    sfTexture_destroy(t_map);
}

int display_ext_map(info_t *info)
{
    static float last_mod = 0;
    static int is_pressed = -1;

    if (sfKeyboard_isKeyPressed(sfKeyW) && last_mod + (0.2) <= info->times) {
        is_pressed *= -1;
        last_mod = info->times;
    }
    if (is_pressed == 1)
        print_map(info, "./sprites/Get_map/map_ext.png");
    return 0;
}
