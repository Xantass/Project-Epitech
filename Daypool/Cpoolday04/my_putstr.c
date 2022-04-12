/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** 
*/  
int my_putstr(char const *str) {
    int nb_arr = 0;
    while (str[nb_arr] != '\0') {
        my_putchar(str[nb_arr]);
        nb_arr++;
    }
}

