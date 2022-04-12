/*
** EPITECH PROJECT, 2021
** boostrap.c
** File description:
** function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "list.h"
#include "proto.h"
#include "struct.h"

char **load_script(char const *filepath);
int check(int x, int y, list_t *list, char **str);
int check_map(char **str, info_t *f);
void print_usage(void);
int check_end_game(char **str, list_t *list);
list_t *init_list(void);
void reset(char *path, info_t *f);
int choose(info_t *f, char *path);

void print(char **str, list_t *list, info_t *f)
{
    int row = 0;
    int col = 0;
    element_t *act = list->first->next;

    getmaxyx(stdscr, row, col);
    while (row < f->line + 1 || col < f->col + 1) {
        clear();
        getmaxyx(stdscr, row, col);
        mvprintw(row / 2, col / 2 - 7, "rezise window");
        refresh();
    }
    mvprintw(0, 0, "Score : %d/%d", f->list->score, f->nb_O);
    for (int i = 0; str[i] != NULL; i++)
        mvprintw(row / 2 + i - (f->line/2), col / 2 - (f->col/2), "%s", str[i]);
    for (int i = 0; i < list->size; i++) {
        if (act->nb != 1)
            mvprintw(row/2+act->x-(f->line/2),col/2+act->y-(f->col/2),
                     "%c",act->c);
        act = act->next;
    }
    move(row / 2 + list->first->x-(f->line/2),col/2+list->first->y-(f->col/2));
}

char **modif(char **str, list_t *list)
{
    int *cor = malloc(sizeof(int) * 2);

    for (int i = 0; str[i] != NULL; i++) {
        for (int j = 0; str[i][j] != '\0'; j++) {
            if (str[i][j] == 'X') {
                cor[0] = i;
                cor[1] = j;
                inser_back(list, cor, str[i][j]);
                str[i][j] = ' ';
            }
            if (str[i][j] == 'P') {
                cor[0] = i;
                cor[1] = j;
                inser_front(list, cor, str[i][j]);
                str[i][j] = ' ';
            }
            if (str[i][j] == 'O') {
                cor[0] = i;
                cor[1] = j;
                inser_back(list, cor, str[i][j]);
            }
        }
    }
    return str;
}

int move_(int key, list_t *list, char **str)
{
    int x = 0;
    int y = 0;
    
    if (key == 259) {
        if (check(x - 1, y, list, str) == 0)
            list->first->x -= 1;
    }
    if (key == 258) {
        if (check(x + 1, y, list, str) == 0)
            list->first->x += 1;
    }
    if (key == 261) {
        if (check(x, y + 1, list, str) == 0)
            list->first->y += 1;
    }
    if (key == 260) {
        if (check(x, y - 1, list, str) == 0)
            list->first->y -= 1;
    }
    return 0;
}

int sokoban(info_t *f, char *path)
{
    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        print(f->str, f->list, f);
        if (f->list->score == f->nb_O)
            break;
        key = getch();
        if (key == ' ')
            reset(path, f);
        move_(key, f->list, f->str);
        check_end_game(f->str, f->list);
        refresh();
    }
    endwin();
    return 0;
}

int main(int argc, char **argv)
{
    info_t f = {0};

    f.list = init_list();
    if (argc == 0)
        return 84;
    if (argc > 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    f.str = load_script(argv[1]);
    if (check_map(f.str, &f) == -1)
        return 84;
    f.str = modif(f.str, f.list);
    choose(&f, argv[1]);
    return 0;
}
