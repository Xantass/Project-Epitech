/*
** EPITECH PROJECT, 2020
** turn_ter.c
** File description:
** functions
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

static int sig_id;

static void sig_one()
{
    sig_id = 1;
}

static void sig_two()
{
    sig_id = 0;
}

static int get_digit_following(char *b_value, char c, long long res)
{
    my_revstr(b_value);
    res = my_get_number_spe(b_value);
    res = binary_to_decimal(res);
    return c = res + 48;
}

int get_digit(int sender_pid)
{
    struct sigaction sigact;
    struct sigaction sigact_bis;
    long long res = 0;
    char *b_value = my_calloc(sizeof(char), (5));
    char c = 0;

    sigact_bis.sa_handler = sig_one;
    sigaction(SIGUSR1, &sigact_bis, NULL);
    sigact.sa_handler = sig_two;
    sigaction(SIGUSR2, &sigact, NULL);
    kill(sender_pid, SIGUSR1);
    for (int i = 0; i < 8; i++) {
        pause();
        if (sig_id == 1)
            b_value[i] = '1';
        else
            b_value[i] = '0';
        kill(sender_pid, SIGUSR1);
    }
    return get_digit_following(b_value, c, res);
}
