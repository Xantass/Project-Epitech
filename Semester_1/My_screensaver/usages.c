/*
** EPITECH PROJECT, 2020
** usages.c
** File description:
** function
*/

#include <stddef.h>
#include "my.h"

void print_h(void)
{
    my_putstr("animation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("   animation_id    ");
    my_putstr("ID of the animation to process (between 1 and 1).\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -d                ");
    my_putstr("print the description of all the animations and quit.\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" LEFT_ARROW        switch to the previous animation.\n");
    my_putstr(" RIGHT_ARROW       switch to the next animation.\n\n");
}

void print_d(void)
{
    my_putstr("1: horizontal and vertical lines create square on a square.\n");
    my_putstr("   circles moving in the final square ");
    my_putstr("and bouncing when touches a border.\n\n");
}

int usage(char **argv, int argc)
{
    if (argc > 2)
        return 84;
    if (argv[1] == NULL)
        return 84;
    if (argv[1][1] == 'h') {
        print_h();
        return 1;
    }
    if (argv[1][1] == 'd') {
        print_d();
        return 1;
    }
    if (argv[1][1] != 'h' && argv[1][1] != 'd' && argv[1][0] != '1')
        return 84;
    return 0;
}
