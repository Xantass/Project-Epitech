/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef HEADER_FILE
#define HEADER_FILE

#include <stddef.h>
#include <sys/types.h>
#include "signals.h"
#include "map.h"

typedef struct list_elem list_elem;
struct list_elem {
    int nb;
    list_elem *next;
    list_elem *prev;
};

typedef struct list list;
struct list {
    int length;
    list_elem *head;
    list_elem *tail;
};

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
long long my_get_number_spe(char *str);
int my_get_number(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
char *my_strdup(char const *src);
int my_char_isalpha(char a);
int my_char_isoperator(char c);
void *my_memset(char *s, int n, size_t size);
void print_list(list *my_list);
void pop_front(list *my_list);
void push_front(list *my_list, int new_nb);
list *init();
char *my_strcat(char *a, char *b);
char *fill_list(int *tab, int size, int max, int *temp_tab);
void sa(list_elem **my_list);
void clear_list(list *my_list);
void push_back(list *my_list, int new_nb);
void sb(int *a, int *b);
void sc(list_elem **first, int *a, int *b);
void pa(list_elem **first, int *a);
void pb(list_elem **first, int *a);
int *rra(int *tab, int size);
int *ra(int *tab, int size);
char *get_attack();
void rb(list *my_list);
void rrb(list *my_list);
void connection_signal();
void attack_signal();
char *get_binary(int nb);
int my_get_number_mod(char c);
int get_bit(int value, int position);
int get_max(int value);
int get_connection(char *argv[], int argc, pid_t pid);
char ascii(char *str);
long long binary_to_decimal(long long nb);
int player_one(char *pos1, int my_pid, int enemy_pid, map_t map);
int player_two(char *pos2, int enemy_pid, int my_pid, map_t map);
int catch_pid(char *pos1, int my_pid, map_t map);
int send_pid(char **argv, int enemy_pid, map_t map);
char get_letter();
void send_letter(char letter, int actual_pid);
void send_digit(int digit, int actual_pid);
int get_digit();
void missed(map_t *f, char *str);
void hit(map_t *f, char *str);
int get_attack_bis(map_t *f, char *str);
int check_map(char c);
void clean_fd(int* fd);
char *load_file_in_mem(const char *filepath);
char **alloc_map_2d_arr(char const *filepath);
char **load_map_mod(char const *filepath);
int **init_int_2d_array(char **pos);
char **mod(char **map, int *size, int row, int col);
char **mod_map(char **map, int **size);
int game(const char *filepaths, map_t *f);
char **my_str_to_word_array(char *str);
void print_enemy_map(char **map);
void print_my_map(char **map, int n);
int hit_or_missed(char *cord_attack, int enemy_pid);
void send_hit_or_missed(int nb, int enemy_pid);
int end_game(map_t map);
int error_handling(char **argv, int argc);
#endif
