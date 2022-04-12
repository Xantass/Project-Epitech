/*
** EPITECH PROJECT, 2020
** my_print_params.c
** File description:
** task04
*/
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1 , &c, 1);
}

int  my_putstr(char *argv)
{
    int i = 0;

    while(argv[i] != '\0') {
        my_putchar(argv[i]);
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i = 0;

    my_putstr(argv[0]);
    my_putchar('\n');
    my_putstr(argv[1]);
    my_putchar('\n');
    my_putstr(argv[2]);
    my_putchar('\n');
}
