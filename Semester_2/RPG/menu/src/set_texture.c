#include "settings.h"

void set_texture(menu *m, in_game_m *g)
{
    crea_t(m->s_prcpl, m->t_prcpl);
    crea_t(m->s_menub, m->t_menub);
    crea_t(m->s_deco, m->t_deco);
    crea_t(m->s_playb, m->t_playb);
    crea_t(m->s_optionb, m->t_optionb);
    crea_t(m->s_cursor, m->t_cursor);
    crea_t(m->s_backb, m->t_backb);
    crea_t(m->s_soundless, m->t_soundless);
    crea_t(m->s_soundmore, m->t_soundmore);
    crea_t(m->s_sound_present, m->t_sound_present);
    crea_t(m->s_tuto, m->t_tuto);
    crea_t(g->s_bckmenu, g->t_bckmenu);
    crea_t(g->s_resume, g->t_resume);
    crea_t(g->s_restart, g->t_restart);
    crea_t(g->s_cross, g->t_cross);
    crea_t(g->s_settings, g->t_settings);
    crea_t(g->s_menu_in_g, m->t_menub);
    crea_t(g->s_deco_in_g, m->t_deco);
    crea_t(g->s_blackf, g->t_bckmenu);
    crea_t(m->s_quitcross2, g->t_cross);
}

void set_texture2(sur *r)
{
    crea_t(r->s_backsur, r->t_backsur);
    crea_t(r->s_play_sur, r->t_play_sur);
    crea_t(r->s_menu_in_g_sur, r->t_menu_in_g_sur);
    crea_t(r->s_soundmore_sur, r->t_soundmore_sur);
    crea_t(r->s_soundless_sur, r->t_soundless_sur);
    crea_t(r->s_resume_sur, r->t_resume_sur);
    crea_t(r->s_restart_sur, r->t_restart_sur);
    crea_t(r->s_cross_sur, r->t_cross_sur);
    crea_t(r->s_cross_sur2, r->t_cross_sur);
    crea_t(r->s_settings_sur, r->t_settings_sur);
    crea_t(r->s_sound_pres_sur, r->t_sound_pres_sur);
    crea_t(r->s_tuto_sur, r->t_tuto_sur);
    crea_t(r->s_options_sur, r->t_options_sur);
}