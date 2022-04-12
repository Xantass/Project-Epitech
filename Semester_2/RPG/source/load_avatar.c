/*
** EPITECH PROJECT, 2021
** load_avatar.c
** File description:
** function
*/

#include "graph.h"
#include "struct.h"

void load_avatar(info_t *info)
{
    sfRectangleShape *avatar = sfRectangleShape_create();
    sfTexture *t_avatar =
        sfTexture_createFromFile("./sprites/Character/avatar.png", NULL);

    sfRectangleShape_setTexture(avatar, t_avatar, sfTrue);
    sfRectangleShape_setPosition(avatar, (sfVector2f) {0, 30});
    sfRectangleShape_setSize(avatar, (sfVector2f) {170, 140});
    sfRenderWindow_drawRectangleShape(info->window, avatar, NULL);
    sfRectangleShape_destroy(avatar);
    sfTexture_destroy(t_avatar);
}

void load_cadre(info_t *info)
{
    sfRectangleShape *cadre = sfRectangleShape_create();
    sfTexture *t_cadre =
        sfTexture_createFromFile("./sprites/Character/cadre.png", NULL);

    sfRectangleShape_setTexture(cadre, t_cadre, sfTrue);
    sfRectangleShape_setPosition(cadre, (sfVector2f) {0, 0});
    sfRectangleShape_setSize(cadre, (sfVector2f) {190, 200});
    sfRenderWindow_drawRectangleShape(info->window, cadre, NULL);
    sfRectangleShape_destroy(cadre);
    sfTexture_destroy(t_cadre);
}
