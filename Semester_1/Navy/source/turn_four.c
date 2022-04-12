/*
** EPITECH PROJECT, 2020
** turn_four.c
** File description:
** functions
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

static void sig_void()
{
}

int end_game(map_t map)
{
    if (map.shipe == 0) {
        hit(&map, map.win_cord);
        print_my_map(map.map_player, 0);
        print_enemy_map(map.map_enemy);
        my_putstr("\nEnemy won\n\n");
        return 1;
    }
    else if (map.is_win == 14) {
        hit(&map, map.win_cord);
        print_my_map(map.map_player, 1);
        print_enemy_map(map.map_enemy);
        my_putstr("\nI won\n\n");
        return 0;
    }
    return 2;
}

void send_letter(char letter, int actual_pid)
{
    static struct sigaction get_sig;
    int ascii_letter = letter;
    char *b_letter = get_binary(ascii_letter);

    get_sig.sa_handler = sig_void;
    sigaction(SIGUSR1, &get_sig, NULL);
    pause();
    for (int i = 0; i < my_strlen(b_letter); i++) {
        if (b_letter[i] == '1')
            kill(actual_pid, SIGUSR1);
        else
            kill(actual_pid, SIGUSR2);
        pause();
        usleep(500);
    }
}

void send_digit(int digit, int actual_pid)
{
    static struct sigaction get_sig;

    get_sig.sa_handler = sig_void;
    sigaction(SIGUSR1, &get_sig, NULL);
    pause();
    for (int i = 0; i < 8; i++) {
        if (get_bit(digit, i) >= 1)
            kill(actual_pid, SIGUSR1);
        else
            kill(actual_pid, SIGUSR2);
        pause();
        usleep(500);
    }
}

void send_hit_or_missed(int nb, int enemy_pid)
{
    static struct sigaction get_sig;

    get_sig.sa_handler = sig_void;
    sigaction(SIGUSR1, &get_sig, NULL);
    pause();
    if (nb == 1)
        kill(enemy_pid, SIGUSR1);
    else
        kill(enemy_pid, SIGUSR2);
    pause();
}
