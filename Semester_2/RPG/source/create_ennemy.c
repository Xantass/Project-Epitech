/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_ennemy
*/

#include "struct.h"

static sfRectangleShape *init_ennemy(sfVector2f position, sfTexture *texture)
{
    sfRectangleShape *ennemy = sfRectangleShape_create();
    sfVector2f size = {50, 50};
    sfRectangleShape_setSize(ennemy, size);
    sfRectangleShape_setPosition(ennemy, position);
    sfRectangleShape_setTexture(ennemy, texture, sfFalse);
    return ennemy;
}

static sfTexture **init_texture_bis(sfTexture **texture)
{
    texture[17] = sfTexture_createFromFile("sprites/ennemy/die/die (4).png", NULL);
    texture[18] = sfTexture_createFromFile("sprites/ennemy/attack/attack (7).png", NULL);
    texture[19] = sfTexture_createFromFile("sprites/ennemy/attack/attack (8).png", NULL);
    return texture;
}

static sfTexture **init_texture(void)
{
    sfTexture **texture = {0};

    texture = malloc(sizeof(sfTexture *) * 20);
    texture[0] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (1).png", NULL);
    texture[1] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (2).png", NULL);
    texture[2] = sfTexture_createFromFile("sprites/ennemy/die/die (1).png", NULL);
    texture[3] = sfTexture_createFromFile("sprites/ennemy/attack/attack (1).png", NULL);
    texture[4] = sfTexture_createFromFile("sprites/ennemy/attack/attack (2).png", NULL);
    texture[5] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (3).png", NULL);
    texture[6] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (4).png", NULL);
    texture[7] = sfTexture_createFromFile("sprites/ennemy/die/die (2).png", NULL);
    texture[8] = sfTexture_createFromFile("sprites/ennemy/attack/attack (3).png", NULL);
    texture[9] = sfTexture_createFromFile("sprites/ennemy/attack/attack (4).png", NULL);
    texture[10] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (5).png", NULL);
    texture[11] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (6).png", NULL);
    texture[12] = sfTexture_createFromFile("sprites/ennemy/die/die (3).png", NULL);
    texture[13] = sfTexture_createFromFile("sprites/ennemy/attack/attack (5).png", NULL);
    texture[14] = sfTexture_createFromFile("sprites/ennemy/attack/attack (6).png", NULL);
    texture[15] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (7).png", NULL);
    texture[16] = sfTexture_createFromFile("sprites/ennemy/mouv/mouv (8).png", NULL);
    return init_texture_bis(texture);
}

sfRectangleShape ***create_ennemy(info_t *info, sfVector2f position)
{
    sfRectangleShape ***ennemy = {0};
    sfTexture **texture = init_texture();
    int k = 0;

    ennemy = malloc(sizeof(sfRectangleShape **) * 4);
    for (int i = 0; i < 4; ++i)
        ennemy[i] = malloc(sizeof(sfRectangleShape *) * 5);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            ennemy[i][j] = init_ennemy(position, texture[k]);
            k++;
        }
    }
    return ennemy;
}