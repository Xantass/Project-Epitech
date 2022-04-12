/*
** EPITECH PROJECT, 2021
** event.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"
#include <stdio.h>

void check_key(sfView *view, info_t *info)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sfView_move(view, (sfVector2f){-1, 0});
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sfView_move(view, (sfVector2f){1, 0});
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sfView_move(view, (sfVector2f){0, -1});
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sfView_move(view, (sfVector2f){0, 1});
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        exit(0);
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        info->map_modif = modif_rotation(info->map_modif, info, -10);
        info->shape = create_tab_convex(info, info->map_modif);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        info->map_modif = modif_rotation(info->map_modif, info, 10);
        info->shape = create_tab_convex(info, info->map_modif);
    }
}

static int find_click_following(info_t *info, int find_event)
{
    if ((info->mouse_pos.x >= -960 && info->mouse_pos.x <= -880) &&
        (info->mouse_pos.y >= 405 && info->mouse_pos.y <= 490)) {
        info->mouse_actions.plus = find_event;
        return 0;
    }
    if ((info->mouse_pos.x >= -810 && info->mouse_pos.x <= -730) &&
        (info->mouse_pos.y >= 405 && info->mouse_pos.y <= 490)) {
        info->mouse_actions.less = find_event;
        return 0;
    }
    return 1;
}

static int find_click(info_t *info, int find_event)
{
    if ((info->mouse_pos.x >= -960 && info->mouse_pos.x <= -880) &&
        (info->mouse_pos.y >= -490 && info->mouse_pos.y <= -405)) {
        info->mouse_actions.up = find_event;
        return 0;
    }
    if ((info->mouse_pos.x >= -810 && info->mouse_pos.x <= -760) &&
        (info->mouse_pos.y >= -490 && info->mouse_pos.y <= - 405)) {
        info->mouse_actions.down = find_event;
        return 0;
    }
    if ((info->mouse_pos.x >= -730 && info->mouse_pos.x <= -643) &&
        (info->mouse_pos.y >= -490 && info->mouse_pos.y <= -405)) {
        info->mouse_actions.resize = find_event;
        return 0;
    }
    else
        return find_click_following(info, find_event);
    return 1;
}

int events(info_t *info)
{
    if (info->event.type == sfEvtMouseButtonReleased &&
        info->select_zone.is_selected == 1)
        close_selected_zone(info);
    if (info->event.type == sfEvtMouseMoved) {
        info->mouse_pos.x = info->event.mouseMove.x - 990;
        info->mouse_pos.y = info->event.mouseMove.y - 540;
    }
    if (info->event.type == sfEvtMouseButtonPressed) {
        if (find_click(info, 1) == 1)
            get_selected_zone(info);
    }
    else
        find_click(info, 2);
    if (info->event.type == sfEvtClosed)
        sfRenderWindow_close(info->window);
    if (info->event.type == sfEvtMouseWheelScrolled)
        sfView_zoom(info->view, info->event.mouseWheelScroll.delta > 0
                    ? 0.9f : 1.1f);
    check_key(info->view, info);
    return 0;
}
