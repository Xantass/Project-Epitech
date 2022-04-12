/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct matchstick_t matchstick_t;
struct matchstick_t {
    int line_nb;
    int matches;
    int nb_last_l;
    char **str;
    int *matchsticks;
    int total_matchsticks;
};
#endif /* !STRUCT_H_ */
