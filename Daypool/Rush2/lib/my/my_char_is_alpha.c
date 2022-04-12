/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** my str is alpha
*/

int my_char_is_alpha(char c)
{
    if ((c >= 'a') && (c <= 'z'))
        return (0);
    if ((c >= 'A') && (c <= 'Z'))
        return (0);
    if (c == 39)
        return (1);
    return (1);
}
