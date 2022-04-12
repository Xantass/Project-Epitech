/*
** EPITECH PROJECT, 2020
** print.c
** File description:
** function
*/

#include "my.h"

void print_usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L' key        enable/disable hitboxes and areas.\n");
    my_putstr(" 'S' key        enable/disable sprites.\n");
}

void print_error_arg(int argc)
{
    my_putstr("./my_radar: bad arguments: ");
    my_put_nbr(argc - 1);
    my_putstr(" given but 1 is required\n");
    my_putstr("retry with -h\n");
}

void print_error_filepath(void)
{
    my_putstr("./my_radar: bad filepath or script\n");
    my_putstr("retry with a correct filepath or correct srcipt\n");
    my_putstr("check -h\n");
}
