/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** task03
*/

int my_strlen(char const *src);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int size = my_strlen(dest);

    while (i <= nb) {
        dest[size + i] = src[i];
        i++;
    }
    return (dest);
}
