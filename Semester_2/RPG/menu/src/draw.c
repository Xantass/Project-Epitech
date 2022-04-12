#include "settings.h"

void norm(state *s, menu *m)
{
    if (s->play == 0) {
        draw(m->window, m->s_prcpl);
        if (s->options == 0) {
            draw(m->window, m->s_playb);
            draw(m->window, m->s_optionb);
            draw(m->window, m->s_menub);
            draw(m->window, m->s_quitcross2);
        }
        if (s->options == 1) {
            draw(m->window, m->s_backb);
            draw(m->window, m->s_sound_present);
            draw(m->window, m->s_soundless);
            draw(m->window, m->s_soundmore);
            draw(m->window, m->s_tuto);
        }
        draw(m->window, m->s_deco);
    }
}

void drawing(menu *m, state *s, in_game_m *g)
{
    norm(s, m);
    if (s->escape == 1 && s->settings == 0 && s->play == 1
    && s->resume == 0) {
        draw(m->window, g->s_bckmenu);
        draw(m->window, g->s_resume);
        draw(m->window, g->s_restart);
        draw(m->window, g->s_cross);
        draw(m->window, g->s_settings);
        draw(m->window, g->s_deco_in_g);
        draw(m->window, g->s_menu_in_g);
    }
    if (s->settings == 1 && s->options == 1 && s->resume == 0) {
        draw(m->window, g->s_blackf);
        draw(m->window, m->s_sound_present);
        draw(m->window, m->s_soundless);
        draw(m->window, m->s_soundmore);
        draw(m->window, m->s_tuto);
        draw(m->window, m->s_backb);
        draw(m->window, g->s_deco_in_g);
    }
}

void norm_draw_sur(state *s, sur *r, menu *m)
{
    if (s->play_sur == 1 && s->escape == 0 && s->settings == 0
    && s->options == 0) {
        draw(m->window, r->s_play_sur);
    }
    if (s->options_sur == 1 && s->settings == 0 && s->options == 0) {
        draw(m->window, r->s_options_sur);
    }
    if (s->back_sur == 1) {
        draw(m->window, r->s_backsur);
    }
    if (s->sound_m_sur == 1 && (s->settings == 1 || s->options == 1))
        draw(m->window, r->s_soundmore_sur);
    if (s->menu_sur == 1 && s->options == 0) {
        draw(m->window, r->s_menu_in_g_sur);
    }
    if (s->resume_sur == 1)
        draw(m->window, r->s_resume_sur);
    if (s->restart_sur == 1 && s->escape == 1)
        draw(m->window, r->s_restart_sur);
}

void draw_sur(menu *m, state *s, sur *r)
{
    norm_draw_sur(s, r, m);
    if (s->cross_sur == 1 && s->escape == 1) {
        draw(m->window, r->s_cross_sur);
    }
    if (s->settings_sur == 1 && s->settings == 0 && s->escape == 1)
        draw(m->window, r->s_settings_sur);
    if (s->sound_l_sur == 1 && (s->settings == 1 || s->options == 1))
        draw(m->window, r->s_soundless_sur);
    if (s->sound_pres_sur == 1 && (s->settings == 1 || s->options == 1))
        draw(m->window, r->s_sound_pres_sur);
    if (s->howtoplay_sur == 1 && (s->settings == 1 || s->options == 1)) {
        draw(m->window, r->s_tuto_sur);
    }
    if (s->cross_sur2 == 1 && s->play == 0 && s->options == 0 && s->escape == 0)
        draw(m->window, r->s_cross_sur2);
    if (s->escape == 1 || s->play == 0 || s->settings == 1)
        draw(m->window, m->s_cursor);
}