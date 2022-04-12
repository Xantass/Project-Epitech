/*
** EPITECH PROJECT, 2021
** set_font.c
** File description:
** functions
*/

#include "graph.h"
#include "my.h"

sfFont *set_font(void)
{
    sfFont *my_font = sfFont_createFromFile("./font/arial.ttf");

    return my_font;
}
