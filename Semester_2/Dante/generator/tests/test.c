/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <string.h>

int core(int x, int y, int perfect);
int error_handling(int argc, char *argv[]);
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(core, functional_tests_one, .init = redirect_all_std)
{
    cr_assert_eq(core(10, 10, 1), 0);
}

Test(core, functional_tests_two, .init = redirect_all_std)
{
    cr_assert_eq(core(10, 10, 0), 0);
}

Test(core, error_handling_one, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "20";
    argv[2] = "30";
    cr_assert_eq(error_handling(3, argv), 0);
}

Test(core, error_handling_two, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "-20";
    argv[2] = "30";
    cr_assert_eq(error_handling(3, argv), -1);
}

Test(core, error_handling_three, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "20";
    argv[2] = "-30";
    cr_assert_eq(error_handling(3, argv), -1);
}

Test(core, error_handling_four, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "20";
    argv[2] = "30";
    argv[3] = "perfect";
    cr_assert_eq(error_handling(4, argv), 0);
}

Test(core, error_handling_five, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "20";
    argv[2] = "30";
    argv[3] = "EZwin";
    cr_assert_eq(error_handling(4, argv), -1);
}

Test(core, error_handling_six, .init = redirect_all_std)
{
    char **argv = my_calloc(sizeof(char*), (5));

    argv[0] = "./generator";
    argv[1] = "20";
    argv[2] = "30";
    argv[3] = "perfect";
    argv[4] = "FREEwin";
    cr_assert_eq(error_handling(5, argv), -1);
}
