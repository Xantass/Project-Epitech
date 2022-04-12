/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get
*/

#ifndef GET_H_
#define GET_H_

int is_number(char const *str);
int is_instruction(char const *str);
int is_label(char const *str, int start);

static const int direct_size[] = {
    4,
    4,
    2,
    2,
    2,
    4,
    4,
    4,
    2,
    2,
    2,
    2,
    4,
    2,
    2,
    2
};

#endif /* !GET_H_ */
