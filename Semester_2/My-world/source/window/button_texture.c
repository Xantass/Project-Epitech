/*
** EPITECH PROJECT, 2021
** button_texture.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

sfTexture *set_raise_button_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/up_arrow_idle.png", area);

    return texture;
}

sfTexture *set_down_button_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/down_arrow_idle.png", area);

    return texture;
}

sfTexture *set_resize_button_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/resize_idle.png", area);

    return texture;
}

sfTexture *set_plus_button_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/plus_idle.png", area);

    return texture;
}

sfTexture *set_less_button_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/less_idle.png", area);

    return texture;
}

