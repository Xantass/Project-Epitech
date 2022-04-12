/*
** EPITECH PROJECT, 2020
** my_print_comb2.c
** File description:
** 
*/

#include <unistd.h>
void my_putchar(char c)
{
    write(1 , &c, 1);
}
int my_print_comb2(void)
{
    int number1;
    int number2;
    for (number1 = '0'; number1 <= '99'; number1++)
    {
        for (number1 = number2 + 1; number2 <= '99'; number2++)
        {
            my_putchar(number1);
            my_putchar(number2);
            if (number1 == '98' && number2 == '99')
            {
                return(0);
            }
        }
    }
}
int main(void)
{
    my_print_comb2();
}
