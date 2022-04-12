/*
** EPITECH PROJECT, 2020
** turn_bis.c
** File description:
** functions
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "my.h"

static void sig_void()
{
}

static int player_two_following(char *pos2, int enemy_pid, int my_pid, map_t map)
{
    struct sigaction sigact;
    char *cord_attack;
    int win = 0;

    cord_attack = get_attack();
    if (cord_attack == NULL)
        return 0;
    sigact.sa_handler = sig_void;
    sigaction(SIGUSR1, &sigact, NULL);
    kill(my_pid, SIGUSR1);
    send_letter(cord_attack[0], my_pid);
    kill(my_pid, SIGUSR1);
    send_digit(my_get_number(&cord_attack[1]), my_pid);
    if (hit_or_missed(cord_attack, my_pid) == 1) {
        map.is_win++;
        hit(&map, cord_attack);
        map.win_cord = cord_attack;
    }
    else
        missed(&map, cord_attack);
    win = end_game(map);
    if (win == 0)
        return 0;
    return player_two(pos2, enemy_pid, my_pid, map);
}

int player_two(char *pos2, int enemy_pid, int my_pid, map_t map)
{
    struct sigaction sigact;
    char *cord = my_calloc(sizeof(char), (3));
    int res = 0;
    int win = 0;

    sigact.sa_handler = sig_void;
    sigaction(SIGUSR1, &sigact, NULL);
    print_my_map(map.map_player, 1);
    print_enemy_map(map.map_enemy);
    my_putstr("\nwaiting for enemy's attack...\n");
    pause();
    cord[0] = get_letter(my_pid);
    pause();
    cord[1] = get_digit(my_pid);
    res = get_attack_bis(&map, cord);
    send_hit_or_missed(res, my_pid);
    win = end_game(map);
    if (win == 1)
        return 1;
    return player_two_following(pos2, enemy_pid, my_pid, map);
}

static int player_one_following(char *pos1, int my_pid, int enemy_pid, map_t map)
{
    struct sigaction sigact;
    char *cord = my_calloc(sizeof(char), (3));
    int res = 0;
    int win = 0;

    win = end_game(map);
    if (win != 2)
        return win;
    sigact.sa_handler = sig_void;
    sigaction(SIGUSR1, &sigact, NULL);
    my_putstr("waiting for enemy's attack...\n");
    pause();
    cord[0] = get_letter(enemy_pid);
    pause();
    cord[1] = get_digit(enemy_pid);
    res = get_attack_bis(&map, cord);
    send_hit_or_missed(res, enemy_pid);
    win = end_game(map);
    if (win == 1)
        return 1;
    return player_one(pos1, my_pid, enemy_pid, map);
}

int player_one(char *pos1, int my_pid, int enemy_pid, map_t map)
{
    struct sigaction sigact;
    char *cord_attack;

    print_my_map(map.map_player, 0);
    print_enemy_map(map.map_enemy);
    cord_attack = get_attack();
    if (cord_attack == NULL)
        return 0;
    sigact.sa_handler = sig_void;
    sigaction(SIGUSR1, &sigact, NULL);
    kill(enemy_pid, SIGUSR1);
    send_letter(cord_attack[0], enemy_pid);
    kill(enemy_pid, SIGUSR1);
    send_digit(my_get_number(&cord_attack[1]), enemy_pid);
    if (hit_or_missed(cord_attack, enemy_pid) == 1) {
        map.is_win++;
        hit(&map, cord_attack);
        map.win_cord = cord_attack;
    }
    else
        missed(&map, cord_attack);
    return player_one_following(pos1, my_pid, enemy_pid, map);
}
