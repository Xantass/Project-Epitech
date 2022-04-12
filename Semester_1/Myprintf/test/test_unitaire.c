/*
** EPITECH PROJECT, 2020
** test_unitaire.c
** File description:
** function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void my_printf(char const *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flagd, .init = redirect_all_std)
{
    int i = 34;

    my_printf("i = %d", i);
    cr_assert_stdout_eq_str("i = 34");
}

Test(my_printf, flagi, .init = redirect_all_std)
{
    int g = 34;

    my_printf("g = %i", g);
    cr_assert_stdout_eq_str("g = 34");
}

Test(my_printf, flags, .init = redirect_all_std)
{
    char *str = "toto";

    my_printf("str = %s", str);
    cr_assert_stdout_eq_str("str = toto");
}

Test(my_printf, flagc, .init = redirect_all_std)
{
    char c = 'e';

    my_printf("c = %c", c);
    cr_assert_stdout_eq_str("c = e");
}

Test(my_printf, flagb, .init = redirect_all_std)
{
    unsigned int g = 34;

    my_printf("g = %b", g);
    cr_assert_stdout_eq_str("g = 100010");
}

Test(my_printf, flagpourcen, .init = redirect_all_std)
{
    char c = '%';

    my_printf("c = %%", c);
    cr_assert_stdout_eq_str("c = %");
}

Test(my_printf, flagX, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %X", g);
    cr_assert_stdout_eq_str("g = 2A3");
}

Test(my_printf, flagx, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %x", g);
    cr_assert_stdout_eq_str("g = 2a3");
}

Test(my_printf, flagu, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %u", g);
    cr_assert_stdout_eq_str("g = 675");
}

Test(my_printf, flago, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %o", g);
    cr_assert_stdout_eq_str("g = 1243");
}

Test(my_printf, unsigned_flagh, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %hu", g);
    cr_assert_stdout_eq_str("g = 675");
}

Test(my_printf, unisgned_flagh_none, .init = redirect_all_std)
{
    unsigned int g = 977362244;

    my_printf("g = %hu", g);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, unsigned_flagz, .init = redirect_all_std)
{
    unsigned int g = 675;

    my_printf("g = %zi", g);
    cr_assert_stdout_eq_str("g = 675");
}

Test(my_printf, unsigned_flagz_none, .init = redirect_all_std)
{
    unsigned int g = 70000;

    my_printf("g = %zb", g);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, unsigned_flagl, .init = redirect_all_std)
{
    unsigned int g = 33000;

    my_printf("g = %li", g);
    cr_assert_stdout_eq_str("g = 33000");
}

Test(my_printf, unsigned_flagj, .init = redirect_all_std)
{
    unsigned long long g = 21474836470;

    my_printf("g = %ji", g);
    cr_assert_stdout_eq_str("g = 21474836470");
}

Test(my_printf, unsigned_flagj_none, .init = redirect_all_std)
{
    unsigned long long g = 92233720368547;

    my_printf("g = %ji", g);
    cr_assert_stdout_eq_str("g = 92233720368547");
}

Test(my_printf, int_flagh, .init = redirect_all_std)
{
    int g = 675;

    my_printf("g = %hi", g);
    cr_assert_stdout_eq_str("g = 675");
}

Test(my_printf, int_flagh_none, .init = redirect_all_std)
{
    int g = 33000;

    my_printf("g = %hi", g);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, int_flagz, .init = redirect_all_std)
{
    int g = 675;

    my_printf("g = %zi", g);
    cr_assert_stdout_eq_str("g = 675");
}

Test(my_printf, int_flagz_none, .init = redirect_all_std)
{
    int g = 33000;

    my_printf("g = %zi", g);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, int_flagl, .init = redirect_all_std)
{
    int g = 33000;

    my_printf("g = %li", g);
    cr_assert_stdout_eq_str("g = 33000");
}

Test(my_printf, int_flagl_none, .init = redirect_all_std)
{
    long g = 21474836470;

    my_printf("g = %li", g);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, int_flagj, .init = redirect_all_std)
{
    long long g = 21474836470;

    my_printf("g = %ji", g);
    cr_assert_stdout_eq_str("g = 21474836470");
}

Test(my_printf, int_flagj_none, .init = redirect_all_std)
{
    long long int g = 92233720368547;

    my_printf("g = %ji", g);
    cr_assert_stdout_eq_str("g = 92233720368547");
}

Test(my_printf, char_flagl, .init = redirect_all_std)
{
    char c = 48;

    my_printf("g = %lc", c);
    cr_assert_stdout_eq_str("g = 0");
}

Test(my_printf, char_flagl_none, .init = redirect_all_std)
{
    char c = 127;

    my_printf("g = %lc", c);
    cr_assert_stdout_eq_str("g = ");
}

Test(my_printf, string_flagl, .init = redirect_all_std)
{
    char *c = "toto";

    my_printf("g = %ls", c);
    cr_assert_stdout_eq_str("g = toto");
}
