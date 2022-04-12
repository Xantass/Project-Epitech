/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** init
*/

#ifndef INIT_H_
#define INIT_H_

#include "struct.h"
#include "hero.h"

sfRenderWindow *init_window(void);
int display_window(info_t *info, hero_status_t *hero_status);
int init_filename_map(info_t *info);
int init_texture(info_t *info);
int init_map(info_t *info);
int create_player(info_t *info, hero_status_t *hero_status);
sfMusic **create_music(void);
int create_cloud(info_t *info);
int create_lava_projectile_one(info_t *info);
int create_lava_projectile_two(info_t *info);
anim_t init_anim(void);
int create_pnj(info_t *info);
int create_quest(info_t *info);
int create_dialog(info_t *info);
int create_box(info_t *info);
int create_orque(info_t *info);
int create_dragon(info_t *info);
int create_boss(info_t *info);
int create_fight(info_t *info);
#endif /* !INIT_H_ */
