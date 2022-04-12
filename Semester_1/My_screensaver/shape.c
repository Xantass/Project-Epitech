/*
** EPITECH PROJECT, 2020
** shape.c
** File description:
** function
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Window/Event.h>
#include <SFML/System/InputStream.h>
#include <SFML/Window/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "graph.h"

void my_put_pixels(shape *s, unsigned int x, unsigned int y, sfColor color);
void my_put_pixel(shape *s, unsigned int x, unsigned int y, sfColor color);
void clear_framebuffer(shape *s, sfColor color);

int create_line(shape *s, sfVector2f *A, sfVector2f *B, sfColor color)
{
    float a = (B->y - A->y) / (B->x - A->x);
    float b = A->y + a * A->x;
    sfVector2f P;
    sfVector2f F;

    P.x = A->x;
    P.y = a * P.x + b;
    F.y = A->y;
    F.x = B->x - 1;
    for (; P.x <= B->x - 1; P.x++) {
        my_put_pixel(s, P.x, P.y, color);
        P.y = a * P.x + b;
    }
    for (; F.y <= 1080; F.y++) {
        my_put_pixel(s, F.x, F.y, color);
    }
    A->y = A->y * 1.77;
    B->y = B->y * 1.77;
    B->x = B->x / 1.11;
    return 0;
}

void create_circle(shape *s, sfVector2f *center, int radius, sfColor color)
{
    float a = 0;
    float b = 0;
    sfVector2f S = {center->x - radius, center->y - radius};
    sfVector2f E = {center->x + radius, center->y + radius};
    sfVector2f P = {center->x - radius, center->y - radius};
    
    for (; P.x <= E.x; P.x++)
        for (P.y = S.y; P.y <= E.y; P.y++) {
            a = (P.x - center->x);
            b = (P.y - center->y);
            if ((a * a) + (b * b) <= (radius * radius))
                my_put_pixels(s, P.x, P.y, color);
        }
}

void init_line(shape *s, sfVector2f A, sfRenderWindow *window, sfVector2f B)
{
    while (A.y * 1.77 < 1080) {
    create_line(s, &A, &B, sfRed);
    sfTexture_updateFromPixels(s->line_t, s->framebuffer->pixels, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(window, s->line_s, NULL);
    sfRenderWindow_display(window);
    }
}

void init_circle(shape *s, sfRenderWindow *window, sfVector2f *center, float *a)
{
    center->x = (1023.78 / 2) + (1023.78 / 2 - 10) * sin(*a);
    center->y = (1546.40 / 2) + (615.40 / 2 - 10) * sin(*a);
    *a = *a + 0.03;
    create_circle(s, center, 10, sfBlue);
    sfTexture_updateFromPixels(s->circle_t, s->framebuffers->pixels, 1920, 1080, 0, 0);
    clear_framebuffer(s, sfBlack);
    sfRenderWindow_drawSprite(window, s->circle_s, NULL);
    sfRenderWindow_drawSprite(window, s->line_s, NULL);
    sfRenderWindow_display(window);
}
