/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** map_modif
*/

#include <stdio.h>
#include "my.h"
#include "struct.h"

void map_modif_player(int *cor, matchstick_t *f)
{
    int i = 1;

    f->matchsticks[cor[0] - 1] -= cor[1];
    f->total_matchsticks -= cor[1];
    for (; f->str[cor[0]][i] != '|'; i++);
    for (; f->str[cor[0]][i] != ' ' && f->str[cor[0]][i] != '*'; i++);
    i--;
    my_putstr("Player removed ");
    my_put_nbr(cor[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(cor[0]);
    my_putchar('\n');
    for (; cor[1] > 0; cor[1]--, i--)
        f->str[cor[0]][i] = ' ';
}

static void print(int i)
{
    my_putstr("AI removed ");
    my_put_nbr(1);
    my_putstr(" match(es) from line ");
    my_put_nbr(i);
    my_putchar('\n');
}

void map_modif_ai(matchstick_t *f)
{
    int nb = 0;
    int i = 0;
    int h = 0;

    for (; f->str[i] != NULL; i++) {
        for (int j = 0; f->str[i][j] != '\0'; j++) {
            if (f->str[i][j] == '|') {
                nb = -1;
                break;
            }
        }
        if (nb == -1)
            break;
    }
    for (; f->str[i][h] != '|'; h++);
    for (; f->str[i][h] != ' ' && f->str[i][h] != '*'; h++);
    h--;
    f->str[i][h] = ' ';
    f->matchsticks[i - 1] -= 1;
    f->total_matchsticks -= 1;
    print(i);
}