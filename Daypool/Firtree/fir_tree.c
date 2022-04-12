/*
** EPITECH PROJECT, 2020
** fir_tree.c
** File description:
** 
*/

void branch()
{
    my_putchar(' ');
    my_putchar(' ');
    my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
    my_putchar(' ');
    my_putchar(' ');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('\n');
    my_putchar(' ');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('\n');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('*');
    my_putchar('\n');

}

void trunk()
{
    my_putchar(' ');
    my_putchar(' ');
    my_putchar(' ');
    my_putchar('|');
    my_putchar('\n');
}

void tree(int size)
{
    branch();
    trunk();
}
