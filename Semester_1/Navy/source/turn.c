/*
** EPITECH PROJECT, 2020
** turn.c
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

char get_letter(int sender_pid)
{
    struct sigaction sigact;
    struct sigaction sigact_bis;
    char *res = my_calloc(sizeof(char), (2));
    int b_res = 0;
    char *b_value = my_calloc(sizeof(char), (9));

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
    b_res = binary_to_decimal(my_get_number(b_value));
    return res[0] = b_res;
}
