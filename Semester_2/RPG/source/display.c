/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** display
*/

#include "hero.h"
#include "display.h"
#include "lib.h"

static int display_player(info_t *info)
{
    sfRenderWindow_drawRectangleShape(info->window,
    info->player[info->node_player][info->node_player_bis], NULL);
    for (int i = 0; i < 4; ++i) {
        if (sfKeyboard_isKeyPressed(spell[i].key))
            spell[i].link_my(info);
    }
    return 0;
}

static int display_entity(info_t *info, hero_status_t *hero_status)
{
    sfRenderWindow_drawRectangleShape(info->window, info->node_act->map[0],NULL);
    display_player(info);
    for (int i = 0; i < 4; i++) {
        if (info->node_map == pnj[i].nb)
            pnj[i].my(info, hero_status);
    }
    if (info->node_map < 5) {
        display_cloud_bis(info);
        display_cloud(info);
    }
    if (info->node_map == 7) {
        display_lava_one(info);
        display_lava_two(info);
    }
    return 0;
}

static int handle_window(info_t *info, hero_status_t *hero_status)
{
    handle_clock(info);
    handle_xp(hero_status);
    load_xp_slot(info, hero_status);
    handle_status_bar(info, hero_status);
    load_cadre(info);
    load_avatar(info);
    handle_skills_tree(info, hero_status);
    handle_xp_from_lvl(hero_status);
    handle_inventory(hero_status, info);
    load_bestiaire(info);
    display_ext_map(info);
    display_int_map(info);
    sfRenderWindow_display(info->window);
    sfRenderWindow_clear(info->window, sfBlack);
    display_entity(info, hero_status);
    return 0;
}

int display_window(info_t *info, hero_status_t *hero_status)
{
    int error = 0;

    info->node_act = info->map->head;
    sfMusic_play(info->music[info->node_music]);
    while (sfRenderWindow_isOpen(info->window)) {
        while(sfRenderWindow_pollEvent(info->window, &info->event))
            error = events(info, hero_status);
        if (error == -1)
            break;
        handle_window(info, hero_status);
    }
    sfRenderWindow_destroy(info->window);
    free_hero(hero_status);
    free_info(info);
    return 0;
}
