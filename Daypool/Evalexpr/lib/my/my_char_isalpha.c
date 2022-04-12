/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
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
