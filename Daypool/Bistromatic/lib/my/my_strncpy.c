/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** fcnewiocm
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int nulll = 0;

    if (n <= 0 || *src == '\0') {
        *dest = '\0';
        return dest;
    }
    for (i = 0; i < n; i++) {
        if (*(src + i) == '\0')
            nulll = 1;
        if (nulll == 0)
            *(dest + i) = *(src + i);
        else
            *(dest + i) = '\0';
    }
    *(dest + i) = '\0';
    return (dest);
}
