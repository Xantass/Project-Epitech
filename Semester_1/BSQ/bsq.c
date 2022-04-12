/*
** EPITECH PROJECT, 2020
** bsq.c
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

char **alloc_map_2d_arr_from_file(char const *filepath);
int ** init_map(char const *filepath, int *u, int *h);

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *mem;
    int i = 0;
    struct stat temp;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &temp) == -1)
        return NULL;
    if (temp.st_size == 0)
        return NULL;
    mem = my_calloc(sizeof(char), (temp.st_size + 1));
    mem[temp.st_size] = '\0';
    while ((read(fd , mem + i , temp.st_size - i)) > 0) {
        if ((read(fd , mem + i , temp.st_size - i)) == -1)
            return NULL;
        i = i + my_strlen(mem);
    }
    return mem;
}

int **alloc_map_2d_arr(char const *filepath, int *u, int *h)
{
    char *mem = load_file_in_mem(filepath);
    int **map;
    int j = 0;

    for (int i = 0; mem[i] != '\0'; i++) {
        if (mem[i] == '\n')
            (*h)++;
    }
    map = malloc(sizeof(int *) * (*h));
    *u = *h;
    for (int i = 0; i < 2; i++) {
        for ((*h) = 0; mem[j] != '\n'; (*h)++)
            j++;
        j++;
    }
    for (int i = 0; i < (*u); i++) {
        map[i] = malloc(sizeof(int) * (*h));
    }
    return map;
}

int **load_map_mod(char const *filepath, int *u, int *h)
{
    int **map = init_map(filepath, u, h);
    char *mem = load_file_in_mem(filepath);
    int i = 0;
    int k = 0;

    for (; mem[i] != '\n'; i++);
    for (int j = 0; mem[i] != '\0'; i++) {
        if (mem[i] == '\n') {
            k++;
            i++;
            j = 0;
        }
        if (mem[i] == '\0')
            break;
        if (mem[i] == 'o')
            map[k][j] = 0;
        else
            map[k][j] = 1;
        j++;
    }
    return map;
}

int number_cro(int **map, int i, int j)
{
    int number;

    number = map[i -1][j];
    if (number > map[i][j - 1])
        number = map[i][j - 1];
    if (number > map[i - 1][j - 1])
        number = map[i - 1][j - 1];
    return number;
}
