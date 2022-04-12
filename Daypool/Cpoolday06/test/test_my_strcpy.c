/*
** EPITECH PROJECT, 2020
** test_my_strcpy.c
** File description:
** 
*/

#include <criterion/criterion.h>
char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, compare_two_string)
{
    char str_1[6] = "hella";
    char const *result = my_strcpy(str_1, "hello");
    cr_assert_str_eq(result, "hello");
}
