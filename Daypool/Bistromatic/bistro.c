/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** fmoewdmi
*/

#define BUFF_SIZE 2000000
#include <unistd.h>
#include "../include/my.h"

char *one_recur(char **myopstr, char const *operators, char *base);

int main(int argc, char *argv[])
{
    char *result;
    char buff[BUFF_SIZE + 1];
    char *buffp = buff;
    int offset = 0;
    int len;
    int calclen = my_getnbr(argv[3]);

    while ((len = read(0 , buff + offset , BUFF_SIZE - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    buff[calclen] = '\0';
    if (len < 0)
        return (84);
    if (argc == 4)
        if (parentheses_same_count(argv[1]) == 1) {
            result = one_recur(&buffp, argv[2], argv[1]);
            if (result != 84) {
                my_putstr(result);
                my_putchar(10);
            } else {
                return 84;
            }
        } else {
            return 84;
        }
    return 0;
}
