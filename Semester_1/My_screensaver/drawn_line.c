/*
** EPITECH PROJECT, 2020
** drawn_line.c
** File description:
** function
*/

#include "graph.h"

sfRenderWindow *create(sfRenderWindow *window);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void init_line(shape *s, sfVector2f A, sfRenderWindow *window, sfVector2f B);
void init_circle(shape *s, sfRenderWindow *window, sfVector2f *center, float *a);
int usage(char **argv, int argc);

void init(shape *s)
{
   s->line_t = sfTexture_create(1920, 1080);
   s->line_s = sfSprite_create();
   s->circle_t = sfTexture_create(1920, 1080);
   s->circle_s = sfSprite_create();
   sfSprite_setTexture(s->line_s, s->line_t, sfTrue);
   sfSprite_setTexture(s->circle_s, s->circle_t, sfTrue); 
}

void hihi(sfRenderWindow *window, shape *s, sfEvent event)
{
    sfVector2f A = {0.00, 15.00};
    sfVector2f center = {497.61, 948.2};
    float a = 0.00;
    sfVector2f B = {1920.00, 15.00};

    init(s);
    init_line(s, A, window, B);
    for (; sfRenderWindow_isOpen(window) && sfRenderWindow_hasFocus(window);) {
        for (; sfRenderWindow_pollEvent(window, &event);) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        init_circle(s, window, &center, &a);
    }
    sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    int a = 0;

    a = usage(argv, argc);
    if (a == 84) {
        return 84;
    }
    if (a == 1)
        return 0;
    if (argv[1][0] == '1') {
    sfEvent event = {0};
    sfRenderWindow *window = create(window);
    shape s;
    s.framebuffer = framebuffer_create(1920, 1080);
    s.framebuffers = framebuffer_create(1920, 1080);
    
    hihi(window, &s, event);
    return 0;
    }
}
