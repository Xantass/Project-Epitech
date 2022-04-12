/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function
*/

#include "main.h"
#include "settings.h"

int main(void)
{
    menu h;
    state s = {0};
    in_game_m g;
    sur r;

    main_code(&h, &s, &g, &r);
    if (s.play == 1)
        return init();
}
