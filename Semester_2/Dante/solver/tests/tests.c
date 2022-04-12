/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <struct.h>
#include "lib.h"

int core(int **map, vector_2ui_t *size);
int **load_map(char *path, vector_2ui_t *size);
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(core, functional_tests_one, .init = redirect_all_std)
{
    char *path = "./bonus/maze";
    vector_2ui_t size = {0};
    int **map = load_map(path, &size);

    cr_assert_eq(core(map, &size), 0);
}

Test(core, functional_tests_two, .init = redirect_all_std)
{
    char *path = "./bonus/maze_bis";
    vector_2ui_t size = {0};
    int **map = load_map(path, &size);

    cr_assert_eq(core(map, &size), 0);
}
