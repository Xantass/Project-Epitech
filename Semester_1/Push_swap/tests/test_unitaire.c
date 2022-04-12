/*
** EPITECH PROJECT, 2020
** test_unitaire.c
** File description:
** function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "list.h"

list *lists(char **argv);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(lists, mixed_int, .init = redirect_all_std)
{
    char **str = malloc(sizeof(char *) * 11);

    str[0] = "0";
    str[1] = "5";
    str[2] = "87";
    str[3] = "-4536";
    str[4] = "-5";
    str[5] = "989643";
    str[6] = "987";
    str[7] = "63";
    str[8] = "673";
    str[9] = "-159";
    str[10] = NULL;
    lists(str);
    cr_assert_stdout_eq_str("ra ra pb ra ra ra ra ra ra pa pb pb ra ra ra ra ra pb pb pa pa pa pa pb ra pb pb ra pb pb pb ra pa pa pa pa pa pa ra pb pb ra ra ra pb pb ra pa pa pa pa pb pb pb ra pb ra pb ra ra pa pa pa pa pa ra ra pb pb pb pb ra pb ra pa pa pa pa pa pb ra ra ra ra pb ra ra pb pa pa pa pb ra pb pb ra pb ra pb ra pa pa pa pa pa pb pb pb pb ra pb ra ra ra pa pa pa pa pa pb pb ra pb ra ra pb ra ra pa pa pa pa pb pb pb pb ra pb ra pb ra pa pa pa pa pa pa pb pb pb ra pb pb ra ra ra pa pa pa pa pa pb pb pb pb pb ra pb ra ra pa pa pa pa pa pa pb pb pb pb pb ra pb ra ra pa pa pa pa pa pa pb pb pb pb pb pb ra ra ra pa pa pa pa pa pa pb pb pb pb pb pb ra ra ra pa pa pa pa pa pa pb pb pb pb pb ra ra ra ra pa pa pa pa pa pb pb pb pb pb ra ra ra ra pa pa pa pa pa pb pb pb pb pb ra ra ra ra pa pa pa pa pa pb pb pb pb pb ra ra ra ra pa pa pa pa pa rra pb rra pb rra pb rrb pa rrb pa rrb pa\n");
}

Test(lists, list_sorted, .init = redirect_all_std)
{
    char **str = malloc(sizeof(char *) * 6);

    str[0] = "0";
    str[1] = "1";
    str[2] = "2";
    str[3] = "3";
    str[4] = "4";
    str[5] = NULL;
    lists(str);
    cr_assert_stdout_eq_str("\n");
}
