/*
** EPITECH PROJECT, 2021
** init_window.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();

    window = sfRenderWindow_create(video_mode,
                                   "radar",
                                   sfFullscreen,
                                   NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return window;
}
