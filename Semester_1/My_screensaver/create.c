/*
** EPITECH PROJECT, 2020
** create.c
** File description:
** function
*/

#include "graph.h"

sfRenderWindow *create(sfRenderWindow *window)
{
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();

    window = sfRenderWindow_create(video_mode,
                                   "draw_line",
                                   sfFullscreen,
                                   NULL);
    //sfRenderWindow_setFramerateLimit(window, 120);
    return window;
}

void my_put_pixel(shape *s, unsigned int x, unsigned int y, sfColor color)
{
    s->framebuffer->pixels[4 * (y * s->framebuffer->width + x)] = color.r;
    s->framebuffer->pixels[4 * (y * s->framebuffer->width+x) + 1] = color.g;
    s->framebuffer->pixels[4 * (y * s->framebuffer->width+x) + 2] = color.b;
    s->framebuffer->pixels[4 * (y * s->framebuffer->width+x) + 3] = color.a;
}

void my_put_pixels(shape *s, unsigned int x, unsigned int y, sfColor color)
{
    s->framebuffers->pixels[4 * (y * s->framebuffers->width + x)] = color.r;
    s->framebuffers->pixels[4 * (y * s->framebuffers->width+x) + 1] = color.g;
    s->framebuffers->pixels[4 * (y * s->framebuffers->width+x) + 2] = color.b;
    s->framebuffers->pixels[4 * (y * s->framebuffers->width+x) + 3] = color.a;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *ptr = malloc(sizeof(framebuffer_t));

    ptr->width = width;
    ptr->height = height;
    ptr->pixels = malloc(width * height * 4 + 1);
    return ptr;
}

void clear_framebuffer(shape *s, sfColor color)
{
    for(int i = 0; i <= 1920; i++) {
        for(int j = 0; j <= 1080; j++) {
            my_put_pixels(s, i, j, color);
        }
    }
}

