/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef HEADER_FILE
#define HEADER_FILE

#include <stddef.h>

typedef struct select_zone_t select_zone_t;
struct select_zone_t {
    int is_selected;
    sfVector2f starting_point;
      sfVector2f end_point;
};

typedef struct mouse_actions_t mouse_actions_t;
struct mouse_actions_t {
    int up;
    int down;
    int resize;
    int plus;
    int less;
};

typedef struct info_t info_t;
struct info_t {
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    int *size_map;
    int **map;
    sfVector2f **map_zero;
    sfVector2f **map_modif;
    sfConvexShape **shape;
    sfRectangleShape *hitbox;
    sfVector2i mouse_pos;
    mouse_actions_t mouse_actions;
    sfEvent last_event;
    select_zone_t select_zone;
};

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
int my_get_number(char *str);;
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
void print_list(list *my_list);
void pop_front(list *my_list);
void push_front(list *my_list, int new_nb);
list *init(int nb, list *my_list);
int fill_list(char *argv[]);
void sa(list_elem **my_list);
void clear_list(list *my_list);
void push_back(list *my_list, int new_nb);
sfRenderWindow *init_window(void);
sfVector2f **compute_map(int **map, info_t *info);
sfVector2f **core(info_t *info);
void *my_calloc_bis(size_t nmemb, size_t size);
int events(info_t *info);
int inits(void);
sfTexture *set_raise_button_texture(void);
void set_buttons(info_t *info);
sfTexture *set_down_button_texture(void);
void set_less_button(info_t *info);
void set_plus_button(info_t *info);
sfTexture *set_resize_button_texture(void);
sfTexture *set_plus_button_texture(void);
sfTexture *set_less_button_texture(void);
void display_button(sfRectangleShape *button, info_t *info);
sfTexture *set_up_clicked_button(void);
sfTexture *set_down_clicked_button(void);
sfTexture *set_resize_clicked_button(void);
sfTexture *set_plus_clicked_button(void);
sfTexture *set_less_clicked_button(void);
void print_up_info(info_t *info);
void print_down_info(info_t *info);
void print_resize_info(info_t *info);
void print_plus_info(info_t *info);
void print_less_info(info_t *info);
sfFont *set_font(void);
void get_new_input(info_t *info);
void display_cadre(info_t *info, sfVector2f pos);
sfVector2f **create_2d_map(int **map, info_t *info);
int **init_map_tab(info_t *info);
sfVector2f project_iso_point(int x, int y, int z);
sfConvexShape **create_tab_convex(info_t *info, sfVector2f **point);
int **rezize_map_up(info_t *info, int **old_map);
int **rezize_map_down(info_t *info, int **old_map);
sfVector2f rotations(int x, int y, int z, double nb);
sfVector2f **modif_rotation(sfVector2f **point, info_t *info, double nb);
sfVector2f translations(sfVector2f point);
void close_selected_zone(info_t *info);
void get_selected_zone(info_t *info);
int check_cord_cursor(info_t *info);
void set_mouse_hitbox(info_t *info);
#endif
