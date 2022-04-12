/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** error management function
*/

#include <unistd.h>
#include <stddef.h>

int my_check_args(int argc, char **argv)
{
    int i = 2;

    if (argc < 3)
        return (1);

    while (argv[i]) {
        if ((my_strlen(argv[i]) > 1) || (argv[i] == NULL))
            return (1);
        if (my_char_is_alpha(argv[i][0]) == 1)
            return (1);
    i++;
    }
    return (0);
}
