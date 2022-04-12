/*
** EPITECH PROJECT, 2020
** my_char_isalpha.c
** File description:
** function
*/

int my_char_isalpha(char a)
{
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') ||
        (a >= '0' && a <= '9') ||
        (a == 95))
        return (1);
    else
        return (0);
}
