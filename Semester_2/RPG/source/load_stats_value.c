/*
** EPITECH PROJECT, 2021
** load_stats_value.c
** File description:
** functions
*/

#include <stdlib.h>
#include "struct.h"
#include "lib.h"

void load_stats_value(info_t *info, sfVector2f pos, int value, unsigned int max)
{
    sfText *stat = sfText_create();
    sfFont *font = sfFont_createFromFile("./Font/stats_font.ttf");
    char *all_stats = my_calloc(sizeof(char), (10) + 1);

    all_stats = my_strcat(all_stats, trans(value));
    all_stats = my_strcat(all_stats, "/");
    all_stats = my_strcat(all_stats, trans((int) max));
    sfText_setCharacterSize(stat, 15);
    sfText_setPosition(stat, pos);
    sfText_setString(stat, all_stats);
    sfText_setFont(stat, font);
    sfRenderWindow_drawText(info->window, stat, NULL);
    sfText_destroy(stat);
    free(all_stats);
    sfFont_destroy(font);
}
