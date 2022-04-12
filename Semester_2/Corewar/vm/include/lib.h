/*
** EPITECH PROJECT, 2020
** lib.h
** File description:
** header
*/

#ifndef LIB_H
#define LIB_H

#include "info.h"

#include <stddef.h>

void my_uchar_swap(unsigned char *a, unsigned char *b);
char *my_strcat(char *dest, char *src);
char *trans(int nb);
int my_char_isnum(char c);
void *my_calloc(size_t nmemb, size_t size);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_number(int nb);
void my_sort_int_array(int *tab, int size);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_get_number(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
char *my_strdup(char const *src);
int my_char_isalpha(char a);
int my_char_isoperator(char c);
void *my_memset(char *s, int n, size_t size);
char **twa(char *content, char *delim);
void print_tab(char **tab);
void free_tab(char **tab);
char **calloc_tab(unsigned int nb_array, unsigned int line_size);
char *clean_str(char *str);
char *get_next_line(int size);
int parse_args(int argc, char *argv[], char *opt_str, info_t *info);
void fill_tab_with_char(char **tab, char c, unsigned int x, unsigned int y);
char **read_from_file(char *path, char *mode);
void switch_char_in_tab(char **tab, char to_change, char new_char);
unsigned int get_size_without_delim(char *content);
int unsigned_strlen(unsigned char *str);
int my_uchar_strlen(unsigned char *str);
void throw_error(int code, char *error_message);

#endif
