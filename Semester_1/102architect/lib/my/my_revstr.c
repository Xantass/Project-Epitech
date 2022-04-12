/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int first_letter = 0;
    int last_letter = my_strlen(str) - 1;
    char stockage;

    while (first_letter < last_letter) {
        stockage = str[first_letter];
        str[first_letter] = str[last_letter];
        str[last_letter] = stockage;
        first_letter++;
        last_letter--;
    }
    return (str);
}
