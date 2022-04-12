/*
** EPITECH PROJECT, 2021
** unsigned_strlen.c
** File description:
** function
*/

int unsigned_strlen(unsigned char *str)
{
    int res = 0;

    for (; str[res] != '\0'; res++);
    return res;
}
