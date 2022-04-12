/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** function
*/

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
