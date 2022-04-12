/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** ofprgnofenwo
*/

int my_compute_power_rec(int nb, int p);

int nb3gtzero(int nb, int nb3, int falsee, int p)
{
    if (p == 0)
        return 1;
    for (int nb2 = nb3; nb2 > 0; nb2--)
        if (nb * nb2 < 0)
            falsee = 1;
    nb = my_compute_power_rec(nb3, p - 1);
    if (falsee == 0) {
        nb *= nb3;
    } else {
        nb = 0;
        return 0;
    }
    return nb;
}

int nb3ltzero(int nb, int nb3, int falsee, int p)
{
    if (p == 0)
        return 1;
    if (nb < 0) {
        for (int nb2 = nb3; nb2 > 0; nb2--)
            if (nb * nb2 < 0)
                falsee = 1;
    } else {
        for (int nb2 = nb3; nb2 > 0; nb2--)
            if (nb * nb2 > 0)
                falsee = 1;
    }
    nb = my_compute_power_rec(nb3, p - 1);
    if (falsee == 0) {
        nb *= nb3;
    } else {
        nb = 0;
        return 0;
    }
    return nb;
}

int my_compute_power_rec(int nb, int p)
{
    int nb3 = nb;
    int falsee = 0;

    if (nb3 == 0)
        return 0;
    else if (nb3 > 0)
        return nb3gtzero(nb, nb3, falsee, p);
    else
        return nb3ltzero(nb, nb3, falsee, p);
}
