/*
** EPITECH PROJECT, 2020
** my_params.h
** File description:
** fonction
*/
#ifndef my_params
#define my_params

struct info_param
{
    int length;
    char *str;
    char *copy;
    char **word_array;
};

char *my_strdup(char const *src);

char **my_str_to_word_array(char const *str);

int my_strlen(char const *str);

void my_putchar(char c);

#endif
