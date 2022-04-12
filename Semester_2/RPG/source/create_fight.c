/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_fight
*/

#include "struct.h"

static sfTexture **init_texture(void)
{
    sfTexture **texture = {0};

    texture = malloc(sizeof(sfTexture *) * 2);
    texture[0] = sfTexture_createFromFile("./sprites/fight/fight_1.png", NULL);
    texture[1] = sfTexture_createFromFile("./sprites/fight/fight_2.png", NULL);
    return texture;
}

static sfRectangleShape *init_fight(sfTexture *texture)
{
    sfRectangleShape *fight = sfRectangleShape_create();
    sfVector2f position = {500, 900};
    sfVector2f size = {900, 100};

    sfRectangleShape_setPosition(fight, position);
    sfRectangleShape_setSize(fight, size);
    sfRectangleShape_setTexture(fight, texture, sfFalse);
    sfRectangleShape_setOutlineThickness(fight, 6);
    sfRectangleShape_setOutlineColor(fight, sfColor_fromRGB(100, 100, 100));
    return fight;
}

int create_fight(info_t *info)
{
    sfRectangleShape **fight = {0};
    sfTexture **texture = init_texture();

    fight = malloc(sizeof(sfRectangleShape *) * 2);
    fight[0] = init_fight(texture[0]);
    fight[1] = init_fight(texture[1]);
    info->fight = fight;
    return 0;
}