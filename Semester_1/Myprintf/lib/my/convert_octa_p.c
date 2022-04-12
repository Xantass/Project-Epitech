/*
** EPITECH PROJECT, 2020
** convert_octa.c
** File description:
** function
*/

int my_put_nbr(int nb);
void my_putchar(char c);
int my_getnbr(char const *str);
char *my_revstr(char *str);

void convert_octa_p(long long int init)
{
    char *base = "012345678";
    char res[100];
    long long nb = 0;
    int i = 0;

    while ((init / 8) > 0) {
        res[i] = (base[init % 8]);
        init = init / 8;
        i++;
    }
    res[i] = (base[init % 8]);
    res[i + 1] = '\0';
    my_revstr(res);
    nb = my_getnbr(res);
    my_put_nbr(nb);
}
