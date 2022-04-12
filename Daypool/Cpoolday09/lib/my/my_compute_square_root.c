/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** fonction
*/

int my_compute_square_root(int nb)
{
    int square_root = 0;

    while ((square_root * square_root) <= nb) {
        if ((square_root * square_root) == nb) {
            return (square_root);
        }
        square_root++;
    }
    return (0);
}
