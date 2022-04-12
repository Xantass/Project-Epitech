/*
** EPITECH PROJECT, 2021
** get_map.c
** File description:
** functions
*/

#include "struct.h"

int init_map(info_t *info)
{
    info->map = malloc(sizeof(list_t));
    info->map->length = 0;
    for (int i = 0; i < 14; ++i) {
        if (i >= 0 && i <= 1)
            push_back(info->map, info->textures[i], i, info->textures[11]);
        if (i >= 2 && i <= 4)
            push_back(info->map, info->textures[i], i, info->textures[12]);
        if (i >= 5 && i <= 6)
            push_back(info->map, info->textures[i], i, info->textures[10]);
        if (i >= 7 && i <= 8)
            push_back(info->map, info->textures[i], i, info->textures[13]);
    }
    return 0;
}

int init_texture(info_t *info)
{
    sfTexture **textures = {0};

    textures = malloc(sizeof(sfTexture *) * 14);
    for (int i = 0; i < 14; ++i)
        textures[i] = sfTexture_createFromFile(info->str[i], NULL);
    info->textures = textures;
    return 0;
}

int init_filename_map(info_t *info)
{
    char **str = malloc(sizeof(char *) * 14);

    str[13] = NULL;
    str[0] = "sprites/map/Part_1.png";
    str[1] = "sprites/map/Part_2.png";
    str[2] = "sprites/map/Part_3.png";
    str[3] = "sprites/map/Part_4.png";
    str[4] = "sprites/map/Part_5.png";
    str[5] = "sprites/map/Part_6.png";
    str[6] = "sprites/map/Part_7.png";
    str[7] = "sprites/map/Part_8.png";
    str[8] = "sprites/map/Part_9.png";
    str[9] = "sprites/map/Part_11.png";
    str[10] = "sprites/map/Part_10.png";
    str[11] = "sprites/map/Part_12.png";
    str[12] = "sprites/map/Part_13.png";
    str[13] = "sprites/map/Part_14.png";
    info->str = str;
    return 0;
}