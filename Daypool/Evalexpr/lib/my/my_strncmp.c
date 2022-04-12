/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int j = 0;

    while (j < n) {
        if (s1[j] > s2[j]) {
            return (s1[j] - s2[j]);
        }
        else if (s1[j] < s2[j]) {
            return (s1[j] - s2[j]);
        } else {
            j++;
        }
    }
}
