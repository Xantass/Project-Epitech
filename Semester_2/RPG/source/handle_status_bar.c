/*
** EPITECH PROJECT, 2021
** handle_status_bar.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

static void load_status_bar(info_t *info)
{
    sfRectangleShape *status_bar = sfRectangleShape_create();
    sfTexture *t_status_bar =
        sfTexture_createFromFile("./sprites/status_bar/status_bar.png", NULL);
    sfRectangleShape_setTexture(status_bar, t_status_bar, 0);
    sfRectangleShape_setPosition(status_bar, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(status_bar, (sfVector2f) {650, 180});
    sfRenderWindow_drawRectangleShape(info->window, status_bar, NULL);
    sfRectangleShape_destroy(status_bar);
    sfTexture_destroy(t_status_bar);
}

static void load_hp_bar(info_t *info, hero_status_t *hero_status)
{
    float div = (float) hero_status->stats[0][0];
    float size = 342 * (hero_status->actual_stats[0] / div);
    sfRectangleShape *hp_bar = sfRectangleShape_create();
    sfTexture *t_hp_bar =
        sfTexture_createFromFile("./sprites/status_bar/red_bar.png", NULL);
    sfRectangleShape_setTexture(hp_bar, t_hp_bar, 0);
    sfRectangleShape_setPosition(hp_bar, (sfVector2f) {238, 21});
    sfRectangleShape_setSize(hp_bar, (sfVector2f) {size, 40});
    sfRenderWindow_drawRectangleShape(info->window, hp_bar, NULL);
    sfRectangleShape_destroy(hp_bar);
    sfTexture_destroy(t_hp_bar);
}

static void load_end_bar(info_t *info, hero_status_t *hero_status)
{
    float div = 100;
    float size = 335 * (hero_status->actual_stats[1] / div);
    sfRectangleShape *end_bar = sfRectangleShape_create();
    sfTexture *t_end_bar =
        sfTexture_createFromFile("./sprites/status_bar/green_bar.png", NULL);
    sfRectangleShape_setTexture(end_bar, t_end_bar, 0);
    sfRectangleShape_setPosition(end_bar, (sfVector2f) {238, 74});
    sfRectangleShape_setSize(end_bar, (sfVector2f) {size, 32});
    sfRenderWindow_drawRectangleShape(info->window, end_bar, NULL);
    sfRectangleShape_destroy(end_bar);
    sfTexture_destroy(t_end_bar);
}

static void load_xp_bar(info_t *info, hero_status_t *hero_status)
{
    float div = (float) hero_status->max_xp;
    float size = 335 * (hero_status->actual_stats[2] / div);
    sfRectangleShape *xp_bar = sfRectangleShape_create();
    sfTexture *t_xp_bar =
        sfTexture_createFromFile("./sprites/status_bar/blue_bar.png", NULL);
    sfRectangleShape_setTexture(xp_bar, t_xp_bar, 0);
    sfRectangleShape_setPosition(xp_bar, (sfVector2f) {238, 127});
    sfRectangleShape_setSize(xp_bar, (sfVector2f) {size, 32});
    sfRenderWindow_drawRectangleShape(info->window, xp_bar, NULL);
    sfRectangleShape_destroy(xp_bar);
    sfTexture_destroy(t_xp_bar);
}

int handle_status_bar(info_t *info, hero_status_t *hero_status)
{
    load_status_bar(info);
    load_hp_bar(info, hero_status);
    load_end_bar(info, hero_status);
    load_xp_bar(info, hero_status);
    return 0;
}
