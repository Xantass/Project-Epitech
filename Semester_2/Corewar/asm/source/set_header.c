/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** set_header
*/

#include <stddef.h>
#include <stdlib.h>
#include "struct.h"
#include "op.h"

static int is_empty(char *s)
{
    for (int i = 0; s[i] && s[i] != COMMENT_CHAR && s[i] != '\n'; i++)
        if (s[i] != ' ' && s[i] != '\t')
            return -1;
    return 0;
}

static int copy(char name[], char *comment, short max)
{
    int i = 0;

    for (; comment[i] && comment[i] != 34 && i < max; i++) {
        name[i] = comment[i];
    }
    if (comment[i] != 34 || is_empty(comment + i + 1) || i + 1 > max)
        return -1;
    name[i] = 0;
    return 0;
}

static int check_header(char const *exp, char *str, char name[], short max)
{
    int i = 0;
    int j = 0;

    for (; *str == ' '; str += 1);
    for (; exp[i] && str[j]; i++, j++)
        if (exp[i] != str[j])
            return -1;
    for (; str[j] == ' '; j++);
    if (exp[i] == 0 && str[j] == 34) {
        if (copy(name, str + j + 1, max) == -1)
            return -1;
        return 0;
    }
    return -1;
}

int set_header(file_t *file, info_t *info)
{
    header_t header = {0};
    char *name = file->file[0];
    char *com = file->file[1];

    if (com == NULL)
        return -1;
    header.magic = SWAP_ENDIAN(COREWAR_EXEC_MAGIC);
    if (check_header(NAME_CMD_STRING, name,
        header.prog_name, PROG_NAME_LENGTH) == -1)
        return -1;
    if (check_header(COMMENT_CMD_STRING, com,
        header.comment, COMMENT_LENGTH) == -1)
        return -1;
    info->head = header;
    return 0;
}