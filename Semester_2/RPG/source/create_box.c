/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_box
*/

#include "struct.h"

static sfVector2f *init_position(void)
{
    sfVector2f *position = {0};

    position = malloc(sizeof(position) * 5);
    position[0].x = 435;
    position[0].y = 210;
    position[1].x = 435;
    position[1].y = 190;
    position[2].x = 32;
    position[2].y = 448;
    position[3].x = 1220;
    position[3].y = -10;
    position[4].x = 1230;
    position[4].y = 840;
    return position;
}

static sfVector2f *init_size(void)
{
    sfVector2f *size = {0};

    size = malloc(sizeof(sfVector2f) * 5);
    size[0].x = 600;
    size[0].y = 80;
    size[1].x = 480;
    size[1].y = 90;
    size[2].x = 1050;
    size[2].y = 80;
    size[3].x = 700;
    size[3].y = 90;
    size[4].x = 710;
    size[4].y = 80;
    return size;
}

static sfRectangleShape *init_box(sfTexture *texture, 
                                  sfVector2f position, sfVector2f size)
{
    sfRectangleShape *box = sfRectangleShape_create();

    sfRectangleShape_setPosition(box, position);
    sfRectangleShape_setTexture(box, texture, sfFalse);
    sfRectangleShape_setSize(box, size);
    return box;
}

int create_box(info_t *info)
{
    sfRectangleShape **box = {0};
    sfVector2f *position = init_position();
    sfVector2f *size = init_size();
    sfTexture *texture=sfTexture_createFromFile("sprites/dialog/box.png",NULL);

    box = malloc(sizeof(sfRectangleShape *) * 5);
    for (int i = 0; i < 5; ++i)
        box[i] = init_box(texture, position[i], size[i]);
    info->box = box;
    return 0;
}