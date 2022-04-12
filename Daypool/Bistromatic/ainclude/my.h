/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** mymymymmyionf
*/

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
void my_putchar(char a);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr_nl(int nb);
int my_getnbr_modified(char **numstr, char const *base);
int my_char_isnum(char const character, char const *base);
void move_ptr_to_next_op(char **str, char const *base);
int parentheses_same_count(char *str);
#endif
