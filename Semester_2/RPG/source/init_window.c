/*
** EPITECH PROJECT, 2021
** init_window.c
** File description:
** functions
*/

#include "graph.h"
#include "lib.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();

    window = sfRenderWindow_create(video_mode,
                                   "RPG",
                                   sfFullscreen,
                                   NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return window;
}
