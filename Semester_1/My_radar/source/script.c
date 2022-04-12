/*
** EPITECH PROJECT, 2020
** script.h
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

int check_temp(char **str);
double *init_a(char **str, double *cor);
double *init_t(char **str, double *cor);

char *load_str(char const *filepath)
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

char **alloc_str(char const *filepath)
{
    char *mem = load_str(filepath);
    char **map;
    int j = 0;
    int h = 1;
    int u = 0;

    for (int i = 0; mem[i] != '\0'; i++) {
        if (mem[i] == '\n')
            h++;
    }
    map = my_calloc(sizeof(char *), h + 1);
    map[h] = NULL;
    u = h;
    for (int i = 0; i < 2; i++) {
        for (h = 0; mem[j] != '\n' && mem[j] != '\0'; h++)
            j++;
        j++;
    }
    for (int i = 0; i < u; i++)
        map[i] = my_calloc(sizeof(char), h + 1);
    return map;
}

char **load_script(char const *filepath)
{
    char *mem = load_str(filepath);
    char **map;
    int i = 0;
    int k = 0;

    if (mem == NULL)
        return NULL;
    map = alloc_str(filepath);
    for (int j = 0; mem[i] != '\0'; i++) {
        if (mem[i] == '\n') {
            k++;
            i++;
            j = 0;
        }
        if (mem[i] == '\0')
            break;
        map[k][j] = mem[i];
        j++;
    }
    return map;
}

double **inits(double **cor, char **str)
{
    char **temp = NULL;

    for (int u = 0; str[u] != NULL; u++) {
        for (;str[u][0] == '\n'; u++);
        temp = my_str_to_word_array(str[u]);
        if (check_temp(temp) == 84) {
            cor[0][0] = 84;
            return cor;
        }
        if (temp[0][0] == 'A')
            cor[u] = init_a(temp, cor[u]);
        if (temp[0][0] == 'T')
            cor[u] = init_t(temp, cor[u]);
        if (str[u + 1] == NULL)
            break;
    }
    return cor;
}

double **script(char const *filepath, int *i)
{
    char **str;
    double **cor;

    if ((str = load_script(filepath)) == NULL) {
        cor = malloc(sizeof(double *) * 1);
        cor[0] = malloc(sizeof(double) * 1);
        cor[0][0] = 84;
        return cor;
    }
    for (; str[*i] != NULL; (*i)++);
    cor = malloc(sizeof(double *) * (*i));
    for (int j = 0; j < *i; j++)
        cor[j] = malloc(sizeof(double) * 8);
    cor = inits(cor, str);
    return cor;
}
