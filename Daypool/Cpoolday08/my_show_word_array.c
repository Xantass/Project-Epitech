/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** fonction
*/

#include <unistd.h>

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int h;
    int j;

    while (tab[h] != NULL) {
        j = 0;
        while (tab[h][j] != '\0') {
            my_putchar(tab[h][j]);
            j++;       
        }
        my_putchar('\n');
        h++;
    }
    return (0);
}
    
