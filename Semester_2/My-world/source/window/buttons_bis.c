/*
** EPITECH PROJECT, 2021
** buttons_bis.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

static void modif_down(info_t *info)
{
    if (info->size_map[0] >= 3 && info->size_map[1] >= 3) {
        info->map = rezize_map_down(info, info->map);
        info->map_modif = create_2d_map(info->map, info);
        info->shape = create_tab_convex(info, info->map_modif);
    }
}

static void modif_up(info_t *info)
{
    info->map = rezize_map_up(info, info->map);
    info->map_modif = create_2d_map(info->map, info);
    info->shape = create_tab_convex(info, info->map_modif);
}

void set_plus_button(info_t *info)
{
    sfRectangleShape *button = sfRectangleShape_create();

    if (info->mouse_actions.plus == 1) {
        sfRectangleShape_setPosition(button, (sfVector2f) {-940, 400});
        sfRectangleShape_setTexture(button, set_plus_clicked_button(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
        info->mouse_actions.plus = 0;
        modif_up(info);
    }
    else {
        sfRectangleShape_setPosition(button, (sfVector2f) {-940, 400});
        sfRectangleShape_setTexture(button, set_plus_button_texture(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
    }
    display_button(button, info);
    if (info->mouse_actions.plus == 2)
        print_plus_info(info);
    info->mouse_actions.plus = 0;
}

void set_less_button(info_t *info)
{
    sfRectangleShape *button = sfRectangleShape_create();

    if (info->mouse_actions.less == 1) {
        sfRectangleShape_setPosition(button, (sfVector2f) {-795, 410});
        sfRectangleShape_setTexture(button, set_less_clicked_button(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
        info->mouse_actions.less = 0;
        modif_down(info);
    }
    else {
        sfRectangleShape_setPosition(button, (sfVector2f) {-820, 400});
        sfRectangleShape_setTexture(button, set_less_button_texture(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {120, 130});
    }
    display_button(button, info);
    if (info->mouse_actions.less == 2)
        print_less_info(info);
    info->mouse_actions.less = 0;
}
