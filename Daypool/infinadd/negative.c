/*
** EPITECH PROJECT, 2020
** negative.c
** File description:
** function
*/

#include <stdio.h>
#include "my.h"

int negative1(char *str1)
{
    int i = 0;
    int nb1 = 0;
    
    while (str1[i] != '\0') {
        while (str1[i] == '-') {
            nb1++;
            i++;
        }
        i++;
    }
    printf("nb1 = %d\n", nb1);
    return nb1;
}

int negative2(char *str2)
{
    int i = 0;
    int nb2 = 0;

    while (str2[i] != '\0') {
        while (str2[i] == '-') {
            nb2++;
            i++;
        }
        i++;
    }
    printf("nb2 = %d\n", nb2);
    return nb2;
}

void print(char *res, char *str1, char *str2)
{
    int nb1 = negative1(str1);
    int nb2 = negative2(str2);

    if (nb1 % 2 == 0 || nb2 % 2 == 0) {
        my_putstr(res);
        my_putchar('\n');
    }
    if (nb1 % 2 == 1 && nb2 % 2 == 1) {
        my_putchar('-');
        my_putstr(res);
        my_putchar('\n');
    }
}

int bigger_number(char *str1, char *str2)
{
    char *nb1 = my_revstr(str1);
    char *nb2 = my_revstr(str2);

    printf("nb1 = %s\n", nb1);
    printf("nb2 = %s\n", nb2);
    return 0;
}
