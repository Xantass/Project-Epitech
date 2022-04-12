/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
int my_get_number(char *str);
int my_put_number(int result);

int print_my_error(char op, int nb_3)
{
    char str_1[] = "Stop: division by zero\n";
    char str_2[] = "Stop: modulo by zero\n";
    int i = 0;

    if (op == '/' && nb_3 == 0) {
        while (str_1[i] != '\0') {
            my_putchar(str_1[i]);
            i = i + 1;
        }
        return (0);
    }
    i = 0;
    if (op == '%' && nb_3 == 0) {
        while (str_2[i] != '\0') {
            my_putchar(str_2[i]);
            i = i + 1;
        }
        return (0);
    }
    return (1);
}

int count_my_result(int nb_1, int nb_3, char op)
{
    long rest = 0;

    if (op == '+') {
        rest = nb_1 + nb_3; }
    else if (op == '-') {
        rest = nb_1 - nb_3; }
    else if (op == '*') {
        rest = nb_1 * nb_3; }
    else if  (op== '%') {
        if (print_my_error(op, nb_3) == 0)
            return (0);
        rest = nb_1 % nb_3; }
    else if (op  == '/') {
        if (print_my_error(op, nb_3) == 0)
            return (0);
        rest = nb_1 / nb_3; }
    return (rest);
}

int do_op(int argc, char *argv[])
{
    int result = 0;
    int nb_1 = 0;
    int nb_3 = 0;
    char op = 0;

    if (argc < 3)
        return (0);
    if (argv[2][0] != '+' && argv[2][0] != '-' &&
        argv[2][0] != '/' && argv[2][0] != '*' && argv[2][0] != '%') {
        my_put_number(0);
        my_putchar('\n'); }
    nb_1 = my_get_number(argv[1]);
    nb_3 = my_get_number(argv[3]);
    op = argv[2][0];
    result = count_my_result(nb_1, nb_3, op);
    if (result == 0)
        return (84);
    my_put_number(result);
    my_putchar('\n');
    return (0);
}
