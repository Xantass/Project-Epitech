/*
** EPITECH PROJECT, 2021
** free_info.c
** File description:
** functions
*/

#include "struct.h"

static void free_texture_tab(info_t *info)
{
    for (unsigned int i = 0; i < 12; i++)
        sfTexture_destroy(info->textures[i]);
    free(info->textures);
}

static void free_rectangleshape_tab(info_t *info)
{
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 3; j++)
            sfRectangleShape_destroy(info->player[i][j]);
    }
    sfRectangleShape_destroy(info->cloud);
    sfRectangleShape_destroy(info->cloud_);
    for (int i = 0; i < 12; ++i) {
        sfRectangleShape_destroy(info->lava[i]);
        sfRectangleShape_destroy(info->lava_[i]);
    }
    for (int i = 0; i < 4; ++i)
        sfRectangleShape_destroy(info->pnj[i]);
    for (int i = 0; i < 5; ++i)
        sfRectangleShape_destroy(info->box[i]);
}

static void free_text_tab(info_t *info)
{
    for (int i = 0; i < 3; ++i)
        sfText_destroy(info->quest[i]);
    free(info->quest);
    for (int i = 0; i < 5; ++i)
        sfText_destroy(info->diag[i]);
    free(info->diag);
}

static void free_clock(info_t *info)
{
    sfClock_destroy(info->clock);
    sfClock_destroy(info->clock_bis);
    sfClock_destroy(info->anim_.clock);
    sfClock_destroy(info->anim.clock);
}

void free_info(info_t *info)
{
    free_texture_tab(info);
    free_rectangleshape_tab(info);
    free_text_tab(info);
    free_clock(info);
    free(info->str);
    free(info->map);
    free(info->lava);
    free(info->lava_);
    free(info->pnj);
    free(info->player);
    free(info->box);
    if (info->actual_sound != NULL)
        sfMusic_destroy(info->actual_sound);
    for (int i = 0; i < 4; i++)
        sfMusic_destroy(info->music[i]);
}
