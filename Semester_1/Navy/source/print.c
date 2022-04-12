/*
** EPITECH PROJECT, 2020
** print.c
** File description:
** functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

static int res;

static void if_hit()
{
    res = 1;
}

static void if_missed()
{
    res = 2;
}

void print_my_map(char **map, int n)
{
    if (n == 1)
        my_putstr("my positions:");
    else
        my_putstr("\nmy_positions:");
    for (int i = 0; map[i] != NULL; i++) {
        my_putchar('\n');
        my_putstr(map[i]);
    }
}

void print_enemy_map(char **map)
{
    my_putstr("\n\nenemy's positions:");
    for (int i = 0; map[i] != NULL; i++) {
        my_putchar('\n');
        my_putstr(map[i]);
    }
    my_putchar('\n');
}

int hit_or_missed(char *cord_attack, int enemy_pid)
{
    struct sigaction sigact_one;
    struct sigaction sigact_two;

    sigact_one.sa_handler = if_hit;
    sigact_two.sa_handler = if_missed;
    sigaction(SIGUSR1, &sigact_one, NULL);
    sigaction(SIGUSR2, &sigact_two, NULL);
    kill(enemy_pid, SIGUSR1);
    pause();
    write(1, cord_attack, my_strlen(cord_attack) - 1);
    if (res == 1) {
        my_putstr(": hit\n\n");
        kill(enemy_pid, SIGUSR1);
        return 1;
    }
    else if (res == 2) {
        my_putstr(": missed\n\n");
        kill(enemy_pid, SIGUSR1);
        return 2;
    }
    return 0;
}
