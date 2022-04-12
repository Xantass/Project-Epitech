/*
** EPITECH PROJECT, 2021
** handle_click.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

sfTexture *set_up_clicked_button(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/up_arrow_clicked.png", area);
    return texture;
}

sfTexture *set_down_clicked_button(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/down_arrow_clicked.png", area);
    return texture;
}

sfTexture *set_resize_clicked_button(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/resize_clicked.png", area);
    return texture;
}

sfTexture *set_plus_clicked_button(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/plus_clicked.png", area);
    return texture;
}

sfTexture *set_less_clicked_button(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("textures/buttons/less_clicked.png", area);
    return texture;
}


