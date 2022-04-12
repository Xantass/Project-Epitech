/*
** EPITECH PROJECT, 2020
** error_mangement.c
** File description:
** function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *load_file_in_mem(char const *filepath);
int check_type(struct stat *temp);

int is_corrects(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '\n')
        return 1;
    else
        return 0;
}

int is_correct(char c)
{
    if (c == '.')
        return 1;
    if (c == 'o')
        return 1;
    if (c == '\n')
        return 1;
    else
        return 0;
}

int check_number(char const *filepath)
{
    char *map = load_file_in_mem(filepath);
    char *check = malloc(sizeof(char) * 6);
    int i = 0;
    int h = 0;

    if (map == NULL)
        return 0;
    check[6] = '\0';
    while (map[i] != '\n') {
        check[i] = map[i];
        i++;
    }
    i++;
    while (map[i] != '\0') {
        if (map[i] == '\n')
            h++;
        i++;
    }
    if (my_getnbr(check) != h)
        return 0;
    return 1;
}

int check_arg(char const *filepath)
{
    struct stat temp;
    char *map;
    int i = 0;

    stat(filepath, &temp);
    if (check_type(&temp) == 0)
        return 0;
    if ((map = load_file_in_mem(filepath)) == NULL)
        return 0;
    if (check_number(filepath) == 0)
        return 0;
    for (; map[i] != '\n'; i++)
        if (is_corrects(map[i]) == 0)
            return 0;
    if (map[i + 1] == '\0')
        return 0;
    for (; map[i] != '\0'; i++)
        if (is_correct(map[i]) == 0)
            return 0;
    return 1;
}

int error_man(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    if (check_arg(argv[1]) == 0)
        return 0;
    return 1;
}
