/*
** EPITECH PROJECT, 2021
** load_locked_sprites.c
** File description:
** functions
*/

#include "hero.h"
#include "graph.h"

void load_locked_sprite(info_t *info, sfVector2f pos)
{
    sfRectangleShape *locked = sfRectangleShape_create();

    sfRectangleShape_setFillColor(locked, sfColor_fromRGBA(0, 0, 0 ,200));
    sfRectangleShape_setPosition(locked, pos);
    if (pos.x != 185 && pos.y != 392)
        sfRectangleShape_setSize(locked, (sfVector2f) {97, 87});
    else
        sfRectangleShape_setSize(locked, (sfVector2f) {143, 130});
    sfRenderWindow_drawRectangleShape(info->window, locked, NULL);
    sfRectangleShape_destroy(locked);
}

int get_locked_sprites(info_t *info, hero_status_t *hero_status)
{
    for (unsigned int i = 0; i < 4; i++) {
        if (hero_status->unlocked_skills[i][0] == 0)
            load_locked_sprite(info, hero_status->locked_skills_pos[i]);
    }
    return 0;
}

