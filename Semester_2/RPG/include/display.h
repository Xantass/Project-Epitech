/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** display
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "hero.h"
#include "display_pnj.h"
#include "spell.h"

int events(info_t *info, hero_status_t *hero_status);
int handle_clock(info_t *info);
int handle_inventory(hero_status_t *hero_status, info_t *info);
int display_lava_one(info_t *info);
int handle_status_bar(info_t *info, hero_status_t *heros_status);
int display_lava_two(info_t *info);
int display_cloud(info_t *info);
int display_cloud_bis(info_t *info);
void load_avatar(info_t *info);
void load_cadre(info_t *info);
void free_hero(hero_status_t *hero_status);
void free_info(info_t *info);
int handle_skills_tree(info_t *info, hero_status_t *hero_status);
int load_xp_slot(info_t *info, hero_status_t *hero_status);
int handle_xp(hero_status_t *hero_status);
int handle_xp_from_lvl(hero_status_t *hero_status);
int load_bestiaire(info_t *info);
int mouse_ptl(info_t *info);
int display_ext_map(info_t *info);
int display_int_map(info_t *info);
void print_map(info_t *info, char *path);

typedef struct pnj_t {
    int nb;
    int (*my)(info_t *info, hero_status_t *hero_status);
} pnj_t;

pnj_t pnj [4] = {
    {0, pnj_zero},
    {3, pnj_three},
    {5, pnj_five},
    {7, pnj_seven}
};

typedef struct spell_t {
    sfKeyCode key;
    int (*link_my)(info_t *info);
}spell_t;

spell_t spell [4] = {
    {sfKeyNum1, attack},
    {sfKeyNum2, shield},
    {sfKeyNum3, roar},
    {sfKeyNum4, rest},
};
#endif /* !DISPLAY_H_ */
