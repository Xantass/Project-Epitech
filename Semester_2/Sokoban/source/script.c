/*
** EPITECH PROJECT, 2020
** script.h
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *load_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *mem = {0};
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
    int h = 0;
    int u = 1;
    int col = 0;

    for (int i = 0; mem[i] != '\0'; i++)
        if (mem[i] == '\n')
            u++;
    map = my_calloc(sizeof(char *), u + 1);
    map[u] = NULL;
    for (int j = 0; mem[j] != '\0'; j++, h++) {
        if (mem[j] == '\n') {
            if (h > col)
                col = h;
            h = 0;
        }
    }
    for (int i = 0; i < u; i++)
        map[i] = my_calloc(sizeof(char), col + 1);
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
