/*
** EPITECH PROJECT, 2021
** bestiaire.c
** File description:
** functions
*/

#include <stdio.h>
#include "struct.h"
#include "lib.h"

static void load_desc(info_t *info, char *path, sfVector2f pos)
{
    char *str = my_calloc(sizeof(char), (100) + 1);
    FILE *file = fopen(path, "r");
    sfFont *font = sfFont_createFromFile("./Font/stats_font.ttf");
    sfText *text = sfText_create();

    fread(str, 50, 51, file);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 15);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(info->window, text, NULL);
    free(str);
    fclose(file);
    sfFont_destroy(font);
    sfText_destroy(text);
}

static int load_monster(info_t *info, char *path, sfVector2f pos)
{
    sfRectangleShape *monster = sfRectangleShape_create();
    sfTexture *t_monster =
        sfTexture_createFromFile(path, NULL);

    sfRectangleShape_setTexture(monster, t_monster, sfTrue);
    sfRectangleShape_setSize(monster, (sfVector2f) {100, 100});
    sfRectangleShape_setPosition(monster, pos);
    sfRenderWindow_drawRectangleShape(info->window, monster, NULL);
    load_desc(info, "./bestiaire/orque.txt", (sfVector2f) {230, 440});
    load_desc(info, "./bestiaire/dragon.txt", (sfVector2f) {230, 550});
    sfRectangleShape_destroy(monster);
    sfTexture_destroy(t_monster);
    return 0;
}

static int set_cadre(info_t *info)
{
    sfRectangleShape *cadre = sfRectangleShape_create();

    sfRectangleShape_setPosition(cadre, (sfVector2f) {100, 400});
    sfRectangleShape_setSize(cadre, (sfVector2f) {500, 450});
    sfRectangleShape_setOutlineThickness(cadre, 5);
    sfRectangleShape_setOutlineColor(cadre, sfColor_fromRGB(100, 100, 100));
    sfRectangleShape_setFillColor(cadre, sfColor_fromRGBA(0, 0, 0, 150));
    sfRenderWindow_drawRectangleShape(info->window, cadre, NULL);
    load_monster(info, "./sprites/bestiaire/orque.png", (sfVector2f) {110, 410});
    load_monster(info, "./sprites/bestiaire/dragon.png", (sfVector2f) {110, 530});
    sfRectangleShape_destroy(cadre);
    return 0;
}

int load_bestiaire(info_t *info)
{
    static float last_mod = 0;
    static int is_open = -1;

    if (is_open == 1)
        set_cadre(info);
    if (sfKeyboard_isKeyPressed(sfKeyTab) && last_mod + (0.1) <= info->times) {
        last_mod = info->times;
        is_open *= -1;
    }
    return 0;
}
