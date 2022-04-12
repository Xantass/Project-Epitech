/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** functions
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void clean_fd(int* fd)
{
    if (*fd != -1)
        close(*fd);
}

char *load_file_in_mem(const char *filepath)
{
    char *map;
    struct stat temp = {0};
    __attribute__((cleanup(clean_fd)))int res_open = open(filepath, O_RDONLY);

    if (res_open == -1)
        return NULL;
    if (stat(filepath, &temp) == -1)
        return NULL;
    map = my_calloc(sizeof(char), (temp.st_size + 1));
    if (map == NULL)
        return NULL;
    if (read(res_open, map , temp.st_size) == -1)
        return NULL;
    map[temp.st_size] = '\0';
    return map;
}

char **alloc_map_2d_arr(char const *filepath)
{
    char *mem = load_file_in_mem(filepath);
    char **map;
    int j = 0;
    int h = 1;
    int u = 0;

    for (int i = 0; mem[i] != '\0'; i++) {
        if (mem[i] == '\n')
            h++;
    }
    map = my_calloc(sizeof(char *), h + 1);
    u = h;
    for (int i = 0; i < 2; i++) {
        for (h = 0; mem[j] != '\n'; h++)
            j++;
        j++;
    }
    for (int i = 0; i < u; i++) {
        map[i] = my_calloc(sizeof(char), h + 1);
    }
    return map;
}

char **load_map_mod(char const *filepath)
{
    char **map = alloc_map_2d_arr(filepath);
    char *mem = load_file_in_mem(filepath);
    int i = 0;
    int k = 0;

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

int **init_int_2d_array(char **pos)
{
    int **size = malloc(sizeof(int *) * 4);
    int j = 0;

    for (int i = 0; i < 4; i++)
        size[i] = malloc(sizeof(int) * 5);
    for (int i = 0; pos[i] != NULL; i += 3) {
        size[j][0] = pos[i][0] - 48;
        size[j][1] = pos[i + 1][0] - 65;
        size[j][2] = pos[i + 1][1] - 48;
        size[j][3] = pos[i + 2][0] - 65;
        size[j][4] = pos[i + 2][1] - 48;
        j++;
    }
    return size;
}

char **mod(char **map, int *size, int row, int col)
{
    int i = 0;

    if (size[1] == size[3]) {
        i = size[2];
        for (; i <= size[4]; row += 1) {
            map[row][col] = size[0] + 48;
            i++;
        }
    }
    if (size[2] == size[4]) {
        i = size[1];
        for (; i <= size[3]; col += 2) {
            map[row][col] = size[0] + 48;
            i++;
        }
    }
    return map;
}

char **mod_map(char **map, int **size)
{
    int row = 2;
    int col = 2;

    for (int i = 0; i < 4; i++) {
        row = row + size[i][2] - 1;
        col = col + (2 * size[i][1]);
        map = mod(map, size[i], row, col);
        row = 2;
        col = 2;
    }
    return map;
}

int game(const char *filepaths, map_t *f)
{
    char *filepath = my_strdup("map_pos/map_batlleship");
    char *str;
    char **pos;
    int **size;

    if ((f->map_player = load_map_mod(filepath)) == NULL)
        return 84;
    if ((str =  load_file_in_mem(filepaths)) == NULL)
        return 84;
    if ((f->map_enemy = load_map_mod(filepath)) == NULL)
        return 84;
    pos = my_str_to_word_array(str);
    size = init_int_2d_array(pos);
    f->map_player = mod_map(f->map_player, size);
    f->shipe = 14;
    return 0;
}
