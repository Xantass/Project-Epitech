/*
** EPITECH PROJECT, 2021
** global_funcs2
** File description:
** global
*/

#include "settings.h"

void create_from_f(menu *m, in_game_m *g)
{
    m->t_prcpl = sfTexture_createFromFile("assets/prcpl.png", NULL);
    m->t_menub = sfTexture_createFromFile("assets/menu_button.png", NULL);
    m->t_deco = sfTexture_createFromFile("assets/deco_menu.png", NULL);
    m->t_playb = sfTexture_createFromFile("assets/play.png", NULL);
    m->t_optionb = sfTexture_createFromFile("assets/options_button.png",
    NULL);
    m->t_cursor = sfTexture_createFromFile("assets/cursor.png", NULL);
    m->t_backb = sfTexture_createFromFile("assets/back_button.png", NULL);
    m->t_sound_present = sfTexture_createFromFile("assets/sound.png", NULL);
    m->t_soundless = sfTexture_createFromFile("assets/sound_less.png", NULL);
    m->t_soundmore = sfTexture_createFromFile("assets/sound_more.png", NULL);
    m->t_tuto = sfTexture_createFromFile("assets/tuto.png", NULL);
    g->t_resume = sfTexture_createFromFile("assets/resume_button.png", NULL);
    g->t_restart = sfTexture_createFromFile("assets/restart.png", NULL);
    g->t_cross = sfTexture_createFromFile("assets/quit_cross.png", NULL);
    g->t_settings = sfTexture_createFromFile("assets/settings_button.png",
    NULL);
    g->t_bckmenu = sfTexture_createFromFile("assets/black.jpg", NULL);
}

void create_from_f2(sur *r)
{
    r->t_backsur = sfTexture_createFromFile("assets/back_sur.png", NULL);
    r->t_play_sur = sfTexture_createFromFile("assets/play_sur.png", NULL);
    r->t_menu_in_g_sur = sfTexture_createFromFile("assets/menu_sur.png", NULL);
    r->t_soundmore_sur = sfTexture_createFromFile("assets/soundmore_sur.png",
    NULL);
    r->t_soundless_sur = sfTexture_createFromFile("assets/soundless_sur.png",
    NULL);
    r->t_resume_sur = sfTexture_createFromFile("assets/resume_sur.png", NULL);
    r->t_restart_sur = sfTexture_createFromFile("assets/restart_sur.png",
    NULL);
    r->t_cross_sur = sfTexture_createFromFile("assets/exit_sur.png", NULL);
    r->t_settings_sur = sfTexture_createFromFile("assets/settings_sur.png",
    NULL);
    r->t_sound_pres_sur = sfTexture_createFromFile("assets/soundpres_sur.png",
    NULL);
    r->t_tuto_sur = sfTexture_createFromFile("assets/tuto_sur.png", NULL);
    r->t_options_sur = sfTexture_createFromFile("assets/options_sur.png",
    NULL);
}