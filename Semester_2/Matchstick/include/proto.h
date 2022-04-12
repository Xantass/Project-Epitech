/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "struct.h"

int error_handling(int ac, char **av);
matchstick_t init_struct(char **av);
char **create_map(matchstick_t f);
int *matchstick_by_line(matchstick_t *f);
int game(matchstick_t *f, int *cor);
#endif /* !PROTO_H_ */
