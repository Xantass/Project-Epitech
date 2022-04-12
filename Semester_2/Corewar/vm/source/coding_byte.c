/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** coding_byte
*/

#include <stdio.h>
#include <stdlib.h>
#include "op.h"

static unsigned char *extract_coding_byte(unsigned char coding_byte)
{
    unsigned char *code = malloc(4 * sizeof(*code));
    int j = 0;

    if (code == NULL)
        return NULL;
    for (int i = 0; i != 4; i++)
        code[i] = 0;
    for (int i = 7; i >= 0; i -= 2, j++) {
        (((coding_byte >> (i - 1)) & 1) == 1) ? code[j] |= 1 << 0 : 0;
        (((coding_byte >> i) & 1) == 1) ? code[j] |= 1 << 1 : 0;
    }
    return code;
}

unsigned char *get_coding_byte(unsigned char coding_byte, unsigned short cmd)
{
    unsigned char *code = extract_coding_byte(coding_byte);

    if (code == NULL)
        return NULL;
    for (unsigned int i = 0; code[i] != 0; i++) {
        if (((op_tab[cmd].type[i] >> (code[i] - 1)) & 1) != 1)
            return NULL;
    }
    return code;
}
