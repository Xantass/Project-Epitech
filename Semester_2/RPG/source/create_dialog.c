/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_dialog
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
    sfText_setCharacterSize(text, 17);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfBlack);
    return text;
}

static sfVector2f *init_position(void)
{
    sfVector2f *position = {0};

    position = malloc(sizeof(position) * 5);
    position[0].x = 485;
    position[0].y = 230;
    position[1].x = 485;
    position[1].y = 210;
    position[2].x = 142;
    position[2].y = 468;
    position[3].x = 1300;
    position[3].y = 10;
    position[4].x = 1300;
    position[4].y = 860;
    return position;
}

static char **init_str(void)
{
    char **str = {0};

    str = malloc(sizeof(char *) * 5);
    str[0] = "    Hello there, young apprentice.\n\
    First of all I want to give you this: sword, shield.";
    str[1] = "Now go explore these lands.\n\
    You will find explorers who can\n advise you to discover the world.";
    str[2] = "Thanks for the help. My team got separated because\
    of a mysterious power.\n If you could help me to find them, \
    that would make me happy.";
    str[3] = "Ho, you found me!\n thank you\
    I think that my last teammate\n    \
    has tried to follow this mysterious power.";
    str[4] = "Argh, argh ... I could'nt overcome this evil power.\n\
    But i beg you can help us to overcome this shitt ...";
    return str;
}

int create_dialog(info_t *info)
{
    sfText **diag = {0};
    sfFont *font = init_font();
    sfVector2f *position = init_position();
    char **str = init_str();

    diag = malloc(sizeof(sfText *) * 5);
    for (int i = 0; i < 5; ++i)
        diag[i] = init_text(font, position[i]);
    sfText_setString(diag[0], str[0]);
    sfText_setString(diag[1], str[1]);
    sfText_setString(diag[2], str[2]);
    sfText_setString(diag[3], str[3]);
    sfText_setString(diag[4], str[4]);
    info->diag = diag;
    return 0;
}
