/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** write
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "write.h"
#include "lib.h"

static char *add_cor(char const *str)
{
    char *ret = {0};
    int i = 0;
    int j = 0;
    int size = 0;

    for (j = my_strlen(str); str[j] != '/' && j >= 0; --j, ++size);
    ret = malloc(sizeof(char) * (size + 4));
    if (j != 0)
        j++;
    for (; str[j]; j++, i++) {
        if (str[j] == '.' && str[j + 1] == 's' && !str[j + 2])
            break;
        ret[i] = str[j];
    }
    *((int *)(ret + i)) = *((int *)".cor");
    ret[i + 4] = 0;
    return ret;
}

static int coding_byte(inst_t *node)
{
    char *ret = malloc(sizeof(char) * 9);
    int i = 0;
    int buf;
    int j = 1 + (is_label(node->args[0], 0) == 0);

    for (int k = 0; k < 9; k++)
        ret[k] = '0';
    for (; node->args[j] != NULL; j++) {
        if (node->size[j] == 2 && node->args[j][0] != DIRECT_CHAR)
            buf = 3;
        else
            buf = 1 + (node->size[j] == DIR_SIZE || node->size[j] == IND_SIZE);
        ((buf >> 1) & 1) ? ret[i] = '1': '0';
        i++;
        ((buf >> 0) & 1) ? ret[i] = '1': '0';
        i++;
    }
    ret[8] = 0;
    return my_getnbr_base(ret, "01");
}

static void write_len(inst_t *node, int i, int j, int fd)
{
    int nb = 0;

    if (node->size[i] == 1) {
        write(fd, &node->hex[i], 1);
        if (node->coding_byte == 1 && node->args[j][0] != 'r') {
            nb = coding_byte(node);
            write(fd, &nb, 1);
        }
    }
    else if (node->size[i] == 2) {
        nb = SWAP_ENDIAN(node->hex[i]);
        nb = (nb << 16) | (nb >> 16);
        write(fd, &nb, 2);
    }
    else {
        nb = SWAP_ENDIAN(node->hex[i]);
        write(fd, &nb, node->size[i]);
    }
}

static int write_instructions(info_t *a, int fd)
{
    inst_t *tmp = a->ins;

    for (int i = 0, j = 0; tmp != NULL; tmp = tmp->next, i = 0, j = 0) {
        if (is_label(tmp->args[j], 0) == 0) {
            j += 1;
            i += 1;
        }
        for (; tmp->size[i] != -1; i++, j++) {
            if (is_instruction(tmp->args[j]) != 84)
                tmp->size[i] = get_type(tmp->args[j], tmp->op_code);
            write_len(tmp, i, j, fd);
        }
    }
    return 0;
}

int write_new_file(info_t *a)
{
    char *new_filepath = add_cor(a->filename);
    int fd = open(new_filepath, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    int error = 0;

    if (fd < 0)
        return -1;
    write(fd, &(a->head), sizeof(header_t));
    error = write_instructions(a, fd);
    free(new_filepath);
    close(fd);
    return error;
}