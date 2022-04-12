/*
** EPITECH PROJECT, 2021
** set_cadre.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

static sfTexture *get_cadre_texture(void)
{
    sfIntRect *area = NULL;
    sfTexture *texture =
        sfTexture_createFromFile("./textures/cadre/cadre.png", area);

    return texture;
}

void display_cadre(info_t *info, sfVector2f pos)
{
    sfRectangleShape *cadre = sfRectangleShape_create();

    if (pos.y < 0)
        pos.y += 100;
    else
        pos.y -= 100;
    sfRectangleShape_setPosition(cadre, pos);
    sfRectangleShape_setSize(cadre, (sfVector2f) {405, 100});
    sfRectangleShape_setTexture(cadre, get_cadre_texture(), 1);
    sfRectangleShape_setOutlineColor(cadre,
                                     sfColor_fromRGB(220, 90, 50));
    sfRectangleShape_setOutlineThickness(cadre, 6);
    sfRenderWindow_drawRectangleShape(info->window, cadre, NULL);
}
