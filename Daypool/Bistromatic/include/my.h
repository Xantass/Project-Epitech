/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
void move_ptr_to_next_op(char **str, char const *base);
int my_char_isnum(char const character, char const *base);
int my_getnbr(char const *numstr);
int my_getnbr_modified(char **numstr, char const *base);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_nl(int nb);
void my_putstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isnum_tolerable(char *str, char *base);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int parentheses_same_count(char *str);
int my_compute_power_rec(int nb, int p);
char *minusret(char *nbr, int minus);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
#endif
