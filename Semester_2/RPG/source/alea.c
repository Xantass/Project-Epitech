/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** alea
*/

#include <stdlib.h>
#include "struct.h"
#include "hero.h"

int handle_clock(info_t *info);

static int choose_spell(info_t *info, ennemy_t *ennemy,
                        hero_status_t *hero_status)
{
    static float last_mod = 0;

    last_mod = info->times;
    while (last_mod +(1) >= info->times)
        handle_clock(info);
    while (1) {
        if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
            ennemy->hp = ennemy->hp - hero_status->actual_stats[4];
            return 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
            return 0;
        }
    }
    hero_status->actual_stats = hero_status->actual_stats - ennemy->atq_phy;
    return 0;
}

static int input(info_t *info, ennemy_t *ennemy,
                 hero_status_t *hero_status, sfRectangleShape *player)
{
    while (1) {
        handle_clock(info);
        sfRenderWindow_drawRectangleShape
        (info->window,info->fight[1],NULL);
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
        sfRenderWindow_drawRectangleShape
        (info->window, info->node_act->map[1],NULL);
        sfRenderWindow_drawRectangleShape(info->window, player, NULL);
        sfRenderWindow_drawRectangleShape
        (info->window,ennemy->ennemy,NULL);
        if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
            choose_spell(info, ennemy, hero_status);
            return 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyNum2))
            return -1;
    }
    return 0;
}

static int fight(info_t *info, ennemy_t ennemy,
                 hero_status_t *hero_status)
{
    sfVector2f position = {1600, 600};
    sfVector2f size = {200, 200};
    sfRectangleShape *player = sfRectangleShape_copy(info->player[4][1]);
    static float last_mod = 0;

    last_mod = info->times;
    sfRectangleShape_setPosition(player, position);
    sfRectangleShape_setSize(player, size);
    while (ennemy.hp > 0 && hero_status->actual_stats[0] > 0) {
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
        sfRenderWindow_drawRectangleShape
        (info->window, info->node_act->map[1],NULL);
        sfRenderWindow_drawRectangleShape(info->window, player, NULL);
        sfRenderWindow_drawRectangleShape
        (info->window,ennemy.ennemy,NULL);
        sfRenderWindow_drawRectangleShape
        (info->window, info->fight[0], NULL);
        handle_clock(info);
        if (last_mod +(1)<=info->times) {
            input(info, &ennemy, hero_status, player);
            last_mod = info->times;
        }
    }
    hero_status->actual_stats[2] = hero_status->actual_stats[2] + 30;
    return 0;
}

static int choose(info_t *info,
                  hero_status_t *hero_status)
{
    if (info->node_map <= 7)
        fight(info, info->orque, hero_status);
    if (info->node_map == 8)
        fight(info, info->dragon, hero_status);
    if (info->node_map == 9)
        fight(info, info->boss, hero_status);
    return 0;
}

int alea(info_t *info,
         hero_status_t *hero_status)
{
    int nb = 0;

    nb = rand();
    while (nb > 100)
        nb = nb / 10;
    if (nb == 36) {
        choose(info, hero_status);
    }
    return 0;
}
