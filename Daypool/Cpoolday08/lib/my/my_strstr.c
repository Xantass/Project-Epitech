/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** fonction
*/

char *return_to_find(char const *to_find, int a, char *str, int b)
{
    if (to_find[b + 1] == '\0') {
        return (str + a);
    }
    b = b + 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        b = 0;
        while (to_find[b] == str[a + 1]) {
            return (return_to_find(to_find, a, str, b));
        }
        a = a + 1;
    }
    return (0);
}
