/*
** EPITECH PROJECT, 2020
** my_compute_errors
** File description:
** mcxzoiqrewoi
*/

#include <unistd.h>

int zero_division_err(void)
{
    write(2, "Stop: division by zero\n", 23);
}

int zero_modulo_err(void)
{
    write(2, "Stop: modulo by zero\n", 21);
}

int my_compute_overflow(void)
{
    return (84);
}

int invalid_operator(void)
{
    int my_add(int numI, int numII);
    int my_sub(int numI, int numII);
    int my_mul(int numI, int numII);
    int my_div(int numI, int numII);
    int my_mod(int numI, int numII);
#include "ainclude/operator.h"
#include "ainclude/my_opp.h"

    write (2, "error: only [ ", 14);
    for (int i = 0; OP_FNS[i].character != ""; i++) {
        write (2, OP_FNS[i].character, 1);
        write (2, " ", 1);
    }
    write (2, "] are supported\n", 16);
    return (84);
}
