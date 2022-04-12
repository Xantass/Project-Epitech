/*
** EPITECH PROJECT, 2020
** rush-1-1
** File description:
** 
*/
int my_putstr(char const *str) {
    int nb_arr = 0;
    while (str[nb_arr] != '\0') {
        my_putchar(str[nb_arr]);
        nb_arr++;
    }
}
void rush(int x, int y) {
    char *str = "Invalid size\n";
    if (x <= 0 || y <= 0) {
        my_putstr(str);
        return(0);
    }
    else if (x == 1 && y == 1) {
        my_putchar('B');
        my_putchar('\n');
        return(0);
    }
    else if (x == 1 && y > 1) { 
        col(x,y);
    }
    else if (y == 1 && x > 1) {
        other_line(x,y);
    }else {
        firstline_col(x,y);
        second_line(x,y);
    }
}
void firstline_col(int x, int y) {
    int lon = 1;
    int lar;
    my_putchar('A');
    while (lon <= x-2) {
        my_putchar('B');
        lon++;
    }
    my_putchar('A');
    my_putchar('\n');
    for (lar = 1; lar <= y - 2; lar++) {
        my_putchar('B');
        for (lon = 1; lon <= x - 2; lon ++) {
            my_putchar(' ');
        }
        my_putchar('B');
        my_putchar('\n');
    }      
}
void second_line(int x, int y) {
    int lon2 = 1;
    my_putchar('C');
    while (lon2 <= x-2) {
        my_putchar('B');
        lon2++;
    }
    my_putchar('C');
}
void other_line(int x, int y) {
    int lon3 = 1;
    my_putchar('B');
    while (lon3 <= x-2) {
        my_putchar('B');
        lon3++;
    }
    my_putchar('B');
}
void col(int x, int y) {
    int lar2 = 1;
    my_putchar('B');
    my_putchar('\n');
    while (lar2 <= y-2){
        my_putchar('B');
        my_putchar('\n');
        lar2++;
    }
    my_putchar('B');
    my_putchar('\n');
}

