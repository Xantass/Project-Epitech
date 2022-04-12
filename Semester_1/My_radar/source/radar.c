/*
** EPITECH PROJECT, 2020
** window.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"
#include "list.h"

double **script(char const *filepath, int *i);
list *create_circle(double **cor, int limit);
void draw(list *list_t, stock f);
sfCircleShape **create_tower(double **cor, int limit, stock *f);
void print_usage(void);
void print_error_filepath(void);
void print_error_arg(int argc);
void coli(list *list_t, stock f);

sfRenderWindow *create(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode,
                                   "radar",
                                   sfTitlebar | sfClose,
                                   NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

stock initss(sfRenderWindow *window, double **cor, int i)
{
    stock f;

    f.window = window;
    f.position.x = 0;
    f.position.y = 0;
    f.pos.x = 1800;
    f.pos.y = 10;
    f.b = sfTexture_createFromFile("image/fond.jpg", NULL);
    f.back = sfSprite_create();
    sfSprite_setTexture(f.back, f.b, sfTrue);
    sfSprite_setPosition(f.back, f.position);
    f.j = 0;
    f.tower = create_tower(cor, i, &f);
    f.s = 1;
    f.l = 1;
    f.clock = sfClock_create();
    f.text = sfText_create();
    sfText_setPosition(f.text, f.pos);
    f.font = sfFont_createFromFile("image/arial.ttf");
    sfText_setFont(f.text, f.font);
    return f;
}

int check_key(stock *f, list *list_t)
{
    element *act = list_t->first;
    element *acts = act->next;

    if (f->event.key.code == sfKeyS) {
        f->s = f->s * (-1);
        return 0;
    }
    if (f->event.key.code == sfKeyL) {
        f->l = f->l * (-1);
        return 0;
    }
    if (f->event.key.code == sfKeyM) {
        for (int i = 0; i < list_t->size; i++) {
            act->finish = acts->finish;
            act = act->next;
            acts = acts->next;
        }
        return 0;
    }
    return 0;
}

void radar(sfRenderWindow *window, double **cor, int i)
{
    stock f = initss(window, cor, i);
    list *list_t = create_circle(cor, i);

    for (; sfRenderWindow_isOpen(f.window);) {
        for (; sfRenderWindow_pollEvent(f.window, &f.event);) {
            if (f.event.type == sfEvtClosed)
                sfRenderWindow_close(f.window);
            if (f.event.type == sfEvtKeyPressed)
                check_key(&f, list_t);
        }
        sfRenderWindow_display(f.window);
        sfRenderWindow_clear(f.window, sfBlack);
        sfRenderWindow_drawSprite(f.window, f.back, NULL);
        coli(list_t, f);
        draw(list_t, f);
        if (list_t->size == 0)
            sfRenderWindow_close(f.window);
    }
    sfRenderWindow_destroy(f.window);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = create();
    double **cor;
    int i = 0;

    if (argc < 2 || argc >= 3) {
        print_error_arg(argc);
        return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    cor = script(argv[1], &i);
    if (cor[0][0] == 84) {
        print_error_filepath();
        return 84;
    }
    radar(window, cor, i);
    return 0;
}
