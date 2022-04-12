/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** init
*/

#include "init.h"
#include "hero.h"
#include "lib.h"

static int get_locked_skills_pos(hero_status_t *hero_status)
{
    hero_status->locked_skills_pos = my_calloc(sizeof(sfVector2f), (4) + 1);
    hero_status->locked_skills_pos[0] = (sfVector2f) {65, 565};
    hero_status->locked_skills_pos[1] = (sfVector2f) {210, 565};
    hero_status->locked_skills_pos[2] = (sfVector2f) {355, 565};
    hero_status->locked_skills_pos[3] = (sfVector2f) {185, 392};
    return 0;
}

static void setup_inventory(hero_status_t *hero_status)
{
    for (unsigned int i = 0; i < 7; i++)
        hero_status->inventory[i][0] = 0;
}

static int init_bis(info_t *info, hero_status_t *hero_status)
{
    info->is_sound_effects = 1;
    info->sound_volume = 0;
    info->clock = sfClock_create();
    info->music = create_music();
    info->clock_bis = sfClock_create();
    get_locked_skills_pos(hero_status);
    setup_inventory(hero_status);
    create_box(info);
    create_orque(info);
    create_dragon(info);
    create_boss(info);
    create_fight(info);
    display_window(info, hero_status);
    return 0;
}

int init(void)
{
    info_t info = {0};
    hero_status_t hero_status = {0};

    hero_status.open = -1;
    info.node_map = 0;
    info.node_music = 1;
    info.anim = init_anim();
    info.anim_ = init_anim();
    create_cloud(&info);
    info.window = init_window();
    init_filename_map(&info);
    init_texture(&info);
    init_map(&info);
    create_lava_projectile_one(&info);
    create_lava_projectile_two(&info);
    create_player(&info, &hero_status);
    create_pnj(&info);
    create_quest(&info);
    create_dialog(&info);
    return init_bis(&info, &hero_status);
}
