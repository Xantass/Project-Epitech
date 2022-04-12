/*
** EPITECH PROJECT, 2021
** asm
** File description:
** check_type
*/

#include "struct.h"
#include "check_type.h"

static int is_reg(char *str)
{
    int nb = 0;

    if (str[0] != REG)
        return -1;
    if (str[1] == '\0')
        return -1;
    if (is_number(&str[1]) == 84)
        return -1;
    nb = get_nbr(&str[1]);
    if (nb > REG_NUMBER)
        return -1;
    if (nb < 1)
        return -1;
    return 0;
}

static int is_direct(char *str)
{
    if (str[0] != DIRECT_CHAR)
        return -1;
    if (str[1] == '\0')
        return -1;
    if (str[1] == LABEL_CHAR)
        return 0;
    if (is_number(&str[1]) == 84)
        return -1;
    return 0;
}

static int is_indirect(char *str)
{
    if (str[0] == DIRECT_CHAR)
        return -1;
    if (str[0] == REG)
        return -1;
    return 0;
}

static int choose_type(char *str, int type)
{
    if (type == R)
        return is_reg(str);
    if (type == D)
        return is_direct(str);
    if (type == RD)
        if (is_direct(str) == -1 && is_reg(str) == -1)
            return -1;
    if (type == I)
        return is_indirect(str);
    if (type == DI)
        if (is_direct(str) == -1 && is_indirect(str) == -1)
            return -1;
    if (type == RDI)
        if (is_direct(str) == -1 && is_reg(str) == -1 && is_indirect(str) == -1)
            return -1;
    return 0;
}

int check_type(inst_t *cur)
{
    int nb_arg = op_tab[cur->op_code - 1].nbr_args;
    int nb = 0;

    if (is_label(cur->args[nb], 0) != 84)
        nb++;
    if (is_instruction(cur->args[nb]) != 84)
        nb++;
    nb_arg += nb;
    for (int i = nb, type = 0; i < nb_arg; ++i, ++type) {
        if (choose_type(
            cur->args[i], op_tab[cur->op_code - 1].type[type]) == -1)
            return -1;
    }
    return 0;
}