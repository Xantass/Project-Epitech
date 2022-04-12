/*
** EPITECH PROJECT, 2021
** print_stats_bis.c
** File description:
** functions
*/

#include "print_stats_bis.h"
#include "hero.h"

int load_magic_armor(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/magic_armor.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1735, 710});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1775, 716},
                     hero_status->actual_stats[7], hero_status->stats[7][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

int load_speed(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/boots.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1735, 740});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1775, 746},
                     hero_status->actual_stats[8], hero_status->stats[8][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

