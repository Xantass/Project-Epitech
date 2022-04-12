/*
** EPITECH PROJECT, 2020
** do-op.c
** File description:
** fonction
*/

int my_getnbr(char  *str);

void my_putchar(char c);

int my_put_nbr(int nb);

int sign(char  *str);

int my_putstr(char *str);

int sum(char **argv)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int res = 0;

    if (a == 0 && b == 0)
        return 0;
    else {
        res = a + b;
        my_put_nbr(res);
        my_putchar('\n');
    }
    return (0);
}

int substraction(char **argv)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int h = sign(argv[3]);
    int res = 0;

    if (a == 0)
        my_put_nbr(b);
    if (b == 0)
        my_put_nbr(a);
    if (a == 0 && b == 0)
        return 0;
    else {
        if (h % 2 == 0) {
            res = a + b;
            my_put_nbr(res);
            my_putchar('\n');
        } else {
            res = a - b;
            my_put_nbr(res);
            my_putchar('\n');
        }
    }
    return (0);
}

int multiplication(char **argv)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int res = 0;

    res = a * b;
    my_put_nbr(res);
    my_putchar('\n');
    return(0);
}

int division(char **argv)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int res = 0;

    if (b == 0)
        my_putstr("Stop: division by zero\n");
    else {
        res = a / b;
        my_put_nbr(res);
        my_putchar('\n');
    }
    return (0);
}

int modulo(char **argv)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int res = 0;

    if (b == 0)
        my_putstr("Stop: modulo by zero\n");
    else {
        res = a % b;
        my_put_nbr(res);
        my_putchar('\n');
    }
    return (0);
}
