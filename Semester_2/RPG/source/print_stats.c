/*
** EPITECH PROJECT, 2021
** print_stats.c
** File description:
** functions
*/

#include "hero.h"
#include "print_stats.h"

static int load_hp_max(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/hp_max.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1590, 680});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1630, 686},
                     hero_status->actual_stats[0], hero_status->stats[0][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

static int load_phys_atq(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/phys_attack.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1590, 710});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1630, 716},
                     hero_status->actual_stats[4], hero_status->stats[4][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

static int load_magic_atq(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/magic_power.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1590, 740});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1630, 746},
                     hero_status->actual_stats[5], hero_status->stats[5][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

static int load_phys_armor(info_t *info, hero_status_t *hero_status)
{
    sfRectangleShape *stat =  sfRectangleShape_create();
    sfTexture *t_stat =
        sfTexture_createFromFile("./sprites/stats/phys_armor.png", NULL);

    sfRectangleShape_setTexture(stat, t_stat, sfTrue);
    sfRectangleShape_setPosition(stat, (sfVector2f) {1735, 680});
    sfRectangleShape_setSize(stat, (sfVector2f) {30, 30});
    sfRenderWindow_drawRectangleShape(info->window, stat, NULL);
    load_stats_value(info, (sfVector2f) {1775, 686},
                     hero_status->actual_stats[6], hero_status->stats[6][0]);
    sfRectangleShape_destroy(stat);
    sfTexture_destroy(t_stat);
    return 0;
}

int print_stats(info_t *info, hero_status_t *hero_status)
{
    load_hp_max(info, hero_status);
    load_phys_atq(info, hero_status);
    load_magic_atq(info, hero_status);
    load_phys_armor(info, hero_status);
    load_magic_armor(info, hero_status);
    load_speed(info, hero_status);
    return 0;
}
