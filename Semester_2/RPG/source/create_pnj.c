/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_pnj
*/

#include "struct.h"

static sfRectangleShape *init_pnj(sfVector2f position, sfTexture *texture)
{
    sfRectangleShape *pnj = sfRectangleShape_create();
    sfVector2f size = {50, 50};

    sfRectangleShape_setPosition(pnj, position);
    sfRectangleShape_setSize(pnj, size);
    sfRectangleShape_setTexture(pnj, texture, sfFalse);
    return pnj;
}

static sfVector2f *init_position(void)
{
    sfVector2f *position = {0};

    position = malloc(sizeof(sfVector2f) * 4);
    position[0].x = 485;
    position[0].y = 280;
    position[1].x = 142;
    position[1].y = 518;
    position[2].x = 1700;
    position[2].y = 70;
    position[3].x = 1860;
    position[3].y = 910;
    return position;
}

static sfTexture **init_texture(void)
{
    sfTexture **texture = {0};

    texture = malloc(sizeof(sfTexture *) * 4);

    texture[0] = sfTexture_createFromFile("sprites/pnj/pnj.png", NULL);
    texture[1] = sfTexture_createFromFile("sprites/pnj/pnj_1.png", NULL);
    texture[2] = sfTexture_createFromFile("sprites/pnj/pnj_2.png", NULL);
    texture[3] = sfTexture_createFromFile("sprites/pnj/pnj_3.png", NULL);
    return texture;
}

int create_pnj(info_t *info)
{
    sfRectangleShape **pnj = {0};
    sfVector2f *position = init_position();
    sfTexture **texture = init_texture();

    pnj = malloc(sizeof(sfRectangleShape *) * 4);
    for (int i = 0; i < 4; ++i)
        pnj[i] = init_pnj(position[i], texture[i]);
    info->pnj = pnj;
    info->position_pnj = position;
    return 0;
}