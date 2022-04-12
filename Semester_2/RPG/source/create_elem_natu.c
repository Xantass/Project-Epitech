/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_elem_natu
*/

#include "struct.h"

int create_cloud(info_t *info)
{
    sfRectangleShape *cloud = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile
    ("sprites/element/cloud.png", NULL);
    sfVector2f position = {-200, -60};
    sfVector2f size = {200, 200};

    sfRectangleShape_setPosition(cloud, position);
    sfRectangleShape_setTexture(cloud, texture, sfFalse);
    sfRectangleShape_setSize(cloud, size);
    info->cloud = cloud;
    position.x = 1940;
    position.y = 40;
    info->cloud_ = sfRectangleShape_copy(info->cloud);
    sfRectangleShape_setPosition(info->cloud_, position);
    return 0;
}

static char **init_str(void)
{
    char **str = malloc(sizeof(char *) * 12);

    str[0] = "sprites/element/lava_part_0.png";
    str[1] = "sprites/element/lava_part_1.png";
    str[2] = "sprites/element/lava_part_2.png";
    str[3] = "sprites/element/lava_part_3.png";
    str[4] = "sprites/element/lava_part_4.png";
    str[5] = "sprites/element/lava_part_5.png";
    str[6] = "sprites/element/lava_part_6.png";
    str[7] = "sprites/element/lava_part_7.png";
    str[8] = "sprites/element/lava_part_8.png";
    str[9] = "sprites/element/lava_part_9.png";
    str[10] = "sprites/element/lava_part_10.png";
    str[11] = "sprites/element/lava_part_11.png";
    return str;
}

static sfRectangleShape *init(sfTexture *texture, sfVector2f position)
{
    sfRectangleShape *lava = sfRectangleShape_create();
    sfVector2f size = {70, 70};

    sfRectangleShape_setPosition(lava, position);
    sfRectangleShape_setSize(lava, size);
    sfRectangleShape_setTexture(lava, texture, sfFalse);
    sfRectangleShape_rotate(lava, -90);
    return lava;
}

int create_lava_projectile_one(info_t *info)
{
    sfTexture **textures = {0};
    sfRectangleShape **lava = {0};
    char **str = init_str();
    sfVector2f position = {308, 600};

    textures = malloc(sizeof(sfTexture *) * 14);
    for (int i = 0; i < 12; ++i)
        textures[i] = sfTexture_createFromFile(str[i], NULL);
    lava = malloc(sizeof(sfRectangleShape *) * 14);
    for (int i = 0; i < 12; ++i)
        lava[i] = init(textures[i], position);
    info->lava = lava;
    info->position_lava = position;
    return 0;
}

int create_lava_projectile_two(info_t *info)
{
    sfTexture **textures = {0};
    sfRectangleShape **lava = {0};
    char **str = init_str();
    sfVector2f position = {1440, 600};

    textures = malloc(sizeof(sfTexture *) * 14);
    for (int i = 0; i < 12; ++i)
        textures[i] = sfTexture_createFromFile(str[i], NULL);
    lava = malloc(sizeof(sfRectangleShape *) * 14);
    for (int i = 0; i < 12; ++i)
        lava[i] = init(textures[i], position);
    info->lava_ = lava;
    info->position_lava_ = position;
    return 0;
}