/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** is_functions
*/

#include "struct.h"
#include "lib.h"

int is_label_char(char c)
{
    for (int i = 0; LABEL_CHARS[i] != 0; i++)
        if (LABEL_CHARS[i] == c)
            return 0;
    return 84;
}

int is_label(char const *str, int start)
{
    int i = start;

    if (str[0] == LABEL_CHAR && start == 0)
        return 84;
    for (; str[i] != LABEL_CHAR; i++) {
        if (str[i] == 0) {
            if (start == 0)
                return 84;
            else
                break;
        }
        if (is_label_char(str[i]) != 0)
            return 84;
    }
    return 0;
}

int is_instruction(char *str)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (my_strcmp(op_tab[i].mnemonique, str) == 0)
            return op_tab[i].code;
    return 84;
}

int is_number(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[0] == '-')
            continue;
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    return 0;
}

int is_empty(char *s)
{
    for (int i = 0; s[i] && s[i] != COMMENT_CHAR && s[i] != '\n'; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return 84;
    return 0;
}
