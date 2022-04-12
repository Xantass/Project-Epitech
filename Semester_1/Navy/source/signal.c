/*
** EPITECH PROJECT, 2020
** signals.c
** File description:
** functions
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include "my.h"

static void blank()
{
    my_putstr("\nenemy connected\n");
}

int get_connection(char *argv[], int argc, pid_t pid)
{
    map_t map;
    struct sigaction sigact;

    sigact.sa_handler = blank;
    sigaction(SIGUSR2, &sigact, NULL);
    if (argc == 3) {
        if (kill(my_get_number(argv[1]), SIGUSR2) == -1)
            return 84;
        else {
            game(argv[2], &map);
            my_putstr("\nsucessfully connected\n\n");
            sigact.sa_handler = attack_signal;
            return send_pid(argv, pid, map);
        }
    }
    my_putstr("\nwaiting for enemy connection...\n");
    game(argv[1], &map);
    pause();
    return catch_pid(argv[1], pid, map);
}

int get_max(int value)
{
    unsigned int counter = 0;

    while (value) {
        counter++;
        value >>= 1;
    }
    return counter;
}

int get_bit(int value, int position)
{
    int mask = 0b00000001;

    mask = mask << position;
    return (value & mask);
}
