#include "settings.h"

void make_sur3(menu *m, state *s, in_game_m *g)
{
    if (m->p_cursor.x <= g->p_resume.x + 240 && m->p_cursor.x >=
    g->p_resume.x && m->p_cursor.y <= g->p_resume.y + 75 &&
    m->p_cursor.y >= g->p_resume.y) {
        s->resume_sur = 1;
    }
    else
        s->resume_sur = 0;
    if (m->p_cursor.x <= g->p_restart.x + 240 && m->p_cursor.x >=
    g->p_restart.x && m->p_cursor.y <= g->p_restart.y + 75 &&
        m->p_cursor.y >= g->p_restart.y) {
            s->restart_sur = 1;
        }
    else
        s->restart_sur = 0;
    if (m->p_cursor.x <= g->p_cross.x + 120 && m->p_cursor.x >=
    g->p_cross.x && m->p_cursor.y <= g->p_cross.y + 38 &&
        m->p_cursor.y >= g->p_cross.y)
            s->cross_sur = 1;
    else
        s->cross_sur = 0;
}

void make_sur_last(menu *m, state *s, in_game_m *g)
{
    if (m->p_cursor.x <= g->p_settings.x + 120 && m->p_cursor.x >=
    g->p_settings.x && m->p_cursor.y <= g->p_settings.y + 40 &&
    m->p_cursor.y >= g->p_settings.y)
        s->settings_sur = 1;
    else
        s->settings_sur = 0;
    if (m->p_cursor.x <= m->p_sound_present.x + 240 && m->p_cursor.x >=
    m->p_sound_present.x && m->p_cursor.y <= m->p_sound_present.y + 75 &&
    m->p_cursor.y >= m->p_sound_present.y)
        s->sound_pres_sur = 1;
    else
        s->sound_pres_sur = 0;
    if (m->p_cursor.x <= m->p_tuto.x + 240 && m->p_cursor.x >=
    m->p_tuto.x && m->p_cursor.y <= m->p_tuto.y + 75 &&
    m->p_cursor.y >= m->p_tuto.y)
        s->howtoplay_sur = 1;
    else
        s->howtoplay_sur = 0;
}

void make_sur_last2(menu *m, state *s)
{
    if (m->p_cursor.x <= m->p_quitcross2.x + 120 && m->p_cursor.x >=
    m->p_quitcross2.x && m->p_cursor.y <= m->p_quitcross2.y + 38 &&
        m->p_cursor.y >= m->p_quitcross2.y) {
            s->cross_sur2 = 1;
        }
    else
        s->cross_sur2 = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (m->p_cursor.x <= m->p_quitcross2.x + 120 && m->p_cursor.x >=
        m->p_quitcross2.x && m->p_cursor.y <= m->p_quitcross2.y + 38 &&
            m->p_cursor.y >= m->p_quitcross2.y)
                s->cross = 1;
    }
}