/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** error management function
*/

#include <unistd.h>
#include <stddef.h>

int main (int argc , char **argv)
{
    int i = 2;

    if (my_check_args(argc, argv) == 1) {
        write(2, "Invalid Arguments\n", 19);
        return (84);
    } else {
        string_to_lower(argv[1]);
        while (argv[i] != NULL) {
            comparative_function(argv[1], argv[i][0]);
        i++;
        }
    }
    return (0);
}
