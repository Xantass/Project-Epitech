/*
** EPITECH PROJECT, 2021
** read_champions.c
** File description:
** functions
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "info.h"
#include "lib.h"
#include "op.h"

static int load_shell_code(prog_info_t *prog_info, int fd)
{
    prog_info->instructions = my_calloc(sizeof(unsigned char),
                                        (prog_info->prog_size) + 1);
    if (prog_info->instructions == NULL)
        return -1;
    if (read(fd, prog_info->instructions, prog_info->prog_size) == -1)
        return -1;
    return 0;
}

static int check_magic_number(prog_info_t *prog_info, header_t header, int fd)
{
    if (END_SWAP(header.magic) != COREWAR_EXEC_MAGIC) {
        write(2, "Bad Magic Number\n\n", 18);
        return -1;
    }
    prog_info->prog_size = END_SWAP(header.prog_size);
    prog_info->name = my_strdup(header.prog_name);
    return load_shell_code(prog_info, fd);
}

static int load_instructions(prog_info_t *prog_info)
{
    header_t header = {0};
    int fd = open(prog_info->name, O_RDONLY);

    if (fd == -1)
        return -1;
    if (read(fd, &header, sizeof(header_t)) == -1)
        return -1;
    if (check_magic_number(prog_info, header, fd) == -1)
        return -1;
    return 0;
}

int read_champions(info_t *info, unsigned int nb_progs)
{
    for (unsigned int i = 0; i < nb_progs; i++) {
        if (load_instructions(&info->prog_info[i]) == -1)
            return -1;
    }
    return 0;
}
