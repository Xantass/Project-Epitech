/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** fonction
*/

#include <stdio.h>
#include <stdlib.h>

int my_putstr(char const *str);

void my_putchar(char c);

int is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    if (c >= 'A' && c <= 'Z') {
        return (1);
    }
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}

int totale_number(int i, int *j, char const *str, int *k)
{
    int o = 0;

    while (o < 1) {
        if (is_alphanum(str[*k]) == 0) {
            (*k)++;
        } else {
            o++;
        }
    }

    while (str[i] != '\0') {
        if (is_alphanum(str[i]) == 0) {
            (*j)++;
        }
        i++;
    }
    return (i);
}

char **allo_memory(int *j, int h, int i, char **memory_word)
{
    while (*j > 0) {
        memory_word[h] = malloc(sizeof(char) * (i + 1));
        h++;
        (*j)--;
    }
    return (memory_word);
}

char **copy(int *k, int *g, int *h, char const *str, char **memory_word)
{
    while (str[*k] != '\0') {
        if (is_alphanum(str[*k]) == 0) {
            memory_word[*h][*g] = '\0';
            (*h)++;
            *g = 0;

        }  else {
            memory_word[*h][*g] = str[*k];
            (*g)++;
        }
        (*k)++;
    }
    return (memory_word);

}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 1;
    int h = 0;
    int g = 0;
    int k = 0;

    i = totale_number(i, &j, str, &k);

    char **memory_word = malloc(sizeof(char *) * (j + 1));
    memory_word[j] = NULL;

    allo_memory(&j, h, i, memory_word);

    copy(&k, &g, &h, str, memory_word);
    memory_word[h][g] = '\0';
    memory_word[h + 1] = NULL;
    return (memory_word);
}
