/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <time.h>

typedef struct rpg
{
    sfRenderWindow *window;
    sfVideoMode pixels;
    sfEvent event;
    sfSprite *s_tuto;
    sfSprite *s_cursor;
    sfSprite *s_backb;
    sfSprite *s_deco;
    sfSprite *s_menub;
    sfSprite *s_optionb;
    sfSprite *s_playb;
    sfSprite *s_prcpl;
    sfSprite *s_quitcross;
    sfSprite *s_quitcross2;
    sfSprite *s_restartb;
    sfSprite *s_resumeb;
    sfSprite *s_settingsb;
    sfSprite *s_soundless;
    sfSprite *s_soundmore;
    sfSprite *s_sound_present;
    sfTexture *t_tuto;
    sfTexture *t_cursor;
    sfTexture *t_backb;
    sfTexture *t_deco;
    sfTexture *t_menub;
    sfTexture *t_optionb;
    sfTexture *t_playb;
    sfTexture *t_prcpl;
    sfTexture *t_quitcross;
    sfTexture *t_restartb;
    sfTexture *t_resumeb;
    sfTexture *t_settingsb;
    sfTexture *t_soundless;
    sfTexture *t_soundmore;
    sfTexture *t_sound_present;
    sfVector2f p_tuto;
    sfVector2f p_cursor;
    sfVector2f p_backb;
    sfVector2f p_deco;
    sfVector2f p_menub;
    sfVector2f p_optionb;
    sfVector2f p_playb;
    sfVector2f p_prcpl;
    sfVector2f p_quitcross;
    sfVector2f p_quitcross2;
    sfVector2f p_restartb;
    sfVector2f p_resumeb;
    sfVector2f p_settingsb;
    sfVector2f p_soundless;
    sfVector2f p_soundmore;
    sfVector2f p_sound_present;
}menu;

typedef struct menu_in_game
{
    sfSprite *s_blackf;
    sfSprite *s_deco_in_g;
    sfSprite *s_menu_in_g;
    sfSprite *s_resume;
    sfSprite *s_restart;
    sfSprite *s_cross;
    sfSprite *s_settings;
    sfSprite *s_bckmenu;
    sfTexture *t_resume;
    sfTexture *t_restart;
    sfTexture *t_cross;
    sfTexture *t_settings;
    sfTexture *t_bckmenu;
    sfVector2f p_resume;
    sfVector2f p_restart;
    sfVector2f p_cross;
    sfVector2f p_settings;
    sfVector2f p_bckmenu;
    sfVector2f p_menu_in_g;
    sfVector2f p_deco_in_g;
    sfVector2f p_blackf;
}in_game_m;

typedef struct states_buttons
{
    int play;
    int options;
    int back;
    int sound_l;
    int sound_m;
    int howtoplay;
    int menu;
    int resume;
    int restart;
    int cross;
    int settings;
    int escape;
    int game_state;
    int play_sur;
    int options_sur;
    int back_sur;
    int sound_l_sur;
    int sound_m_sur;
    int howtoplay_sur;
    int menu_sur;
    int resume_sur;
    int restart_sur;
    int cross_sur;
    int settings_sur;
    int sound_pres_sur;
    int cross_sur2;
}state;

typedef struct surbrillance
{
    sfSprite *s_backsur;
    sfSprite *s_play_sur;
    sfSprite *s_menu_in_g_sur;
    sfSprite *s_soundmore_sur;
    sfSprite *s_soundless_sur;
    sfSprite *s_resume_sur;
    sfSprite *s_restart_sur;
    sfSprite *s_cross_sur;
    sfSprite *s_cross_sur2;
    sfSprite *s_settings_sur;
    sfSprite *s_sound_pres_sur;
    sfSprite *s_tuto_sur;
    sfSprite *s_options_sur;
    sfTexture *t_play_sur;
    sfTexture *t_options_sur;
    sfTexture *t_backsur;
    sfTexture *t_menu_in_g_sur;
    sfTexture *t_soundmore_sur;
    sfTexture *t_soundless_sur;
    sfTexture *t_resume_sur;
    sfTexture *t_restart_sur;
    sfTexture *t_cross_sur;
    sfTexture *t_settings_sur;
    sfTexture *t_sound_pres_sur;
    sfTexture *t_tuto_sur;
    sfVector2f p_options_sur;
    sfVector2f p_backsur;
    sfVector2f p_menu_in_g_sur;
    sfVector2f p_soundmore_sur;
    sfVector2f p_soundless_sur;
    sfVector2f p_resume_sur;
    sfVector2f p_restart_sur;
    sfVector2f p_cross_sur;
    sfVector2f p_cross_sur2;
    sfVector2f p_settings_sur;
    sfVector2f p_sound_pres_sur;
    sfVector2f p_tuto_sur;
    sfVector2f p_play_sur;
}sur;

void main_code(menu *h, state *s, in_game_m *g, sur *r);
sfSprite *crea_s(sfSprite *sprite);
void crea_t(sfSprite *sprite, sfTexture *texture);
void draw(sfRenderWindow *window, sfSprite *sprite);
void create_from_f(menu *m, in_game_m *g);
void set_p(sfSprite *sprite, sfVector2f pos);
void create_sprite(menu *m, in_game_m *g);
void drawing(menu *m, state *s, in_game_m *g);
void set_texture(menu *m, in_game_m *g);
void set_sprite_pos(menu *m, in_game_m *g);
void init_pos(menu *m, in_game_m *g);
void make_hit(menu *m, state *s);
void make_hit2(menu *m, state *s, in_game_m *g);
void tune_states_together(menu *m, state *s, in_game_m *g);
void make_hit3(menu *m, state *s, in_game_m *g);
void create_from_f2(sur *r);
void create_sprite2(sur *r);
void draw_sur(menu *m, state *s, sur *r);
void set_sprite_pos2(sur *r);
void set_texture2(sur *r);
void set_sprite_pos2(sur *r);
void init_pos2(sur *r);
void make_sur(menu *m, state *s);
void make_sur2(menu *m, state *s);
void make_sur3(menu *m, state *s, in_game_m *g);
void tune_states_together(menu *m, state *s, in_game_m *g);
void draw_sur(menu *m, state *s, sur *r);
void make_sur_last(menu *m, state *s, in_game_m *g);
void make_sur_last2(menu *m, state *s);
void norm(state *s, menu *m);