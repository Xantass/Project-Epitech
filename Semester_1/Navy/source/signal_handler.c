/*
** EPITECH PROJECT, 2020
** signal_handler.c
** File description:
** functions
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"
#include "map.h"

static pid_t sig_id;

static void get_enemy_pid(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    (void)sig;
    sig_id = info->si_pid;
}

void attack_signal()
{
    sig_id = 0;
}

void connection_signal()
{
    sig_id = 1;
}

int send_pid(char **argv, int enemy_pid, map_t map)
{
    kill(my_get_number(argv[1]), SIGUSR1);
    return player_two(argv[2], enemy_pid, my_get_number(argv[1]), map);
}

int catch_pid(char *pos1, int my_pid, map_t map)
{
    struct sigaction sigact;

    sigact.sa_sigaction = get_enemy_pid;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    pause();
    return player_one(pos1, my_pid, sig_id, map);
}
