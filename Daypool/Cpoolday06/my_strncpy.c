/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** 
*/

char *my_strncpy(char *dest, char const *src, int n) {
    int j = 0;

    while(j < n) {
        for(int i; i < n; i++) {
            dest[i] = src[i];
        }
        j++;
    }
    return(dest);
}

