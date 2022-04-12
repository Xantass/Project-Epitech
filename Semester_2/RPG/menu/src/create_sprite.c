#include "settings.h"

void create_sprite(menu *m, in_game_m *g)
{
    m->s_prcpl = crea_s(m->s_prcpl);
    m->s_menub = crea_s(m->s_menub);
    m->s_deco = crea_s(m->s_deco);
    m->s_playb = crea_s(m->s_playb);
    m->s_optionb = crea_s(m->s_optionb);
    m->s_cursor = crea_s(m->s_cursor);
    m->s_backb = crea_s(m->s_backb);
    m->s_sound_present = crea_s(m->s_sound_present);
    m->s_soundless = crea_s(m->s_soundless);
    m->s_soundmore = crea_s(m->s_soundmore);
    m->s_tuto = crea_s(m->s_tuto);
    g->s_bckmenu = crea_s(g->s_bckmenu);
    g->s_resume = crea_s(g->s_resume);
    g->s_restart = crea_s(g->s_restart);
    g->s_cross = crea_s(g->s_cross);
    g->s_settings = crea_s(g->s_settings);
    g->s_menu_in_g = crea_s(g->s_menu_in_g);
    g->s_deco_in_g = crea_s(g->s_deco_in_g);
    g->s_blackf = crea_s(g->s_blackf);
    m->s_quitcross2 = crea_s(m->s_quitcross2);
}

void create_sprite2(sur *r)
{
    r->s_backsur = crea_s(r->s_backsur);
    r->s_play_sur = crea_s(r->s_play_sur);
    r->s_menu_in_g_sur = crea_s(r->s_menu_in_g_sur);
    r->s_soundmore_sur = crea_s(r->s_soundmore_sur);
    r->s_soundless_sur = crea_s(r->s_soundless_sur);
    r->s_resume_sur = crea_s(r->s_resume_sur);
    r->s_restart_sur = crea_s(r->s_restart_sur);
    r->s_cross_sur = crea_s(r->s_cross_sur);
    r->s_cross_sur2 = crea_s(r->s_cross_sur2);
    r->s_settings_sur = crea_s(r->s_settings_sur);
    r->s_sound_pres_sur = crea_s(r->s_sound_pres_sur);
    r->s_tuto_sur = crea_s(r->s_tuto_sur);
    r->s_options_sur = crea_s(r->s_options_sur);
}