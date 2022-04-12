/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef HEADER_FILE
#define HEADER_FILE

#include <stddef.h>

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

typedef struct bit_info_t bit_info_t;
struct bit_info_t {
    int bit_counter;
    int size;
    int print;
    int i;
    int nb_one_bis;
    int nb_neg;
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
int my_get_number(char *str);;
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
list *init(int nb, list *my_list);
int fill_list(char *argv[]);
void sa(list_elem **my_list);
void clear_list(list *my_list);
void push_back(list *my_list, int new_nb);
void sb(list *my_list);
void sc(list_elem **first, int *a, int *b);
void pa(list *my_list_bis, list *my_list);
void pb(list *my_list, list *my_list_bis);
void ra(list *my_list);
void rb(list *my_list);
void rrb(list *my_list);
int run_algo(int argc, char *argv[]);
void move_list(int index, list *my_list, int nb);
void replace_neg(list *list_a, list *list_b, bit_info_t *bit_info);
int get_max(int max);
int run_my_radix(list *list_a, list *list_b, int max, bit_info_t bit_info);
void pb_bis(list *my_list , list *my_list_bis);
void bit_one(list *list_a, list *list_b, bit_info_t *bit_info, int max);
void check_bit_bis(list *list_a, list *list_b, int counter);
void rra(list *my_list);
int if_unsorted(list *list_a, list *list_b, int max, bit_info_t bit_info);
void bit_zero_bis(list *list_a, list *list_b, bit_info_t *bit_info);
void bit_zero(list *list_a, list *list_b, int max, bit_info_t *bit_info);
void bit_one_bis(list *list_a, bit_info_t *bit_info, int max);
long val_max(long nb, long max);
#endif
