/*
** EPITECH PROJECT, 2020
** do-op.c
** File description:
** fonction
*/

int my_put_nbr(int nb);

void my_putchar(char c);

int sum(char **argv);

int substraction(char **argv);

int multiplication(char **argv);

int division(char **argv);

int modulo(char **argv);

void do_op(char **argv);
{
    int (*add)(char **) = &sum;
    int (*subs)(char **) = &substraction;
    int (*multi)(char **) = &multiplication;
    int (*div)(char **) = &division;
    int (*mod)(char **) = &modulo;

    if (argv[2][0] != '+' && argv[2][0] != '-' &&
        argv[2][0] != '/' && argv[2][0] != '*' && argv[2][0] != '%') {
        my_put_nbr(0);
        my_putchar('\n');
    }
    if (argv[2][0] == '+')
        add(argv);
    if (argv[2][0] == '-')
        subs(argv);
    if (argv[2][0] == '*')
        multi(argv);
    if (argv[2][0] == '/')
        div(argv);
    if (argv[2][0] == '%')
        mod(argv);
}

int main(int argc, char **argv)
{
    do_op(argv);
    return (0);
}
