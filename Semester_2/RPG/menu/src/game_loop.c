/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-4-myhunter-luka.boudjelal
** File description:
** my_hunter.c
*/

#include "settings.h"
#include <stdlib.h>

void initialisation(menu *m, in_game_m *g, sur *r)
{
    create_from_f(m, g);
    create_from_f2(r);
    create_sprite(m, g);
    create_sprite2(r);
    set_texture(m, g);
    set_texture2(r);
    init_pos(m, g);
    init_pos2(r);
}

void set_cursor_event(menu *m)
{
    sfRenderWindow_setMouseCursorVisible(m->window, sfFalse);
    m->p_cursor.x = sfMouse_getPositionRenderWindow(m->window).x -20;
    m->p_cursor.y = sfMouse_getPositionRenderWindow(m->window).y -20;
}

void game_loop(menu *m, state *s, in_game_m *g, sur *r)
{
    set_sprite_pos(m, g);
    set_sprite_pos2(r);
    drawing(m, s, g);
    draw_sur(m, s, r);
    set_cursor_event(m);
    make_hit(m, s);
    make_hit2(m, s, g);
    make_hit3(m, s, g);
    make_sur(m, s);
    make_sur2(m, s);
    make_sur3(m, s, g);
    make_sur_last(m, s, g);
    make_sur_last2(m, s);
    tune_states_together(m, s, g);
}

void main_code(menu *m, state *s, in_game_m *g, sur *r)
{
    m->window = malloc(sizeof(menu));
    m->pixels = (sfVideoMode){1880, 1040, 64};
    m->window = sfRenderWindow_create(m->pixels,
    "window", sfDefaultStyle, NULL);

    initialisation(m, g, r);
    while (sfRenderWindow_isOpen(m->window) && s->game_state == 0) {
        while (sfRenderWindow_pollEvent(m->window, &m->event)) {
            if (m->event.type == sfEvtClosed)
                sfRenderWindow_close(m->window);
        }
        game_loop(m, s, g, r);
        sfRenderWindow_display(m->window);
    }
}
