/*
** EPITECH PROJECT, 2021
** switch_char_in_tab.c
** File description:
** functions
*/

#include <stddef.h>

void switch_char_in_tab(char **tab, char to_change, char new_char)
{
    for (unsigned int i = 0; tab[i] != NULL; i++) {
        for (unsigned int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == to_change)
                tab[i][j] = new_char;
        }
    }
}
