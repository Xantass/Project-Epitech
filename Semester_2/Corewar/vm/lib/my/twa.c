/*
** EPITECH PROJECT, 2021
** twa.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

static unsigned int is_delim(char *delim, char c)
{
    if (c == '\n')
        return 1;
    if (delim == NULL)
        return 0;
    for (unsigned int i = 0; delim[i] != '\0'; i++) {
        if (delim[i] == c)
            return 1;
    }
    return 0;
}

static unsigned int get_size(char *content, char *delim)
{
    unsigned int res = 1;

    if (delim == NULL)
        return get_size_without_delim(content);
    for (unsigned int i = 0; content[i] != '\0'; i++) {
        for (unsigned int j = 0; delim[j] != '\0'; j++) {
            if (is_delim(delim, content[i]) == 1)
                res++;
        }
    }
    return res;
}

static char **alloc_tab(unsigned int size, unsigned int limit)
{
    char **tab = my_calloc(sizeof(char *), (size) + 1);

    if (tab == NULL)
        return NULL;
    for (unsigned int i = 0; i < size; i++) {
        tab[i] = my_calloc(sizeof(char), (limit) + 1);
        if (tab[i] == NULL)
            return NULL;
    }
    return tab;
}

static void fill_tab(char **tab, char *content, char *delim)
{
    unsigned int counter = 0;
    unsigned int offset = 0;

    for (unsigned int i = 0; content[i] != '\0'; i++) {
        if (is_delim(delim, content[i]) == 1) {
            counter++;
            offset = 0;
        }
        else {
            tab[counter][offset] = content[i];
            offset++;
        }
    }
}

char **twa(char *content, char *delim)
{
    char *clean_content = clean_str(content);
    unsigned int size = get_size(clean_content, delim);
    char **tab = alloc_tab(size, my_strlen(clean_content));

    if (tab == NULL)
        return NULL;
    fill_tab(tab, clean_content, delim);
    free(clean_content);
    return tab;
}
