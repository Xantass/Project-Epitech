/*
** EPITECH PROJECT, 2021
** winner.c
** File description:
** functions
*/

#include <unistd.h>
#include <stdbool.h>
#include "lib.h"
#include "info.h"
#include "winner.h"

unsigned int check_win(info_t *info)
{
    unsigned int nbr_alive = 0;
    int id = 0;

    for (unsigned int i = 0; i < info->nb_progs; i++) {
        if (get_state(&info->living_process,
                      info->prog_info[i].prog_number) == 1) {
            nbr_alive++;
            id = (int) i;
        }
    }
    if (nbr_alive == 1)
        return id;
    return -1;
}

void print_winner(prog_info_t prog_info)
{
    my_putstr("The player ");
    my_put_number((int) prog_info.prog_number);
    write(1, "(", 1);
    my_putstr(prog_info.name);
    write(1, ")", 1);
    my_putstr("has won.\n");
}
