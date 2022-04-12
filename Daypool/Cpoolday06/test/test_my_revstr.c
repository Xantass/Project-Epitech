/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <criterion/criterion.h>
char *my_revstr(char *str);

Test(my_revstr, compare_two_result)
{
    char  str[] = "bool";
    char *result = my_revstr(str);
    cr_assert_str_eq(result, "loob");
}
