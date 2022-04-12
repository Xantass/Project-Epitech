/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** init_struc_anim
*/

#include "struct.h"

anim_t init_anim(void)
{
    anim_t anim = {0};

    anim.clock = sfClock_create();
    anim.times = 0;
    return anim;
}