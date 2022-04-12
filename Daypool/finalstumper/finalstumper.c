/*
** EPITECH PROJECT, 2020
** finalstumper
** File description:
** reading output of rush1 binary 
** and finding which binary it is
*/

#include "rush3.h"
#include <stdio.h>

void rush3(char *buff)
{
    int a = find_size(buff[0]) - '0';
    int b = find_size(buff[1]) - '0';
    
    if (choose_rush(buff) == 1)
        my_putstr("[rush1-1] ");
    if (choose_rush(buff) == 2)
        my_putstr("[rush1-2] ");
    if (choose_rush(buff) == 3)
        my_putstr("[rush1-3] ");
    if (choose_rush(buff) == 4)
        my_putstr("[rush1-4] ");
    if (choose_rush(buff) == 5)
        my_putstr("[rush1-5] ");
    if (choose_rush(buff) == 6) {
        my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1");
    }
    my_putnbr(a);
    my_putchar(' ');
    my_putnbr(b);
    my_putchar('\n');
}

int choose_rush(char *buff)
{
    int i = 0;
    int j = 0;

    while (buff[i] != '\0')
        i++;
    if (buff[0] == 'o')
        return 1;
    if (buff[0] == '/' || buff[0] == '*')
        return 2;
    if (buff[i] == 'A')
        return 5;
    if (buff[0] == 'B')
        return 6;
    while (buff[j] != '\n') {
        if (buff[j] == 'A')
            return 3;
        if (buff[j] == 'C')
            return 4;
        j++;
    }
    return 0;
}

char *find_size_1(char buff[])
{
    int row;
    int col = 1;
    static char result[3];

    for (int i = 1; buff[i] != '\0'; i++) {
        if (buff[i] == 'o')
            row = i + 1;
        else if(buff[i] == '\n')
            col += 1;
    }
    result = {row + '0', col + '0','\0'};
    return result;
}

int main()
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    // print_rush(buff);
    printf("%s",find_size_1(buff));
    return (0);
}
// char *find_size_2(char buff[])
// {

// }
// char *find_size_3(char buff[])
// {

// }
// char *find_size_4(char buff[])
// {

// }
// char *find_size_5(char buff[])
// {

// }
// char *choose_rush(char buff[])
// {

// }

// void print_rush(int a)
// {
//     switch a
// }