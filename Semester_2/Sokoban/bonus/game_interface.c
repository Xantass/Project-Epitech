/*
** EPITECH PROJECT, 2021
** game_interface.c
** File description:
** function
*/

#include <ncurses.h>
#include <stdlib.h>
#include "list.h"
#include "proto.h"
#include "struct.h"

int sokoban(info_t *f, char *path);
char **load_script(char const *filepath);
int check(int x, int y, list_t *list, char **str);
int check_map(char **str, info_t *f);
void print_usage(void);
int check_end_game(char **str, list_t *list);
list_t *init_list(void);
void reset(char *path, info_t *f);
int choose(info_t *f, char *path);
int move_(int key, list_t *list, char **str);
void print(char **str, list_t *list, info_t *f);

static int init_map(info_t *f)
{
    f->map = malloc(sizeof(char *) * 5);
    f->map[4] = NULL;
    f->map[0] = "map/map";
    f->map[1] = "map/map_1";
    f->map[2] = "map/map_2";
    f->map[3] = "map/map_3";
    return 0;
}

static int sokoban_bis(info_t *f)
{
    int key = 0;
    static int i = 0;
    static int time = 0;
    int row  = 0;
    int col = 0;

    init_map(f);
    reset(f->map[i], f);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        getmaxyx(stdscr, row, col);
        mvprintw(0, col - 10, "time : %d", time);
        print(f->str, f->list, f);
        key = getch();
        if (key == ' ')
            reset(f->map[i], f);
        move_(key, f->list, f->str);
        check_end_game(f->str, f->list);
        if (f->list->score == f->nb_O) {
            i++;
            f->list->score = 0;
            f->nb_O = 0;
            f->nb_X = 0;
            if (i > 3)
                break;
            reset(f->map[i], f);
            check_map(f->str, f);
        }
        time++;
        refresh();
    }
    endwin();
    return 0;
}

int choose(info_t *f, char *path)
{
    int key = 0;
    int col = 0;
    int row = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while(1) {
        clear();
        getmaxyx(stdscr, row, col);
        mvprintw(row / 2, col/ 2 - 15, "1: for the level choose on argument\n");
        mvprintw(row / 2 + 1, col / 2 - 15, "2: for all level one by one\n");
        move(row / 2 + 2, col / 2 - 15);
        key = getch();
        if (key == '1') {
            endwin();
            sokoban(f, path);
            return 0;
        }
        if (key == '2') {
            endwin();
            sokoban_bis(f);
            return 0;
        }
        refresh();
    }
    endwin();
    return 0;
}
