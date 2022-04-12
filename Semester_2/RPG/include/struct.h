/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "linked_lists.h"

typedef struct anim_t anim_t;
struct anim_t {
    sfClock *clock;
    sfTime time;
    float times;
};

typedef struct ennemy_t ennemy_t;
struct ennemy_t {
    sfRectangleShape *ennemy;
    sfRectangleShape **spell;
    int hp;
    int atq_phy;
    int def_phy;
    int atq_spe;
    int def_spe;
};

typedef struct info_t info_t;
struct info_t {
    list_t *map;
    int node_map;
    int node_music;
    sfTexture **textures;
    char **str;
    list_elem_t *node_act;
    sfRenderWindow *window;
    sfEvent event;
    sfRectangleShape ***player;
    sfVector2f position_player;
    sfClock *clock;
    sfTime time;
    float times;
    sfMusic **music;
    sfRectangleShape *cloud;
    sfRectangleShape **lava;
    anim_t anim;
    sfVector2f position_lava;
    sfRectangleShape **lava_;
    sfVector2f position_lava_;
    anim_t anim_;
    sfRectangleShape *cloud_;
    int node_player;
    int node_player_bis;
    sfVector2i mouse_pos;
    sfRectangleShape **pnj;
    sfVector2f *position_pnj;
    sfText **quest;
    sfText **diag;
    sfClock *clock_bis;
    sfRectangleShape **box;
    int is_sound_effects;
    int sound_volume;
    sfMusic *actual_sound;
    ennemy_t orque;
    ennemy_t dragon;
    ennemy_t boss;
    sfRectangleShape **fight;
    sfText *hp_ennemy;
    sfText *hp_player;
    sfCircleShape *circle;
};

#endif /* !STRUCT_H_ */
