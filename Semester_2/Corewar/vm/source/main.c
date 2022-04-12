/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** functions
*/

#include "info.h"
#include "main.h"
#include "lib.h"

int main(int argc, char *argv[])
{
    info_t info = {0};

    if (handle_args(argc, argv, &info) == -1) {
        free_info(&info);
        throw_error(84, "./corewar [-dump nbr_cycle] [[-n prog_number] \
 [-a load_address] prog_name] ...");
    }
    if (core(&info) == -1) {
        free_info(&info);
        return 84;
    }
    free_info(&info);
    return 0;
}
