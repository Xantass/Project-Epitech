/*
** EPITECH PROJECT, 2021
** alea.c
** File description:
** function
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "my.h"
#include "list.h"

int alea(void)
{
    int i = 0;

    i = rand();
    while (1) {
        if (i <= 10 && i >= 0)
            break;
        i = i / 10;
    }
    return i;
}
