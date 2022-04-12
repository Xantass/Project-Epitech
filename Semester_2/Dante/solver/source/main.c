/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function
*/

#include "main.h"
#include "struct.h"

int main(int argc, char *argv[])
{
    int **map = NULL;
    vector_2ui_t size = {0};

    if (argc != 2)
        exit(84);
    map = load_map(argv[1], &size);
    if (core(map, &size) == -1)
        return 84;
    return 0;
}
