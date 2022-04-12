/*
** EPITECH PROJECT, 2020
** my_test_my_strcmp.c
** File description:
** 
*/

#include <criterion/criterion.h>

Test(my_strcmp, compare_two_result)
{
    int result = my_strcmp("hellb", "hellg");
    
    cr_assert_eq(result, -5);
}
