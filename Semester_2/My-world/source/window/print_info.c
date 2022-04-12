/*
** EPITECH PROJECT, 2021
** print_info.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

void print_up_info(info_t *info)
{
    sfText *my_text = sfText_create();

    display_cadre(info, (sfVector2f) {-940, -500});
    sfText_setPosition(my_text, (sfVector2f) {-940, -400});
    sfText_setCharacterSize(my_text, 25);
    sfText_setColor(my_text, sfColor_fromRGB(0, 0, 170));
    sfText_setString(my_text, "To raise the pre-selected zone");
    sfText_setFont(my_text, set_font());
    sfRenderWindow_drawText(info->window, my_text, NULL);
}

void print_down_info(info_t *info)
{
    sfText *my_text = sfText_create();

    display_cadre(info, (sfVector2f) {-820, -500});
    sfText_setPosition(my_text, (sfVector2f) {-820, -400});
    sfText_setCharacterSize(my_text, 25);
    sfText_setColor(my_text, sfColor_fromRGB(0, 0, 170));
    sfText_setString(my_text, "To decrease the pre-selected zone");
    sfText_setFont(my_text, set_font());
    sfRenderWindow_drawText(info->window, my_text, NULL);
}

void print_resize_info(info_t *info)
{
     sfText *my_text = sfText_create();

     display_cadre(info, (sfVector2f) {-700, -500});
     sfText_setPosition(my_text, (sfVector2f) {-700, -400});
     sfText_setCharacterSize(my_text, 25);
     sfText_setColor(my_text, sfColor_fromRGB(0, 0, 170));
     sfText_setString(my_text, "To set the pre-selected zone to\nthe same height");
     sfText_setFont(my_text, set_font());
     sfRenderWindow_drawText(info->window, my_text, NULL);
}

void print_plus_info(info_t *info)
{
     sfText *my_text = sfText_create();

     display_cadre(info, (sfVector2f) {-940, 400});
     sfText_setPosition(my_text, (sfVector2f) {-940, 300});
     sfText_setCharacterSize(my_text, 25);
     sfText_setColor(my_text, sfColor_fromRGB(0, 0, 170));
     sfText_setString(my_text, "To add one line and one column\nto the map size");
     sfText_setFont(my_text, set_font());
     sfRenderWindow_drawText(info->window, my_text, NULL);
}

void print_less_info(info_t *info)
{
     sfText *my_text = sfText_create();

     display_cadre(info, (sfVector2f) {-820, 400});
     sfText_setPosition(my_text, (sfVector2f) {-820, 300});
     sfText_setCharacterSize(my_text, 25);
     sfText_setColor(my_text, sfColor_fromRGB(0, 0, 170));
     sfText_setString(my_text, "To remove one line and one column\nto the map size");
     sfText_setFont(my_text, set_font());
     sfRenderWindow_drawText(info->window, my_text, NULL);
}
