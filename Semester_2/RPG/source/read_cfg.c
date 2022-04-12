/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** read_cfg
*/

#include "struct.h"
#include "lib.h"

static int *fill_tab(int *tab, char *buffer)
{
    unsigned int index = 0;
    unsigned int is_writing = 0;
    unsigned int ptr = 0;
    char *buf = my_calloc(sizeof(char), (10) + 1);

    for (unsigned int i = 1; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            is_writing = 0;
            tab[index] = my_get_number(buf);
            index++;
            ptr = 0;
            buf = my_calloc(sizeof(char), (10) + 1);
        }
        else if (buffer[i - 1] == ';' || is_writing == 1) {
            is_writing = 1;
            buf[ptr] = buffer[i];
            ptr++;
        }
    }
    tab[index] = my_get_number(buf);
    return tab;
}

static int *fill_hero_info(int *tab, char *path)
{
    char *real_path = my_calloc(sizeof(char), (my_strlen(path) + 12 + 1));
    char *buffer = NULL;
    size_t nmemb = 60;
    size_t size = 50;
    FILE *file = NULL;

    real_path = my_strcat(real_path, "./cfg_files/");
    real_path = my_strcat(real_path, path);
    buffer = my_calloc(sizeof(char), (300));
    file = fopen(real_path, "r");
    fread(buffer, size, nmemb, file);
    tab = fill_tab(tab, buffer);
    return tab;
}

static int *alloc_lines(int *tab, unsigned int limit, char *path)
{
    for (unsigned int i = 0; i < limit; i++) {
        tab = my_calloc(sizeof(int), (20) + 1);
        if (path == NULL)
            tab[i] = 0;
    }
    if (path != NULL)
        tab = fill_hero_info(tab, path);
    return tab;
}

int *read_cfg(int node)
{
    int *tab = {0};

    if (node == 1) {
        tab = alloc_lines(tab, 6, "ennemy_1.cfg");
        return tab;
    }
    if (node == 2) {
        tab = alloc_lines(tab, 6, "ennemy_2.cfg");
        return tab;
    }
    if (node == 3) {
        tab = alloc_lines(tab, 6, "boss.cfg");
        return tab;
    }
    return tab;
}