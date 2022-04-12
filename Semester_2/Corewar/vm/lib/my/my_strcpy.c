/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** function
*/

char *my_strcpy(char *dest, char const *src)
{
    int j = 0;

    while (src[j] != '\0') {
        dest[j] = src[j];
        j = j + 1;
    }
    dest[j] = '\0';
    return (dest);
}
