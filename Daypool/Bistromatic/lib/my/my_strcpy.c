/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** fewpodkrcm
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int lensrc = my_strlen(src);
    int i = 0;

    for (; i < lensrc; i++)
        *(dest + i) = *(src + i);
    *(dest + i) = '\0';
    return (dest);
}
