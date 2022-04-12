/*
** EPITECH PROJECT, 2020
** percentage.c
** File description:
** fonction
*/

int my_char_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (0);
    }
    else if (c >= 'A' && c <= 'Z') {
        return (0);
    } else {
        return (1);
    }
    return (0);
}

float  percentage(char *test, int k)
{
    float stock = 0;
    int h = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    
    
    while (test[i] != '\0') {
        if (my_char_is_alpha(test[i]) == 0) { 
            h++;
        }
        i++;   
    }
    printf("k = %d\n", k);
    printf("h = %d\n", h);
    stock = (k / h);
    printf("stock = %f\n", stock);
    x = stock * 100;
    y = ((stock * 100) - x) * 100;
    printf("%d\n", x);
    printf("%d\n", y);
    return (stock);
}

int main(void)
{
    int k = 2;
    char test[] = "cbdecbeubc              ";
    percentage(test, k);
    //printf("%f\n", percentage(test, k));
}
