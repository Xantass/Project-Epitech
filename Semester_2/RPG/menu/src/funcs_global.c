/*
** EPITECH PROJECT, 2021
** funcs
** File description:
** funcs_global_csfml
*/

#include "settings.h"

sfSprite *crea_s(sfSprite *sprite)
{
    sprite = sfSprite_create();
    return sprite;
}

void crea_t(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
}

void draw(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void set_p(sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setPosition(sprite, pos);
}