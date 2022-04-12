/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** functions
*/

#include <unistd.h>
#include "graph.h"
#include "my.h"

int main(int argc, char *argv[], char **env)
{
    if (env == NULL) {
        write(2, &"no environement\n", 16);
        return 84;
    }
    inits();
    return 0;
}
