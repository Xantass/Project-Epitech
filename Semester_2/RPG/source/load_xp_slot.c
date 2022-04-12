/*
** EPITECH PROJECT, 2021
** load_xp_slots.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "hero.h"
#include "lib.h"

static void get_xp(info_t *info, hero_status_t *hero_status)
{
    sfText *text = sfText_create();
    char *str = my_calloc(sizeof(char), (30) + 1);
    sfFont *font = sfFont_createFromFile("./Font/stats_font.ttf");

    str = my_strcpy(str, "LVL: ");
    str = my_strcat(str, trans(hero_status->actual_stats[3]));
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfGreen);
    sfText_setPosition(text, (sfVector2f) {30, 210});
    sfRenderWindow_drawText(info->window, text, NULL);
    sfFont_destroy(font);
    free(str);
    sfText_destroy(text);
}

int load_xp_slot(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *xp_s = sfRectangleShape_create();
    sfTexture *xp_t =
        sfTexture_createFromFile("./sprites/status_bar/xp_slot.png", NULL);

    sfRectangleShape_setTexture(xp_s, xp_t, sfTrue);
    sfRectangleShape_setPosition(xp_s, (sfVector2f) {0, 195});
    sfRectangleShape_setSize(xp_s, (sfVector2f) {165, 55});
    sfRenderWindow_drawRectangleShape(info->window, xp_s, NULL);
    get_xp(info, hero_status);
    sfRectangleShape_destroy(xp_s);
    sfTexture_destroy(xp_t);
    return 0;
}
