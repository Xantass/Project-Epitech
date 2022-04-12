/*
** EPITECH PROJECT, 2020
** test_strlen.c
** File description:
** test_unitaire
*/

#include <criterion/criterion.h>
#include <stdlib.h>

int my_strlen(char const *str);

int my_getnbr(char const *str);

char *my_revstr(char *str);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strncpy(char *dest, char const *src, int n);

char **my_str_to_word_array(char *str);

void *my_memset(char *tab, int value, size_t size);

void *my_calloc(unsigned int size_elem, unsigned int block);

Test(my_strlen, compare)
{
    cr_assert_eq(my_strlen("toto"), strlen("toto"));
}

Test(my_getnbr, compares)
{
    cr_assert_eq(my_getnbr("214748364800"), atoi("214748364800"));
}

Test(my_getnbr, compares_negatif)
{
    cr_assert_eq(my_getnbr("-42"), atoi("-42"));
}

Test(mygetnbr, compare_)
{
    cr_assert_eq(my_getnbr("42aze"), atoi("42aze"));
}

Test(my_strcpy, compare_s)
{
    char dest[5];

    cr_assert_str_eq(my_strcpy(dest, "toto"), strcpy(dest,"toto"));
}

Test(my_strncpy, compraes)
{
    char dest[6] = "AAAAA";
    
    cr_assert_str_eq(my_strncpy(dest, "hello", 6), strncpy(dest, "hello", 6));
}

Test(my_revstr, clpel)
{
    cr_assert_str_eq(my_revstr(my_strdup("abcd")), "dcba");
}

Test(my_strcmp, feun)
{
    cr_assert_eq(my_strcmp("toto", "toto"), strcmp("titi", "titi"));
}

Test(my_strcmp, tsce)
{
    cr_assert_eq(my_strcmp("toto", "toti"), strcmp("toto", "toti"));
}

Test(my_strncmp, bdbdn)
{
    cr_assert_eq(my_strncmp("toto", "toto", 3), strncmp("toto", "toto", 3));
}

Test(my_strncmp, bdbdndyeb)
{
    cr_assert_eq(my_strncmp("tito", "toto", 3), strncmp("tito", "toto", 3));
}

Test(my_strncmp, bdndyeb)
{
    cr_assert_eq(my_strncmp("tzto", "tato", 3), strncmp("tzto", "tato", 3));
}

Test(my_strcat, jdbejdj)
{
    char dest[100] = "titi";
    
    cr_assert_str_eq(my_strcat(dest, "toto"), strcat(dest, "toto"));
}

Test(my_strncat, knfbfjn)
{
    char dest[100] = "titi";

    cr_assert_str_eq(my_strncat(dest, "toto", 3), strncat(dest, "toto", 3));
}

Test(my_strdup, dnbdjj)
{
    cr_assert_str_eq(my_strdup("tutu"), strdup("tutu"));
}

Test(my_str_to_word_array, jbfckenfub)
{
    int i = 0;
    char *dest[4];
    
    dest[0] = "je";
    dest[1] = "suis";
    dest[2] = "une";
    dest[3] = "patate";
    dest[4] = NULL;
    while (dest[i] != NULL) {
        cr_assert_str_eq(my_str_to_word_array("je suis une patate")[i], dest[i]);
        i++;
    }
}

Test(my_str_to_word_array, jbfckenfujhub)
{
    int i = 0;
    char *dest[4];
    
    dest[0] = "je";
    dest[1] = "suis";
    dest[2] = "une";
    dest[3] = "patate";
    dest[4] = NULL;
    while (dest[i] != NULL) {
        cr_assert_str_eq(my_str_to_word_array("je suis         une patate")[i], dest[i]);
        i++;
    }
}
