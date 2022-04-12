/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_dragon
*/

#include "struct.h"
#include "read.h"

static sfRectangleShape *init_orque(sfTexture *texture, sfVector2f position)
{
    sfRectangleShape *orque = sfRectangleShape_create();
    sfVector2f size = {300, 300};

    sfRectangleShape_setPosition(orque, position);
    sfRectangleShape_setSize(orque, size);
    sfRectangleShape_setTexture(orque, texture, sfFalse);
    return orque;
}

static sfRectangleShape *init_spell(sfTexture *texture, sfVector2f position)
{
    sfRectangleShape *spell = sfRectangleShape_create();
    sfVector2f size = {300, 300};

    sfRectangleShape_setPosition(spell, position);
    sfRectangleShape_setSize(spell, size);
    sfRectangleShape_setTexture(spell, texture, sfFalse);
    return spell;
}

static sfTexture **init_texture(void)
{
    sfTexture **texture = {0};

    texture = malloc(sizeof(sfTexture *) * 3);
    texture[0] = sfTexture_createFromFile("sprites/ennemy/orque/mouv/mouv (3).png", NULL);
    texture[1] = sfTexture_createFromFile("sprites/ennemy/orque/attack/attack (3).png", NULL);
    texture[2] = sfTexture_createFromFile("sprites/ennemy/orque/attack/attack (4).png", NULL);
    return texture;
}

int create_dragon(info_t *info)
{
    ennemy_t dragon = {0};
    sfTexture **texture = init_texture();
    sfVector2f position = {200, 500};
    int *tab = {0};

    dragon.ennemy = init_orque(texture[0], position);
    dragon.spell = malloc(sizeof(sfRectangleShape *) * 2);
    for (int i = 0; i < 2; ++i)
        dragon.spell[i] = init_spell(texture[i + 1], position);
    tab = read_cfg(2);
    dragon.atq_phy = tab[0];
    dragon.atq_spe = tab[1];
    dragon.def_phy = tab[2];
    dragon.def_spe = tab[3];
    dragon.hp = tab[4];
    info->dragon = dragon;
    return 0;
}