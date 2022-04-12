/*
** EPITECH PROJECT, 2021
** global_funcs2
** File description:
** global
*/

#include "settings.h"

void create_from_f(menu *m, in_game_m *g)
{
    m->t_prcpl = sfTexture_createFromFile("sprites/Menu/prcpl.png", NULL);
    m->t_menub = sfTexture_createFromFile("sprites/Menu/menu_button.png", NULL);
    m->t_deco = sfTexture_createFromFile("sprites/Menu/deco_menu.png", NULL);
    m->t_playb = sfTexture_createFromFile("sprites/Menu/play.png", NULL);
    m->t_optionb = sfTexture_createFromFile("sprites/Menu/options_button.png",
    NULL);
    m->t_cursor = sfTexture_createFromFile("sprites/Menu/cursor.png", NULL);
    m->t_backb = sfTexture_createFromFile("sprites/Menu/back_button.png", NULL);
    m->t_sound_present = sfTexture_createFromFile("sprites/Menu/sound.png", NULL);
    m->t_soundless = sfTexture_createFromFile("sprites/Menu/sound_less.png", NULL);
    m->t_soundmore = sfTexture_createFromFile("sprites/Menu/sound_more.png", NULL);
    m->t_tuto = sfTexture_createFromFile("sprites/Menu/tuto.png", NULL);
    g->t_resume = sfTexture_createFromFile("sprites/Menu/resume_button.png", NULL);
    g->t_restart = sfTexture_createFromFile("sprites/Menu/restart.png", NULL);
    g->t_cross = sfTexture_createFromFile("sprites/Menu/quit_cross.png", NULL);
    g->t_settings = sfTexture_createFromFile("sprites/Menu/settings_button.png",
    NULL);
    g->t_bckmenu = sfTexture_createFromFile("sprites/Menu/black.jpg", NULL);
}

void create_from_f2(sur *r)
{
    r->t_backsur = sfTexture_createFromFile("sprites/Menu/back_sur.png", NULL);
    r->t_play_sur = sfTexture_createFromFile("sprites/Menu/play_sur.png", NULL);
    r->t_menu_in_g_sur = sfTexture_createFromFile("sprites/Menu/menu_sur.png", NULL);
    r->t_soundmore_sur = sfTexture_createFromFile("sprites/Menu/soundmore_sur.png",
    NULL);
    r->t_soundless_sur = sfTexture_createFromFile("sprites/Menu/soundless_sur.png",
    NULL);
    r->t_resume_sur = sfTexture_createFromFile("sprites/Menu/resume_sur.png", NULL);
    r->t_restart_sur = sfTexture_createFromFile("sprites/Menu/restart_sur.png",
    NULL);
    r->t_cross_sur = sfTexture_createFromFile("sprites/Menu/exit_sur.png", NULL);
    r->t_settings_sur = sfTexture_createFromFile("sprites/Menu/settings_sur.png",
    NULL);
    r->t_sound_pres_sur = sfTexture_createFromFile("sprites/Menu/soundpres_sur.png",
    NULL);
    r->t_tuto_sur = sfTexture_createFromFile("sprites/Menu/tuto_sur.png", NULL);
    r->t_options_sur = sfTexture_createFromFile("sprites/Menu/options_sur.png",
    NULL);
}