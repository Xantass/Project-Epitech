#include "settings.h"

void make_hit(menu *m, state *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (m->p_cursor.x <= m->p_playb.x + 240 && m->p_cursor.x >=
        m->p_playb.x && m->p_cursor.y <= m->p_playb.y + 75 &&
        m->p_cursor.y >= m->p_playb.y) {
            if (s->options == 0)
                s->play = 1;
        }
        if (m->p_cursor.x <= m->p_optionb.x + 240 && m->p_cursor.x >=
        m->p_optionb.x && m->p_cursor.y <= m->p_optionb.y + 75 &&
        m->p_cursor.y >= m->p_optionb.y) {
            s->options = 1;
        }
        if (m->p_cursor.x <= m->p_backb.x + 240 && m->p_cursor.x >=
        m->p_backb.x && m->p_cursor.y <= m->p_backb.y + 75 &&
        m->p_cursor.y >= m->p_backb.y)
            s->back = 1;
    }
}

void make_hit2(menu *m, state *s, in_game_m *g)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (m->p_cursor.x <= m->p_soundless.x + 240 && m->p_cursor.x >=
            m->p_soundless.x && m->p_cursor.y <= m->p_soundless.y + 75 &&
            m->p_cursor.y >= m->p_soundless.y)
                s->sound_l = 1;
        if (m->p_cursor.x <= m->p_soundmore.x + 240 && m->p_cursor.x >=
            m->p_soundmore.x && m->p_cursor.y <= m->p_soundmore.y + 75 &&
            m->p_cursor.y >= m->p_soundmore.y)
                s->sound_m = 1;
        if (m->p_cursor.x <= m->p_menub.x + 240 && m->p_cursor.x >=
            m->p_menub.x && m->p_cursor.y <= m->p_menub.y + 75 &&
            m->p_cursor.y >= m->p_menub.y)
                s->menu = 1;
        if (m->p_cursor.x <= g->p_resume.x + 240 && m->p_cursor.x >=
            g->p_resume.x && m->p_cursor.y <= g->p_resume.y + 75 &&
            m->p_cursor.y >= g->p_resume.y)
                s->resume = 1;
    }
}

void make_hit3(menu *m, state *s, in_game_m *g)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (m->p_cursor.x <= g->p_restart.x + 240 && m->p_cursor.x >=
            g->p_restart.x && m->p_cursor.y <= g->p_restart.y + 75 &&
            m->p_cursor.y >= g->p_restart.y)
                s->restart = 1;
        if (m->p_cursor.x <= g->p_cross.x + 50 && m->p_cursor.x >=
            g->p_cross.x && m->p_cursor.y <= g->p_cross.y + 50 &&
            m->p_cursor.y >= g->p_cross.y)
                s->cross = 1;
        if (m->p_cursor.x <= g->p_settings.x + 240 && m->p_cursor.x >=
            g->p_settings.x && m->p_cursor.y <= g->p_settings.y + 75 &&
            m->p_cursor.y >= g->p_settings.y)
                s->settings = 1;
    }
}

void make_sur(menu *m, state *s)
{
    if (m->p_cursor.x <= m->p_soundless.x + 120 && m->p_cursor.x >=
    m->p_soundless.x && m->p_cursor.y <= m->p_soundless.y + 40 &&
    m->p_cursor.y >= m->p_soundless.y) {
            s->sound_l_sur = 1;
    }
    else
        s->sound_l_sur = 0;
    if (m->p_cursor.x <= m->p_soundmore.x + 120 && m->p_cursor.x >=
    m->p_soundmore.x && m->p_cursor.y <= m->p_soundmore.y + 40 &&
        m->p_cursor.y >= m->p_soundmore.y && (s->options == 1)) {
            s->sound_m_sur = 1;
        }
    else
        s->sound_m_sur = 0;
    if (m->p_cursor.x <= m->p_backb.x + 240 && m->p_cursor.x >=
    m->p_backb.x && m->p_cursor.y <= m->p_backb.y + 75 &&
        m->p_cursor.y >= m->p_backb.y)
            s->back_sur = 1;
    else
        s->back_sur = 0;
}

void make_sur2(menu *m, state *s)
{
    if (m->p_cursor.x <= m->p_playb.x + 240 && m->p_cursor.x >=
    m->p_playb.x && m->p_cursor.y <= m->p_playb.y + 75 &&
    m->p_cursor.y >= m->p_playb.y) {
            s->play_sur = 1;
    }
    else
        s->play_sur = 0;
    if (m->p_cursor.x <= m->p_optionb.x + 240 && m->p_cursor.x >=
    m->p_optionb.x && m->p_cursor.y <= m->p_optionb.y + 75 &&
        m->p_cursor.y >= m->p_optionb.y && s->escape == 0) {
            s->options_sur = 1;
        }
    else
        s->options_sur = 0;
    if (m->p_cursor.x <= m->p_menub.x + 240 && m->p_cursor.x >=
    m->p_menub.x && m->p_cursor.y <= m->p_menub.y + 75 &&
        m->p_cursor.y >= m->p_menub.y)
            s->menu_sur = 1;
    else
        s->menu_sur = 0;
}