/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_file
*/

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lib.h"
#include "struct.h"

static int is_empty(char *s)
{
    for (int i = 0; s[i] && s[i] != COMMENT_CHAR && s[i] != '\n'; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return -1;
    return 0;
}

static int get_nb_line(char *filepath, file_t *file)
{
    int nb = 0;
    FILE *fd = fopen(filepath, "r");
    size_t buf = 0;
    char *line  = {0};

    while (getline(&line, &buf, fd) != -1) {
        if (is_empty(line) != 0)
            nb++;
    }
    fclose(fd);
    file->nb = nb;
    return nb;
}

static char *modif_str(char *line, char old, char new)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(line) + 1));
    int i = 0;

    for (; line[i] && line[i] != '\n'; i++)
        if (line[i] == old)
            cpy[i] = new;
        else if (line[i] == '#')
            break;
        else
            cpy[i] = line[i];
    cpy[i] = 0;
    return cpy;
}

int get_file(char *filepath, file_t *file)
{
    FILE *fd = fopen(filepath, "r");
    size_t buf = 0;
    char *line  = {0};
    char **file_ = {0};
    int nb_line = 0;

    if (fd == NULL)
        return -1;
    nb_line = get_nb_line(filepath, file);
    file_ = malloc(sizeof(char *) * nb_line);
    nb_line = 0;
    while (getline(&line, &buf, fd) != -1) {
        if (line[0] != COMMENT_CHAR && line[0] != '\n' && is_empty(line) != 0)
            file_[nb_line] = my_strdup(modif_str(line, '\t', ' '));
        if (is_empty(line) != 0)
            nb_line++;
    }
    file->file = file_;
    fclose(fd);
    return 0;
}