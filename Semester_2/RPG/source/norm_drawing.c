#include "settings.h"

void norm_states(state *s, menu *m)
{
    if (s->play == 1)
        s->game_state = 1;
    if (s->options == 1 && s->back == 1 && s->settings == 0) {
        s->options = 0;
        s->back = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyM) && s->play == 1) {
        s->escape = 1;
    }
    if (s->escape == 1 && s->menu == 1) {
        s->menu = 0;
        s->escape = 0;
        s->play = 0;
    }
    if (s->escape == 1 && s->settings == 1) {
        s->options = 1;
        s->escape = 0;
    }
    if (s->options == 0 || (s->back == 1 && s->settings == 1))
        m->p_backb = (sfVector2f){0, 0};
    else
        m->p_backb = (sfVector2f){850, 50};
}

void tune_states_together(menu *m, state *s, in_game_m *g)
{
    norm_states(s, m);
    if (s->play == 0 && s->menu == 1)
        s->menu = 0;
    if (s->settings == 1 && s->back == 1 && s->options == 1) {
        s->escape = 1;
        s->settings = 0;
        s->options = 0;
        s->play = 1;
        s->back = 0;
    }
    if (s->cross == 1)
        s->game_state = 1;
    if (s->resume == 1)
        s->escape = 0;
    if (s->escape == 0) 
        g->p_resume = (sfVector2f){0, 0};
    else
        g->p_resume = (sfVector2f){850, 550};
}