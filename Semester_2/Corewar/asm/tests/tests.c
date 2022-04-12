/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <strings.h>
#include "lib.h"

int error_man(char **argv, int argc);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_man, basic_error_handling_test_one, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (2) + 1);

    argv[0] = "./asm";
    argv[1] = "wesh.s";
    cr_assert_eq(error_man(argv, 2), 0);
}

Test(error_man, functional_test_one, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (2) + 1);

    argv[0] = "./asm";
    argv[1] = "./bill.s";
    cr_assert_eq(error_man(argv, 2), 0);
}

