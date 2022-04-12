/*
** EPITECH PROJECT, 2021
** write_bit.c
** File description:
** functions
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static void display_byte(char c)
{
    write(1, &c, 1);
}

static int bit_by_bit(unsigned char res, int mask, char c, int pt)
{
    int mask_bis = 0b10000000;
    int nb = 0;

    nb |= res;
    mask_bis = mask_bis >> (pt - 1);
    for (int i = 0; i < pt; i++) {
        if (mask & c) {
            res = res ^ mask_bis;
            nb = nb ^ mask_bis;
            mask_bis = mask_bis << 1;
            mask = mask << 1;
        }
        else {
            mask_bis = mask_bis << 1;
            mask = mask << 1;
        }
    }
    display_byte(res);
    c = c >> pt;
    res = 0;
    return res |= c;
}

static char write_byte(char c, int pt)
{
    static unsigned char res = 0;
    int mask = 0b00000001;
    int mask_bis = 0b10000000;

    if (pt == 0) {
        res |= c;
        return res;
    }
    else if (pt == 1) {
        if (c & mask)
            res = res ^ mask_bis;
        display_byte(res);
        c = c >> pt;
        res = 0;
        res |= c;
        return res;
    }
    else if (pt >= 2)
        res = bit_by_bit(res, mask, c, pt);
    return res;
}

void send_string(char *str)
{
    int size = my_strlen(str);
    int pt = 0;
    char temp_res = 0;

    for (int i = 0; i < size; i++, pt++) {
        if (pt == 8)
            pt = 0;
        temp_res = write_byte(str[i], pt);
    }
    my_putchar(temp_res);
}
