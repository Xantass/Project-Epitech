/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** check_get_line
*/

#include "my.h"
#include "struct.h"

static int check(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return -1;
}

static int check_match_bis(int match, matchstick_t *f, int line)
{
    if (match > f->matches) {
        my_putstr("Error: you cannot remove more than "); 
        my_put_nbr(f->matches);
        my_putstr(" matches per turn\n");
        return -1;
    }
    if (match > f->matchsticks[line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return -1;
    }
    return 0;
}

int check_match(char *str, matchstick_t *f, int line)
{
    int match = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (check(str[i]) == -1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return -1;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
    match = my_getnbr(str);
    if (match == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return -1;
    }
    if (check_match_bis(match, f, line) == -1)
        return -1;
    return match;
}

int check_line(char *str, matchstick_t *f)
{
    int line = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (check(str[i]) == -1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return -1;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
    line = my_getnbr(str);
    if (line == 0 || line > f->line_nb) {
        my_putstr("Error: this line is out of range\n");
        return -1;
    }
    return line;
}