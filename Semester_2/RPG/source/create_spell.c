/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_spell
*/

#include "struct.h"

static sfTexture **init_texture(void)
{
    sfTexture **texture = {0};

    texture = malloc(sizeof(sfTexture *) * 5);
    texture[0] = 
    sfTexture_createFromFile("sprites/Character/spell/spell (1).png", NULL);
    texture[1] = 
    sfTexture_createFromFile("sprites/Character/spell/spell (2).png", NULL);
    texture[2] = 
    sfTexture_createFromFile("sprites/Character/spell/spell (3).png", NULL);
    texture[3] = 
    sfTexture_createFromFile("sprites/Character/spell/spell (4).png", NULL);
    texture[4] = 
    sfTexture_createFromFile("sprites/Character/spell/spell (5).png", NULL);
    return texture;
}

static sfRectangleShape *init_spell(sfTexture *texture)
{
    sfRectangleShape *spell = sfRectangleShape_create();
    sfVector2f size = {50, 50};

    sfRectangleShape_setSize(spell, size);
    sfRectangleShape_setTexture(spell, texture, sfFalse);
    return spell;
}

sfRectangleShape **create_spell(void)
{
    sfRectangleShape **spell = {0};
    sfTexture **texture = init_texture();

    spell = malloc(sizeof(sfRectangleShape *) * 5);
    for (int i = 0; i < 5; ++i)
        spell[i] = init_spell(texture[i]);
    return spell;
}