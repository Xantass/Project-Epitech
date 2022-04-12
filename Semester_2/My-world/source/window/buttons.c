/*
** EPITECH PROJECT, 2021
** buttons.c
** File description:
** fucntions
*/

#include "graph.h"
#include "my.h"

void display_button(sfRectangleShape *button, info_t *info)
{
    sfRenderWindow_drawRectangleShape(info->window, button, NULL);
}

static void set_raise_button(info_t *info)
{
    sfRectangleShape *button = sfRectangleShape_create();

    if (info->mouse_actions.up == 1) {
        sfRectangleShape_setPosition(button, (sfVector2f) {-950, -510});
        sfRectangleShape_setTexture(button, set_up_clicked_button(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {120, 120});
        info->mouse_actions.up = 0;
    }
    else {
        sfRectangleShape_setPosition(button, (sfVector2f) {-940, -500});
        sfRectangleShape_setTexture(button, set_raise_button_texture(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
    }
    display_button(button, info);
    if (info->mouse_actions.up == 2)
        print_up_info(info);
    info->mouse_actions.up = 0;
}

static void set_down_button(info_t *info)
{
    sfRectangleShape *button = sfRectangleShape_create();

    if (info->mouse_actions.down == 1) {
        sfRectangleShape_setPosition(button, (sfVector2f) {-820, -495});
        sfRectangleShape_setTexture(button, set_down_clicked_button(), 0);
        info->mouse_actions.down = 0;
    }
    else {
        sfRectangleShape_setPosition(button, (sfVector2f) {-820, -500});
        sfRectangleShape_setTexture(button, set_down_button_texture(), 0);
    }
    sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
    display_button(button, info);
    if (info->mouse_actions.down == 2)
        print_down_info(info);
    info->mouse_actions.down = 0;
}

static void set_resize_button(info_t *info)
{
    sfRectangleShape *button = sfRectangleShape_create();

    if (info->mouse_actions.resize == 1) {
        sfRectangleShape_setPosition(button, (sfVector2f) {-705, -500});
        sfRectangleShape_setTexture(button, set_resize_clicked_button(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {100, 100});
        info->mouse_actions.resize = 0;
    }
    else {
        sfRectangleShape_setPosition(button, (sfVector2f) {-700, -490});
        sfRectangleShape_setTexture(button, set_resize_button_texture(), 0);
        sfRectangleShape_setSize(button, (sfVector2f) {90, 80});
    }
    display_button(button, info);
    if (info->mouse_actions.resize == 2)
        print_resize_info(info);
    info->mouse_actions.resize = 0;
}

void set_buttons(info_t *info)
{
    set_raise_button(info);
    set_down_button(info);
    set_resize_button(info);
    set_plus_button(info);
    set_less_button(info);
}
