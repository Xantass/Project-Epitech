/*
** EPITECH PROJECT, 2020
** infin_add.c
** File description:
** fonction
*/

#define CTOI(x) (x - '0')
#define ITOC(x) (x + '0')
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
char *my_revstr(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char const *src);
void *my_calloc(unsigned int elem, unsigned int block);
void print(char *res, char *str1, char *str2);
int bigger_number(char *str1, char *str2);

char *bigger_str(char *str1, char *str2)
{
    if (my_strlen(str1) < my_strlen(str2))
        return (str2);
    return (str1);
}

int check(char const *str1, char const *str2)
{
    if (my_strlen(str1) < my_strlen(str2))
        return (1);
    return (0);
}

char *first_calcul(char *str1, char *str2, int i, char *res)
{
    int carry = 0;
    char *nbr1 = my_revstr(str1);
    char *nbr2 = my_revstr(str2);
    char *big_str = my_strdup(bigger_str(str1, str2));

    while (i < my_strlen(str1) && i < my_strlen(str2)) {
        res[i] = ITOC((CTOI(nbr1[i]) + CTOI(nbr2[i]) + carry) % 10);
        carry = (CTOI(nbr1[i]) + CTOI(nbr2[i]))/ 10;
        (i)++;
    }
    while (big_str[i] != '\0') {
        if (check(str1, str2) == 0) {
            res[i] =  ITOC((CTOI(nbr1[i]) + carry) % 10);
            carry = (CTOI(nbr1[i]) + carry)/ 10;
        } else {
            res[i] = ITOC((CTOI(nbr2[i]) + carry) % 10);
            carry = (CTOI(nbr2[i]) + carry)/ 10;
        }
        (i)++;
    }
    if (carry == 1)
      res[i] = ITOC(carry);
    return (res);
}

char *infin_add(char *str1, char *str2)
{
    int size = (my_strlen(str1) > my_strlen(str2)) ? my_strlen(str1):my_strlen(str2);
    char *res = my_calloc(sizeof(char), size + 1);
    int i = 0;
    int j = 0;

    size = size + 1;
    res[size] = '\0';
    first_calcul(str1, str2, i, res);
    res = my_revstr(res);
    while (res[j] == '0')
        j++;
    while (res[j] != '\0') {
        res[i] = res[j];
        (i)++;
        j++;
    }
    res[i] = '\0';
    print(res, str1, str2);
    return (res);
}

int main(int argc, char **argv)
{
    char *str1 = my_strdup(argv[1]);
    char *str2 = my_strdup(argv[2]);

    bigger_number(str1, str2);
    infin_add(str1, str2);
    return (0);
}
