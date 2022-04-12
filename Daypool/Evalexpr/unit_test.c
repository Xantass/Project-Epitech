/*
** EPITECH PROJECT, 2020
** unit_test.c
** File description:
** test
*/

#include <criterion/crietrion.h>

Test(bridge_function, dhiknek)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 + 2")), "4");
}

Test(bridge_function, kndkenfi)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 + 2 + 3")), "7");
}

Test(bridge_function, hfhrfi)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 * (2 + 3)")), "10");
}

Test(bridge_function, hrfi)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 * (2 + 3) - 2")), "8");
}

Test(bridge_function, hffi)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 * ((2 + 3) - 2)")), "6");
}

Test(bridge_function, hfh)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 / ((2 + 3) - 2)")), "1");
}

Test(bridge_function, uieyiuo)
{
    cr_assert_str_eq(bridge_function(my_strdup("2 % ((2 + 3) - 2)")), "0");
}

Test(bridge_function, hfh)
{
    cr_assert_str_eq(bridge_function(my_strdup("45 / ((2 + 3) - 2)")), "15");
}

Test(eval_expr, jdinidni)
