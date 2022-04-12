/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_quest
*/

#include "struct.h"

static sfFont *init_font(void)
{
    sfFont *font = sfFont_createFromFile("Font/stats_font.ttf");

    return font;
}

static sfText *init_text(sfFont *font, sfVector2f position)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 14);
    sfText_setPosition(text, position);
    sfText_setString(text, "???????????");
    return text;
}

static sfVector2f *init_position(void)
{
    sfVector2f *position = {0};

    position = malloc(sizeof(position) * 3);
    position[0].x = 1425;
    position[0].y = 670;
    position[1].x = 1425;
    position[1].y = 720;
    position[2].x = 1425;
    position[2].y = 770;
    return position;
}

int create_quest(info_t *info)
{
    sfFont *font = init_font();
    sfText **quest = {0};
    sfVector2f *position = init_position();

    quest = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i < 3; ++i)
        quest[i] = init_text(font, position[i]);
    info->quest = quest;
    return 0;
}