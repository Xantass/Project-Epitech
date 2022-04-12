/*
** Epitech PROJECT, 2021
** RPG
** File description:
** display_pnj
*/

#include "hero.h"
#include "display_diag_bis.h"
#include "display_pnj.h"

int pnj_zero(info_t *info, hero_status_t *hero_status)
{
    static int pass = -1;
    static int items = -1;

    if (info->position_player.x < 585 && info->position_player.x > 385 &&
        info->position_player.y < 380 && info->position_player.y > 180) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            pass = 0;
            sfClock_restart(info->clock_bis);
        }
    }
    if (pass == 0) {
        pass = display_diag_zero(info);
        if (items == -1) {
            quest_one(hero_status);
            hero_status->inventory[0][0] = 1;
            hero_status->inventory[1][0] = 1;
            items *= -1;
        }
    }
    sfRenderWindow_drawRectangleShape(info->window, info->pnj[0], NULL);
    return 0;
}

int pnj_three(info_t *info, hero_status_t *hero_status)
{
    static int pass = -1;
    static int items = -1;

    if (info->position_player.x < 242 && info->position_player.x > 42 &&
        info->position_player.y < 618 && info->position_player.y > 418) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            pass = 0;
            sfClock_restart(info->clock_bis);
        }
    }
    if (pass == 0) {
        pass = display_diag_three(info);
        if (items == -1) {
            quest_two(hero_status);
            hero_status->inventory[2][0] = 1;
            hero_status->inventory[3][0] = 1;
            items *= -1;
        }
    }
    sfRenderWindow_drawRectangleShape(info->window, info->pnj[1], NULL);
    return 0;
}

int pnj_five(info_t *info, hero_status_t *hero_status)
{
    static int pass = -1;
    static int items = -1;

    if (info->position_player.x < 1800 && info->position_player.x > 1600 &&
        info->position_player.y < 200 && info->position_player.y > 0) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            pass = 0;
            sfClock_restart(info->clock_bis);
        }
    }
    if (pass == 0) {
        pass = display_diag_five(info);
        if (items == -1) {
            quest_three(hero_status);
            hero_status->inventory[4][0] = 1;
            hero_status->inventory[5][0] = 1;
            items *= -1;
        }
    }
    sfRenderWindow_drawRectangleShape(info->window, info->pnj[2], NULL);
    return 0;
}

int pnj_seven(info_t *info, hero_status_t *hero_status)
{
    static int pass = -1;
    static int items = -1;

    if (info->position_player.x < 1920 && info->position_player.x > 1720 &&
        info->position_player.y < 1010 && info->position_player.y > 810) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            pass = 0;
            sfClock_restart(info->clock_bis);
        }
    }
    if (pass == 0) {
        pass = display_diag_seven(info);
        if (items == -1) {
            quest_four(hero_status);
            hero_status->inventory[6][0] = 1;
            items *= -1;
        }
    }
    sfRenderWindow_drawRectangleShape(info->window, info->pnj[3], NULL);
    return 0;
}
