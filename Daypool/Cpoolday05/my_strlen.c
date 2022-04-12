/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** 
*/
int my_strlen(char const *str) {
    int nb_arr = 0;
    if (str[nb_arr] != '\0') {
        nb_arr++;
    }
    else if (str[nb_arr] == '\0') {
        return(nb_arr);
        }
}

