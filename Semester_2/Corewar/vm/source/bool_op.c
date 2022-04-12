/*
** EPITECH PROJECT, 2021
** bool_op.c
** File description:
** functions
*/

void set_bool(short int *bool_tab, unsigned int index)
{
    *bool_tab ^= (1 << index);
}

int get_state(short int *bool_tab, unsigned int index)
{
    return (*bool_tab >> index) & 1;
}

