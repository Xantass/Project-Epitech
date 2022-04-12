/*
** EPITECH PROJECT, 2021
** uncompress.c
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char uncomp_bis(int *counter, int mask, unsigned char res,
                       unsigned char c)
{
    int mask_ter = 0b00000001;

    for (int i = 0; i < 8 - *counter; i++) {
        if (c & mask)
            res = (res | mask_ter);
        mask = mask << 1;
        mask_ter = mask_ter << 1;
    }
    if (*counter > 0)
        *counter= *counter - 1;
    else
        *counter = 7;
    return res;
}

static void uncomp(unsigned char c)
{
    static int counter = 7;
    static unsigned char res = 0;
    int mask = 0b00000001;
    int mask_bis = 0b00000001;

    mask_bis = mask_bis << (7 - counter);
    for (int i = 0; i < counter; i++) {
        if (c & mask)
            res = (res | mask_bis);
        mask_bis = mask_bis << 1;
        mask = mask << 1;
    }
    write(1, &res, 1);
    res = 0;
    mask = 1;
    mask = mask << counter;
    if (counter == 0) {
        counter = 7;
        return uncomp(c);
    }
    res = uncomp_bis(&counter, mask, res, c);
}

void send_string(char *comp_str)
{
    for (int i = 0; comp_str[i] != '\0'; i++) {
        uncomp(comp_str[i]);
    }
}
