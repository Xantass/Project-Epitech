/*
** EPITECH PROJECT, 2020
** match.c
** File description:
** projet
*/

int match(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
        }
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return(1);
}

