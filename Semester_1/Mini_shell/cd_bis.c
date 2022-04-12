/*
** EPITECH PROJECT, 2021
** cd_bis.c
** File description:
** function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int reset_env(char *line, info_t *f);

int print_error(char *str)
{
    int fd = open(str, O_RDONLY);

    if (fd == -1) {
        write(2, str, my_strlen(str));
        write(2, &": No such file or directory.\n", 29);
    }
    else {
        write(2, str, my_strlen(str));
        write(2, &": Not a directory.\n", 19);
    }
    return 0;
}


int cd_bis(info_t *f)
{
    if (chdir(f->com[1]) == -1) {
        print_error(f->com[1]);
        return -1;
    }
    reset_env(f->com[1], f);
    return 0;
}
