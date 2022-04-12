#include "settings.h"

void init_pos(menu *m, in_game_m *g)
{
    m->p_menub = (sfVector2f){850, 50};
    m->p_deco = (sfVector2f){850, 200};
    m->p_playb = (sfVector2f){850, 550};
    m->p_optionb = (sfVector2f){850, 750};
    m->p_sound_present = (sfVector2f){850, 550};
    m->p_soundless = (sfVector2f){860, 660};
    m->p_soundmore = (sfVector2f){980, 660};
    m->p_tuto = (sfVector2f){850, 840};
    m->p_backb = (sfVector2f){850, 50};
    g->p_resume = (sfVector2f){850, 550};
    g->p_restart = (sfVector2f){850, 700};
    g->p_cross = (sfVector2f){820, 850};
    m->p_quitcross2 = (sfVector2f){920, 850};
    g->p_settings = (sfVector2f){990, 850};
    g->p_menu_in_g = (sfVector2f){850, 50};
    g->p_deco_in_g = (sfVector2f){850, 200};
}

void init_pos2(sur *r)
{
    r->p_backsur = (sfVector2f){850, 50};
    r->p_play_sur = (sfVector2f){850, 550};
    r->p_menu_in_g_sur = (sfVector2f){850, 50};
    r->p_soundmore_sur = (sfVector2f){980, 660};
    r->p_soundless_sur = (sfVector2f){860, 660};
    r->p_resume_sur = (sfVector2f){850, 550};
    r->p_restart_sur = (sfVector2f){850, 700};
    r->p_cross_sur = (sfVector2f){820, 850};
    r->p_cross_sur2 = (sfVector2f){920, 850};
    r->p_settings_sur = (sfVector2f){990, 850};
    r->p_sound_pres_sur = (sfVector2f){850, 550};
    r->p_tuto_sur = (sfVector2f){850, 840};
    r->p_options_sur = (sfVector2f){850, 750};
}

void set_sprite_pos(menu *m, in_game_m *g)
{
    set_p(m->s_menub, m->p_menub);
    set_p(m->s_deco, m->p_deco);
    set_p(m->s_playb, m->p_playb);
    set_p(m->s_optionb, m->p_optionb);
    set_p(m->s_cursor, m->p_cursor);
    set_p(m->s_backb, m->p_backb);
    set_p(m->s_sound_present, m->p_sound_present);
    set_p(m->s_soundless, m->p_soundless);
    set_p(m->s_soundmore, m->p_soundmore);
    set_p(m->s_tuto, m->p_tuto);
    set_p(g->s_bckmenu, g->p_bckmenu);
    set_p(g->s_resume, g->p_resume);
    set_p(g->s_restart, g->p_restart);
    set_p(g->s_cross, g->p_cross);
    set_p(g->s_settings, g->p_settings);
    set_p(g->s_deco_in_g, g->p_deco_in_g);
    set_p(g->s_menu_in_g, g->p_menu_in_g);
    set_p(m->s_quitcross2, m->p_quitcross2);
}

void set_sprite_pos2(sur *r)
{
    set_p(r->s_backsur, r->p_backsur);
    set_p(r->s_play_sur, r->p_play_sur);
    set_p(r->s_menu_in_g_sur, r->p_menu_in_g_sur);
    set_p(r->s_soundmore_sur, r->p_soundmore_sur);
    set_p(r->s_soundless_sur, r->p_soundless_sur);
    set_p(r->s_resume_sur, r->p_resume_sur);
    set_p(r->s_restart_sur, r->p_restart_sur);
    set_p(r->s_cross_sur, r->p_cross_sur);
    set_p(r->s_cross_sur2, r->p_cross_sur2);
    set_p(r->s_settings_sur, r->p_settings_sur);
    set_p(r->s_sound_pres_sur, r->p_sound_pres_sur);
    set_p(r->s_tuto_sur, r->p_tuto_sur);
    set_p(r->s_options_sur, r->p_options_sur);
    set_p(r->s_backsur, r->p_backsur);
}