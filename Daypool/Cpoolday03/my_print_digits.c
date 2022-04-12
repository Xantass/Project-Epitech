/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/
int my_print_digits(void)
{
    int digit;

    digit = '0';
    while (digit <= '9')
    {
        my_putchar(digit);
        digit = digit + 1;
    }
}

