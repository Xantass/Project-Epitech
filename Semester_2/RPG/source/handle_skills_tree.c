/*
** EPITECH PROJECT, 2021
** handle_skills_tree.c
** File description:
** functions
*/

#include "hero.h"
#include "handle_skills_tree.h"

static int load_skills(info_t *info)
{
    sfRectangleShape *skills = sfRectangleShape_create();
    sfTexture *t_skills =
        sfTexture_createFromFile("./sprites/skills/skills.png", NULL);

    sfRectangleShape_setTexture(skills, t_skills, sfTrue);
    sfRectangleShape_setPosition(skills, (sfVector2f) {60, 290});
    sfRectangleShape_setSize(skills, (sfVector2f) {400, 500});
    sfRenderWindow_drawRectangleShape(info->window, skills, NULL);
    sfRectangleShape_destroy(skills);
    sfTexture_destroy(t_skills);
    return 0;
}

static int load_cadre(info_t *info)
{
    sfRectangleShape *cadre = sfRectangleShape_create();
    sfTexture *t_cadre =
        sfTexture_createFromFile("./sprites/skills/cadre.png", NULL);

    sfRectangleShape_setTexture(cadre, t_cadre, sfTrue);
    sfRectangleShape_setPosition(cadre, (sfVector2f) {40, 191});
    sfRectangleShape_setSize(cadre, (sfVector2f) {439, 680});
    sfRenderWindow_drawRectangleShape(info->window, cadre, NULL);
    sfRectangleShape_destroy(cadre);
    sfTexture_destroy(t_cadre);
    return 0;
}

static int load_skills_tree(info_t *info)
{
    load_skills(info);
    load_cadre(info);
    return 0;
}

int handle_skills_tree(info_t *info, hero_status_t *hero_status)
{
    static float last_mod = 0;
    static int is_open = -1;

    if (sfKeyboard_isKeyPressed(sfKeyE) && last_mod + (0.1) <= info->times) {
        is_open *= -1;
        last_mod = info->times;
    }
    if (is_open == 1) {
        load_skills_tree(info);
        get_locked_sprites(info, hero_status);
    }
    return 0;
}
