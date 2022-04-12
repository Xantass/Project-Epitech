/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** nnfewoimmcxioew
*/

int my_aachar_isnum(char const character)
{
    if (character < 48 || character > 57 )
        return 0;
    return 1;
}

int my_getpos_getnbr(char const *numstr, int resultnbr, int i)
{
    for (; my_aachar_isnum(*(numstr + i)) == 1; i++) {
        for (int u = 10; u > 0; u--)
            if (((u * resultnbr) + (*(numstr + i) - 48)) < 0)
                return (0);
        resultnbr = 10 * resultnbr + *(numstr + i) - 48;
    }
    return (resultnbr);
}

int my_getneg_getnbr(char const *numstr, int resultnbr, int i)
{
    for (; my_aachar_isnum(*(numstr + i)) == 1; i++) {
        for (int u = 10; u > 0; u--)
            if (((u * resultnbr) - (*(numstr + i) - 48)) > 0)
                return (0);
        resultnbr = (10 * resultnbr) - *(numstr + i) + 48;
    }
    return (resultnbr);
}

int my_getnbr(char const *numstr)
{
    int neg = 1;
    int i = 0;
    int resultnbr = 0;

    for (; *(numstr + i) == '-' || *(numstr + i) == '+'; i++)
        if (*(numstr + i) == '-')
            neg = -neg;
    if (neg == -1)
        return (my_getneg_getnbr(numstr, resultnbr, i));
    else
        return (my_getpos_getnbr(numstr, resultnbr, i));
}
