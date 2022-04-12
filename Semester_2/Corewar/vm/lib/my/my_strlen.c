/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** function
*/

int my_uchar_strlen(unsigned char *str)
{
    int res = 0;

    for (; str[res] != '\0'; res++);
    return res;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
