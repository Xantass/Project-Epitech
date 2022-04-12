/*
** EPITECH PROJECT, 2021
** boostrap.c
** File description:
** function
*/

#include "graph.h"
#include "my.h"

static void display_convex(sfRenderWindow *window, info_t *info, sfConvexShape **shape)
{
    int size = (info->size_map[0] - 1) * (info->size_map[1] - 1);

    for (int i = 0; i != size; i++)
        sfRenderWindow_drawConvexShape(window, shape[i], NULL);
}

static int display_window(info_t *info)
{
    for (; sfRenderWindow_isOpen(info->window);) {
        for(;sfRenderWindow_pollEvent(info->window, &info->event);)
            get_new_input(info);
        if (events(info) == -1)
            return 0;
        set_buttons(info);
        set_mouse_hitbox(info);
        display_convex(info->window, info, info->shape);
        sfRenderWindow_setView(info->window, info->view);
        sfRenderWindow_display(info->window);
        sfRenderWindow_clear(info->window, sfBlack);
        set_mouse_hitbox(info);
        if (info->select_zone.is_selected == 1)
            check_cord_cursor(info);
    }
    sfRenderWindow_destroy(info->window);
    return 0;
}

int inits(void)
{
    info_t info = {NULL};
    sfVector2u size = {0, 0};

    info.view = sfView_create();
    info.window = init_window();
    size = sfRenderWindow_getSize(info.window);
    sfView_setSize(info.view, (sfVector2f){size.x, size.y});
    sfView_setCenter(info.view, (sfVector2f){0, 0});
    info.map = init_map_tab(&info);
    info.map_zero = create_2d_map(info.map, &info);
    info.map_modif = info.map_zero;
    info.shape = create_tab_convex(&info, info.map_modif);
    display_window(&info);
    return 0;
}
