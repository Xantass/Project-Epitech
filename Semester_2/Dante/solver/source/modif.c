/*
** EPITECH PROJECT, 2021
** dante
** File description:
** modif
*/

int modif_map(int maze, int sol)
{
    if (maze == 1 && sol != 1)
        return 2;
    if (maze == 0 && sol != 1)
        return 0;
    return sol;
}