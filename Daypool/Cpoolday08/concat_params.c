/*
** EPITECH PROJECT, 2020
** concat_params.c
** File description:
** fonction
*/

#include <stdlib.h>
#include <stdio.h>

int my_putstr(char const *str);

int total_of_character(char **argv, int i, int j, int h)
{
    while (argv[j] != NULL) {
        h = 0;
        while (argv[j][h] != '\0') {
            h++;
        }
        i = i + h + 1;
        j++;
    }
    return (i);
}

char *string_total(char **argv, char *memoire, int j, int h)
{
    int g = 0;

    while (argv[g] != NULL) {
        h = 0;
        while (argv[g][h] != '\0') {
            memoire[j] = argv[g][h];
            h++;
            j++;
        }
        memoire[j] = '\n';
        j++;
        g++;
    }
    memoire[j] = '\0';
    return (memoire);
}

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int h = 0;

    total_of_character(argv, i, j, h);

    char *memoire = malloc(sizeof(char) * (i + 1));

    j = 0;
    string_total(argv, memoire, j, h);
    return (memoire);
}
