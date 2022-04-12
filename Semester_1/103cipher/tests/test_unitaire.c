/*
** EPITECH PROJECT, 2020
** test_unitaire.c
** File description:
** function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "proto.h"

Test(choose, encrypted_3x3)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "Just because I don't care doesn't mean I don't understand.";
    str[2] = "Homer S";
    str[3] = "0";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, encrypted_2x2)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "Just because I don't care doesn't mean I don't understand.";
    str[2] = "Home";
    str[3] = "0";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, encrypted_1x1)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "Just because I don't care doesn't mean I don't understand.";
    str[2] = "S";
    str[3] = "0";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, descrypted_3x3)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014";
    str[2] = "Homer S";
    str[3] = "1";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, descrypted_2x2)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014";
    str[2] = "Home";
    str[3] = "1";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, descrypted_1x1)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014";
    str[2] = "S";
    str[3] = "1";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 0);
}

Test(choose, incorrect)
{
    char **str = malloc(sizeof(char *) * 5);
    int argc = 4;
    int nb = 0;
    
    str[0] = "0";
    str[1] = "Just because I don't care doesn't mean I don't understand.";
    str[2] = "Homer S";
    str[3] = "2";
    str[4] = NULL;
    nb = choose(argc, str);
    cr_assert_eq(nb, 84);
}
