/*
** EPITECH PROJECT, 2020
** my_char_isnum
** File description:
** fiedsffefwhewq
*/

int my_char_isnum(char const character, char const *base)
{
    for (; *base != '\0'; base++) {
        if (character == *base)
            return (1);
    }
    return 0;
}
