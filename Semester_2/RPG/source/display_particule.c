/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** display_particule
*/

#include "struct.h"

int display_lava_one(info_t *info)
{
    static int node = 0;
    sfVector2f position = {308, 600};

    info->anim.time = sfClock_getElapsedTime(info->anim.clock);
    info->anim.times = sfTime_asSeconds(info->anim.time);
    if (info->anim.times > 0.10) {
        sfClock_restart(info->anim.clock);
        node++;
        info->position_lava.y = info->position_lava.y - 5;
    }
    if (node > 11) {
        node = 0;
        info->position_lava = position;
    }
    sfRectangleShape_setPosition(info->lava[node], info->position_lava);
    sfRenderWindow_drawRectangleShape(info->window, info->lava[node], NULL);
    return 0;
}

int display_lava_two(info_t *info)
{
    static int node = 0;
    sfVector2f position = {1440, 600};

    info->anim_.time = sfClock_getElapsedTime(info->anim_.clock);
    info->anim_.times = sfTime_asSeconds(info->anim_.time);
    if (info->anim_.times > 0.10) {
        sfClock_restart(info->anim_.clock);
        node++;
        info->position_lava_.y = info->position_lava_.y - 5;
    }
    if (node > 11) {
        node = 0;
        info->position_lava_ = position;
    }
    sfRectangleShape_setPosition(info->lava_[node], info->position_lava_);
    sfRenderWindow_drawRectangleShape(info->window, info->lava_[node], NULL);
    return 0;
}

int display_cloud(info_t *info)
{
    sfVector2f offset = {1, 0};
    sfVector2f position = {0};
    sfVector2f origin = {-200, -60};
    static float last_mod = 0;

    if(last_mod +(0.01)<=info->times) {
        last_mod = info->times;
        sfRectangleShape_move (info->cloud, offset);
        position = sfRectangleShape_getPosition(info->cloud);
        if (position.x > 1940)
            sfRectangleShape_setPosition(info->cloud, origin);
    }
    sfRenderWindow_drawRectangleShape(info->window, info->cloud, NULL);
    return 0;
}

int display_cloud_bis(info_t *info)
{
    sfVector2f offset = {-1, 0};
    sfVector2f position = {0};
    sfVector2f origin = {1940, 40};
    static float last_mod = 0;

    if(last_mod +(0.01)<=info->times) {
        last_mod = info->times;
        sfRectangleShape_move (info->cloud_, offset);
        position = sfRectangleShape_getPosition(info->cloud_);
        if (position.x < -200)
            sfRectangleShape_setPosition(info->cloud_, origin);
    }
    sfRenderWindow_drawRectangleShape(info->window, info->cloud_, NULL);
    return 0;
}