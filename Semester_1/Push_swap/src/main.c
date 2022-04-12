/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function
*/

#include "my.h"
#include "list.h"

list *lists(char **argv);

int main(int argc, char **argv)
{
    if (argc == 1) {
        my_putstr("\n");
        return 0;
    }
    if (argc == 2) {
        my_putstr("\n");
        return 0;
    }
    lists(argv);
    return 0;
}
