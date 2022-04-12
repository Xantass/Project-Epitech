/*
** EPITECH PROJECT, 2020
** parentheses_same_count
** File description:
** femwiofwhio
*/

int parentheses_same_count(char *str)
{
    int open = 0;
    int close = 0;

    for (; *str != '\0'; str++) {
        if (*str == '(')
            open++;
        if (*str == ')')
            close++;
    }
    if (open != close)
        return 0;
    else
        return 1;
}
