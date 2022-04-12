/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** game
*/

#include <stdlib.h>
#include "my.h"
#include "game.h"

static void print(matchstick_t *f)
{
    for (int i = 0; f->str[i] != NULL; i++)
        my_putstr(f->str[i]);
}

int game(matchstick_t *f, int *cor)
{
    while (1) {
        print(f);
        if (f->total_matchsticks == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return 1;
        }
        my_putstr("\nYour turn:\n");
        cor = get_com(f);
        if (cor[0] == -2 || cor[1] == -2)
            return 0;
        map_modif_player(cor, f);
        print(f);
        if (f->total_matchsticks == 0) {
            my_putstr("You lost, too bad...\n");
            return 2;
        }
        my_putstr("\nAI's turn...\n");
        map_modif_ai(f);
    }
    return 0;
}