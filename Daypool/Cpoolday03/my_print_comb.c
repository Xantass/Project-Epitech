/*
** EPITECH PROJECT, 2020
** 
** File description:
** my_print_comb.c
*/
int my_print_comb(void)
{
    int unit;
    int decade;
    int hundred;
    for (hundred = '0'; hundred <= '9'; hundred++) {
        
        for (decade = hundred + 1; decade <= '9'; decade++) {

            for (unit = decade + 1; unit <= '9'; unit++) {

                my_putchar(hundred);
                my_putchar(decade);
                my_putchar(unit);
                if (hundred == '7' && decade == '8' && unit == '9'){

                    return(0); {
                    }
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }                  
    }
}
