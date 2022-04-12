/*
** EPITECH PROJECT, 2021
** twa_bis.c
** File description:
** functions
*/

unsigned int get_size_without_delim(char *content)
{
    unsigned int res = 1;

    for (unsigned int i = 0; content[i] != '\0'; i++) {
        if (content[i] == '\n')
            res++;
    }
    return res;
}

