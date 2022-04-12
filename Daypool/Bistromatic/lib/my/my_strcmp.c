/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** vmrekwmclk
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (1) {
        if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
            return result;
        if (*(s1 + i) != *(s2 + i)) {
            result = *(s1 + i) - *(s2 + i);
            return result;
        }
        i++;
    }
}
