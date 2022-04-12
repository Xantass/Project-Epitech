/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include "my.h"
#include "signals.h"

int main(int argc, char *argv[])
{
    pid_t pid;
    int res = 0;

    pid = getpid();
    my_putstr("my_pid: ");
    my_put_number(pid);
    res = get_connection(argv, argc, pid);
    if (res != 0 && res != 1)
        return 84;
    else
        return res;
    return 0;
}
