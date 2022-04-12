/*
** EPITECH PROJECT, 2020
** my_print_alpha.c
** File description:
** 
*/
int my_print_alpha(void)
{
    int letter;
    
    letter = 97;
    while (letter <= 122)
    {
        my_putchar(letter);
        letter = letter +1;
    }
}
