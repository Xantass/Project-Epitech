/*
** EPITECH PROJECT, 2021
** load_hero_status.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "hero.h"

static void fill_tab(int **tab, char *buffer)
{
    unsigned int index = 0;
    unsigned int is_writing = 0;
    unsigned int ptr = 0;
    char *buf = my_calloc(sizeof(char), (10) + 1);

    for (unsigned int i = 1; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            is_writing = 0;
            tab[index][0] = my_get_number(buf);
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
}

static void fill_hero_info(int **tab, char *path)
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
    fill_tab(tab, buffer);
}

static void alloc_lines(int **tab, unsigned int limit, char *path)
{
    for (unsigned int i = 0; i < limit; i++) {
        tab[i] = my_calloc(sizeof(int), (20) + 1);
        if (path == NULL)
            tab[i][0] = 0;
        if (tab[i] == NULL)
            return;
    }
    if (path != NULL)
        fill_hero_info(tab, path);
}

static int alloc_hero(hero_status_t *hero_status)
{
    hero_status->stats = my_calloc(sizeof(int *), (10) + 1);
    if (hero_status->stats == NULL)
        return -1;
    alloc_lines(hero_status->stats, 11, "statistics.cfg");
    hero_status->inventory = my_calloc(sizeof(int *), (9) + 1);
    if (hero_status->inventory == NULL)
        return -1;
    alloc_lines(hero_status->inventory, 8, "inventory.cfg");
    hero_status->passive_skills = my_calloc(sizeof(int *), (3) + 1);
    if (hero_status->passive_skills == NULL)
        return -1;
    alloc_lines(hero_status->passive_skills, 3, "passive_skills.cfg");
    hero_status->active_skills = my_calloc(sizeof(int *), (5) + 1);
    if (hero_status->active_skills == NULL)
        return -1;
    alloc_lines(hero_status->active_skills, 5, "active_skills.cfg");
    hero_status->unlocked_skills = my_calloc(sizeof(int *), (5) + 1);
    if (hero_status->unlocked_skills == NULL)
        return -1;
    alloc_lines(hero_status->unlocked_skills, 6, NULL);
    return 0;
}



int load_hero_status(hero_status_t *hero_status)
{
    if (alloc_hero(hero_status) == -1)
        return -1;
    return 0;
}
