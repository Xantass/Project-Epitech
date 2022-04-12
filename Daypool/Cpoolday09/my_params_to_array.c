/*
** EPITECH PROJECT, 2020
** my_params_to_array.c
** File description:
** fonction
*/

#include "my_params.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int argc, char **argv)
{
    struct info_param *stock;
    int i = 0;

    stock = malloc(sizeof(struct info_param) * (argc + 1));
    while (i < argc) {
        stock[i].length = my_strlen(argv[i]);
        stock[i].str = argv[i];
        stock[i].copy = my_strdup(argv[i]);
        stock[i].word_array = my_str_to_word_array(argv[i]);
        i++;
    }
    i = i + 1;
    stock[i].str = 0;
    return (stock);
}
