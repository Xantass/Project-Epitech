/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <criterion/criterion.h>
char *my_strncpy(char *dest, char const *src, int n);

Test(my_revstr, compare_two_result)
{
    char const src[] = "fais toi plaise";
    int n = 5;
    char  dest[40];
    char *result = my_revstr(dest, src, n);
    cr_assert_str_eq(result, "oi plaise");
}
