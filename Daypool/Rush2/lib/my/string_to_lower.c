/*
** EPITECH PROJECT, 2018
** rush2
** File description:
** convert string to lower
*/

char *string_to_lower(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
        }
    return (str);
}
