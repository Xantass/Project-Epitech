/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_player
*/

#include "struct.h"
#include "create_player.h"
#include "hero.h"
#include "lib.h"

static void load_actual_stats(hero_status_t *hero_status)
{
    hero_status->actual_stats = my_calloc(sizeof(int), (10) + 1);
    for (unsigned int i = 0; i < 9; i++)
        hero_status->actual_stats[i] = hero_status->stats[i][0];
}

static void load_sprites_positions(hero_status_t *hero_status)
{
    hero_status->inventory_positions = my_calloc(sizeof(sfVector2f), (7) + 1);
    hero_status->inventory_positions[0] = (sfVector2f) {1200, 230};
    hero_status->inventory_positions[1] = (sfVector2f) {1278, 230};
    hero_status->inventory_positions[2] = (sfVector2f) {1358, 230};
    hero_status->inventory_positions[3] = (sfVector2f) {1438, 230};
    hero_status->inventory_positions[4] = (sfVector2f) {1200, 294};
    hero_status->inventory_positions[5] = (sfVector2f) {1278, 294};
    hero_status->inventory_positions[6] = (sfVector2f) {1358, 294};
}

static void load_paths(hero_status_t *hero_status)
{
    hero_status->paths_to_sprites = my_calloc(sizeof(char*), (7) + 1);
    for (unsigned int i = 0; i < 7; i++)
        hero_status->paths_to_sprites[i] = my_calloc(sizeof(char), (40));
    hero_status->paths_to_sprites[0]
        = my_strdup("./sprites/inventory/sword.png");
    hero_status->paths_to_sprites[1] =
        my_strdup("./sprites/inventory/shield.png");
    hero_status->paths_to_sprites[2] =
        my_strdup("./sprites/inventory/helmet.png");
    hero_status->paths_to_sprites[3] =
        my_strdup("./sprites/inventory/armor.png");
    hero_status->paths_to_sprites[4] =
        my_strdup("./sprites/inventory/belt.png");
    hero_status->paths_to_sprites[5] =
        my_strdup("./sprites/inventory/boots.png");
    hero_status->paths_to_sprites[6] =
        my_strdup("./sprites/inventory/bracelet.png");
}

static void load_equiped_pos(hero_status_t *hero_status)
{
    hero_status->equiped_pos = my_calloc(sizeof(sfVector2f), (7) + 1);
    hero_status->equiped_pos[0] = (sfVector2f) {1592, 361};
    hero_status->equiped_pos[1] = (sfVector2f) {1784, 362};
    hero_status->equiped_pos[2] = (sfVector2f) {1690, 237};
    hero_status->equiped_pos[3] = (sfVector2f) {1689, 322};
    hero_status->equiped_pos[4] = (sfVector2f) {1689, 403};
    hero_status->equiped_pos[5] = (sfVector2f) {1689, 481};
    hero_status->equiped_pos[6] = (sfVector2f) {1784, 280};
}

int create_player(info_t *info, hero_status_t *hero_status)
{
    sfVector2f position = {990, 590};

    info->player = create_player_bis();
    info->position_player = position;
    info->node_player = 0;
    info->node_player_bis = 0;
    sfRenderWindow_display(info->window);
    if (load_hero_status(hero_status) == -1)
        return -1;
    init_inventory(hero_status);
    load_paths(hero_status);
    load_sprites_positions(hero_status);
    load_actual_stats(hero_status);
    hero_status->loaded_items = my_calloc(sizeof(sfSprite *), (10) + 1);
    load_items_background_pos(hero_status);
    load_equiped_pos(hero_status);
    hero_status->equiped_stuff = my_calloc(sizeof(unsigned int), (7) + 1);
    hero_status->max_xp = 100;
    return 0;
}
