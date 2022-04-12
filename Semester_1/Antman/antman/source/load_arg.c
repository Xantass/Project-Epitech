/*
** EPITECH PROJECT, 2021
** load_arg.c
** File description:
** functions
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

char *load_file_in_mem(char *filepath)
{
    char *map;
    struct stat temp = {0};
    __attribute__((cleanup(clean_fd)))int res_open = open(filepath, O_RDONLY);

    if (res_open == -1)
        return NULL;
    if (stat(filepath, &temp) == -1)
        return NULL;
    if ((map = my_calloc(sizeof(char), (temp.st_size + 1))) == NULL)
        return NULL;
    if (map == NULL)
        return NULL;
    if (read(res_open, map , temp.st_size) == -1)
        return NULL;
    return map;
}
